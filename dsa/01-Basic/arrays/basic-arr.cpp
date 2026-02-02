// arrays
// int arr[]={1,2,3,4,5};
// int arr[5]={1,2,3,4,5};
// they are in contiguous memory location

// Q- sum of elements of an array
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }
    cout << sum << endl;
    return 0;
}

// Q- find num of odd elements in an array
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] % 2 != 0)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

// Q-reverse an array
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

// Q- check if an array is sorted ascendingly
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}