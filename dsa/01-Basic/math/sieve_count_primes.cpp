// count of prime numbers up to n using Sieve of Eratosthenes
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 2)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
