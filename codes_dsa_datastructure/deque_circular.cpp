#include <iostream>

#define MAX_SIZE 100

class CircularDeque
{
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    CircularDeque()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % MAX_SIZE == front);
    }

    void insertFront(int value)
    {
        if (isFull())
        {
            std::cout << "Deque is full. Cannot insert at the front." << std::endl;
            return;
        }

        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front = (front - 1 + MAX_SIZE) % MAX_SIZE;
        }

        arr[front] = value;
        std::cout << value << " inserted at the front successfully." << std::endl;
    }

    void insertRear(int value)
    {
        if (isFull())
        {
            std::cout << "Deque is full. Cannot insert at the rear." << std::endl;
            return;
        }

        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = value;
        std::cout << value << " inserted at the rear successfully." << std::endl;
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty. Cannot delete from the front." << std::endl;
            return;
        }

        std::cout << arr[front] << " deleted from the front successfully." << std::endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty. Cannot delete from the rear." << std::endl;
            return;
        }

        std::cout << arr[rear] << " deleted from the rear successfully." << std::endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty. Cannot get front." << std::endl;
            return -1;
        }

        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty. Cannot get rear." << std::endl;
            return -1;
        }

        return arr[rear];
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty." << std::endl;
            return;
        }

        std::cout << "Deque: ";
        int current = front;
        while (current != rear)
        {
            std::cout << arr[current] << " ";
            current = (current + 1) % MAX_SIZE;
        }
        std::cout << arr[rear] << std::endl;
    }
};

int main()
{
    CircularDeque deque;

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
