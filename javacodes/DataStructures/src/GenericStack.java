public class GenericStack<T> {
    private Object[] stack;
    private int top;
    private int capacity;

    public GenericStack(int capacity) {
        this.capacity = capacity;
        stack = new Object[capacity];
        top = -1;
    }

    // Push an item onto the stack
    public void push(T item) {
        if (isFull()) {
            throw new IllegalStateException("Stack is full");
        }
        stack[++top] = item;
    }

    // Pop an item from the stack
    public T pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        T item = (T) stack[top];
        stack[top--] = null; // Clear the reference
        return item;
    }

    // Peek at the top item of the stack without removing it
    public T top() {
        if (isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        }
        return (T) stack[top];
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    public boolean isFull() {
        return top == capacity - 1;
    }

    public static void main(String[] args) {
        GenericStack<Integer> intStack = new GenericStack<>(5);
        intStack.push(1);
        intStack.push(2);
        intStack.push(3);

        System.out.println("Top: " + intStack.top()); // Output: 3
        System.out.println("Pop: " + intStack.pop()); // Output: 3
        System.out.println("Top: " + intStack.top()); // Output: 2
        System.out.println("Is Empty: " + intStack.isEmpty()); // Output: false
        System.out.println("Is Full: " + intStack.isFull()); // Output: false

        GenericStack<String> stringStack = new GenericStack<>(5);
        stringStack.push("A");
        stringStack.push("B");

        System.out.println("Top: " + stringStack.top()); // Output: B
        System.out.println("Pop: " + stringStack.pop()); // Output: B
        System.out.println("Top: " + stringStack.top()); // Output: A
        System.out.println("Is Empty: " + stringStack.isEmpty()); // Output: false
        System.out.println("Is Full: " + stringStack.isFull()); // Output: false
    }
}
