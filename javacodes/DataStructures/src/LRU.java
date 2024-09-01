import java.util.HashMap;
import java.util.Map;

class LRUCache<K, V> {
    private Node head = new Node(null, null);
    private Node tail = new Node(null, null);
    private Map<K, Node> map = new HashMap<>();
    private int capacity;

    public LRUCache(int _capacity) {
        capacity = _capacity;
        head.next = tail;
        tail.prev = head;
    }

    public V get(K key) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            remove(node);
            insert(node);
            return node.value;
        } else {
            return null; // Return null if key doesn't exist
        }
    }

    public void put(K key, V value) {
        if (map.containsKey(key)) {
            remove(map.get(key));
        }
        if (map.size() == capacity) {
            remove(tail.prev);
        }
        insert(new Node(key, value));
    }

    private void remove(Node node) {
        map.remove(node.key);
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private void insert(Node node) {
        map.put(node.key, node);
        node.next = head.next;
        node.next.prev = node;
        head.next = node;
        node.prev = head;
    }

    private class Node {
        Node prev, next;
        K key;
        V value;

        Node(K _key, V _value) {
            key = _key;
            value = _value;
        }
    }

    public static void main(String[] args) {
        // Testing the LRUCache with Integer keys and String values
        LRUCache<Integer, String> lruCache = new LRUCache<>(2);

        lruCache.put(1, "one");
        lruCache.put(2, "two");

        System.out.println(lruCache.get(1)); // Output: "one"

        lruCache.put(3, "three");

        System.out.println(lruCache.get(2)); // Output: null (2 has been evicted)

        lruCache.put(4, "four");

        System.out.println(lruCache.get(1)); // Output: null (1 has been evicted)
        System.out.println(lruCache.get(3)); // Output: "three"
        System.out.println(lruCache.get(4)); // Output: "four"

        // Testing with String keys and Integer values
        LRUCache<String, Integer> lruCacheStrInt = new LRUCache<>(2);

        lruCacheStrInt.put("one", 1);
        lruCacheStrInt.put("two", 2);

        System.out.println(lruCacheStrInt.get("one")); // Output: 1

        lruCacheStrInt.put("three", 3);

        System.out.println(lruCacheStrInt.get("two")); // Output: null (two has been evicted)

        lruCacheStrInt.put("four", 4);

        System.out.println(lruCacheStrInt.get("one")); // Output: null (one has been evicted)
        System.out.println(lruCacheStrInt.get("three")); // Output: 3
        System.out.println(lruCacheStrInt.get("four")); // Output: 4
    }
}
