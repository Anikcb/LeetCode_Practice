class Solution {
public:
    string tostring(long long x){string s="";while(x){s += (x%10)+'0';x/=10;}reverse(s.begin(),s.end());return s;}

    bool isPalindrome(int x) {
        string s;
        if(x<0)s="-"+tostring((long long)-1*x);
        else s=tostring(x);
        for(int i=0;i<(int)s.size()/2;i++){
            if(s[i]!=s[(int)s.size()-i-1])return false;
        }
        return true;
    }
};
