#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int h)
{
    int pivot = v[l];
    int i = l;
    
    int j = h;
    while (i < j)
    {
        while (v[i] <= pivot and i < h)
            i++;
        while (v[j] > pivot and j > l)
            j--;
        if (i < j)
            swap(v[i], v[j]);
    }
    swap(v[l], v[j]);
    return j;
}

void quickSort(vector<int> &v, int l, int h)
{
    if (l < h)
    {
        int p = partition(v, l, h);
        quickSort(v, l, p - 1);
        quickSort(v, p + 1, h);
    }
}

int main()
{
    vector<int> v{4, 9, 2, 9, 5, 2, 0, 5, 1, 7};
    quickSort(v, 0, v.size() - 1);
    for (auto x : v)
        cout << x << " ";
}