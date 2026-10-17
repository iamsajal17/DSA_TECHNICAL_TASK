#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    long long arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long max1 = arr[0] + 0;
    long long min1 = arr[0] + 0;
    long long max2 = arr[0] - 0;
    long long min2 = arr[0] - 0;

    for (int i = 1; i < n; i++) {
        long long val1 = arr[i] + i;
        long long val2 = arr[i] - i;

        if (val1 > max1) {
            max1 = val1;
        }
        if (val1 < min1) {
            min1 = val1;
        }

        if (val2 > max2) {
            max2 = val2;
        }
        if (val2 < min2) {
            min2 = val2;
        }
    }

    long long diff1 = max1 - min1;
    long long diff2 = max2 - min2;

    long long ans = diff1;
    if (diff2 > ans) {
        ans = diff2;
    }

    cout << "Maximum value: " << ans << endl;
    return 0;
}
