#include <bits/stdc++.h>
using namespace std;
vector<int> merging(vector<int> arr)
{
    if (arr.size() <= 1)
        return arr;
    int middle = arr.size() / 2;
    vector<int> left_side;
    vector<int> right_side;
    for (int i = 0; i < middle; i++)
    {
        left_side.push_back(arr[i]);
    }
    for (int i = middle; i < arr.size(); i++)
    {
        right_side.push_back(arr[i]);
    }
    vector<int> sorted_left = merging(left_side);
    vector<int> sorted_right = merging(right_side);
    vector<int> sorted_all;
    int left_index = 0;
    int right_index = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (left_index == sorted_left.size())
        {
            sorted_all.push_back(sorted_right[right_index]);
            right_index++;
        }
        else if (right_index == sorted_right.size())
        {
            sorted_all.push_back(sorted_left[left_index]);
            left_index++;
        }
        else if (sorted_left[left_index] > sorted_right[right_index])
        {
            sorted_all.push_back(sorted_right[right_index]);
            right_index++;
        }
        else
        {
            sorted_all.push_back(sorted_left[left_index]);
            left_index++;
        }
    }
    return sorted_all;
};
int main()
{
    int input, target, result = 0;
    cin >> input;
    vector<int> array;
    for (int i = 0; i < input; i++)
    {
        int array_items;
        cin >> array_items;
        array.push_back(array_items);
    }
    cin >> target;
    vector<int> sorted_array = merging(array);
    int left_side = 0;
    int right_side = sorted_array.size() - 1;

    while (right_side > left_side)
    {
        if (sorted_array[left_side] + sorted_array[right_side] == target)
        {
            result++;
            left_side++;
            right_side--;
        }
        else if (sorted_array[left_side] + sorted_array[right_side] > target)
        {
            right_side--;
        }
        else
        {
            left_side++;
        }
    }
    cout << result << endl;

    return 0;
}