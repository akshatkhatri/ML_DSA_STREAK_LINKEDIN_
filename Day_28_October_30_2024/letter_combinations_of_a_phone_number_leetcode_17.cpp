class Solution {

private:
    unordered_map<char,string> phone_map = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    void generate(vector<string>&res,string &digits, string &ans, int i)
    {
        if(i == digits.size())
        {
            res.push_back(ans);
            return;
        }

        for(auto character : phone_map[digits[i]])
        {
            ans.push_back(character);
            generate(res,digits,ans,i+1);
            ans.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {

        vector<string>res;
        if(digits.size() == 0)
        {
            return res;
        }
        string ans;

        generate(res,digits,ans,0);
        return res;
    }
};