#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V>
class AbHashMap
{
    int size;
    vector<list<pair<K, V>>> mp;

public:
    AbHashMap(int size)
    {
        this->size = size;
        mp.resize(size);
    }

    long long int hashKey(K key)
    {
        return hash<K>{}(key) % size;
    }

    auto search(K key)
    {
        int i = hashKey(key);
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
        int i = hashKey(key);
        remove(key);
        mp[i].push_back({key, value});
    }

    V get(K key)
    {
        int i = hashKey(key);
        auto it = search(key);
        // if (it != mp[i].end())
            return it->second;
        // return -1;
        // return V();
    }
 
    void remove(K key)
    {
        int i = hashKey(key);
        auto it = search(key);
        if (it != mp[i].end())
            mp[i].erase(it);
    }
};

int main()
{
    AbHashMap<string, int> mp(100); // Pass the desired size here
    mp.put("A", 1);
    mp.put("B", 2);
    mp.put("C", 3);
    cout << mp.get("A") << endl;
    cout << mp.get("C") << endl;
    cout << mp.get("B") << endl;

    AbHashMap<int, int> mp1(100); // Pass the desired size here
    mp1.put(1, 1);
    mp1.put(2, 2);
    mp1.put(3, 3);
    cout << mp1.get(1) << endl;
    cout << mp1.get(2) << endl;
    cout << mp1.get(3) << endl;
    mp1.put(3, 4);
    cout << mp1.get(1) << endl;
}
