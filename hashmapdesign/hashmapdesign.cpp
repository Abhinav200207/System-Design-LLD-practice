#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V>
class AbHashMap
{
    int size;
    vector<list<pair<K, V>>> mp;

public:
    AbHashMap()
    {
        this->size = 1e5;
        mp.resize(size);
    }

    long long int hash(K key)
    {
        return std::hash<K>()(key) % size;
    }

    auto search(K key)
    {
        int i = hash(key);
        auto it = mp[i].begin();
        while (it != mp[i].end())
        {
            if (it->first == key)
                return it;
            it++;
        }
        return mp[i].end();
    }

    void put(K key, V value)
    {
        int i = hash(key);
        remove(key);
        mp[i].push_back({key, value});
    }

    V get(K key)
    {
        int i = hash(key);
        auto it = search(key);
        if (it != mp[i].end())
            return it->second;
        return -1;
    }

    void remove(K key)
    {
        int i = hash(key);
        auto it = search(key);
        if (it != mp[i].end())
            mp[i].erase(it);
    }
};

class MyHashMap
{
public:
    AbHashMap<int, int> mp;
    MyHashMap()
    {
    }

    void put(int key, int value)
    {
        mp.put(key, value);
    }

    int get(int key)
    {
        return mp.get(key);
    }

    void remove(int key)
    {
        mp.remove(key);
    }
};

int main()
{
    AbHashMap<string,int> mp;
    mp.put("A",1);
    mp.put("B",2);
    mp.put("C",3);
    cout << mp.get("A") << endl;
    cout << mp.get("C") << endl;
    cout << mp.get("B") << endl;
}