class TrieNode {
    TrieNode[] children;
    boolean isEndOfWord;

    // Constructor
    public TrieNode() {
        children = new TrieNode[26];  // Assuming only lowercase a-z
        isEndOfWord = false;
    }
}

public class Trie {
    private TrieNode root;

    // Constructor
    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie
    public void insert(String word) {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            int index = ch - 'a';
            if (current.children[index] == null) {
                current.children[index] = new TrieNode();
            }
            current = current.children[index];
        }
        current.isEndOfWord = true;
    }

    // Returns true if the word is in the trie
    public boolean search(String word) {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            int index = ch - 'a';
            if (current.children[index] == null) {
                return false;
            }
            current = current.children[index];
        }
        return current.isEndOfWord;
    }

    // Returns true if there is any word in the trie that starts with the given prefix
    public boolean startsWith(String prefix) {
        TrieNode current = root;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix.charAt(i);
            int index = ch - 'a';
            if (current.children[index] == null) {
                return false;
            }
            current = current.children[index];
        }
        return true;
    }

    // Helper function to delete a word from the Trie
    private boolean deleteHelper(TrieNode current, String word, int depth) {
        if (current == null) {
            return false;
        }

        // Base case: If the last character of the word is being processed
        if (depth == word.length()) {
            // This node is no longer the end of the word
            if (current.isEndOfWord) {
                current.isEndOfWord = false;
            }

            // If this node has no children, it can be deleted
            return current.children == null;
        }

        // Recursively delete the word
        int index = word.charAt(depth) - 'a';
        boolean shouldDeleteCurrentNode = deleteHelper(current.children[index], word, depth + 1);

        // If the child node can be deleted, then delete it
        if (shouldDeleteCurrentNode) {
            current.children[index] = null;

            // If the current node has no other children and is not the end of another word, it can also be deleted
            return !current.isEndOfWord && isEmpty(current);
        }

        return false;
    }

    // Deletes a word from the trie
    public void delete(String word) {
        deleteHelper(root, word, 0);
    }

    // Check if the node is empty (i.e., has no children)
    private boolean isEmpty(TrieNode node) {
        for (int i = 0; i < 26; i++) {
            if (node.children[i] != null) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Trie trie = new Trie();

        // Insert words
        trie.insert("apple");
        trie.insert("app");
        trie.insert("bat");

        // Search for words
        System.out.println(trie.search("apple"));  // true
        System.out.println(trie.search("app"));    // true
        System.out.println(trie.search("bat"));    // true
        System.out.println(trie.search("batman")); // false

        // Check if prefix exists
        System.out.println(trie.startsWith("app")); // true
        System.out.println(trie.startsWith("bat")); // true
        System.out.println(trie.startsWith("cat")); // false

        // Delete a word
        trie.delete("bat");
        System.out.println(trie.search("bat"));    // false
        System.out.println(trie.search("batman")); // false
    }
}
