#include <iostream>
#include <vector>
#define TABLE_SIZE 10
using namespace std;

class Node {
public:
    int key;
    int value;

    Node(int k, int v) {
        key = k;
        value = v;
    }
};

class Htable {
public:
    vector<Node*> table;

    Htable() {
        table.resize(TABLE_SIZE, nullptr);
    }

    int index_(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key, int value) {
        int index = index_(key);
        int i = 0;

        // Quadratic probing
        while (i < TABLE_SIZE && table[(index + i * i) % TABLE_SIZE] != nullptr) {
            i++;
        }

        if (i == TABLE_SIZE) {
            cout << "The table is full" << endl;
            return;
        }

        table[(index + i * i) % TABLE_SIZE] = new Node(key, value);
    }

    bool search(int key) {
        int index = index_(key);
        int i = 0;

        // Quadratic probing for search
        while (i < TABLE_SIZE && table[(index + i * i) % TABLE_SIZE] != nullptr &&
               table[(index + i * i) % TABLE_SIZE]->key != key) {
            i++;
        }

        return (i < TABLE_SIZE && table[(index + i * i) % TABLE_SIZE] != nullptr &&
                table[(index + i * i) % TABLE_SIZE]->key == key);
    }

    void deletion(int key) {
        int index = index_(key);
        int i = 0;

        while (i < TABLE_SIZE && table[(index + i * i) % TABLE_SIZE] != nullptr &&
               table[(index + i * i) % TABLE_SIZE]->key != key) {
            i++;
        }

        if (i < TABLE_SIZE && table[(index + i * i) % TABLE_SIZE] != nullptr &&
            table[(index + i * i) % TABLE_SIZE]->key == key) {
            delete table[(index + i * i) % TABLE_SIZE];
            table[(index + i * i) % TABLE_SIZE] = nullptr;
            cout << "Key " << key << " deleted successfully." << endl;
        } else {
            cout << "Key " << key << " not found in the hash table." << endl;
        }
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                cout << i << " -> Key: " << table[i]->key << ", Value: " << table[i]->value << endl;
            } else {
                cout << i << " -> Empty" << endl;
            }
        }
    }

    ~Htable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            delete table[i]; // Free memory for each node
        }
    }
};

int main() {
    Htable hashTable;

    // Insertion
    cout << "Inserting elements into the hash table:" << endl;
    hashTable.insert(12, 100);
    hashTable.insert(22, 200);
    hashTable.insert(32, 300);
    hashTable.insert(42, 400); // Additional insert
    hashTable.display();

    // Search for keys
    int searchKey = 22;
    if (hashTable.search(searchKey)) {
        cout << "Key " << searchKey << " found in hash table." << endl;
    } else {
        cout << "Key " << searchKey << " not found in hash table." << endl;
    }

    searchKey = 50; // Key not in table
    if (hashTable.search(searchKey)) {
        cout << "Key " << searchKey << " found in hash table." << endl;
    } else {
        cout << "Key " << searchKey << " not found in hash table." << endl;
    }

    // Deletion
    cout << "\nDeleting a key from the hash table:" << endl;
    hashTable.deletion(22); // Delete an existing key
    hashTable.display();

    cout << "\nAttempting to delete a non-existent key:" << endl;
    hashTable.deletion(50); // Try to delete a non-existent key

    // Display final hash table state
    cout << "\nFinal state of the hash table:" << endl;
    hashTable.display();

    return 0;
}
