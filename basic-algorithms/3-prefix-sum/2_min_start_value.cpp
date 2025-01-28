#include <iostream>
#include <vector>

class Solution {
public:
    int minStartValue(std::vector<int>& nums) {
        
        for (int i = 1 ; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i-1];
        }

        bool good_val;
        int final_start_value;

        for (int start_value = 1; start_value <= 100 * nums.size(); start_value++ ) {
            good_val = true;
            for (int j = 0; j < nums.size(); j++) {
                
                if (nums[j] + start_value <= 0) {
                    good_val = false;
                    break;
                } 
            }
            
            if (good_val) {
                final_start_value = start_value;
                break;
            }

        }

        return final_start_value;
    }
};

int main() {


    Solution solution;

    std::vector<int> vec = {-22,-29,-21,0,-4,-26,10,-11,-14,-11};
    int val = solution.minStartValue(vec);

    std::cout << val << std::endl;

    return 0;
}
