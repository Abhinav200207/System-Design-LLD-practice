#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> rank, parent;

public:
    DSU(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int parent_u = find(u);
        int parent_v = find(v);

        if (parent_u == parent_v)
        {
            return;
        }
        if (rank[parent_u] < rank[parent_v])
        {
            parent[parent_u] = parent_v;
        }
        else if (rank[parent_u] > rank[parent_v])
        {
            parent[parent_v] = parent_u;
        }
        else
        {
            parent[parent_u] = parent_v;
            rank[parent_u]++;
        }
    }
    bool isConnected(int node1, int node2)
    {
        return find(node1) == find(node2);
    }
    int numberOfComponents(int n)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};

class DSU_sz
{
    vector<int> size, parent;

public:
    DSU_sz(int n)
    {
        size.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int parent_u = find(u);
        int parent_v = find(v);
        if (parent_u == parent_v)
            return;
        if (size[parent_u] < size[parent_v])
        {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else
        {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }

    bool isConnected(int node1, int node2)
    {
        return find(node1) == find(node2);
    }

    int numberOfComponents(int n)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};

int main()
{
    int n = 10;
    DSU *dsu = new DSU(n);

    dsu->unionByRank(1, 2);
    dsu->unionByRank(1, 4);
    dsu->unionByRank(5, 6);
    dsu->unionByRank(9, 8);
    dsu->unionByRank(2, 7);

    cout << 1 << " : " << dsu->find(1) << endl;
    cout << 2 << " : " << dsu->find(2) << endl;
    cout << 3 << " : " << dsu->find(3) << endl;
    cout << 4 << " : " << dsu->find(4) << endl;
    cout << 5 << " : " << dsu->find(5) << endl;
    cout << 6 << " : " << dsu->find(6) << endl;
    cout << 7 << " : " << dsu->find(7) << endl;
    cout << 8 << " : " << dsu->find(8) << endl;
    cout << 9 << " : " << dsu->find(9) << endl;
    cout << 10 << " : " << dsu->find(10) << endl;
    cout << dsu->numberOfComponents(10);
}