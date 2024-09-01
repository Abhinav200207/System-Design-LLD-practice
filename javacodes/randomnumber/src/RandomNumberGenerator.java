import java.util.Random;

public class RandomNumberGenerator {
    private Random random;

    // Constructor with optional seed for reproducibility
    public RandomNumberGenerator(Long seed) {
        if (seed != null) {
            random = new Random(seed);
        } else {
            random = new Random();
        }
    }

    // Default constructor without seed
    public RandomNumberGenerator() {
        this(null);
    }

    // Generate a random integer between minValue (inclusive) and maxValue (inclusive)
    public int generate(int minValue, int maxValue) {
        return random.nextInt((maxValue - minValue) + 1) + minValue;
    }

    // Generate a random floating-point number between minValue (inclusive) and maxValue (exclusive)
    public double generateFloat(double minValue, double maxValue) {
        return minValue + (maxValue - minValue) * random.nextDouble();
    }

    // Generate a sequence of random integers
    public int[] generateSequence(int length, int minValue, int maxValue) {
        int[] sequence = new int[length];
        for (int i = 0; i < length; i++) {
            sequence[i] = generate(minValue, maxValue);
        }
        return sequence;
    }
}
