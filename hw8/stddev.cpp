#include "stddev.h"
#include <iostream>
#include <cstdarg>
#include <cmath>
#include <vector>
using namespace std;

double stddev(int n, ...)
{
    double sum = 0;
    double mean = 0.0;
    double stdev = 0.0;
    vector<int> e; //vector containing elements
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++)
	{
        int num = va_arg(args, int);
        e.push_back(num);
		sum += num; 
	}
    va_end(args);
    
    mean = sum / n;
    for (int i = 0; i < n; i++)
	{
        stdev += pow( e[i] - mean, 2); 
	}
    stdev /= n;
	return sqrt(stdev);
}

