#include <iostream>
#include <stack>

class QueueUsingStack {
private:
    std::stack<int> s1;
    std::stack<int> s2;

public:
    void enqueue(int data) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void dequeue() {
        if (s1.empty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Dequeued: " << s1.top() << std::endl;
        s1.pop();
    }
};

int main() {
    QueueUsingStack queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.dequeue();
    queue.dequeue();

    queue.enqueue(40);

    queue.dequeue();

    return 0;
}
