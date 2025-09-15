// factorial of a number using loop
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 0)
    {
        cout << -1 << endl; // undefined for negative integers
        return 0;
    }
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial = factorial * i;
    }
    cout << factorial << endl;
    return 0;
}
