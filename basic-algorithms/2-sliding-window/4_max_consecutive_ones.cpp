#include <iostream>
#include <boost/math/special_functions/pow.hpp>
#include <vector>
#include <deque>

class Solution {
public:
    int maxOnes(std::vector<int>& nums, int k) {
    
    //would work better as an array if leetcode allowed it

    //using the standard catepillar technique, move the back foot when there are more than k zeroes

    int maxOnes =0;
    int right = nums.size()-1;
    int left = right -k+1;
    // left and right are inclusive, so the sub array is [left,right] (i.e. not (left,right])



    //initialize maxOne
    while (left <= right) {
        maxOnes += nums[left];
        left++;
    }


    int ones = maxOnes;
    left = right -k +1;
    int zeroes = right - left + 1 - ones;
    
    if (maxOnes < k) {
        maxOnes =k;
    }


    //recall zeroes = right - left + 1 - ones
    while (left > 0) {
        left--;
        zeroes += 1 - nums[left];
        //crawl catepilar if condition is not met
        while (zeroes > k) {
            zeroes -= 1 - nums[right];
            right--; 
        }
        //if the condition is met, evaluate the metric, maxOnes
        ones = right - left + 1;
        if (ones > maxOnes) {
            maxOnes = ones;
        }

    }
    return maxOnes;
    }        
};


int main() {


    Solution solution;

    std::vector<int> vec = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int maxOnes = solution.maxOnes(vec,3);

    std::cout << "maxOnes: " << maxOnes << std::endl;

    return 0;
}