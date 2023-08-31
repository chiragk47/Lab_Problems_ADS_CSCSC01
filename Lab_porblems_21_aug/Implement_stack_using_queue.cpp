#include <iostream>
#include <queue>

class StackUsingQueue {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    void push(int data) {
        q2.push(data);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        std::swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        std::cout << "Popped: " << q1.front() << std::endl;
        q1.pop();
    }
};

int main() {
    StackUsingQueue stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.pop();
    stack.pop();

    stack.push(40);

    stack.pop();

    return 0;
}
