#include <bits/stdc++.h>
using namespace std;
vector<int> even_generator(vector<int> arr)
{
    vector<int> even_arr;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
        {
            even_arr.push_back(arr[i]);
        }
    }
    return even_arr;
}
int main()
{
    vector<int> array = {1, 2, 3, 4, 5};
    vector<int> even_numbers = even_generator(array);
    for (int i = 0; i < even_numbers.size(); i++)
    {
        cout << even_numbers[i] << " ";
    }
    return 0;
}