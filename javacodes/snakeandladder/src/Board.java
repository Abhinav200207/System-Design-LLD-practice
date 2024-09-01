import java.util.*;

public class Board {
    private List<Jumper> jumpers;
    private List<List<Cell>> cells;

    public Board(int numSnakes, int numLadders) {
        cells = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            List<Cell> temp = new ArrayList<>();
            for (int j = 0; j < 10; j++) {
                temp.add(new Cell(new int[]{i, j}, calcPos(i, j)));
            }
            cells.add(temp);
        }

        for (int i = 0; i < numSnakes; i++) {
            int head = generateRandom(0, 99);
            int tail = generateRandom(0, head);
            int[] abshead = calcAbsPos(head);
            Jumper jumper = new Jumper(head, tail, 1, abshead, calcAbsPos(tail));
            cells.get(abshead[0]).get(abshead[1]).setJumper(jumper);
            cells.get(abshead[0]).get(abshead[1]).setIsAnythingPresent(true);
        }

        for (int i = 0; i < numLadders; i++) {
            int head = generateRandom(0, 99);
            int tail = generateRandom(0, head);
            int[] abstail = calcAbsPos(tail);
            Jumper jumper = new Jumper(tail, head, 0, abstail, calcAbsPos(head));
            cells.get(abstail[0]).get(abstail[1]).setJumper(jumper);
            cells.get(abstail[0]).get(abstail[1]).setIsAnythingPresent(true);
        }
    }

    public int calcPos(int i, int j) {
        if (i % 2 == 0) {
            return i * 10 + j;
        }
        return i * 10 + (10 - j - 1);
    }

    public int[] calcAbsPos(int x) {
        if ((x / 10) % 2 == 0) {
            return new int[]{x / 10, x % 10};
        }
        return new int[]{x / 10, 10 - (x % 10) - 1};
    }

    public Cell getCell(int x) {
        int[] p = calcAbsPos(x);
        return cells.get(p[0]).get(p[1]);
    }

    public int generateRandom(int upperBound, int lowerBound) {
        List<Integer> randomList = new ArrayList<>();
        for (int i = upperBound; i <= lowerBound; i++) {
            randomList.add(i);
        }
        Collections.shuffle(randomList);
        return randomList.get(0);
    }
}
