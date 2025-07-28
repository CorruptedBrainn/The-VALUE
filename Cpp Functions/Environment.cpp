#include "Environment.h"

// Be given some points, a radius, an irregularity value, a sharpness value, and a frequency
// Returns the list of points that make up the generated polygon
// Frequency works from 0-1, with 10 points at 1, 0 points at 0, multiplied by floor(radius / 100)

using namespace std;

vector<double> generateSteps(int n, double i) {
	vector<double> angles;
	double lowerBound = (2 * M_PI / n) - i;
	double upperBound = (2 * M_PI / n) + i;
	double angleSum = 0;
	random_device seed;
	mt19937 gen(seed());
	uniform_real_distribution<double> rand(lowerBound, upperBound);
	for (int i = 0; i < n; i++) {
		double angle = rand(gen);
		angles.push_back(angle);
		angleSum += angle;
	}
	angleSum /= 2 * M_PI;
	for (int i = 0; i < n; i++) angles[i] /= angleSum;
	return angles;
}

double clip(double value, double lower, double upper) {
	return min(upper, max(value, lower));
}

DLL_FUNCTION double** createPolygon(double x, double y, double r, double i, double s, int n) {
	i *= 2 * M_PI / n;
	s *= r;
	vector<double> angles = generateSteps(n, i);
	random_device seed;
	mt19937 gen(seed());
	uniform_real_distribution<double> once(0, 2 * M_PI);
	normal_distribution<double> rand(r, s);
	double angle = once(gen);
	double** ret = new double*[n];
	for (int i = 0; i < n; i++) {
		double radius = clip(rand(gen), 0, 2 * r);
		double* point = new double[2](x + r * cos(angle), y + r * sin(angle));
		ret[i] = point;
		angle += angles[i];
	}
	return ret;
}

DLL_FUNCTION int deletePolygon(double** polygon, int n) {
	for (int i = 0; i < n; i++) delete[] polygon[i];
	delete[] polygon;
	return 0;
}
