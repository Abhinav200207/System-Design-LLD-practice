import java.util.ArrayList;
import java.util.List;

public class Theatre {
    private String name;
    private String location;
    private List<Screen> screens;

    public Theatre(String name, String location) {
        this.name = name;
        this.location = location;
        this.screens = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public String getLocation() {
        return location;
    }

    public List<Screen> getScreens() {
        return new ArrayList<>(screens);
    }

    public void addScreen(Screen screen) {
        screens.add(screen);
    }

    public List<Screen> getAvailableScreens() {
        return new ArrayList<>(screens);
    }

    public void displayTheatreDetails() {
        System.out.println("Theatre Name: " + name);
        System.out.println("Location: " + location);
        System.out.println("Number of Screens: " + screens.size());
    }
}
