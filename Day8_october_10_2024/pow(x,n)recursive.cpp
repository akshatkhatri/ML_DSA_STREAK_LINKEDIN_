class Solution {
public:
    double myPow(double x, int n) {

        bool neg_flag = false;
        if(n == 0)
        {
            return (double)1;
        }
        if(n < 0)
        {
            neg_flag = true;
            n = n * (-1);
        }

        if(n < 1)
        {
            return x;
        }

        
        return neg_flag == true? 1/(myPow(x,n-1) * x) : myPow(x,n - 1) * x;
    }
};