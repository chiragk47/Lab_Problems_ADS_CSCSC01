#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PriorityQueue2D {
private:
    vector<vector<int>> pq;
    int size;
    int capacity;

public:
    PriorityQueue2D(int max_size) {
        capacity = max_size;
        pq.resize(max_size, vector<int>(2, -1));
        size = 0;
    }

    void add(int value, int priority) {
        if (size >= capacity) {
            cout << "Priority queue is full." << endl;
            return;
        }

        pq[size][0] = value;
        pq[size][1] = priority;
        size++;
        heapifyUp(size - 1);

        printGraphicalRepresentation();
    }

    void remove() {
        if (size == 0) {
            cout << "Priority queue is empty." << endl;
            return;
        }

        pq[0] = pq[size - 1];
        pq[size - 1][0] = -1;
        pq[size - 1][1] = -1;
        size--;
        heapifyDown(0);

        printGraphicalRepresentation();
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && pq[parent][1] > pq[index][1]) {
            swap(pq[parent], pq[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && pq[leftChild][1] < pq[smallest][1])
            smallest = leftChild;

        if (rightChild < size && pq[rightChild][1] < pq[smallest][1])
            smallest = rightChild;

        if (smallest != index) {
            swap(pq[index], pq[smallest]);
            heapifyDown(smallest);
        }
    }

    void printGraphicalRepresentation() {
        cout << "Priority Queue:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << pq[i][0] << "(" << pq[i][1] << ") ";
        }
        cout << endl << "--------------------------------" << endl;
    }
};

int main() {
    PriorityQueue2D pq(10);

    pq.add(10, 3);
    pq.add(20, 2);
    pq.add(30, 4);
    pq.add(40, 1);

    pq.remove();
    pq.remove();

    pq.add(50, 5);
    pq.remove();

    return 0;
}
