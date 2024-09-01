public class MyString {
    private char[] chars;
    private int length;

    public MyString(String str) {
        length = str.length();
        chars = new char[length];
        for (int i = 0; i < length; i++) {
            chars[i] = str.charAt(i);
        }
    }

    // Returns the length of the string
    public int length() {
        return length;
    }

    // Returns the character at the specified index
    public char charAt(int index) {
        if (index < 0 || index >= length) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        return chars[index];
    }

    // Returns a new MyString that is a substring of this MyString
    public MyString substring(int start, int end) {
        if (start < 0 || end > length || start > end) {
            throw new IndexOutOfBoundsException("Invalid substring range");
        }
        return new MyString(new String(chars, start, end - start));
    }

    // Returns a string representation of this MyString
    @Override
    public String toString() {
        return new String(chars);
    }

    // Compares this MyString to another MyString
    public boolean equals(MyString other) {
        if (this.length != other.length) {
            return false;
        }
        for (int i = 0; i < length; i++) {
            if (this.chars[i] != other.chars[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        MyString myStr = new MyString("Hello");
        System.out.println("Length: " + myStr.length()); // Output: 5
        System.out.println("Character at index 1: " + myStr.charAt(1)); // Output: e
        System.out.println("Substring (1, 4): " + myStr.substring(1, 4)); // Output: ell
        System.out.println("String: " + myStr.toString()); // Output: Hello

        MyString anotherStr = new MyString("Hello");
        System.out.println("Are the strings equal? " + myStr.equals(anotherStr)); // Output: true

        MyString differentStr = new MyString("World");
        System.out.println("Are the strings equal? " + myStr.equals(differentStr)); // Output: false
    }
}
