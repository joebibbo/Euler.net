// prime.cpp : 
//
// This is a self-contained console application to solve a specific problem. T
// https://projecteuler.net/problem=6

//
// Programmer: Joe A. Bibbo
// Date: 3/28/2016
//

#include "stdio.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <map>
#include <unordered_map>
#include <time.h>

using namespace std;


int main(int argc, char* argv[])
{
    const int max=100;
    const int min=1;

    long long sumSquared = 0;
    long long sum = 0;
    for (int n = min; n <= max; n++)
    {
        sum += n;
        sumSquared += ( n*n );
    }

    long long diff = ( sum * sum ) - sumSquared;

    printf("diff of the sum of squares from the sum squared of the first %d integers is %lld\n", max, diff);

	return 0;
}

