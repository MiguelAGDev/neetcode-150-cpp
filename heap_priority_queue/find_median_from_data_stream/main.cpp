/*
Find Median From Data Stream - Hard

The median is the middle value in a sorted list of integers. For lists of even length, there is no middle value, so the median is the mean of the two middle values.
For example:

For arr = [1,2,3], the median is 2.
For arr = [1,2], the median is (1 + 2) / 2 = 1.5

Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far.

Example 1:
Input:
["MedianFinder", "addNum", "1", "findMedian", "addNum", "3" "findMedian", "addNum", "2", "findMedian"]

Output:
[null, null, 1.0, null, 2.0, null, 2.0]

Explanation:
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1); // arr = [1]
medianFinder.findMedian(); // return 1.0
medianFinder.addNum(3); // arr = [1, 3]
medianFinder.findMedian(); // return 2.0
medianFinder.addNum(2); // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

Constraints:
-100,000 <= num <= 100,000
At most 50,000 calls will be made to addNum and findMedian.
findMedian will only be called after adding at least one integer to the data structure.

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxHeap priority_queue<int>
#define minHeap priority_queue<int, vector<int>, greater<int>>

class MedianFinder {
public:
    minHeap min_;
    maxHeap max_;
    MedianFinder() {}

    void addNum(int num) {
        max_.push(num);

        min_.push(max_.top());
        max_.pop();

        if (min_.size() > max_.size()) {
            max_.push(min_.top());
            min_.pop();
        }
    }

    double findMedian() {

        if (max_.size() > min_.size())
            return max_.top();

        return (max_.top() + min_.top()) / 2.0;
    }
};

int main() {

    MedianFinder medianFinder;

    medianFinder.addNum(1);
    cout << medianFinder.findMedian() << endl; // 1.0

    medianFinder.addNum(3);
    cout << medianFinder.findMedian() << endl; // 2.0

    medianFinder.addNum(2);
    cout << medianFinder.findMedian() << endl; // 2.0

    return 0;
}
