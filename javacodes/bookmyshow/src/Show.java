public class Show {
    private Movie movie;
    private String showTime; // Format: "HH:MM"
    private int availableSeats;
    private int totalSeats;

    public Show(Movie movie, String showTime, int totalSeats) {
        this.movie = movie;
        this.showTime = showTime;
        this.totalSeats = totalSeats;
        this.availableSeats = totalSeats;
    }

    public Movie getMovie() {
        return movie;
    }

    public String getShowTime() {
        return showTime;
    }

    public int getTotalSeats(){
        return totalSeats;
    }

    public int getAvailableSeats() {
        return availableSeats;
    }

    public void bookTicket(int numberOfSeats) {
        if (numberOfSeats <= 0 || numberOfSeats > availableSeats) {
            throw new IllegalArgumentException("Invalid number of seats.");
        }
        availableSeats -= numberOfSeats;
        System.out.println(numberOfSeats + " seats booked successfully for " + movie.getTitle() + " at " + showTime);
    }

    public void displayShowDetails() {
        System.out.println("Movie: " + movie.getTitle());
        System.out.println("Show Time: " + showTime);
        System.out.println("Available Seats: " + availableSeats);
    }
}
