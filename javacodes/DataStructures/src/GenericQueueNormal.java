public class GenericQueueNormal<T> {
    private Object[] queue;
    private int front;
    private int rear;
    private int size;
    private int capacity;

    public GenericQueueNormal(int capacity) {
        this.capacity = capacity;
        queue = new Object[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Add an item to the queue
    public void enqueue(T item) {
        if (isFull()) {
            throw new IllegalStateException("Queue is full");
        }
        rear = (rear + 1) % capacity;
        queue[rear] = item;
        size++;
    }

    // Remove and return the item from the front of the queue
    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        T item = (T) queue[front];
        queue[front] = null; // Clear the reference
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    // Peek at the front item of the queue without removing it
    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        return (T) queue[front];
    }

    // Check if the queue is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    public boolean isFull() {
        return size == capacity;
    }

    public static void main(String[] args) {
        GenericQueueNormal<Integer> intQueue = new GenericQueueNormal<>(5);
        intQueue.enqueue(1);
        intQueue.enqueue(2);
        intQueue.enqueue(3);

        System.out.println("Peek: " + intQueue.peek()); // Output: 1
        System.out.println("Dequeue: " + intQueue.dequeue()); // Output: 1
        System.out.println("Peek: " + intQueue.peek()); // Output: 2
        System.out.println("Is Empty: " + intQueue.isEmpty()); // Output: false
        System.out.println("Is Full: " + intQueue.isFull()); // Output: false

        GenericQueueNormal<String> stringQueue = new GenericQueueNormal<>(5);
        stringQueue.enqueue("A");
        stringQueue.enqueue("B");

        System.out.println("Peek: " + stringQueue.peek()); // Output: A
        System.out.println("Dequeue: " + stringQueue.dequeue()); // Output: A
        System.out.println("Peek: " + stringQueue.peek()); // Output: B
        System.out.println("Is Empty: " + stringQueue.isEmpty()); // Output: false
        System.out.println("Is Full: " + stringQueue.isFull()); // Output: false
    }
}
