public class Jumper {
    private int start;
    private int end;
    private int isSnake; // 1 for snake, 0 for ladder
    private int[] absStart, absEnd;

    public Jumper(int start, int end, int isSnake, int[] absStart, int[] absEnd) {
        this.start = start;
        this.end = end;
        this.isSnake = isSnake;
        this.absStart = absStart;
        this.absEnd = absEnd;
    }

    public int[] getAbsStart() {
        return absStart;
    }

    public int[] getAbsEnd() {
        return absEnd;
    }

    public int getEnd() {
        return end;
    }

    public int getStart() {
        return start;
    }

    public int getIsSnake() {
        return isSnake;
    }
}
