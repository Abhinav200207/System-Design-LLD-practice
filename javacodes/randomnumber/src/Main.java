public class Main {
    public static void main(String[] args) {
        // Example 1: Generate random numbers with a specific seed for reproducibility
        RandomNumberGenerator rngWithSeed = new RandomNumberGenerator(41L);
        System.out.println("Example 1 - With Seed:");
        System.out.println("Random Integer: " + rngWithSeed.generate(0, 100));
        System.out.println("Random Float: " + rngWithSeed.generateFloat(0.0, 1.0));

        int[] sequenceWithSeed = rngWithSeed.generateSequence(5, 0, 100);
        System.out.print("Random Sequence: ");
        for (int num : sequenceWithSeed) {
            System.out.print(num + " ");
        }
        System.out.println("\n");

        // Example 2: Generate random numbers without specifying a seed
        RandomNumberGenerator rngWithoutSeed = new RandomNumberGenerator();
        System.out.println("Example 2 - Without Seed:");
        System.out.println("Random Integer: " + rngWithoutSeed.generate(0, 100));
        System.out.println("Random Float: " + rngWithoutSeed.generateFloat(0.0, 1.0));

        int[] sequenceWithoutSeed = rngWithoutSeed.generateSequence(5, 0, 100);
        System.out.print("Random Sequence: ");
        for (int num : sequenceWithoutSeed) {
            System.out.print(num + " ");
        }
        System.out.println("\n");

        // Example 3: Generate a random integer within a specific range
        System.out.println("Example 3 - Random Integer within Range (10 to 50):");
        int randomIntInRange = rngWithoutSeed.generate(10, 50);
        System.out.println("Random Integer: " + randomIntInRange);

        // Example 4: Generate a random floating-point number within a specific range
        System.out.println("Example 4 - Random Float within Range (2.5 to 7.5):");
        double randomFloatInRange = rngWithoutSeed.generateFloat(2.5, 7.5);
        System.out.println("Random Float: " + randomFloatInRange);
    }

}