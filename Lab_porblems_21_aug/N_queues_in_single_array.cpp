#include <iostream>
#include <vector>
using namespace std;

class NQueues {
private:
    vector<int> arr;
    vector<int> front;
    vector<int> rear;
    int N;
    int queueSize;

public:
    NQueues(int numQueues, int size) : N(numQueues), queueSize(size) {
        arr.resize(N * queueSize, 0);
        front.resize(N, -1);
        rear.resize(N, -1);
    }

    bool isFull(int queueIndex) {
        return (rear[queueIndex] + 1) % queueSize == front[queueIndex];
    }

    bool isEmpty(int queueIndex) {
        return front[queueIndex] == -1;
    }

    void enqueue(int queueIndex, int data) {
        if (isFull(queueIndex)) {
            cout << "Queue " << queueIndex << " is full." << endl;
            return;
        }

        if (isEmpty(queueIndex))
            front[queueIndex] = rear[queueIndex] = 0;
        else
            rear[queueIndex] = (rear[queueIndex] + 1) % queueSize;

        arr[queueIndex * queueSize + rear[queueIndex]] = data;

        printState();
    }

    void dequeue(int queueIndex) {
        if (isEmpty(queueIndex)) {
            cout << "Queue " << queueIndex << " is empty." << endl;
            return;
        }

        if (front[queueIndex] == rear[queueIndex])
            front[queueIndex] = rear[queueIndex] = -1;
        else
            front[queueIndex] = (front[queueIndex] + 1) % queueSize;

        printState();
    }

    void printState() {
        cout << "Queue State:" << endl;
        for (int i = 0; i < N; ++i) {
            cout << "Queue " << i << ": ";
            if (!isEmpty(i)) {
                int index = front[i];
                while (index != rear[i]) {
                    cout << arr[i * queueSize + index] << " ";
                    index = (index + 1) % queueSize;
                }
                cout << arr[i * queueSize + index];
            }
            cout << endl;
        }
        cout << "----------------------" << endl;
    }
};

int main() {
    int numQueues = 3; // Number of queues
    int queueSize = 5; // Size of each queue

    NQueues nQueues(numQueues, queueSize);

    nQueues.enqueue(0, 10);
    nQueues.enqueue(1, 20);
    nQueues.enqueue(2, 30);

    nQueues.dequeue(0);
    nQueues.enqueue(1, 40);
    nQueues.enqueue(2, 50);
    nQueues.dequeue(1);
    nQueues.enqueue(0, 60);

    return 0;
}
