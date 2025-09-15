// count number of digits in a number
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n < 0)
    {
        n = -n;
    }
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    cout << count << endl;
    return 0;
}
