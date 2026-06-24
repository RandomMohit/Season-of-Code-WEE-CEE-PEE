class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {   
        int length=s.length(),ans=1;

        if (!length) return 0;
        else if (length==1) return 1;
        
        unordered_map<char,int> Uniq={{s[0],0}};

        int ptr1=0,ptr2=0;
        while(ptr2!=length-1)
        {
            if (Uniq.count(s[ptr2+1]) and Uniq[s[ptr2+1]]>=ptr1)
            {
                ptr1=Uniq[s[ptr2+1]]+1;                
                ptr2++;
                Uniq[s[ptr2]]=ptr2;
            }
            else
            {
                ptr2++;
                Uniq[s[ptr2]]=ptr2;
            }
            ans=max(ans,ptr2-ptr1+1);
        }
        return ans;        
    }
};