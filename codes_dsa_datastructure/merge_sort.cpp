#include <bits/stdc++.h>
using namespace std;

// int ans = 0;
// Merges two sorted arrays into one
void merge(vector<int> &v, int l, int mid, int h)
{
    int n1 = mid - l + 1;
    int n2 = h - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = l;


    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            v[k++] = L[i++];
        else
        {
            // ans += (n1 - i);
            v[k++] = R[j++];
        }
    }

    while (i < n1)
        v[k++] = L[i++];

    while (j < n2)
        v[k++] = R[j++];

}

void mergeSort(vector<int> &v, int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, h);
        merge(v, l, mid, h);
    }
}

int main()
{
    vector<int> v{5, 1, 0, -1};
    mergeSort(v, 0, v.size() - 1);
    for (auto x : v)
        cout << x << " ";
    // cout << "\ncount inversion = " << ans;
}
