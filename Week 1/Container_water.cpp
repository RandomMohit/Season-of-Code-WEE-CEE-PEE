class Solution {
public:
    int maxArea(vector<int>& height) {
        int length=height.size(),low=0,high=length-1;

        int area=0;

        while(low<high)
        {
            area=max(area,(high-low)*min(height[high],height[low]));

            if (height[low]<height[high]) low++;
            else high--;
        }

        return area;
    }
};