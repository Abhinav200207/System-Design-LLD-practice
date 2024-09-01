import java.util.ArrayList;
import java.util.List;

public class User {
    private String name;
    private String email;
    private String phoneNumber;
    private List<Ticket> bookedTickets;

    public User(String name, String email, String phoneNumber) {
        this.name = name;
        this.email = email;
        this.phoneNumber = phoneNumber;
        this.bookedTickets = new ArrayList<>();
    }

    // Getter methods
    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public String getPhoneNumber(){
        return phoneNumber;
    }

    public List<Ticket> getBookedTickets() {
        return new ArrayList<>(bookedTickets);
    }

    public void bookTicket(Show show, int numberOfSeats) {
        try {
            // Attempt to book tickets in the show
            show.bookTicket(numberOfSeats);

            // Assuming each seat has a unique seat number, we can generate them.
            // For simplicity, we'll assign sequential seat numbers starting from 1.
            for(int i = 1; i <= numberOfSeats; i++) {
                int seatNumber = show.getTotalSeats() - show.getAvailableSeats() + i;
//                System.out.println(i+","+seatNumber+","+show.getTotalSeats()+","+show.getAvailableSeats());
                double price = 100.0; // Example fixed price, can be dynamic
                Ticket ticket = new Ticket(this, show, seatNumber, price);
                bookedTickets.add(ticket);
            }
            System.out.println("Successfully booked " + numberOfSeats + " tickets for " + show.getMovie().getTitle() + " at " + show.getShowTime());
        } catch (IllegalArgumentException e) {
            System.out.println("Booking failed: " + e.getMessage());
        }
    }

    /**
     * Displays all tickets booked by the user.
     */
    public void viewBookedTickets() {
        if(bookedTickets.isEmpty()) {
            System.out.println("No tickets booked.");
            return;
        }
        System.out.println("Booked Tickets for " + name + ":");
        for(Ticket ticket : bookedTickets) {
            ticket.displayTicketDetails();
            System.out.println("---------------------------");
        }
    }

    /**
     * Displays user details.
     */
    public void displayUserDetails() {
        System.out.println("User Details:");
        System.out.println("Name: " + name);
        System.out.println("Email: " + email);
        System.out.println("Phone Number: " + phoneNumber);
    }
}
