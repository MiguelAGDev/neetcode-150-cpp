#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {

    vector <vector <float>> cars;
    stack <int> seen;

    for(int i  = 0; i < speed.size(); i++){
        cars.push_back({
            float(position[i]),
            float(target - position[i])/speed[i]
        });
    }

    sort(cars.begin(), cars.end());

    int fleet = 0;
    for(int i = cars.size() - 1; i >= 0 ; i--){
        while(!seen.empty() &&  cars[i][1] > cars[seen.top()][1]){
            seen.pop();

        }

        if(seen.empty()) fleet++;
        seen.push(i);

    }

    return fleet;
}

int main() {
    int target = 12;

    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    int result = carFleet(target, position, speed);

    cout << "Car Fleets: " << result << endl;

    return 0;
}
