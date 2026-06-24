class Solution {
public:
    string minWindow(string s, string t) 
    {   
        vector<int> a(128,0);

        for (auto x:t)
        {
            a[x]++;
        }

        int begin=0,best_length=INT_MAX,current_length=0,best_start=0,size1=s.size(),size2=t.size();

        for(int end=0;end<size1;end++)
        {
            if (a[s[end]]>0) size2--;
            a[s[end]]--;

            while(size2==0)
            {   
                current_length=end-begin+1;
                if (current_length<best_length)
                {
                    best_length=current_length;
                    best_start=begin;
                }
                if(a[s[begin]]==0) size2++;
                a[s[begin]]++;
                begin++;
            }
        }
        if (best_length==INT_MAX)
        {
            return "";
        }
        return s.substr(best_start,best_length);
    }
};