class Node<T> {
    T data;
    Node<T> next;

    Node(T data) {
        this.data = data;
        this.next = null;
    }
}

public class GenericQueue<T> {
    private Node<T> head;
    private Node<T> tail;
    private int size;

    public GenericQueue() {
        head = null;
        tail = null;
        size = 0;
    }

    // Function to check if the queue is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Function to add an item to the end of the queue
    public void enqueue(T data) {
        size++;
        Node<T> newNode = new Node<>(data);
        if (head == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            tail = newNode;
        }
    }

    // Function to remove and return the item at the front of the queue
    public T dequeue() {
        if (isEmpty()) {
            return null; // Returning null if the queue is empty
        }
        T ans = head.data;
        head = head.next;
        if (head == null) {
            tail = null;
        }
        size--;
        return ans;
    }

    // Function to get the item at the front of the queue without removing it
    public T front() {
        if (isEmpty()) {
            return null; // Returning null if the queue is empty
        }
        return head.data;
    }

    // Function to get the size of the queue
    public int size() {
        return size;
    }

    public static void main(String[] args) {
        GenericQueue<Integer> intQueue = new GenericQueue<>();
        intQueue.enqueue(1);
        intQueue.enqueue(2);
        intQueue.enqueue(3);

        System.out.println("Front: " + intQueue.front()); // Output: 1
        System.out.println("Dequeue: " + intQueue.dequeue()); // Output: 1
        System.out.println("Front: " + intQueue.front()); // Output: 2
        System.out.println("Size: " + intQueue.size()); // Output: 2

        GenericQueue<String> stringQueue = new GenericQueue<>();
        stringQueue.enqueue("A");
        stringQueue.enqueue("B");

        System.out.println("Front: " + stringQueue.front()); // Output: A
        System.out.println("Dequeue: " + stringQueue.dequeue()); // Output: A
        System.out.println("Front: " + stringQueue.front()); // Output: B
        System.out.println("Size: " + stringQueue.size()); // Output: 1
    }
}
