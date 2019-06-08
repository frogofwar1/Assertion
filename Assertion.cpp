#include <iostream>
#include "CWStd.hpp"
#include "CWUtest.hpp"

#define _CRTDBG_MAP_ALLOC

const float PI = 3.141;

using namespace cw;

float calCircleArea(float t_r)
{
	return PI * t_r * t_r;
}

float calSquareArea(float t_w)
{
	// What are valid values
	REQUIRED(t_w >= 0);
	REQUIRED(t_w < 100000);

	float area = 0.0f;

	if (t_w >= 0)
		area = t_w * t_w;

	PROMISED(area >= 0);
	
	return area;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CWUtest ut;

	ut.init("Test CalSqrArea Funtion");
	ut.test("calSquareArea(5) == 25 : ", calSquareArea(5) == 25);
	ut.test("calSquareArea(5) == 20 : ", calSquareArea(5) == 20);
	ut.test("calSquareArea(30000) == 25 : ", calSquareArea(30000) == 25);
	ut.report();
	// 1 pass
	// 2 fail


	//std::cout << "circle : " << calSquareArea(-5);

	getchar();
}