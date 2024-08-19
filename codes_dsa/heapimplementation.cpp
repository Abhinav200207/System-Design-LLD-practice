#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int arr[100];
    int sz = 0;

    void insert(int val)
    {
        sz++;
        int idx = sz;

        while (sz > 1)
        {
            int parent = idx / 2;

            if (arr[parent] < arr[idx])
            {
                swap(arr[parent], arr[idx]);
                idx = idx / 2;
            }
            else
            {
                return;
            }
        }
    }
};