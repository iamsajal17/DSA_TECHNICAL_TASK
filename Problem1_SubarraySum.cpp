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

    long long total_sum = 0;

    for (int i = 0; i < n; i++) {
        long long count = (long long)(i + 1) * (n - i);
        total_sum = total_sum + (arr[i] * count);
    }

    cout << "Sum of all subarrays: " << total_sum << endl;
    return 0;
}
