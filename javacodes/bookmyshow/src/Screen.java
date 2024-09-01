import java.util.ArrayList;
import java.util.List;

public class Screen {
    private int screenNumber;
    private int capacity;
    private List<Show> shows;

    public Screen(int screenNumber, int capacity) {
        this.screenNumber = screenNumber;
        this.capacity = capacity;
        this.shows = new ArrayList<>();
    }

    public int getScreenNumber() {
        return screenNumber;
    }

    public int getCapacity() {
        return capacity;
    }

    public List<Show> getShows() {
        return new ArrayList<>(shows);
    }

    public void addShow(Show show) {
        shows.add(show);
    }

    public List<Show> getAvailableShows() {
        return new ArrayList<>(shows);
    }

    public void displayScreenDetails() {
        System.out.println("Screen Number: " + screenNumber);
        System.out.println("Capacity: " + capacity);
        System.out.println("Number of Shows: " + shows.size());
    }
}
