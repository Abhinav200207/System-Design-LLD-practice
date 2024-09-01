import java.util.Stack;

public class MaxStack<T extends Number & Comparable<T>> {
    private Stack<Long> stack;
    private long max;

    public MaxStack() {
        stack = new Stack<>();
        max = Long.MIN_VALUE;
    }

    public void push(T val) {
        long value = val.longValue();

        if (stack.isEmpty()) {
            stack.push(value);
            max = value;
        } else {
            if (value > max) {
                stack.push(2 * value - max);
                max = value;
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
        if (top > max) {
            max = 2 * max - top;
        }
    }

    public T top() {
        if (stack.isEmpty()) {
            return null;
        }

        long top = stack.peek();
        if (top > max) {
            return (T) Long.valueOf(max);
        } else {
            return (T) Long.valueOf(top);
        }
    }

    public T getMax() {
        return (T) Long.valueOf(max);
    }

    public static void main(String[] args) {
        MaxStack<Integer> maxStack = new MaxStack<>();
        maxStack.push(5);
        maxStack.push(3);
        maxStack.push(7);

        System.out.println("Maximum: " + maxStack.getMax()); // Output: 7
        System.out.println("Top: " + maxStack.top());        // Output: 7

        maxStack.pop();
        System.out.println("Maximum: " + maxStack.getMax()); // Output: 5
        System.out.println("Top: " + maxStack.top());        // Output: 3

        maxStack.pop();
        System.out.println("Maximum: " + maxStack.getMax()); // Output: 5
        System.out.println("Top: " + maxStack.top());        // Output: 5
    }
}
