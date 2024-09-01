import java.util.ArrayList;
import java.util.Comparator;

public class PriorityQueueAb<T> {
    private ArrayList<T> heap;
    private Comparator<? super T> comp;

    public PriorityQueueAb() {
        heap = new ArrayList<>();
        comp = (a, b) -> ((Comparable<? super T>) a).compareTo(b);
    }

    public PriorityQueueAb(Comparator<? super T> comp) {
        heap = new ArrayList<>();
        this.comp = comp;
    }

    private int parent(int index) {
        return (index - 1) / 2;
    }

    private int left(int index) {
        return (2 * index + 1);
    }

    private int right(int index) {
        return (2 * index + 2);
    }

    private void heapifyUp(int index) {
        int parentIndex = parent(index);
        if (index > 0 && comp.compare(heap.get(parentIndex), heap.get(index)) > 0) {
            swap(index, parentIndex);
            heapifyUp(parentIndex);
        }
    }

    private void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int highestPriority = index;

        if (leftChild < heap.size() && comp.compare(heap.get(highestPriority), heap.get(leftChild)) > 0) {
            highestPriority = leftChild;
        }

        if (rightChild < heap.size() && comp.compare(heap.get(highestPriority), heap.get(rightChild)) > 0) {
            highestPriority = rightChild;
        }

        if (highestPriority != index) {
            swap(index, highestPriority);
            heapifyDown(highestPriority);
        }
    }

    private void swap(int i, int j) {
        T temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }

    public boolean isEmpty() {
        return heap.isEmpty();
    }

    public int size() {
        return heap.size();
    }

    public void push(T value) {
        heap.add(value);
        heapifyUp(heap.size() - 1);
    }

    public void pop() {
        if (isEmpty()) {
            throw new IllegalStateException("PriorityQueue is empty.");
        }
        if (heap.size() == 1) {
            heap.remove(0);
        } else {
            heap.set(0, heap.remove(heap.size() - 1));
            heapifyDown(0);
        }
    }

    public T top() {
        if (isEmpty()) {
            throw new IllegalStateException("PriorityQueue is empty.");
        }
        return heap.get(0);
    }

    public static void main(String[] args) {
        PriorityQueueAb<Integer> pq = new PriorityQueueAb<>(Comparator.reverseOrder()); // Max heap
        pq.push(10);
        pq.push(30);
        pq.push(20);
        pq.push(5);
        System.out.println(pq.size());
        while (!pq.isEmpty()) {
            System.out.println(pq.top());
            pq.pop();
        }
    }
}
