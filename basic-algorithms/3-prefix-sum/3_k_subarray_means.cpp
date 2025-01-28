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
    std::vector<int> getAverages(std::vector<int>& input, int k) {
        
        std::vector<int> nums;
        nums.push_back(0);

        int total_nums_minus_k = input.size() -k;
        int total_nums = input.size();
        
        for (int i = 0 ; i < total_nums; i++) {
            nums.push_back(nums[i] + input[i]);
        }

        printVector(nums);

        std::vector<int> result;

        for (int i=0; i < k; i++) {
            result.push_back(-1);
        }

        // The meat of the calculation
        for (int i=k; i < total_nums_minus_k ; i++ ) {
            std::cout << "my start: " << nums[i-k] << std::endl;
            std::cout << "my end: " << nums[i+k] << std::endl;
            result.push_back((nums[i + k] - nums[i-k])/(2*k +1));

        }


        for (int i=total_nums_minus_k; i < total_nums; i++) {
            result.push_back(-1);
        }

        return result;
    }
};

int main() {


    Solution solution;

    std::vector<int> vec = {7,4,3,9,1,8,5,2,6};
    std::vector<int> sum = solution.getAverages(vec,3);

    printVector(sum);

    return 0;
}
