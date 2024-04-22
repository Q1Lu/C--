// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int findMax(int number_list[], int length, int &max_i) {
    int max = number_list[0];
    max_i = 0;
    for (int i = 1; i < length; i++) {
        if (number_list[i] > max) {
            max = number_list[i];
            max_i = i;
        }
    }
    return max;
}

void findMin(int number_list[], int length, int &min_n, int &min_i) {
    min_n = number_list[0];
    min_i = 0;
    for (int i = 1; i < length; i++) {
        if (number_list[i] < min_n) {
            min_n = number_list[i];
            min_i = i;
        }
    }
}

int main() {
    int test_cases;
    cin >> test_cases;

    for (int i=0; i<test_cases; i++) {
        int length;
        cin >> length;

        int number_list[length] = {0};
        for (int j=0; j<length; j++) {
            cin >> number_list[j];
        }

        int max_i, min_i, min_n, out_count=0;
        cout << "##";
        do {
            if (out_count % 10 == 0 && out_count != 0) {
                cout << endl << "#";
            }
            findMin(number_list, length, min_n, min_i);
            number_list[min_i] = findMax(number_list, length, max_i);
            cout << " " << min_n;
            out_count++;
        } while (out_count < length || min_i != max_i);
        cout << endl;
    }
}