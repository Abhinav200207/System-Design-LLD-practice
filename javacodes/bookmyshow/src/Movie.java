import java.util.ArrayList;
import java.util.List;

public class Movie {
    private String title;
    private String genre;
    private int duration; // in minutes
    private List<String> cast;
    private String director;
    private String language;
    private double rating;
    private int ratingCount;

    public Movie(String title, String genre, int duration, List<String> cast, String director, String language) {
        this.title = title;
        this.genre = genre;
        this.duration = duration;
        this.cast = new ArrayList<>(cast);
        this.director = director;
        this.language = language;
        this.rating = 0.0;
        this.ratingCount = 0;
    }

    public String getTitle() {
        return title;
    }

    public String getGenre() {
        return genre;
    }

    public int getDuration() {
        return duration;
    }

    public List<String> getCast() {
        return new ArrayList<>(cast);
    }

    public String getDirector() {
        return director;
    }

    public String getLanguage() {
        return language;
    }

    public double getRating() {
        return rating;
    }

    public void addRating(double newRating) {
        if (newRating < 0 || newRating > 10) {
            throw new IllegalArgumentException("Rating should be between 0 and 10.");
        }
        rating = (rating * ratingCount + newRating) / (++ratingCount);
    }

    public void displayMovieDetails() {
        System.out.println("Title: " + title);
        System.out.println("Genre: " + genre);
        System.out.println("Duration: " + duration + " minutes");
        System.out.println("Director: " + director);
        System.out.println("Language: " + language);
        System.out.println("Rating: " + rating + " (" + ratingCount + " reviews)");
        System.out.println("Cast: " + String.join(", ", cast));
    }
}
