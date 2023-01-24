#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<int> arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int middle = ceil((right + left) / 2);
        if (arr[middle] == target)
        {
            arr.erase(arr.begin() + middle);
            return middle;
        }
        else if (arr[middle] > target)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }
    return -1;
};
int index_check(vector<int> arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int middle = ceil((right + left) / 2);
        if (arr[middle] == target)
        {
            return middle;
        }
        else if (arr[middle] > target)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }
    return 0;
}
int main()
{
    int input, target;
    cin >> input;
    vector<int> array;
    for (int i = 0; i < input; i++)
    {
        int item;
        cin >> item;
        array.push_back(item);
    }
    cin >> target;
    int first_index = binary_search(array, target);
    if (index_check(array, target))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}