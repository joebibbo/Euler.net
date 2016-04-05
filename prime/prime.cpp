// prime.cpp : 
//
// This is a self-contained console application to solve a specific interview problem. The problem is to find largest
// prime factor a number passed through the command line.

// Horribly slow implementation.

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

bool isPrime(long long n)
{
    //printf("isPrime(%lld) \n", n);
    bool bPrime = true;
    for (long long m = 2; m < n / 2 && bPrime; m++)
    { 
        //printf("\t trying (%lld) remainder ( %lld %% %lld = %lld) \n", m, n, m,  n%m );
        if ( n%m == 0 )
            bPrime = false;
    }

    return bPrime;
}

long long largestPrime(long long n)
{
    if ( isPrime(n) )
        return n;

    long long onePerc = (n / 2) / 100;
    
    long long count = onePerc;
    int perc = 0;
      
    for (long long m = n / 2; m > 1; m--)
    {
        if (0 == onePerc--)
        {
            printf("percentage completed(%d) \n", perc++);
            onePerc = count;
        }

       // printf("trying prime: %ld\n", m);
        if ( n%m == 0)
            if (isPrime(m))
                return m;
    }

    return (long long) -1;
}

int main(int argc, char* argv[])
{

    if ( argc != 2 )
    {
        printf("Usage: prime <number>\n");
        return 1;
    }

    long long nValue = 0;
    try 
    {
        nValue = std::stoll(argv[1]);


        long long  nLargestPrimeFactor = largestPrime(nValue);

        if ( nLargestPrimeFactor != -1 )
            printf("largest prime factor: %d\n", nLargestPrimeFactor);
        else
            printf("There are NO prime factors for this number.\n");
    }
    catch (...)
    {
        printf("Invalid input: '%s'. Needs to be a valid integer\n", argv[1]);
        exit(1);
    }

    time_t start, end;
    time(&start);
   

    time(&end);
    double seconds = difftime( end, start );
    printf("execution time: %.f secs (rounded) \n", seconds);

	return 0;
}

