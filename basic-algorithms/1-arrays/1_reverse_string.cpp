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
    void reverseString(std:: vector<char>& s) {\

        int left = 0;
        int right = s.size() -1;

        while (left < right) {

            char left_ch = s[left];
            char right_ch = s[right];

            s[left]=right_ch;
            s[right]=left_ch;

            left++;
            right--;

        }

        printVector(s);
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

    std::vector<char> stringToReverse = {'h', 'e', 'l', 'l', 'o'};

    solution.reverseString(stringToReverse);

    return 0;
}