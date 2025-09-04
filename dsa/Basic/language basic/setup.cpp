#include <bits/stdc++.h>
using namespace std;

int main()
{
    FAST_IO;

    // Competitive Programming Template Demonstration
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Demonstrate various features
    cout << "Array size: " << sz(arr) << endl;
    cout << "Sum: " << accumulate(all(arr), 0) << endl;
    cout << "Max element: " << *max_element(all(arr)) << endl;
    cout << "Min element: " << *min_element(all(arr)) << endl;

    // Test mathematical functions
    cout << "GCD of first two: " << gcd(arr[0], arr[1]) << endl;
    cout << "2^10 = " << power(2, 10) << endl;

    // Sort and display
    sort(all(arr));
    cout << "Sorted: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}