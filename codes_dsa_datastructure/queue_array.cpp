#include <iostream>
#include <vector>
using namespace std;

#define MAX_SIZE 5

class Queue
{
    int front, rear, cnt;
    vector<int> arr;

public:
    Queue()
    {
        front = 0;
        rear = 0;
        cnt = 0;
        arr.resize(MAX_SIZE);
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        if (cnt == MAX_SIZE)
            return;
        arr[rear % MAX_SIZE] = e;
        rear++;
        cnt++;
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        if (cnt == 0)
            return -1;
        int ans = arr[front % MAX_SIZE];
        front++;
        cnt--;
        return ans;
    }

    int peek()
    {
        if (cnt == 0)
            return -1;
        return arr[front % MAX_SIZE];
    }

    void display()
    {
        if (cnt == 0)
            cout << "Empty hai bhai\n";
        for (int i = front; i < rear; i++)
        {
            cout << arr[i % MAX_SIZE] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    queue.display();

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    queue.enqueue(60);
    queue.enqueue(70);
    queue.dequeue();
    queue.dequeue();
    queue.display();
    queue.dequeue();
    cout << "Front element: " << queue.peek() << endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.display();
}