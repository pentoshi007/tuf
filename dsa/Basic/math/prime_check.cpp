// check for prime number
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n <= 1)
    {
        cout << "No" << endl;
        return 0;
    }
    bool isPrime = true;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    cout << (isPrime ? "Yes" : "No") << endl;
    return 0;
}
