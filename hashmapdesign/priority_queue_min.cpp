#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Compare = less<T>>
class MinMaxQueue
{
public:
    queue<T> Q;
    deque<T> D;
    Compare comp;

    void enque_element(const T &element)
    {
        if (Q.empty())
        {
            Q.push(element);
            D.push_back(element);
        }
        else
        {
            Q.push(element);
            while (!D.empty() && comp(element, D.back()))
            {
                D.pop_back();
            }
            D.push_back(element);
        }
    }

    void deque_element()
    {
        if (Q.front() == D.front())
        {
            Q.pop();
            D.pop_front();
        }
        else
        {
            Q.pop();
        }
    }

    T getMinMax() { return D.front(); }
};

// Example usage
int main()
{
    MinMaxQueue<int> k; // min queue
    int example[3] = {1, 2, 4};

    for (int i = 0; i < 3; i++)
    {
        k.enque_element(example[i]);
    }
    cout << k.getMinMax() << "\n";
    k.deque_element();
    cout << k.getMinMax() << "\n";

    // Using MinMaxQueue with strings
    MinMaxQueue<string, greater<string>> k_string; // max queue
    k_string.enque_element("c");
    k_string.enque_element("b");
    k_string.enque_element("a");
    cout << k_string.getMinMax() << "\n";
    k_string.deque_element();
    cout << k_string.getMinMax() << "\n";
    return 0;
}
