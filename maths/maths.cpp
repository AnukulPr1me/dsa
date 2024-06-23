#include <iostream>

using namespace std;

// all functions

void countNumber(int n)
{
    int count = 0;
    while (n > 0)
    {
        count = count + 1;
        n = n / 10;
    }
    cout << count;
}

void revNumber(int n)
{
    int reversed = 0;
    while (n > 0)
    {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }
    cout << reversed;
}

void isPalindrome(int n)
{
    int original = n;
    int reversed = 0;

    while (n > 0)
    {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }

    if (reversed == original)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

void isArmstrongNum(int n)
{
    int sum = 0;
    int orignal = n;

    while (n > 0)
    {
        int digit = n % 10;
        sum = sum + (digit * digit * digit);
        n = n / 10;
    }
    if (sum == orignal)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

void printAllDiv(int n)
{

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << endl;
        }
    }
}

void printAllPrime(int n)
{
    int count = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if ((n / i) != i)
                count++;
        }
    }
    if (count == 2)
        cout << "true";
    else
        cout << "false";
}

void gcd(int n1, int n2) {
    cin >> n1;
    cin >> n2;
    for(int i =min(n1, n2); i>=1; i++) {
        if(n1%i==0 && n2%i == 0) {
            cout << i;
            break;
        }
    }
}
int main()
{
    int n1;
    int n2;
    // calling function
    gcd(n1, n2);
    return 0;
}