#include <iostream>
#include <vector>
using namespace std;

void missingNum(vector<int> &arr)
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        int j;
        for (j = 0; j < arr.size(); j++)
        {
            if (i == arr[j])
            {
                break;
            }
        }
        if (j == arr.size())
        {
            cout << i << " ";
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 5};

    missingNum(arr);

    return 0;
}
