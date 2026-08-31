#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void visit(int v) {
    cout << "Visited: " << v << endl;
}

void bfs(vector<vector<int>> &graph, int start){

    vector <bool> visited(graph.size(), false);

    queue<int> _queue;
    _queue.push(start);

    while(!_queue.empty()){

        int value = _queue.front();
        _queue.pop();

        if(!visited[value]){

            visited[value] = true;
            visit(value);

            for(int w : graph[value])
                if(!visited[w])
                    _queue.push(w);

        }
    }
} // end bfs

int main()
{

    vector<vector<int>> graph = {
        { 5, 4},                 // Node: 0
        {0, 3, 4},              // Node: 1
        {0, 5},                 // Node: 2
        {1},                    // Node: 3
        {1, 5},                 // Node: 4
        {2, 4}                  // Node: 5
    };

    bfs(graph, 0);

    cout<<endl;

}
