import java.util.ArrayList;
import java.util.List;

public class BookingSystem {
    private List<Theatre> theatres;
    private List<Movie> movies;

    public BookingSystem() {
        this.theatres = new ArrayList<>();
        this.movies = new ArrayList<>();
    }

    // Method to add a theatre to the system
    public void addTheatre(Theatre theatre) {
        theatres.add(theatre);
    }

    // Method to add a movie to the system
    public void addMovie(Movie movie) {
        movies.add(movie);
    }

    // Method to search for movies by title
    public List<Movie> searchMovies(String title) {
        List<Movie> result = new ArrayList<>();
        for (Movie movie : movies) {
            if (movie.getTitle().equalsIgnoreCase(title)) {
                result.add(movie);
            }
        }
        return result;
    }

    // Method to search for shows by movie and location
    public List<Show> searchShows(Movie movie, String location) {
        List<Show> result = new ArrayList<>();
        for (Theatre theatre : theatres) {
            if (theatre.getLocation().equalsIgnoreCase(location)) {
                for (Screen screen : theatre.getScreens()) {
                    for (Show show : screen.getAvailableShows()) {
                        if (show.getMovie().equals(movie)) {
                            result.add(show);
                        }
                    }
                }
            }
        }
        return result;
    }

    // Method to book a ticket
    public void bookTicket(User user, Show show, int numberOfSeats) {
        user.bookTicket(show, numberOfSeats);
    }

    // Method to display all theatres
    public void displayAllTheatres() {
        for (Theatre theatre : theatres) {
            theatre.displayTheatreDetails();
            System.out.println("---------------------------");
        }
    }

    // Method to display all movies
    public void displayAllMovies() {
        for (Movie movie : movies) {
            movie.displayMovieDetails();
            System.out.println("---------------------------");
        }
    }
}
