// gcd using brute force from min(a, b) downwards
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    int start = a < b ? a : b;
    int gcd = 1;
    for (int i = start; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
            break;
        }
    }
    cout << gcd << endl;
    return 0;
}
