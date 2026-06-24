class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {   
        int best=1;

        for (auto point1: points)
        {
            unordered_map<string,int> p;
            for(auto point2: points)
            {   
                int x,y;
                if (point1[0]-point2[0]>=0)
                {
                    x=point1[0]-point2[0];
                    y=point1[1]-point2[1];
                }
                else
                {
                    x=point2[0]-point1[0];
                    y=point2[1]-point1[1];
                }

                if (x==0 and y==0) continue;

                int g=__gcd(x,y);
                x=x/g;
                y=y/g;

                string key=to_string(x)+" "+to_string(y);

                p[key]++;

                best=max(best,p[key]+1);
            }
        }  
        return best;  
    }
};