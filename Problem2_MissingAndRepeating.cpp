#include <iostream>
using namespace std;

int main() {
    long long n;
    cout << "Enter size of array: ";
    cin >> n;

    long long arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long s = 0;
    long long s2 = 0;

    for (int i = 0; i < n; i++) {
        s = s + arr[i];
        s2 = s2 + (arr[i] * arr[i]);
    }

    long long exp_s = (n * (n + 1)) / 2;
    long long exp_s2 = (n * (n + 1) * (2 * n + 1)) / 6;

    long long A = s - exp_s;
    long long B = s2 - exp_s2;
    long long C = B / A;

    long long repeating = (A + C) / 2;
    long long missing = repeating - A;

    cout << "Repeating Number: " << repeating << endl;
    cout << "Missing Number: " << missing << endl;

    return 0;
}
