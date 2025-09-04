#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array size: " << arr.size() << endl;
    cout << "Sum: " << accumulate(arr.begin(), arr.end(), 0) << endl;
    cout << "Max element: " << *max_element(arr.begin(), arr.end()) << endl;

    return 0;
}