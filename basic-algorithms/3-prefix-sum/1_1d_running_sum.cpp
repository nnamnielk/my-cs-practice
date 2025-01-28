#include <iostream>
#include <vector>

void printVector(const std::vector<int>& vec) {
    // Method 1: Using range-based for loop
    for (int ch : vec) {
        std::cout << '|' << ch << '|';
    }
    std::cout << std::endl;
}

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        for (int i = 1 ; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i-1];
        }

        return nums;
    }
};

int main() {


    Solution solution;

    std::vector<int> vec = {7,4,3,9,1,8,5,2,6};
    std::vector<int> sum = solution.runningSum(vec);

    printVector(sum);

    return 0;
}
