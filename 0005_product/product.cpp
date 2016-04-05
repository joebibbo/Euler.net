// prime.cpp : 
//
// This is a self-contained console application to solve a specific interview problem. 
// https://projecteuler.net/problem=5

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

    const int max=20;
    const int min=2;

    int product= max;
    bool found = false;

    while (!found)
    {
        for (int n = max - 1; n >= min; n--)
        {
            found = true;
            if ((product % n) != 0)
            {
                found = false;
                break;
            }
        }

        if ( !found )
            product += max;
    }

    printf("smallest divisible product = %d, for all integers [%d, %d]\n", product, max, min-1);

	return 0;
}

