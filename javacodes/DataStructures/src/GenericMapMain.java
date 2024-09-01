import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class GenericMapMain<K, V> {
    private int size;
    private List<LinkedList<Map.Entry<K, V>>> map;

    public GenericMapMain(int size) {
        this.size = size;
        map = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            map.add(new LinkedList<>());
        }
    }

    private int hashKey(K key) {
        return key.hashCode() % size;
    }

    private LinkedList<Map.Entry<K, V>> getBucket(K key) {
        int index = hashKey(key);
        return map.get(index);
    }

    public void put(K key, V value) {
        LinkedList<Map.Entry<K, V>> bucket = getBucket(key);
        remove(key);
        bucket.add(new HashMap.SimpleEntry<>(key, value));
    }

    public V get(K key) {
        LinkedList<Map.Entry<K, V>> bucket = getBucket(key);
        for (Map.Entry<K, V> entry : bucket) {
            if (entry.getKey().equals(key)) {
                return entry.getValue();
            }
        }
        return null; // Or throw exception if preferred
    }

    public void remove(K key) {
        LinkedList<Map.Entry<K, V>> bucket = getBucket(key);
        bucket.removeIf(entry -> entry.getKey().equals(key));
    }

    public static void main(String[] args) {
        GenericMapMain<String, Integer> mp = new GenericMapMain<>(100);
        mp.put("A", 1);
        mp.put("B", 2);
        mp.put("C", 3);
        System.out.println(mp.get("A"));
        System.out.println(mp.get("C"));
        System.out.println(mp.get("B"));

        GenericMapMain<Integer, Integer> mp1 = new GenericMapMain<>(100);
        mp1.put(1, 1);
        mp1.put(2, 2);
        mp1.put(3, 3);
        System.out.println(mp1.get(1));
        System.out.println(mp1.get(2));
        System.out.println(mp1.get(3));
        mp1.put(3, 4);
        System.out.println(mp1.get(3));
        System.out.println(mp1.get(4));
    }
}
