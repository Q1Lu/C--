#include <iostream>
using namespace std;

bool searchMatrix(int matrix[][4], int rows, int cols, int target) {
    int row = 0;
    int col = cols - 1;

    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            cout << "元素 " << target << " 位於 (" << row + 1 << ", " << col + 1 << ")" << endl;
            return true;
        }
        else if (matrix[row][col] > target) {
            col--;
        }
        else {
            row++;
        }
    }

    cout << "元素 " << target << " 不在矩陣中" << endl;
    return false;
}

int main() {
    int matrix[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    int target;
    cout << "請輸入要搜尋的元素: ";
    cin >> target;

    searchMatrix(matrix, 4, 4, target);

    return 0;
}