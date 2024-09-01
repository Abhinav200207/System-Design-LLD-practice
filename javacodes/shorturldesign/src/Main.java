import java.util.concurrent.atomic.AtomicInteger;
import java.util.HashMap;
import java.util.Map;

class TinyUrlService {
    private final Map<String, String> urlMap = new HashMap<>();
    private final Map<String, String> reverseUrlMap = new HashMap<>();
    private final String baseUrl = "http://tinyurl.com/";
    private final AtomicInteger counter = new AtomicInteger(1000);

    public String createShortUrl(String longUrl) {
        // Check if the long URL already has a short URL
        if (reverseUrlMap.containsKey(longUrl)) {
            return baseUrl + reverseUrlMap.get(longUrl);
        }

        // Generate a unique ID and encode it
        int id = counter.getAndIncrement();
        String shortUrl = encode(id);
        urlMap.put(shortUrl, longUrl);
        reverseUrlMap.put(longUrl, shortUrl);
        return baseUrl + shortUrl;
    }

    public String getLongUrl(String shortUrl) {
        // Strip base URL
        String key = shortUrl.replace(baseUrl, "");
        return urlMap.getOrDefault(key, "URL not found");
    }

    private String encode(int id) {
        StringBuilder shortUrl = new StringBuilder();
        String chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        while (id > 0) {
            shortUrl.append(chars.charAt(id % 62));
            id /= 62;
        }
        System.out.println(shortUrl);
        return shortUrl.reverse().toString();
    }

    public int decode(String shortUrl) {
        int id = 0;
        String chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        for (int i = 0; i < shortUrl.length(); i++) {
            id = id * 62 + chars.indexOf(shortUrl.charAt(i));
        }
        return id;
    }
}

public class Main {
    private static final TinyUrlService tinyUrlService = new TinyUrlService();

    public static String shortenUrl(String longUrl) {
        return tinyUrlService.createShortUrl(longUrl);
    }

    public static String redirectToLongUrl(String shortUrl) {
        return tinyUrlService.getLongUrl(shortUrl);
    }

    public static void main(String[] args) {
//        TinyUrlController controller = new TinyUrlController();

        // Test cases
        String shortUrl = shortenUrl("https://chatgpt.com/c/2680ae55-cd12-4c0b-8066-3d12a2118497");
        System.out.println("Short URL: " + shortUrl);

        String longUrl = redirectToLongUrl(shortUrl);
        System.out.println("Long URL: " + longUrl);
    }
}
