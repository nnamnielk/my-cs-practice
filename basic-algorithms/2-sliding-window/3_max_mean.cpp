#include <iostream>
#include <boost/math/special_functions/pow.hpp>
#include <vector>
#include <deque>

class Solution {
public:
    double maxMean(std::vector<int>& nums, int k) {
    
        //would work better as an array if leetcode allowed it

        int right = nums.size() -1;
        int left = right - k + 1; 
        double maxSum = 0;

        while (left <= right) {
            maxSum += nums[left]; //apparently [] doesn't check bounds and is therefore faster that .at(). 
            left++; //.at() added 12 ms and made me 42% slower
        }

        left = right -k +1;
        int windowSum = maxSum;

        while (left > 0) {
            left--;
            windowSum = windowSum + nums[left] - nums[right]; 
            right--;
            if (windowSum > maxSum) {
                maxSum = windowSum;
            }

        }

        double maxMean = static_cast<double>(maxSum)/k;
        return maxMean;

    }        
};


int main() {


    Solution solution;

    std::vector<int> vec = {1,12,-5,-6,50,3};
    double maxMean;
    maxMean = solution.maxMean(vec,4);

    std::cout << "maxMean: " << maxMean << std::endl;

    return 0;
}