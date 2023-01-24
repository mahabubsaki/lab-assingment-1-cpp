#include <bits/stdc++.h>
using namespace std;
int main()
{
    int input, start, end;
    cin >> input;
    vector<int> array;
    for (int i = 0; i < input; i++)
    {
        int item;
        cin >> item;
        array.push_back(item);
    }
    cin >> start;
    cin >> end;
    for (int i = start - 1; i < end; i++)
    {
        array[i] = 0;
    }
    for (int i = 0; i < input; i++)
    {
        if (array[i] != 0)
        {
            cout << array[i] << " ";
        }
    }

    return 0;
}