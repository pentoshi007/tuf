#include <bits/stdc++.h>
using namespace std;

int main()
{
    int bdate, bmonth;
    cin >> bdate >> bmonth;
    cout << bdate << " " << bmonth << endl;
    string name, greetings, greetings2;
    cin >> name;
    cout << name << endl;
    cin >> greetings;
    cout << greetings << endl;
    cin.ignore(); // Clear the newline character left in the buffer
    getline(cin, greetings2);
    cout << greetings2 << endl;

    int num = 5;
    cout << &num << endl;
    int *ptr = &num;
    cout << ptr << endl;
    cout << *ptr << endl;
    *ptr = 10;
    cout << num << endl;
    cout << "name size " << name.size() << endl;
    cout << "greetings size " << greetings.size() << endl;
    cout << "greetings2 size " << greetings2.size() << endl;
    return 0;
}