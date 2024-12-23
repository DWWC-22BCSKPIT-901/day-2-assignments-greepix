#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend()); // Sort jobs in descending order
        vector<int> workers(k, 0); // Array to store working times of workers
        int left = jobs[0], right = accumulate(jobs.begin(), jobs.end(), 0);
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssign(jobs, workers, 0, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

private:
    bool canAssign(vector<int>& jobs, vector<int>& workers, int jobIndex, int maxTime) {
        if (jobIndex >= jobs.size()) return true;

        for (int i = 0; i < workers.size(); i++) {
            if (workers[i] + jobs[jobIndex] > maxTime) continue; // Prune invalid cases

            workers[i] += jobs[jobIndex];
            if (canAssign(jobs, workers, jobIndex + 1, maxTime)) return true;
            workers[i] -= jobs[jobIndex];

            // Prune redundant checks: if the worker is still 0, no point assigning further jobs
            if (workers[i] == 0) break;
        }

        return false;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> jobs1 = {3, 2, 3};
    int k1 = 3;
    cout << "Minimum Max Working Time (Example 1): " << solution.minimumTimeRequired(jobs1, k1) << endl;

    // Example 2
    vector<int> jobs2 = {1, 2, 4, 7, 8};
    int k2 = 2;
    cout << "Minimum Max Working Time (Example 2): " << solution.minimumTimeRequired(jobs2, k2) << endl;

    return 0;
}

