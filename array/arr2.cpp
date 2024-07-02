#include <iostream>
#include <vector>
using namespace std;

void missingNum(vector<int> &arr)
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        int appear = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] == i)
            {
                appear = 1;
                break;
            }
        }
        if (appear == 0)
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
