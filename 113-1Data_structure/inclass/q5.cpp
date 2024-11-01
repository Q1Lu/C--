#include <iostream>
using namespace std;

struct Pair {
    int min;
    int max;
};

Pair findMinMax(int arr[], int low, int high) {
    Pair minmax, leftMinMax, rightMinMax;

    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    int mid = (low + high) / 2;
    leftMinMax = findMinMax(arr, low, mid);
    rightMinMax = findMinMax(arr, mid + 1, high);

    if (leftMinMax.min < rightMinMax.min) {
        minmax.min = leftMinMax.min;
    } else {
        minmax.min = rightMinMax.min;
    }

    if (leftMinMax.max > rightMinMax.max) {
        minmax.max = leftMinMax.max;
    } else {
        minmax.max = rightMinMax.max;
    }

    return minmax;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);

    Pair minmax = findMinMax(arr, 0, n - 1);

    cout << "最小值是: " << minmax.min << endl;
    cout << "最大值是: " << minmax.max << endl;

    return 0;
}
