// check if number is palindrome
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n < 0)
    {
        cout << "No" << endl;
        return 0;
    }
    long long original = n;
    long long reversed = 0;
    while (n > 0)
    {
        int lastDigit = (int)(n % 10);
        reversed = reversed * 10 + lastDigit;
        n = n / 10;
    }
    cout << (original == reversed ? "Yes" : "No") << endl;
    return 0;
}
