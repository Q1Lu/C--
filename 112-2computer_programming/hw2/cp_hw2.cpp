#include <iostream>
#include <string> 

using namespace std;

class BigInteger
{
    private:
        string s;
    
    public:
        BigInteger(string num){this->s = num;};
        void print() const {cout << s << endl;};

        BigInteger multiply(BigInteger b)
        {
            int ia[30] = {};
            int ib[2] = {};
            int product[32] = {};
            int len = s.length();
            int start = 0;
            string answer ;
            string b_=b.s;

            for(int i = 0, j = len-1; j >= 0; i++, j--)
            {
                ia[i] = s[j] - '0';
            }
            for(int i = 0, j = 1; j >= 0; i++, j--)
            {
                ib[i] = b_[j] - '0';
            }
            
            for(int m = 0; m < 2; m++)
            {
                for(int n = 0; n < 30; n++)
                {
                    product[m + n] += ib[m] * ia[n];
                    
                    if(product[m + n] >= 10)
                    {
                        product[m + n + 1] += product[m + n] / 10;
                        product[m + n] = product[m + n] % 10;
                    }
                }
            }

            for(int k = 31; k >= 0; k--)
            {
                if(product[k] != 0)
                {
                    start = k;
                    break;
                }
            }

            for(int k = start; k >= 0; k--)
            {
                answer.append(to_string( product[k]));
            };

            BigInteger result(answer);
            return result;
        };
};

int main()
{
    string s;
    cin >> s;
    BigInteger a( s );
    const BigInteger b( "17" );
    b.print();
    a.multiply( b ).print();
}