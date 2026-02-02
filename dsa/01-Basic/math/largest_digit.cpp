// find largest digit in a number
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n < 0)
    {
        n = -n;
    }
    int largest = 0;
    if (n == 0)
    {
        largest = 0;
    }
    while (n > 0)
    {
        int lastDigit = (int)(n % 10);
        if (lastDigit > largest)
        {
            largest = lastDigit;
        }
        n = n / 10;
    }
    cout << largest << endl;
    return 0;
}
