/*
Time Based Key-Value Store - Medium

Implement a time-based key-value data structure that supports:

Storing multiple values for the same key at specified time stamps
Retrieving the key's value at a specified timestamp

Implement the TimeMap class:

 - TimeMap() Initializes the object.
 - void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
 - String get(String key, int timestamp) Returns the most recent value of key if set was previously called on it and the most recent timestamp for that key prev_timestamp is less than or equal to the given timestamp (prev_timestamp <= timestamp). If there are no values, it returns "".

Note: For all calls to set, the timestamps are in strictly increasing order.

Example 1:
Input:
["TimeMap", "set", ["alice", "happy", 1], "get", ["alice", 1], "get", ["alice", 2], "set", ["alice", "sad", 3], "get", ["alice", 3]]

Output:
[null, null, "happy", "happy", null, "sad"]

Explanation:
TimeMap timeMap = new TimeMap();
timeMap.set("alice", "happy", 1);  // store the key "alice" and value "happy" along with timestamp = 1.
timeMap.get("alice", 1);           // return "happy"
timeMap.get("alice", 2);           // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
timeMap.set("alice", "sad", 3);    // store the key "alice" and value "sad" along with timestamp = 3.
timeMap.get("alice", 3);           // return "sad"

Constraints:
1 <= key.length, value.length <= 100
key and value only include lowercase English letters and digits.
1 <= timestamp <= 1000

*/

#include <iostream>]
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class TimeMap {

    unordered_map <string, vector <pair <string, int>>> timeMap;


public:


    // I will use a un_map to store the data
    TimeMap() {} // inicializator

    void set(string key, string value, int timestamp) {


        timeMap[key].push_back({
            value,
            timestamp
        });
    }

    string get(string key, int timestamp) {

        if(!timeMap.count(key)) return "";

        int left = 0, right = timeMap[key].size() - 1, ans = -1;

        while( left <= right){

            int mid = left + (right - left)/2;

            if(timeMap[key][mid].second <= timestamp){
                ans = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }

        }

        if(ans == -1) return "";

        return timeMap[key][ans].first;


    }
};



int main() {
    TimeMap tm;

    tm.set("foo", "bar", 1);
    cout << tm.get("foo", 1) << endl; // bar
    cout << tm.get("foo", 3) << endl; // bar

    tm.set("foo", "bar2", 4);
    cout << tm.get("foo", 4) << endl; // bar2
    cout << tm.get("foo", 5) << endl; // bar2

    return 0;
}
