public class GenericStackLL<T> {
    private static class Node<T> {
        T data;
        Node<T> next;

        Node(T data) {
            this.data = data;
            this.next = null;
        }
    }
    private Node<T> top;
    private int size;

    public GenericStackLL() {
        top = null;
        size = 0;
    }

    // Push an item onto the stack
    public void push(T item) {
        Node<T> newNode = new Node<>(item);
        newNode.next = top;
        top = newNode;
        size++;
    }

    // Pop an item from the stack
    public T pop() {
        if (isEmpty()) {
            return null; // Returning null if the stack is empty
        }
        T item = top.data;
        top = top.next;
        size--;
        return item;
    }

    // Peek at the top item of the stack without removing it
    public T peek() {
        if (isEmpty()) {
            return null; // Returning null if the stack is empty
        }
        return top.data;
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return top == null;
    }

    // Get the size of the stack
    public int size() {
        return size;
    }

    public static void main(String[] args) {
        GenericStackLL<Integer> intStack = new GenericStackLL<>();
        intStack.push(1);
        intStack.push(2);
        intStack.push(3);

        System.out.println("Peek: " + intStack.peek()); // Output: 3
        System.out.println("Pop: " + intStack.pop());   // Output: 3
        System.out.println("Peek: " + intStack.peek()); // Output: 2
        System.out.println("Size: " + intStack.size()); // Output: 2

        GenericStackLL<String> stringStack = new GenericStackLL<>();
        stringStack.push("A");
        stringStack.push("B");

        System.out.println("Peek: " + stringStack.peek()); // Output: B
        System.out.println("Pop: " + stringStack.pop());   // Output: B
        System.out.println("Peek: " + stringStack.peek()); // Output: A
        System.out.println("Size: " + stringStack.size()); // Output: 1
    }
}
