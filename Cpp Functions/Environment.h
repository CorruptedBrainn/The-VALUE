#define _CRT_SECURE_NO_WARNINGS 1

#include <random>

#define DLL_FUNCTION __declspec(dllexport)

#pragma execution_character_set("utf-8")

extern "C" {
	DLL_FUNCTION int** createPolygon(float x, float y, float r, float i, float s, float f);
}