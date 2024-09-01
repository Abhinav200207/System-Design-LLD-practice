public class Piece {
    private int[] absPos;
    private int pos;

    public Piece(int[] absPos, int pos) {
        this.absPos = absPos;
        this.pos = pos;
    }

    public int[] getAbsPos() {
        return absPos;
    }

    public int getPos() {
        return pos;
    }

    public void setPos(int pos) {
        this.pos = pos;
    }
}
