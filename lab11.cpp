#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    priority_queue<string> priorityQueue;

    cout << "Enter the names of 5 students." << endl;

    for (int i = 0; i < 5; ++i) {
        string name;
        cout << "Enter a name: ";
        cin >> name;
        priorityQueue.push(name);
    }

    cout << "Now popping names from the priority queue:" << endl;

    while (!priorityQueue.empty()) {
        cout << priorityQueue.top() << endl;
        priorityQueue.pop();
    }

    cout << "The queue is empty." << endl;

    return 0;
}