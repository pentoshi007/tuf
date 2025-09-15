// reverse a number
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    bool negative = n < 0;
    if (negative)
    {
        n = -n;
    }
    long long reversed = 0;
    while (n > 0)
    {
        int lastDigit = (int)(n % 10);
        reversed = reversed * 10 + lastDigit;
        n = n / 10;
    }
    if (negative)
    {
        reversed = -reversed;
    }
    cout << reversed << endl;
    return 0;
}
