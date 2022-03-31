
#include<iostream>
#include<stdio.h>
#include<math.h>
#include"myatan.h"
#include"myasin.h"
#include"mysin.h"
#include"mycos.h"
#define PI  3.14159265358979323846;
#define TIME    100;
#define STEP    0.1;
using namespace std;

void test()
{
    int t,n = 0;
    double test_num = 0;
    double sin_error;
    double cos_error;
    double asin_error;
    double atan_error;
    double sin_error_mean;
    double cos_error_mean;
    double asin_error_mean;
    double atan_error_mean;

    for (t = 1; t <= TIME;t++)
    {
        sin_error += (sin(test_num) - mysin(test_num));
        sin_error_mean = sin_error / 100;
        cos_error += (cos(test_num) - mycos(test_num));
        cos_error_mean = cos_error / 100;
        asin_error += (asin(test_num) - myasin(test_num));
        asin_error_mean = asin_error/ 100;
        atan_error += (atan(test_num) - myatan(test_num));
        atan_error_mean = atan_error / 100;
        test_num += STEP;
    }
    cout << "sin函数误差均值 = " << sin_error_mean << endl;
    cout << "cos函数误差均值 = " << cos_error_mean << endl;
    cout << "arcsin函数误差均值 = " << asin_error_mean << endl;
    cout << "arctan函数误差均值 = " << atan_error_mean << endl;
}

