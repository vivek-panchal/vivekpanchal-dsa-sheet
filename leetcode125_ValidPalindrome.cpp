class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ' ')
                continue;
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                t += tolower(s[i]);
        }
        int i = 0, j = t.size() - 1;
        while(i < j)
        {
            if(t[i] == t[j])
            {
                ++i;
                --j;
            }
            else
                return false;
        }
        return true;
    }
};
