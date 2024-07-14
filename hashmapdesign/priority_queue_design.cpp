#include <bits/stdc++.h>
using namespace std;

template<typename T, typename Comparator = less<T>>
class PriorityQueue {
private:
    vector<T> heap;
    Comparator comp;

    void heapifyUp(int index) {
        if (index && comp(heap[parent(index)], heap[index])) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);

        int highestPriority = index;

        if (leftChild < size() && comp(heap[highestPriority], heap[leftChild])) {
            highestPriority = leftChild;
        }

        if (rightChild < size() && comp(heap[highestPriority], heap[rightChild])) {
            highestPriority = rightChild;
        }

        if (highestPriority != index) {
            swap(heap[index], heap[highestPriority]);
            heapifyDown(highestPriority);
        }
    }

    int parent(int index) const { return (index - 1) / 2; }
    int left(int index) const { return (2 * index + 1); }
    int right(int index) const { return (2 * index + 2); }

public:
    PriorityQueue() = default;
    PriorityQueue(const Comparator& comp) : comp(comp) {}

    bool empty() const { return heap.empty(); }
    int size() const { return heap.size(); }

    void push(const T& value) {
        heap.push_back(value);
        heapifyUp(size() - 1);
    }

    void pop() {
        if (empty()) throw out_of_range("PriorityQueue is empty.");
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    const T& top() const {
        if (empty()) throw out_of_range("PriorityQueue is empty.");
        return heap.front();
    }
};

int main() {
    PriorityQueue<int,greater<int>> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    cout << "Top element is: " << pq.top() << endl; // 30

    pq.pop();
    cout << "Top element is: " << pq.top() << endl; // 20

    return 0;
}
