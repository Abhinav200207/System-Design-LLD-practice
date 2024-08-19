#include <iostream>

class Node
{
public:
    int val;
    Node *next;

    Node(int value)
    {
        val = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << value << " enqueued successfully." << std::endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node *temp = front;
        int dequeuedValue = temp->val;

        front = front->next;
        delete temp;

        std::cout << dequeuedValue << " dequeued successfully." << std::endl;

        if (front == nullptr)
        {
            rear = nullptr;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot peek." << std::endl;
            return -1;
        }

        return front->val;
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        std::cout << "Queue: ";
        Node *current = front;
        while (current != nullptr)
        {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display(); // Queue: 10 20 30

    std::cout << "Front element: " << queue.peek() << std::endl; // Front element: 10

    queue.dequeue();
    queue.dequeue();

    queue.display(); // Queue: 30

    std::cout << "Front element: " << queue.peek() << std::endl; // Front element: 30

    queue.dequeue();

    queue.display(); // Queue is empty.
    return 0;
}
