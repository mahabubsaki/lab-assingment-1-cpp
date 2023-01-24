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
    int first_array_size, second_array_size;
    cin >> first_array_size;
    vector<int> first_array, second_array;
    for (int i = 0; i < first_array_size; i++)
    {
        int item;
        cin >> item;
        first_array.push_back(item);
    }
    cin >> second_array_size;
    for (int i = 0; i < second_array_size; i++)
    {
        int item;
        cin >> item;
        second_array.push_back(item);
    }
    vector<int> sorted_first = merging(first_array);
    vector<int> sorted_second = merging(second_array);
    int first_index = 0, second_index = 0;
    bool is_subset = true;
    while (first_index < sorted_first.size() && second_index < sorted_second.size())
    {
        if (sorted_first[first_index] < sorted_second[second_index])
        {
            is_subset = false;
            break;
        }
        else if (sorted_first[first_index] == sorted_second[second_index])
        {
            first_index++;
        }
        else
        {
            second_index++;
        }
    }
    if (is_subset && (first_index == sorted_first.size()))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}