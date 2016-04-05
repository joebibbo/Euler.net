// palindrome.cpp : 
//
// This is a self-contained console application to solve a specific interview problem. The problem is to find largest
// prime factor a number passed through the command line.


//
// Programmer: Joe A. Bibbo
// Date: 3/28/2016
//

#include "stdio.h"
#include <vector>
#include <string>


using namespace std;

bool isPalindrome(int value)
{
    string strValue = std::to_string(value);
    string strReverse = strValue;

    std::reverse(std::begin(strReverse), std::end(strReverse));

    return ( strValue == strReverse);
}


int main(int argc, char* argv[])
{

    vector<int> operands;
    for ( int hundreds=9; hundreds > 0 ; hundreds--)
        for ( int tens=9; tens >= 0; tens--)
            for ( int ones=9; ones >= 0; ones--)
               operands.push_back(hundreds*100 + tens*10 + ones);
               //operands.push_back(tens*10 + ones);

    int largest = 0;
    while (operands.size())
    {
        int next = operands.front(); 
        printf("%d\n", next);

        for (int n: operands)
        {
            if (isPalindrome(n * next))
            {
                if ( (n*next) > largest)
                    largest = n*next;

                break;
            }
        }

        operands.erase( operands.begin() );
    }

    printf("the largest palindrome for a 3-digit product is : %d\n", largest);

	return 0; 
}

