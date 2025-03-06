#include <iostream>
#include <vector>
#define TABLE_SIZE 10
using namespace std;

class Htable {
    vector<int> table;

public:
    Htable() {
        table.resize(TABLE_SIZE, -1);
    }

    int index_(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = index_(key);
        int i = 0;
        while (table[(i + index) % TABLE_SIZE] != -1 && i < TABLE_SIZE) {
            i++;
        }
        if (i == TABLE_SIZE) {
            cout << "The table is full" << endl;
            return;
        }
        table[(i + index) % TABLE_SIZE] = key;
    }

    bool search(int key) {
        int index = index_(key);
        int i = 0;
        while (table[(i + index) % TABLE_SIZE] != key && table[(i + index) % TABLE_SIZE] != -1 && i < TABLE_SIZE) {
            i++;
        }
        return table[(i + index) % TABLE_SIZE] == key;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != -1) {
                cout << i << " -> " << table[i] << endl;
            } else {
                cout << i << " -> Empty" << endl;
            }
        }
    }
};

int main() {
    Htable hashTable;
    hashTable.insert(12);
    hashTable.insert(22);
    hashTable.insert(32);
    hashTable.display();
    int key = 22;
    if (hashTable.search(key))
        cout << key << " found in hash table." << endl;
    else
        cout << key << " not found in hash table." << endl;
    return 0;
}
