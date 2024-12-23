#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(const vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        // Calculate the area
        int area = min(height[left], height[right]) * (right - left);
        max_area = max(max_area, area);

        // Move the pointer with the smaller height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> height2 = {1, 1};

    cout << "Max Area for height1: " << maxArea(height1) << endl; // Output: 49
    cout << "Max Area for height2: " << maxArea(height2) << endl; // Output: 1

    return 0;
}

