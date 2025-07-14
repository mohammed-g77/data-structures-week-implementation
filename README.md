#  Data Structures Week Implementation

A collection of classic data structures implemented in C++ as part of the Summer Training program. 
- Dynamic Array
- Singly Linked List
- Stack using Array
- Stack using Linked List

---

##  Table of Contents

- [Introduction](#introduction)
- [Data Structures](#data-structures)
- [Dynamic Array](#dynamic-array)
- [Singly Linked List](#singly-linked-list)
- [Stack (Array-based)](#stack-array-based)
- [Stack (Linked List-based)](#stack-linked-list-based)
- [Time and Space Complexity Analysis](#time-and-space-complexity-analysis)
- [Usage Examples](#usage-examples)
- [How to Run Tests](#how-to-run-tests)


##  Introduction

This repository demonstrates the manual implementation of key linear data structures using C++, focusing on practical coding, dynamic memory management, and fundamental data operations such as insertions, deletions, search, and traversal.

---

##  Data Structures

###  Dynamic Array

A dynamic, resizable array capable of expanding and shrinking based on usage.

**Core Operations:**
- Add to first/last/specific index
- Remove from first/last/by index
- Search elements
- Shrink to fit
- Access front/back/size/capacity

---

###  Singly Linked List

A linear data structure composed of dynamically allocated nodes linked sequentially.

**Core Operations:**
- Add to first/last/after a specific value
- Remove from first/last
- Search elements
- Display list
- Clear list
- Get list size

---

###  Stack (Array-based)

Implements LIFO (Last In First Out) using a fixed-size array.

**Core Operations:**
- Push
- Pop
- Peek (Top element)
- Check empty/full
- Get current stack size

---

###  Stack (Linked List-based)

Implements LIFO using dynamically allocated nodes.

**Core Operations:**
- Push
- Pop
- Top
- Check empty
- Get current size

---

##  Time and Space Complexity Analysis

| Operation               | Dynamic Array | Singly Linked List | Stack (Array) | Stack (Linked List) |
|:------------------------|:--------------|:------------------|:--------------|:--------------------|
| Add to First             | O(n)          | O(1)               | O(1)          | O(1)                 |
| Add to Last              | O(1)\*        | O(1)               | O(1)          | O(1)                 |
| Add by Index / After     | O(n)          | O(n)               | N/A           | N/A                  |
| Remove from First        | O(n)          | O(1)               | O(1)          | O(1)                 |
| Remove from Last         | O(1)          | O(n)               | O(1)          | O(1)                 |
| Search                   | O(n)          | O(n)               | O(1)          | O(1) (Top only)      |
| Access by Index          | O(1)          | O(n)               | O(1)          | O(1) (Top only)      |
| Space (per n elements)   | O(n)          | O(n)               | O(1)          | O(n)                 |



---

##  Usage Examples

### Dynamic Array
```cpp
DynamicArray<int> arr;
arr.addToFirst(10);
arr.addToLast(20);
arr.addToIndex(1, 15);
arr.Display();
```

### Singly Linked List
```
Sll list;
list.addToFirst(5);
list.addToLast(10);
list.addAfter(5, 7);
list.Display();
```

### Stack (Array)
```
StackArray s;
s.push(10);
s.push(20);
cout << s.peek();
s.pop();
```

### Stack (Linked List)
```
Stack s;
s.push(10);
while (!s.isEmpty()) {
    cout << s.Top() << " ";
    s.pop();
}

```
## How to Run Tests

### To compile and run: 
 
- Open the .cpp file you want to test in Visual Studio.

- Start Without Debugging (Ctrl + F5)

- The program will compile and run in the terminal window inside Visual Studio.

- Review the output based on the example test cases already included in each file’s main() function
 
