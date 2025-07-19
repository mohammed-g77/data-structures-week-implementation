
# 📚 Week 1 – Data Structures in C++

##  Introduction

This repository contains fundamental data structure implementations in C++ for the first week of a Data Structures & Algorithms course. These include various types of arrays, linked lists, stacks, queues, trees, graphs, hash tables, and disjoint sets.

 
---

## 📁 Folder Structure

```
w1_day1/
    - DynamicArray.cpp
    - SinglyLinkedList.cpp
    - StackArray.cpp
    - StackLinkedList.cpp

w1_day2/
    - Circular Linked List.cpp
    - Doubly Linked List.cpp
    - QueueArray.cpp
    - QueueList.cpp

w1_day3/
    - BinarySearch.cpp
    - BinarySearchTree.cpp
    - TreeTraversalAlgorithms.cpp

w1_day4/
    - BasicGraph.cpp
    - HashTable.cpp
    - MinHeap.cpp

w1_day5/
    - GraphTraversal(BFS-DFS).cpp
    - Union-Find(Disjoint Set).cpp
    - trie.cpp
```

---

##  Data Structures Implemented

| Type       | Structures                                                                 |
|------------|-----------------------------------------------------------------------------|
| **Linear** | Dynamic Array, Singly Linked List, Stack (Array/Linked List), Queue (Array/List), Doubly & Circular Linked Lists |
| **Tree**   | Binary Tree, Binary Search Tree, Tree Traversal Algorithms, Trie           |
| **Graph**  | Undirected Graph (Adjacency List), BFS, DFS                                |
| **Heap**   | MinHeap (Binary Heap)                                                      |
| **Hashing**| Hash Table (Chaining with Lists)                                           |
| **Set DS** | Union-Find / Disjoint Set                                                  |

---

##  Time & Space Complexity Summary

| Data Structure       | Insertion | Deletion | Search   | Space       |
|----------------------|-----------|----------|----------|-------------|
| **Dynamic Array**    | O(1)*     | O(n)     | O(n)     | O(n)        |
| **Singly Linked List**| O(1)     | O(1)     | O(n)     | O(n)        |
| **Doubly Linked List**| O(1)     | O(1)     | O(n)     | O(n)        |
| **Circular DLL**     | O(1)     | O(1)     | O(n)     | O(n)        |
| **Stack (Array)**    | O(1)     | O(1)     | O(1)     | O(n)        |
| **Stack (LL)**       | O(1)     | O(1)     | O(1)     | O(n)        |
| **Queue (Array)**    | O(1)     | O(1)     | O(1)     | O(n)        |
| **Queue (LL)**       | O(1)     | O(1)     | O(1)     | O(n)        |
| **Binary Tree (BT)** | O(n)     | O(n)     | O(n)     | O(n)        |
| **Binary Search Tree**| O(log n)| O(log n) | O(log n) | O(n)        |
| **Hash Table**       | O(1)     |  O(1)    | O(1)     | O(n)        |
| **MinHeap**          | O(log n) | O(log n) | O(1)     | O(n)        |
| **Trie**             | O(k)     | O(k)     | O(k)     | O(k × n)    |
| **Union-Find**       | O(α(n))  | O(α(n))  | O(α(n))  | O(n)        |
| **Graph (BFS/DFS)**  | O(V+E)   | —        | —        | O(V+E)      |

 
---

##  Example Usage

### Singly Linked List
```cpp
 
Sll list;
list.addToFirst(5);
list.addToLast(10);
list.addAfter(5, 7);
list.Display();
```
### Stack (Array)
```cpp
 
StackArray s;
s.push(10);
s.push(20);
cout << s.peek();
s.pop();
```

### Stack (Linked List)
```cpp
 
Stack s;
s.push(10);
while (!s.isEmpty()) {
    cout << s.Top() << " ";
    s.pop();
}
```


###  Circular Doubly Linked List

```cpp
CDLL list;
list.addElement(10);
list.addElement(20);
list.Display();      // Output: 10 20
list.DisplayRev();   // Output: 20 10
list.deleteElement(10);
list.clear();
```

###  Queue Using Array

```cpp
QueueArray q;
q.enqueue(5);
q.enqueue(10);
q.dequeue();
q.display(); // Output: 10
```

###  Binary Search Tree

```cpp
BST tree;
tree.Insert(10);
tree.Insert(20);
tree.Insert(5);
tree.Inorder(tree.getRoot());  // Output: 5 10 20
```

###  Graph (BFS & DFS)

```cpp
Graph g(5);
g.addEdge(0, 1);
g.addEdge(0, 2);
g.BFS(0); // Output: 0 1 2 ...
g.DFS(0); // Output: 0 1 3 ...
```

###  Trie

```cpp
Trie t;
t.insert("apple");
t.insert("app");
t.search("apple");        // true
t.startsWith("ap");       // true
t.countWordsWithPrefix("app"); // 2
```

---

##  How to Run Tests

Each `.cpp` file contains a `main()` function with basic test cases.

###  To compile and run ( Visual Studio):

1. Open any `.cpp` file in **Visual Studio**.
2. Press `Ctrl + F5` (Start without debugging).
3. Observe the console output.

 
