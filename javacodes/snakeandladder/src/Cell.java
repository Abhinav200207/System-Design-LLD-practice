import java.util.*;

public class Cell {
    private int[] absPos;
    private int pos;
    private Set<Piece> pieces;
    private Jumper jumper;
    private boolean isAnythingPresent; // true if present, false if not present for snake and ladder

    public Cell(int[] absPos, int pos) {
        this.absPos = absPos;
        this.pos = pos;
        this.isAnythingPresent = false;
        this.pieces = new HashSet<>();
    }

    public int[] getAbsPos() {
        return absPos;
    }

    public int getPos() {
        return pos;
    }

    public void setJumper(Jumper jumper) {
        this.jumper = jumper;
    }

    public Jumper getJumper() {
        return this.jumper;
    }

    public boolean getIsAnythingPresent() {
        return this.isAnythingPresent;
    }

    public void setIsAnythingPresent(boolean isAnything) {
        this.isAnythingPresent = isAnything;
    }

    public void addPiece(Piece piece) {
        pieces.add(piece);
    }

    public void removePiece(Piece piece) {
        pieces.remove(piece);
    }
}
