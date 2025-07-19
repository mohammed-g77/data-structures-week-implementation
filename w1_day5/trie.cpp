#include <iostream>
#include <cstring>
using namespace std;

const int ALPHABET_SIZE = 26;

 struct Node {
    Node* children[ALPHABET_SIZE];
    bool isEnd;

    Node() {
        isEnd = false;
        memset(children, 0, sizeof(children));
    }
};

class Trie {
private:
    Node* root;

 
    bool removeHelper(Node* node, const char* str) {
        if (*str == '\0') {
            if (!node->isEnd) return false;
            node->isEnd = false;
            return isEmpty(node);
        }

        int idx = *str - 'a';
        if (!node->children[idx]) return false;

        bool shouldDeleteChild = removeHelper(node->children[idx], str + 1);
        if (shouldDeleteChild) {
            delete node->children[idx];
            node->children[idx] = nullptr;
            return !node->isEnd && isEmpty(node);
        }

        return false;
    }

     
    int countWords(Node* node) {
        if (!node) return 0;
        int count = node->isEnd ? 1 : 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            count += countWords(node->children[i]);
        return count;
    }
 
    void listWords(Node* node, string current) {
        if (node->isEnd) cout << current << endl;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (node->children[i]) {
                char ch = 'a' + i;
                listWords(node->children[i], current + ch);
            }
        }
    }

     bool isEmpty(Node* node) {
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            if (node->children[i]) return false;
        return true;
    }

public:
    Trie() {
        root = new Node();
    }

 
    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new Node();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    
    bool search(const string& word) {
        Node* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }
 
    bool startsWith(const string& prefix) {
        Node* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }

     bool remove(const string& word) {
        return removeHelper(root, word.c_str());
    }

     int countWordsWithPrefix(const string& prefix) {
        Node* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->children[idx]) return 0;
            node = node->children[idx];
        }
        return countWords(node);
    }

     void listAllWords() {
        listWords(root, "");
    }

    
    bool isEmpty() {
        return isEmpty(root);
    }
};


int main() {
    Trie trie;

    
    trie.insert("apple");
    trie.insert("app");
    trie.insert("ape");
    trie.insert("bat");
    trie.insert("bath");
   

    cout << "Words in Trie:\n";
    trie.listAllWords();

     cout << "\nSearch results:\n";
    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'bat': " << (trie.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Search 'bad': " << (trie.search("bad") ? "Found" : "Not Found") << endl;

 
    cout << "\nPrefix results:\n";
    cout << "Starts with 'app': " << (trie.startsWith("app") ? "Yes" : "No") << endl;
    cout << "Starts with 'batm': " << (trie.startsWith("batm") ? "Yes" : "No") << endl;
    cout << "Starts with 'cat': " << (trie.startsWith("cat") ? "Yes" : "No") << endl;

  
    cout << "\nCount words with prefix 'bat': " << trie.countWordsWithPrefix("bat") << endl;
    cout << "Count words with prefix 'ap': " << trie.countWordsWithPrefix("ap") << endl;

    
    cout << "\nRemoving 'bath'\n";
    trie.remove("bath");

    cout << "\nWords after removing 'bath':\n";
    trie.listAllWords();

    
    cout << "\nIs Trie empty? " << (trie.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
