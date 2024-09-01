public class Ticket {
    private User user;
    private Show show;
    private int seatNumber;
    private double price;

    public Ticket(User user, Show show, int seatNumber, double price) {
        this.user = user;
        this.show = show;
        this.seatNumber = seatNumber;
        this.price = price;
    }

    // Getter methods
    public User getUser() {
        return user;
    }

    public Show getShow() {
        return show;
    }

    public int getSeatNumber() {
        return seatNumber;
    }

    public double getPrice() {
        return price;
    }

    /**
     * Displays the details of the ticket.
     */
    public void displayTicketDetails() {
        System.out.println("Ticket Details:");
        System.out.println("User: " + user.getName());
        System.out.println("Movie: " + show.getMovie().getTitle());
        System.out.println("Show Time: " + show.getShowTime());
        System.out.println("Seat Number: " + seatNumber);
        System.out.println("Price: $" + price);
    }
}
