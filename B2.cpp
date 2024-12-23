#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;

    // Loop to generate rows
    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1); // Create a row with `i+1` elements initialized to 1

        // Fill the middle elements
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        // Add the row to the triangle
        triangle.push_back(row);
    }

    return triangle;
}

int main() {
    int numRows = 5; // Example input
    vector<vector<int>> result = generate(numRows);

    // Print the Pascal's triangle
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

