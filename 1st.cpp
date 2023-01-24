// WAP that takes n integer numbers, sorts them in non-increasing order using Quick sort.
#include <bits/stdc++.h>
using namespace std;
vector<int> quick_sort_reverse(vector<int> input_array)
{

    if (input_array.size() <= 1)
    {
        return input_array;
    }
    srand(time(nullptr));
    int pivot = rand() % input_array.size();
    vector<int> greater;
    vector<int> less_or_equal;
    for (int i = 0; i < input_array.size(); i++)
    {
        if (i == pivot)
        {
            continue;
        }
        else if (input_array[pivot] > input_array[i])
        {
            greater.push_back(input_array[i]);
        }
        else
        {
            less_or_equal.push_back(input_array[i]);
        }
    }
    vector<int> sorted_greater = quick_sort_reverse(greater);
    vector<int> sorted_less_or_equal = quick_sort_reverse(less_or_equal);
    vector<int> sorted_full;
    for (int i = 0; i < sorted_less_or_equal.size(); i++)
    {
        sorted_full.push_back(sorted_less_or_equal[i]);
    }
    sorted_full.push_back(input_array[pivot]);

    for (int i = 0; i < sorted_greater.size(); i++)
    {
        sorted_full.push_back(sorted_greater[i]);
    }
    return sorted_full;
};
int main()
{
    int input;
    cin >> input;
    vector<int> array;
    for (int i = 0; i < input; i++)
    {
        int array_items;
        cin >> array_items;
        array.push_back(array_items);
    }
    vector<int> sorted_array = quick_sort_reverse(array);
    for (int i = 0; i < sorted_array.size(); i++)
    {
        cout << sorted_array[i] << endl;
    }

    return 0;
}
// {4,3,32,53,75,312,32}
