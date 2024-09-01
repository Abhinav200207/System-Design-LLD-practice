import java.util.*;

public class Game {
    private List<Player> players;
    private int turn = 0;
    private int totPlayer;
    private Board board;
    private Dice dice;
    private String winner = "";

    public Game(List<String> names, int totPlayer) {
        board = new Board(5, 5);
        dice = new Dice();

        this.totPlayer = totPlayer;
        players = new ArrayList<>();

        for (String name : names) {
            Player p = new Player(name);
            Piece piece = new Piece(new int[]{0, 0}, 0);
            p.setPiece(piece);
            board.getCell(0).addPiece(piece);
            players.add(p);
        }
    }

    public void startGame() {
        while (winner.equals("")) {
            Player p = players.get(turn);

            System.out.println("Your turn player: " + p.getName());

            int diceNum = dice.getDiceNum();

            System.out.println("Dice number is: " + diceNum);

            int nextCell = p.getPiece().getPos() + diceNum;

            if (nextCell >= 100) {
                System.out.println("Turn Wasted, try to get lower");
                turn = (turn + 1) % totPlayer;
                continue;
            }

            if (nextCell == 99) {
                System.out.println("You won player: " + p.getName());
                winner = p.getName();
                break;
            }

            Cell prevCell = board.getCell(p.getPiece().getPos());
            Cell nxtCell = board.getCell(nextCell);

            if (!nxtCell.getIsAnythingPresent()) {
                prevCell.removePiece(p.getPiece());

                nxtCell.addPiece(p.getPiece());
                p.getPiece().setPos(nextCell);

                turn = (turn + 1) % totPlayer;
                continue;
            }

            Jumper jumper = nxtCell.getJumper();

            if (jumper.getIsSnake() == 1) {
                System.out.println("Bitten by snake moved to " + jumper.getEnd());
            } else {
                System.out.println("Got the ladder to " + jumper.getEnd());
            }

            Cell nxtNxtCell = board.getCell(jumper.getEnd());
            prevCell.removePiece(p.getPiece());

            nxtNxtCell.addPiece(p.getPiece());

            turn = (turn + 1) % totPlayer;
        }
    }
}
