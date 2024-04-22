#include <bits/stdc++.h>
using namespace std;

int factorial(int input) {
    int ans = 1;
    for (int i = 1; i <= input; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    int num = 0;
    cin >> num;
    cout << factorial(num);
    return 0;
}