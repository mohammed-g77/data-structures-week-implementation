#include <iostream>
#include <list>
using namespace std;

class HashNode {
public:
    int key;
    string value;

    HashNode(int k, string v) {
        key = k;
        value = v;
    }
};

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    list<HashNode> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(int key, string value) {
        int index = hashFunction(key);
        list<HashNode>::iterator it = table[index].begin();

        while (it != table[index].end()) {
            if (it->key == key) {
                it->value = value; // Update value if key exists
                return;
            }
            ++it;
        }

        table[index].push_back(HashNode(key, value)); // Insert new node
    }

    string search(int key) {
        int index = hashFunction(key);
        list<HashNode>::iterator it = table[index].begin();

        while (it != table[index].end()) {
            if (it->key == key)
                return it->value;
            ++it;
        }
        return "Key not found";
    }

    void remove(int key) {
        int index = hashFunction(key);
        list<HashNode>::iterator it = table[index].begin();

        while (it != table[index].end()) {
            if (it->key == key) {
                it = table[index].erase(it);
                return;
            } else {
                ++it;
            }
        }
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << ": ";
            list<HashNode>::iterator it = table[i].begin();
            while (it != table[i].end()) {
                cout << "[" << it->key << ": " << it->value << "] ";
                ++it;
            }
            cout << endl;
        }
    }
};


int main() {
    HashTable ht;

    ht.insert(1, "Apple");
    ht.insert(2, "Banana");
    ht.insert(12, "Orange");  // Collision with key 2  
    ht.insert(22, "Grapes");  // Collision with key 2 

    cout << "Initial table:" << endl;
    ht.display();

    cout << "\nSearch key 12: " << ht.search(12) << endl;
    cout << "Search key 5: " << ht.search(5) << endl;

    cout << "\nRemoving key 2..." << endl;
    ht.remove(2);
    ht.display();

    cout << "\nInserting key 2 again with new value..." << endl;
    ht.insert(2, "Blueberry");
    ht.display();

    return 0;
}

