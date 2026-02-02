// gcd using Euclidean algorithm
#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    cout << a << endl;
    return 0;
}
