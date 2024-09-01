import java.util.*;

public class Dice {

    public Dice() {}

    public int getDiceNum() {
        List<Integer> randomList = new ArrayList<>();
        for (int i = 1; i <= 6; i++) {
            randomList.add(i);
        }
        Collections.shuffle(randomList);
        return randomList.get(0);
    }
}
