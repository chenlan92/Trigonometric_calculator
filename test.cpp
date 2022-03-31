

#include <stdio.h>
#include <math.h>

#include "mysin.h"
#include "mycos.h"
#include "myasin.h"
#include "myatan.h"
#include <iostream>

#define PI        3.14159265358979323846
#define TIME      100
#define STEP1      0.1
#define STEP2      0.01
#define STEP3      1
using namespace std;

int main()
{
	int t;
	double test_num1 = -5;
	double test_num2 = -0.8;
	double test_num3 = -50;
	double sin_error;
	double cos_error;
	double asin_error;
	double atan_error;
	double sin_error_mean;
	double cos_error_mean;
	double asin_error_mean;
	double atan_error_mean;

	for (t = 1; t <= TIME; t++)
	{
		sin_error = sin(test_num1) - mysin(test_num1);
		cos_error = cos(test_num1) - mycos(test_num1);
		asin_error = asin(test_num2) - myasin(test_num2);
		atan_error = atan(test_num3) - myatan(test_num3);
		test_num1 = test_num1 + STEP1;
		test_num2 = test_num2 + STEP2;
		test_num3 = test_num3 + STEP3;
	}
	sin_error_mean = sin_error / TIME;
	cos_error_mean = cos_error / TIME;
	asin_error_mean = asin_error / TIME;
	atan_error_mean = atan_error / TIME;
    cout << "sin函数误差均值 = " << sin_error << endl;
    cout << "cos函数误差均值 = " << cos_error << endl;
    cout << "arcsin函数误差均值 = " << asin_error << endl;
    cout << "arctan函数误差均值 = " << atan_error << endl;

}
