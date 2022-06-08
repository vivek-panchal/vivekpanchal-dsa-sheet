// 100% faster string comparision method

class Solution {
public:
string longestCommonPrefix(vector<string>& strs) {
    string ans;
    int n=strs.size();
    bool match =true;
    for(int i=0;i<strs[0].size();i++)
    {
        char ch=strs[0][i];
        for(int j=0;j<n;j++)
        {
            if(ch!=strs[j][i])
            {
                match=false;
                break;
            }
        }
        if(match==false)
        {
            break;
        }
        else
            ans.push_back(ch);
    }
    return ans;
  }
};

// sort the string and compare first & last string of given array

class Solution {
public:

string longestCommonPrefix(vector<string>& strs) {
    int n=strs.size();
    if(n==0)
        return "";
    string ans="";
    sort(strs.begin(),strs.end());
    string a=strs[0];
    string b=strs[n-1];
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==b[i])
        {
            ans+=a[i];
        }
        else
            break;
    }
    return ans;
    
}
};
