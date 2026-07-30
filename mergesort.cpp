#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <=mid && right <=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
{
    arr[i] = temp[i - low];
}
}
void ms(vector<int> &arr, int low, int high)
{
    if(low == high) return;
    int mid = (low + high)/2;
    ms(arr, low, mid);
    ms(arr,mid+1,high);
    merge(arr, low, mid, high);
}

vector<int> mergesort(vector<int> arr)
{
    ms(arr, 0, (arr.size()) - 1);
    return arr;
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    vector<int> sorted = mergesort(arr);

    for (int x : sorted)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}