import java.util.*;

class Twitter {
    private Map<Integer, Set<Integer>> friends;
    private Map<Integer, List<int[]>> tweets;
    private int time;

    public Twitter() {
        friends = new HashMap<>();
        tweets = new HashMap<>();
        time = 0;
    }

    public void postTweet(int userId, int tweetId) {
        tweets.putIfAbsent(userId, new ArrayList<>());
        tweets.get(userId).add(new int[]{++time, tweetId});
    }

    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        List<Integer> ans = new ArrayList<>();

        // Add user's own tweets to the priority queue
        if (tweets.containsKey(userId)) {
            List<int[]> userTweets = tweets.get(userId);
            if (!userTweets.isEmpty()) {
                int[] lastTweet = userTweets.get(userTweets.size() - 1);
                pq.offer(new int[]{lastTweet[0], userId, userTweets.size() - 1, lastTweet[1]});
            }
        }

        // Add tweets of the users that this user follows
        if (friends.containsKey(userId)) {
            for (int followeeId : friends.get(userId)) {
                if (tweets.containsKey(followeeId)) {
                    List<int[]> followeeTweets = tweets.get(followeeId);
                    if (!followeeTweets.isEmpty()) {
                        int[] lastTweet = followeeTweets.get(followeeTweets.size() - 1);
                        pq.offer(new int[]{lastTweet[0], followeeId, followeeTweets.size() - 1, lastTweet[1]});
                    }
                }
            }
        }

        int k = 10;
        while (k > 0 && !pq.isEmpty()) {
            int[] top = pq.poll();
            ans.add(top[3]);
            if (top[2] > 0) {
                int[] nextTweet = tweets.get(top[1]).get(top[2] - 1);
                pq.offer(new int[]{nextTweet[0], top[1], top[2] - 1, nextTweet[1]});
            }
            k--;
        }

        return ans;
    }

    public void follow(int followerId, int followeeId) {
        friends.putIfAbsent(followerId, new HashSet<>());
        friends.get(followerId).add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        if (friends.containsKey(followerId)) {
            friends.get(followerId).remove(followeeId);
        }
    }

    public static void main(String[] args) {
        Twitter twitter = new Twitter();

        twitter.postTweet(1, 5);
        System.out.println(twitter.getNewsFeed(1)); // Output: [5]

        twitter.follow(1, 2);
        twitter.postTweet(2, 6);
        System.out.println(twitter.getNewsFeed(1)); // Output: [6, 5]

        twitter.unfollow(1, 2);
        System.out.println(twitter.getNewsFeed(1)); // Output: [5]
    }
}
