#include <iostream>
#include <vector>
using namespace std;


class myHeap{

private:

    // D.S. where the heap is
    vector <int> heap;

    // Helper Functions
    int parent(int index){ return (index - 1) / 2; }

    int left(int index)  { return (2 * index) + 1; }

    int right(int index) { return (2 * index) + 2; }


    // HeapifyUp use to insert
    void heapifyUp(int index){

        while(index > 0 && heap[index] < heap[parent(index)]){

            swap(heap[index] , heap[parent(index)]);
            index = parent(index);

        }

    }

    //HeapifyDown use to remove
    void heapifyDown(int index){

        int smallest = index;

        for(;;){

            int leftChild  = left(index);
            int rightChild = right(index);

            smallest = index;

            if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
                smallest = leftChild;

            if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
                smallest = rightChild;


            if(smallest == index) break;

            swap(heap[smallest], heap[index]);
            index = smallest;
        }

    }

public:

    // Insert at the end and compare until parent is lower than or it is in the root
    void insert(int value){

        heap.push_back(value);
        heapifyUp(heap.size() - 1);

    }

    void remove(){

        if(heap.empty()) return;

        heap[0] = heap.back();

        heap.pop_back();

        if(!heap.empty())
            heapifyDown(0);
    }

    int top()   { return heap.front(); }

    bool empty(){ return heap.empty(); }

    int size()  { return heap.size(); }

    void print()
    {
        cout << "Heap: ";

        for (int num : heap)
            cout << num << " ";

        cout << endl;
    }




};


int main()
{

    myHeap h;

    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);
    h.insert(8);
    h.insert(15);
    h.insert(1);

    h.print();  // Heap after inserts

    cout << "Top: " << h.top() << endl;

    cout << "\nRemoving...\n";
    h.remove();
    h.print();
    cout << "Top: " << h.top() << endl;

    cout << "\nInserting 3\n";
    h.insert(3);
    h.print();

    cout << "Size: " << h.size() << endl;

    return 0;


}
