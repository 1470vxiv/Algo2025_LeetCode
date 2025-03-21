#include <iostream>
using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            bool a=false;
            

            if (n == 0) return 1.0;//終止條件
            if(n == -2147483648)
            {
                a = true;
                x = 1/x;
                n = 2147483647;
            }

            else if (n < 0)
            {
                x = 1/x;
                n = -n;
            }
            
            double half = myPow(x,n/2);
            if(n == 2147483647 && a == true) return x * x * half * half;
            else if(n%2 == 0) return half * half;
            else return x * half * half;
        }
    };

