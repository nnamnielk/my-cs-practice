#include <iostream>
#include <vector>

// Function to print vector
void printVector(const std::vector<char>& vec) {
    // Method 1: Using range-based for loop
    for (char ch : vec) {
        std::cout << ch;
    }
    std::cout << std::endl;
}

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        
        //split into negative and positive integers
        std::vector<int> neg_nums;

        for (int num : nums) {
            if (num < 0) {
                neg_nums.push_back(-1 * num);
            } else {
                break;
            }
        }
 
        nums = std::slice(nums.begin()+neg_nums.size(),nums.end());

        //re-sort string be absolute value



        //square everything

        return nums;

    }
};


int main() {

    // std::vector<int> Vector;

    // Vector.push_back(5);
    // Vector.push_back(5);
    // Vector.push_back('3');

    // printVector(Vector);

    // Create a vector of characters

    Solution solution;

    std::vector<int> vecToSquare = {-4,-1,0,3,10};

    solution.sortedSquares(vecToSquare);

    return 0;
}