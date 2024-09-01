import java.util.List;

//Class Relationships:
//Theatre has multiple Screens.
//Screen has multiple Shows.
//Show is associated with a Movie.
//User books Tickets for a Show.
//BookingSystem manages Theatres, Movies, and facilitates ticket booking.

public class Main {
    public static void main(String[] args) {
        // Create a booking system instance
        BookingSystem bookingSystem = new BookingSystem();

        // Create some movies
        Movie movie1 = new Movie("Inception", "Sci-Fi", 180, List.of("Leonardo DiCaprio"), "Christopher Nolan", "English");
        Movie movie2 = new Movie("The Dark Knight", "Action", 120, List.of("Christian Bale"), "Christopher Nolan", "English");

        // Add movies to the booking system
        bookingSystem.addMovie(movie1);
        bookingSystem.addMovie(movie2);

        // Create some theatres
        Theatre theatre1 = new Theatre("PVR Cinemas", "Mumbai");
        Theatre theatre2 = new Theatre("INOX", "Delhi");

        // Add theatres to the booking system
        bookingSystem.addTheatre(theatre1);
        bookingSystem.addTheatre(theatre2);

        // Create screens for theatres
        Screen screen1 = new Screen(1, 200);
        Screen screen2 = new Screen(2, 150);

        // Add screens to theatres
        theatre1.addScreen(screen1);
        theatre2.addScreen(screen2);

        // Create shows for screens
        Show show1 = new Show(movie1, "18:00", 200);
        Show show2 = new Show(movie2, "21:00", 150);

        // Add shows to screens
        screen1.addShow(show1);
        screen2.addShow(show2);

        // Display all movies
        System.out.println("Available Movies:");
        bookingSystem.displayAllMovies();
        System.out.println("---------------------------");

        // Display all theatres
        System.out.println("Available Theatres:");
        bookingSystem.displayAllTheatres();
        System.out.println("---------------------------");

        // Create a user
        User user = new User("John Doe", "john@example.com", "1234567890");

        // Search for shows in Mumbai for "Inception"
        System.out.println("Searching for shows of 'Inception' in Mumbai:");
        List<Show> availableShows = bookingSystem.searchShows(movie1, "Mumbai");
        for (Show show : availableShows) {
            show.displayShowDetails();
        }
        System.out.println("---------------------------");

        // Book a ticket for the first available show
        if (!availableShows.isEmpty()) {
            Show selectedShow = availableShows.getFirst();
            bookingSystem.bookTicket(user, selectedShow, 2);  // Book 2 seats
        }

        // View user's booked tickets
        System.out.println("User's Booked Tickets:");
        user.viewBookedTickets();
    }
}
