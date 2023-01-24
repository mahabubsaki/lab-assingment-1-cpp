#include <bits/stdc++.h>
using namespace std;
int main()
{
    int input;
    cin >> input;
    vector<int> array;
    for (int i = 0; i < input; i++)
    {
        array.push_back(0);
    }
    for (int i = 0; i < input - 1; i++)
    {
        int item;
        cin >> item;
        array[item - 1] = item;
    }
    for (int i = 0; i < input; i++)
    {
        if (array[i] == 0)
        {
            cout << i + 1;
            break;
        }
    }

    return 0;
}