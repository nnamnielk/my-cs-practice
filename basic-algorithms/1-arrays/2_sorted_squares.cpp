#include <iostream>
#include <boost/math/special_functions/pow.hpp>
#include <vector>
#include <deque>

// Function to print vector
void printVector(const std::vector<int>& vec) {
    // Method 1: Using range-based for loop
    std::cout << "Beggining Output" << std::endl;
    for (int ch : vec) {
        std::cout << "<" << ch << ">";
    }
    std::cout << std::endl;
}

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        
        std::deque<int> sortedSquaredNums;

        int left = 0;
        int right = nums.size()-1;

        int leftSquared = std::pow(nums.at(left),2);
        int rightSquared = std::pow(nums.at(right),2);

        while (left <= right) {
            if (leftSquared > rightSquared) {
                left++;
                sortedSquaredNums.push_front(leftSquared);
                leftSquared = std::pow(nums.at(left),2);
            } else {
                right--;
                sortedSquaredNums.push_front(rightSquared);
                rightSquared = std::pow(nums.at(right),2);
            }
        }


        std::vector<int> result(sortedSquaredNums.begin(),sortedSquaredNums.end());


        return result;


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

    printVector(solution.sortedSquares(vecToSquare));

    return 0;
}