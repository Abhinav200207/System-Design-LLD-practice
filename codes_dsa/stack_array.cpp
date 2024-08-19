#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Stack
{
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == MAX_SIZE - 1);
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is full. Cannot push." << endl;
            return;
        }

        top++;
        arr[top] = value;
        cout << value << " pushed successfully." << endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        cout << arr[top] << " popped successfully." << endl;
        top--;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1;
        }

        return arr[top];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack: ";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    stack.display(); // Stack: 10 20 30

    cout << "Top element: " << stack.peek() << endl; // Top element: 30

    stack.pop();
    stack.pop();

    stack.display(); // Stack: 10

    cout << "Top element: " << stack.peek() << endl; // Top element: 10

    stack.pop();

    stack.display(); // Stack is empty.

    return 0;
}
