#include <iostream>
#include <string>

using namespace std;

const int N = 31;

class Node {
public:
    int key;
    string value;
    Node* next;

    Node(int key, string value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

class HashTable {
private:
    Node* arr[N];

public:
    HashTable() {
        for (int i = 0; i < N; i++) {
            arr[i] = NULL;
        }
    }

    int hash(int key) {
        return key % N;
    }

    void insert(int key, string value) {
        int index = hash(key);
        Node* newNode = new Node(key, value);
        if (arr[index] == NULL) {
            arr[index] = newNode;
        } else {
            int i = 1;
            int newIndex = (index + i*i) % N;
            while (arr[newIndex] != NULL) {
                i++;
                newIndex = (index + i*i) % N;
            }
            arr[newIndex] = newNode;
        }
    }

    void remove(int key) {
        int index = hash(key);
        if (arr[index] != NULL && arr[index]->key == key) {
            arr[index] = arr[index]->next;
        } else {
            int i = 1;
            int newIndex = (index + i*i) % N;
            while (arr[newIndex] != NULL && arr[newIndex]->key != key) {
                i++;
                newIndex = (index + i*i) % N;
            }
            if (arr[newIndex] != NULL && arr[newIndex]->key == key) {
                arr[newIndex] = arr[newIndex]->next;
            }
        }
    }

    void print() {
        cout << "Vector index --- Key --- Value\n";
        cout << "--------------------------------\n";
        for (int i = 0; i < N; i++) {
            cout << "     [" << i << "]  ";
            Node* curr = arr[i];
            while (curr != NULL) {
                cout << " ->   (" << curr->key << ",     " << curr->value << ")";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable table;

    cout << "/********************************************\n";
    cout << "* This program will store given keys\n";
    cout << "* and values into a vector using a quadratic\n";
    cout << "* hashing algorithm and a map.\n";
    cout << "*********************************************/\n";
    table.insert(18, "Laguna Niguel");
    table.insert(41, "Mission Viejo");
    table.insert(22, "San Clemente");
    table.insert(44, "Irvine");
    table.remove(41);
    table.insert(58, "Lake Forest");
    table.insert(32, "San Diego");
    table.insert(49, "Anaheim");
    table.remove(58);
    table.insert(31, "Los Angeles");
    table.insert(17, "Orange");
    table.insert(72, "Palms Springs");
    table.insert(41, "Riverside");
    table.remove(72);
    table.insert(19, "Brea");
    table.insert(60, "Santa Ana");
    table.insert(35, "Tustin");
    table.insert(103, "Oceanside");
    table.insert(11, "La Jolla");
    table.insert(18, "Del Mar");
    table.insert(22, "Aliso Viejo");
    table.insert(49, "Laguna Beach");
    table.print();

    return 0;
}