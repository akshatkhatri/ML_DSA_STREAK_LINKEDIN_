class Solution {

public:
    int helper(string &s, int i,bool is_negative,bool number_encountered,long long int result)
    {
        // long long int result = 0;
        // bool is_negative = false;
        // cout<<number_encountered<<endl;
        // cout<<result<<endl;
        if(i >= s.size() || ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '.'))
        {
            // cout<<result<<endl;
            // if (result == 2147483648) { // corresponds to INT_MIN
            //     return is_negative ? INT_MIN : (int)result;
            // }
            return is_negative ? -(int)result : (int)result; //placeholder
        }
        

        else if(s[i] == ' ')
        {
            if (number_encountered) {
                return is_negative ? -(int)result : (int)result; 
            }
            return helper(s,i+1,is_negative,number_encountered,result);
        }
        else if(s[i] == '+')
        {
            if (number_encountered) {
                return is_negative ? -(int)result : (int)result; 
            }
            number_encountered = true;
            is_negative = false;
            return helper(s,i+1,is_negative,number_encountered,result);
        }
        else if(s[i] == '-')
        {
            if (number_encountered) {
                return is_negative ? -(int)result : (int)result;
            }

            number_encountered = true;
            is_negative = true;
            return helper(s,i+1,is_negative,number_encountered,result);
        }
        else if(s[i] == '0' && result == 0)
        {
            number_encountered = true;
           return helper(s,i+1,is_negative,number_encountered,result);
        }
        else
        {
            number_encountered = true;

            if((long long) result * 10 + (s[i] - '0')> INT_MAX)
            {
                return is_negative ? INT_MIN : INT_MAX;
            }

            result = (result * 10) + (s[i] - '0');
            return helper(s,i+1,is_negative,number_encountered,result);
        }
        
        return is_negative ? -(int)result : (int)result; //placeholder

    }

public:
    int myAtoi(string s) {
        int i = 0;
        int result = helper(s,i,false,false,0);
        return result;
    }
};