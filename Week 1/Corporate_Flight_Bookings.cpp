class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
        vector<int> flights(n,0);

        for(auto x:bookings)
        {
            flights[x[0]-1]+=x[2];
            if (x[1]!=n) flights[x[1]]-=x[2];
        }

        for (int i=1;i<n;i++)
        {
            flights[i]+=flights[i-1];
        }
        return flights;
    }
};