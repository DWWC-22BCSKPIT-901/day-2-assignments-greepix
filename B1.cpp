#include <iostream>
#include <vector>

int majorityElement(const std::vector<int>& nums) {
    int candidate = 0, count = 0;

    // Step 1: Find the candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Step 2: Return the candidate
    return candidate;
}

int main() {
    std::vector<int> nums1 = {3, 2, 3};
    std::vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};

    std::cout << "Majority element in nums1: " << majorityElement(nums1) << std::endl; // Output: 3
    std::cout << "Majority element in nums2: " << majorityElement(nums2) << std::endl; // Output: 2

    return 0;
}

