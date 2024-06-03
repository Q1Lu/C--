#include<iostream>
#include<string>
using namespace std;

unsigned long long convertToDecimal(string skewedBinary)
{
    unsigned long long decimal = 0;
    for(int i = 0; i < skewedBinary.length(); i++)
    {
        unsigned long long digit = skewedBinary[skewedBinary.length() - i - 1] - '0';
        decimal = decimal + digit * ((1ULL << i + 1) - 1);
    }
    return decimal;
}

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
       string BinaryOne;
       string BinaryTwo;
       cin >> BinaryOne >> BinaryTwo;
       unsigned long long totalDecimal = convertToDecimal(BinaryOne) + convertToDecimal(BinaryTwo);
       int finalBinary[63] = {0};
       for(int n = 0, m = 63; n < 63, m > 0; n++, m--)
       {
        if(totalDecimal >= (1ULL << m) - 1)
        {
            finalBinary[n]++;
            totalDecimal = totalDecimal - ((1ULL << m) - 1);
            if(totalDecimal == (1ULL << m) - 1)
            {
                finalBinary[n]++;
                totalDecimal = totalDecimal - ((1ULL << m) - 1);
            }
        }  
            if(totalDecimal == 0)
            {
               break;
            }
        }
        bool nonzero = false;
        int spaces = 0;
        cout << "#" << " ";
        for(int x = 0; x < 63; x++)
        {
            if(finalBinary[x] == 0 && !nonzero)
            {
                continue;
            }
            if(finalBinary[x] != 0)
            {
                nonzero = true;
            }
            if(nonzero)
            {
                spaces++;
                cout << finalBinary[x];
                if(spaces % 10 == 0)
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}