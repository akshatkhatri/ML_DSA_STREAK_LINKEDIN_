#include<bits/stdc++.h>
using namespace std;

int priority(char s)
{
    if(s == '^')
        return 3;
        
    else if(s == '*' || s == '/')
        return 2;
            
    else if(s == '+' || s == '-')
        return 1;
        
    else
        return -1;
}

char flip_brackets(char ch)
{
    if(ch == '(')
        ch = ')';

    if(ch == ')')
        ch = '(';

    return ch;
}

void reverse_string_with_bracket_flip(string &s)
{
    int i = 0;
    int j = s.size() - 1;

    while(i < j)
    {
        if(s[i] == ')' || s[i] == '(')
            s[i] = flip_brackets(s[i]);

        if(s[j] == ')' || s[j] == '(')
            s[j] = flip_brackets(s[j]);

        swap(s[i], s[j]);
        i++;
        j--;
    }
    
}

string convert_infix_to_prefix(string s)
{
    stack<char>st;
    string ans;
    reverse_string_with_bracket_flip(s);

    int i = 0;

    while(i < s.size())
    {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            ans += s[i];
        }
        else if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if(s[i] == '^')
            {
                while(!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while(!st.empty() && priority(s[i]) < priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }

                st.push(s[i]);
            }
        }
            i++;
    }

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse_string_with_bracket_flip(ans);

    return ans;
}

int main()
{
    string s = "x+y*z/w+u";
    string ans = convert_infix_to_prefix(s);

    cout << ans << endl;
}