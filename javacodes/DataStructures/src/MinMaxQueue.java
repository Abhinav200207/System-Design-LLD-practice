import java.util.*;

public class MinMaxQueue<T> {
    private Queue<T> queue;
    private Deque<T> deque;
    private Comparator<? super T> comparator;

    // Constructor to initialize with a custom comparator
    public MinMaxQueue(Comparator<? super T> comparator) {
        this.queue = new LinkedList<>();
        this.deque = new LinkedList<>();
        this.comparator = comparator;
    }

    // Default constructor for natural ordering (min queue)
    public MinMaxQueue() {
        this((a, b) -> ((Comparable<? super T>) a).compareTo(b));
    }

    public void enqueue(T element) {
        queue.offer(element);

        // Remove elements from deque that are not needed
        while (!deque.isEmpty() && comparator.compare(element, deque.peekLast()) < 0) {
            deque.pollLast();
        }
        deque.offerLast(element);
    }

    public void dequeue() {
        if (queue.isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }

        T element = queue.poll();
        if (element.equals(deque.peekFirst())) {
            deque.pollFirst();
        }
    }

    public T getMinMax() {
        if (deque.isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        return deque.peekFirst();
    }

    public boolean isEmpty() {
        return queue.isEmpty();
    }

    public static void main(String[] args) {
        // Min queue (default)
        MinMaxQueue<Integer> minQueue = new MinMaxQueue<>();
        int[] example = {1,3,4,4,4, 2, 4};

        for (int i : example) {
            minQueue.enqueue(i);
        }
        System.out.println(minQueue.getMinMax()); // Output: 1
        minQueue.dequeue();
        System.out.println(minQueue.getMinMax()); // Output: 2

        // Max queue using custom comparator
        MinMaxQueue<String> maxQueue = new MinMaxQueue<>(Comparator.reverseOrder());
        maxQueue.enqueue("c");
        maxQueue.enqueue("b");
        maxQueue.enqueue("a");
        System.out.println(maxQueue.getMinMax()); // Output: c
        maxQueue.dequeue();
        System.out.println(maxQueue.getMinMax()); // Output: b
    }
}
