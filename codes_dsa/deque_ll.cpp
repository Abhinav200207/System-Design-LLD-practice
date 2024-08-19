#include <iostream>

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class Deque
{
private:
    Node *front;
    Node *rear;

public:
    Deque()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        return (front == nullptr && rear == nullptr);
    }

    void insertFront(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        std::cout << value << " inserted at the front successfully." << std::endl;
    }

    void insertRear(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << value << " inserted at the rear successfully." << std::endl;
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty. Cannot delete from the front." << std::endl;
            return;
        }

        Node *temp = front;
        int deletedValue = temp->data;

        if (front == rear)
        {
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;

        std::cout << deletedValue << " deleted from the front successfully." << std::endl;
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty. Cannot delete from the rear." << std::endl;
            return;
        }

        Node *temp = rear;
        int deletedValue = temp->data;

        if (front == rear)
        {
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;

        std::cout << deletedValue << " deleted from the rear successfully." << std::endl;
    }

    int getFront()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty. Cannot get front." << std::endl;
            return -1;
        }

        return front->data;
    }

    int getRear()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty. Cannot get rear." << std::endl;
            return -1;
        }

        return rear->data;
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty." << std::endl;
            return;
        }

        std::cout << "Deque: ";
        Node *ptr = front;
        while (ptr != nullptr)
        {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Deque deque;

    deque.insertFront(10);
    deque.insertRear(20);
    deque.insertFront(5);

    deque.display(); // Deque: 5 10 20

    std::cout << "Front element: " << deque.getFront() << std::endl; // Front element: 5
    std::cout << "Rear element: " << deque.getRear() << std::endl;   // Rear element: 20

    deque.deleteFront();
    deque.deleteRear();

    deque.display(); // Deque: 10

    std::cout << "Front element: " << deque.getFront() << std::endl; // Front element: 10
    std::cout << "Rear element: " << deque.getRear() << std::endl;   // Rear element: 10

    deque.deleteFront();

    deque.display(); // Deque is empty.

    return 0;
}
