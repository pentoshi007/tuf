// check if 3-digit Armstrong number (sum of cubes of digits equals number)
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int original = n;
    int sum = 0;
    while (n > 0)
    {
        int lastDigit = n % 10;
        sum = sum + lastDigit * lastDigit * lastDigit;
        n = n / 10;
    }
    cout << (original == sum ? "Yes" : "No") << endl;
    return 0;
}
