#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j)
    {
        while(arr[i]<=pivot && i<=high -1)
        {
            i++;
        }
        while(arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotidx = partition(arr, low, high);
        qs(arr, low, pivotidx - 1);
        qs(arr, pivotidx + 1, high);
    }
}

vector<int> quicksort(vector<int> arr)
{
    qs(arr, 0, (arr.size()) - 1);
    return arr;
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    vector<int> sorted = quicksort(arr);

    for (int x : sorted)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}