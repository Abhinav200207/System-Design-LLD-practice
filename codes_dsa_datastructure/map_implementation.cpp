#include <vector>
#include <list>

using namespace std;

class MyHashMap
{
    vector<list<pair<int, int>>> mp;
    int size;

public:
    MyHashMap()
    {
        this->size = 1e5;
        mp.resize(size);
    }

    long long int hash(long long int key)
    {
        return ((key * 1031237) & ((1 << 20) - 1)) >> 5;
    }

    auto search(int key)
    {
        int i = hash(key);
        auto it = mp[i].begin();
        while (it != mp[i].end())
        {
            if (it->first == key)
                return it;
            it++;
        }
        return it;
    }

    void put(int key, int value)
    {
        int i = hash(key);
        remove(key);
        mp[i].push_back({key, value});
    }

    int get(int key)
    {
        int i = hash(key);
        auto it = search(key);
        if (it != mp[i].end())
            return it->second;
        return -1;
    }

    void remove(int key)
    {
        int i = hash(key);
        auto it = search(key);
        if (it != mp[i].end())
            mp[i].erase(it);
    }
};