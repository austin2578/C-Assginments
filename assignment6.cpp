#include <iostream>
#include <vector>

using namespace std;

const int N = 31;

int h(int key) {
    return key % N;
}

int h_prime(int key) {
    return 13 - (key % 13);
}

struct Node {
    int key;
    string value;
    Node(int k, string v) {
        key = k;
        value = v;
    }
};

class Map {
private:
    vector<Node*> table;
public:
    Map() {
        table.resize(N);
    }
    void put(int key, string value) {
        int index = h(key);
        int offset = h_prime(key);
        while (table[index] != nullptr) {
            index = (index + offset) % N;
        }
        table[index] = new Node(key, value);
    }
    void remove(int key) {
        int index = h(key);
        int offset = h_prime(key);
        while (table[index] != nullptr && table[index]->key != key) {
            index = (index + offset) % N;
        }
        if (table[index] != nullptr && table[index]->key == key) {
            delete table[index];
            table[index] = nullptr;
        }
    }
    string get(int key) {
        int index = h(key);
        int offset = h_prime(key);
        while (table[index] != nullptr && table[index]->key != key) {
            index = (index + offset) % N;
        }
        if (table[index] != nullptr && table[index]->key == key) {
            return table[index]->value;
        }
        return "";
    }
    void print() {
        for (int i = 0; i < N; i++) {
            if (table[i] != nullptr) {
                cout << "Vector Index: " << i << " ------- Key: " << table[i]->key << " ------- Value: " << table[i]->value << endl;
            }
        }
    }
};

int main() {
    Map myMap;
    cout << "/********************************************\n";
    cout << "* This program will store given keys\n";
    cout << "* and values into a vector using a double\n";
    cout << "* hashing algorithm and a map.\n";
    cout << "*********************************************/\n";
    myMap.put(18, "Laguna Niguel");
    myMap.put(41, "Mission Viejo");
    myMap.put(22, "San Clemente");
    myMap.put(44, "Irvine");
    myMap.remove(41);
    myMap.put(58, "Lake Forest");
    myMap.put(32, "San Diego");
    myMap.put(49, "Anaheim");
    myMap.remove(58);
    myMap.put(31, "Los Angeles");
    myMap.put(17, "Orange");
    myMap.put(72, "Palms Springs");
    myMap.put(41, "Riverside");
    myMap.remove(72);
    myMap.put(19, "Brea");
    myMap.put(60, "Santa Ana");
    myMap.put(35, "Tustin");
    myMap.put(103, "Oceanside");
    myMap.put(11, "La Jolla");
    myMap.put(18, "Del Mar");
    myMap.put(22, "Aliso Viejo");
    myMap.put(49, "Laguna Beach");
    myMap.remove(41);
    myMap.put(42, "Vista");
    myMap.put(49, "San Diego");
    myMap.put(99, "San Juan");
    myMap.put(29, "Dana Point");
    myMap.put(88, "El Segundo");
    myMap.put(41, "San Clemente");
    myMap.put(62, "Laguna Hills");
    myMap.print();
    return 0;
}