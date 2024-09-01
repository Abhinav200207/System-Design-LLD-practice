import java.util.Stack;

public class MinStack<T extends Number & Comparable<T>> {
    private Stack<Long> stack;
    private long min;

    public MinStack() {
        stack = new Stack<>();
        min = Long.MAX_VALUE;
    }

    public void push(T val) {
        long value = val.longValue();

        if (stack.isEmpty()) {
            stack.push(value);
            min = value;
        } else {
            if (value < min) {
                stack.push(2 * value - min);
                min = value;
            } else {
                stack.push(value);
            }
        }
    }

    public void pop() {
        if (stack.isEmpty()) {
            return;
        }

        long top = stack.pop();
        if (top < min) {
            min = 2 * min - top;
        }
    }

    public T top() {
        if (stack.isEmpty()) {
            return null;
        }

        long top = stack.peek();
        if (top < min) {
            return (T) Long.valueOf(min);
        } else {
            return (T) Long.valueOf(top);
        }
    }

    public T getMin() {
        return (T) Long.valueOf(min);
    }

    public static void main(String[] args) {
        MinStack<Integer> minStack = new MinStack<>();
        minStack.push(5);
        minStack.push(3);
        minStack.push(7);

        System.out.println("Minimum: " + minStack.getMin()); // Output: 3
        System.out.println("Top: " + minStack.top());         // Output: 7

        minStack.pop();
        System.out.println("Minimum: " + minStack.getMin()); // Output: 3
        System.out.println("Top: " + minStack.top());         // Output: 3

        minStack.pop();
        System.out.println("Minimum: " + minStack.getMin()); // Output: 5
        System.out.println("Top: " + minStack.top());         // Output: 5
    }
}
