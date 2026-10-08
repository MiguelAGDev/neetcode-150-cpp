/*
Design Twitter - Medium

Implement a simplified version of Twitter which allows users to post tweets, follow/unfollow each other, and view the 10 most recent tweets within their own news feed.
Users and tweets are uniquely identified by their IDs (integers).
Implement the following methods:

Twitter() Initializes the twitter object.
void postTweet(int userId, int tweetId) Publish a new tweet with ID tweetId by the user userId. You may assume that each tweetId is unique.
List<Integer> getNewsFeed(int userId) Fetches at most the 10 most recent tweet IDs in the user's news feed. Each item must be posted by users who the user is following or by the user themself. Tweets IDs should be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId follows the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId unfollows the user with ID followeeId.

Example 1:
Input:
["Twitter", "postTweet", [1, 10], "postTweet", [2, 20], "getNewsFeed", [1], "getNewsFeed", [2], "follow", [1, 2], "getNewsFeed", [1], "getNewsFeed", [2], "unfollow", [1, 2], "getNewsFeed", [1]]

Output:
[null, null, null, [10], [20], null, [20, 10], [20], null, [10]]

Explanation:
Twitter twitter = new Twitter();
twitter.postTweet(1, 10); // User 1 posts a new tweet with id = 10.
twitter.postTweet(2, 20); // User 2 posts a new tweet with id = 20.
twitter.getNewsFeed(1); // User 1's news feed should only contain their own tweets -> [10].
twitter.getNewsFeed(2); // User 2's news feed should only contain their own tweets -> [20].
twitter.follow(1, 2); // User 1 follows user 2.
twitter.getNewsFeed(1); // User 1's news feed should contain both tweets from user 1 and user 2 -> [20, 10].
twitter.getNewsFeed(2); // User 2's news feed should still only contain their own tweets -> [20].
twitter.unfollow(1, 2); // User 1 unfollows user 2.
twitter.getNewsFeed(1); // User 1's news feed should only contain their own tweets -> [10].

Constraints:
1 <= userId, followerId, followeeId <= 500
0 <= tweetId <= 10^4
All the tweets have unique IDs.
At most 3 * 10^4 calls will be made to postTweet, getNewsFeed, follow, and unfollow.
A user cannot follow themself.

*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Twitter {
public:

    // All this problem work like a database
    unordered_map < int, unordered_map < int, int > > myTweets;
    unordered_map < int, unordered_set < int > > followers;
    int time;

    Twitter() {

        myTweets.clear();
        followers.clear();
        time = 0;

    }

    void postTweet(int userId, int tweetId) {

        myTweets[userId][tweetId] = ++time;



        // one hasmaps that have, this user



        // save the tweet id with user id
        // hashset de hashset? the first have the uset id,
        // the second the tweetId

    }

    vector<int> getNewsFeed(int userId) {

        priority_queue < pair< int, int > > pq;

        unordered_set <int> users = followers[userId];
        users.insert(userId);

        for( int user : users ){
            for( auto tweets : myTweets[user] ){


                int timestamp = tweets.second;
                int id        = tweets.first;

                pq.push( {timestamp, id} );

            }
        }

        int i = 10;
        vector< int > ans;
        while( i--  && !pq.empty() ){
            int tweet = pq.top().second;
            pq.pop();
            ans.push_back( tweet );
        }

        return ans;

        // load the 10's newers twits FROM the follow
        // users or by himself

    }

    void follow(int followerId, int followeeId) {

        followers[followerId].insert(followeeId);

        // insertar los tweets del heap

        // connect follower to followed

    }

    void unfollow(int followerId, int followeeId) {

        followers[followerId].erase(followeeId);

        // eliminar la heap

        // un-connect the follower from the followed

    }
};

void printFeed(const vector<int> &feed){
    cout << "[";
    for(int i = 0; i < feed.size(); i++){
        cout << feed[i];
        if(i + 1 < feed.size()) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {

    Twitter twitter;

    twitter.postTweet(1, 10);
    twitter.postTweet(2, 20);

    printFeed(twitter.getNewsFeed(1)); // [10]
    printFeed(twitter.getNewsFeed(2)); // [20]

    twitter.follow(1, 2);

    printFeed(twitter.getNewsFeed(1)); // [20, 10]
    printFeed(twitter.getNewsFeed(2)); // [20]

    twitter.unfollow(1, 2);

    printFeed(twitter.getNewsFeed(1)); // [10]

    return 0;
}
