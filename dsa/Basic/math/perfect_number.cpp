// check for perfect number (sum of proper divisors equals the number)
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 1)
    {
        cout << "No" << endl;
        return 0;
    }
    int sum = 1;
    for (int i = 2; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
        {
            sum += i;
            int other = n / i;
            if (other != i)
            {
                sum += other;
            }
        }
    }
    cout << (sum == n ? "Yes" : "No") << endl;
    return 0;
}
