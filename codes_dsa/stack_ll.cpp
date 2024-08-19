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

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    bool isEmpty()
    {
        return (top == nullptr);
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        std::cout << value << " pushed successfully." << std::endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }

        Node *temp = top;
        int poppedValue = temp->val;
        top = top->next;
        delete temp;

        std::cout << poppedValue << " popped successfully." << std::endl;
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
            return -1;
        }

        return top->val;
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        std::cout << "Stack: ";
        Node *ptr = top;
        while (ptr != nullptr)
        {
            std::cout << ptr->val << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display(); // Stack: 30 20 10

    std::cout << "Top element: " << stack.peek() << std::endl; // Top element: 30

    stack.pop();
    stack.pop();

    stack.display(); // Stack: 10

    std::cout << "Top element: " << stack.peek() << std::endl; // Top element: 10

    stack.pop();

    stack.display(); // Stack is empty.

    return 0;
}
