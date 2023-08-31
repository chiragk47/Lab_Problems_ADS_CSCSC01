#include <iostream>
#include <vector>

class NStacks {
private:
    int n; // Number of stacks
    int capacity; // Total capacity of the array
    std::vector<int> arr; // The single array to hold the stacks
    std::vector<int> top; // Store the top index of each stack

public:
    NStacks(int numStacks, int totalCapacity) : n(numStacks), capacity(totalCapacity) {
        arr.resize(capacity * n);
        top.resize(n, -1); // Initialize top indices to -1 (empty)
    }

    bool isFull(int stackNum) {
        return top[stackNum] == capacity - 1;
    }

    bool isEmpty(int stackNum) {
        return top[stackNum] == -1;
    }

    void push(int stackNum, int value) {
        if (isFull(stackNum)) {
            std::cout << "Stack " << stackNum << " is full. Cannot push." << std::endl;
            return;
        }

        int index = top[stackNum] + 1 + stackNum * capacity; // Calculate index
        arr[index] = value;
        top[stackNum]++;
    }

    void pop(int stackNum) {
        if (isEmpty(stackNum)) {
            std::cout << "Stack " << stackNum << " is empty. Cannot pop." << std::endl;
            return;
        }

        int index = top[stackNum] + stackNum * capacity; // Calculate index
        std::cout << "Popped value from Stack " << stackNum << ": " << arr[index] << std::endl;
        top[stackNum]--;
    }

    int peek(int stackNum) {
        if (isEmpty(stackNum)) {
            std::cout << "Stack " << stackNum << " is empty." << std::endl;
            return -1;
        }

        int index = top[stackNum] + stackNum * capacity; // Calculate index
        return arr[index];
    }
};

int main() {
    int numStacks = 3;
    int totalCapacity = 10;
    NStacks nStacks(numStacks, totalCapacity);

    nStacks.push(0, 1);
    nStacks.push(1, 11);
    nStacks.push(2, 21);

    nStacks.pop(0);
    nStacks.pop(1);

    std::cout << "Top element of Stack 2: " << nStacks.peek(2) << std::endl;

    return 0;
}
