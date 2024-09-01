import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");

        Game game = new Game(List.of(new String[]{"Abhinav", "Bobby"}),2);
        game.startGame();
    }
}