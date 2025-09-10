# C++ Standard Template Library (STL)

The C++ Standard Template Library (STL) is a collection of generic containers, iterators, algorithms, and utilities that solve common programming tasks efficiently. By leveraging STL, developers focus on application logic instead of re-implementing data structures and algorithms.

### Table of Contents

- [Introduction](#c-standard-template-library-stl)
- [Key Components](#key-components-of-stl)
- [Pair](#stl---pair)
- [Vector](#c-stl-vector-operations)
- [List and Deque](#c-stl-list-and-deque-operations)
- [Stack](#stack-lifo)
- [Queue](#queue-fifo)
- [Set](#set-container)
- [Multiset](#multiset)
- [Unordered Set](#unordered-set)
- [Map](#map)
- [Multimap](#multimap)
- [Algorithms](#functions-and-algorithms)

## Quick Example

```cpp
#include <bits/stdc++.h> // Prefer specific headers in production
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    sort(numbers.begin(), numbers.end());
    for (int num : numbers) {
        cout << num << " ";
    }
    return 0;
}
```

In this example, the `vector` container stores integers and the `sort` algorithm arranges them in ascending order.

## Key Components of STL

### Containers

Containers in STL are used to store collections of objects. They provide various data structures like `vector`, `list`, `set`, and `map` to efficiently manage and access data.

### Algorithms

Algorithms are a collection of functions that perform tasks such as
searching, sorting, and manipulating data stored in containers. They are
designed to work with a wide variety of data types.

### Functions

Functions in STL include a range of utility functions that perform specific operations on data, such as `for_each` and `transform`, making it easier to process collections of data.

### Iterators

Iterators are objects that point to elements within a container and
provide a way to traverse through the container. They are essential for
accessing and modifying elements in STL containers.

## STL - Pair

The `pair` in C++ STL is a utility that allows the storage
of two heterogeneous objects as a single unit. This is particularly
useful when there is a need to associate two values together, such as
when storing key-value pairs. The pair can store values of any data
type, and the values can be accessed directly using `first` and `second` members.

### Example Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, string> student;
    student.first = 1;
    student.second = "Alice";

    cout << "Roll No: " << student.first << ", Name: " << student.second << endl;
    return 0;
}
```

### Expected Output

```
Roll No: 1, Name: Alice

```

### Example Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, string> student;
    student.first = 1;
    student.second = "Alice";

    cout << "Roll No: " << student.first << ", Name: " << student.second << endl;

    pair<pair<int, char>, int> complexPair = {{2, 'B'}, 20};
    cout << "Roll No: " << complexPair.first.first << ", Section: " << complexPair.first.second;
    cout << ", Marks: " << complexPair.second << endl;

    return 0;
}
```

### Expected Output

```
Roll No: 1, Name: Alice
Roll No: 2, Section: B, Marks: 20

```

## C++ STL Vector Operations

### 1. Initialization

`vector` is a dynamic array that can automatically resize itself when elements are added or removed.
It provides the same functionalities as an array but with additional features like dynamic resizing.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    for (int i : v) {
        cout << i << " ";
    }
    return 0;
}
```

### 2. push_back

The `push_back` function adds a new element at the end of the vector.
This is often used to append elements in a loop or based on certain conditions.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    v.push_back(4);
    v.push_back(5);
    for (int i : v) {
        cout << i << " ";
    }
    return 0;
}
```

**Expected Output:** 1 2 3 4 5

### 3. front

The `front` function returns a reference to the first element in the vector.
This is useful when you need to access the starting element without modifying the vector.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    cout << "Front element: " << v.front();
    return 0;
}
```

**Expected Output:** Front element: 10

### 4. back

The `back` function returns a reference to the last element in the vector.
It’s typically used when the last inserted element needs to be accessed or modified.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    cout << "Back element: " << v.back();
    return 0;
}
```

**Expected Output:** Back element: 30

### 5. iterator

Vectors support iterators, which allow traversal through the elements in the vector.
Iterators behave like pointers and can be used for accessing elements or performing operations on the vector.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    return 0;
}
```

**Expected Output:** 10 20 30

### 6. range-based for

The `for_each` loop in C++11 allows for a simpler way to iterate over vectors.
It simplifies the syntax and enhances code readability.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    for (int i : v) {
        cout << i << " ";
    }
    return 0;
}
```

**Expected Output:** 10 20 30

### 7. erase

The `erase` function removes an element from the vector by a position causing all subsequent elements to be
shifted one position to the left.This helps reduces the size of the vector by one.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    v.erase(v.begin() + 1);
    for (int i : v) {
        cout << i << " ";
    }
    return 0;
}
```

**Expected Output:** 10 30

### 8. insert

The `insert` function inserts elements at a specified position in the vector.
It shifts all elements at and after the insertion point to the right, increasing the vector's size.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 30};
    v.insert(v.begin() + 1, 20);
    for (int i : v) {
        cout << i << " ";
    }
    return 0;
}
```

**Expected Output:** 10 20 30

### 9. size

The `size` function returns the number of elements in the vector.
This is helpful in loops or conditions where the vector’s length is a determining factor.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    cout << "Size of vector: " << v.size();
    return 0;
}
```

**Expected Output:** Size of vector: 3

### 10. Access Element

Elements in a vector can be accessed using the `[]` operator or the `at()` method.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    cout << "Element at index 1: " << v[1];
    return 0;
}
```

**Expected Output:** Element at index 1: 20

### 11. swap

The `swap` function swaps the contents of two
vectors.
This is an efficient way to swap large vectors since it only
swaps the internal pointers rather than copying elements.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};
    swap(v1, v2);
    for (int i : v1) {
        cout << i << " ";
    }
    return 0;
}
```

**Expected Output:** 4 5 6

### 12. clear

The `clear` function removes all elements from the vector, making it empty.
It reduces the vector's size to zero but does not free the memory allocated by the vector.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    v.clear();
    cout << "Size after clear: " << v.size();
    return 0;
}
```

**Expected Output:** Size after clear: 0

## C++ STL List and Deque Operations

### What is a List?

Lists are sequence containers that support non-contiguous memory
allocation. Unlike vectors, which offer faster traversal, lists have
slower traversal times.
However, they excel in insertion and deletion operations, which are
performed in constant time once the desired position is identified.
A `list` in C++ STL is a doubly-linked list, which allows
elements to be efficiently inserted or deleted from both ends as well
as from the middle.
Unlike arrays or vectors, lists do not provide fast random access
but are highly efficient in insertion and deletion operations.

### 1. push_front / emplace_front (List)

The `push_front` function inserts a new element at the beginning of the list, while `emplace_front`
constructs an element in place at the beginning. These operations are
efficient since they only involve adjusting a few pointers.

```cpp
#include <bits/stdc++.h>
        using namespace std;

        int main() {
            list<int> lst;
            lst.push_front(20);
            lst.emplace_front(10);  // Constructs 10 at the beginning
            for (int i : lst) {
                cout << i << " ";
            }
            return 0;
        }
```

**Expected Output:** 10 20

### 2. front (List)

The `front` function returns a reference to the
first element in the list. This is useful for accessing or modifying the
element at the front without affecting the rest of the list.

```cpp
#include <bits/stdc++.h>
        using namespace std;

        int main() {
            list<int> lst = {10, 20, 30};
            cout << "Front element: " << lst.front();
            return 0;
        }
```

**Expected Output:** Front element: 10

### 3. Deque

A `deque` is a sequence container with the
ability to expand and contract on both ends efficiently. It supports
fast insertions and deletions at both the beginning and the end, making
it more flexible than a vector or list in scenarios where elements are
frequently added or removed from both ends.

```cpp
#include <bits/stdc++.h>
        using namespace std;

        int main() {
            deque<int> dq = {10, 20, 30};
            dq.push_front(0);  // Insert at the beginning
            dq.push_back(40);  // Insert at the end
            for (int i : dq) {
                cout << i << " ";
            }
            return 0;
        }
```

**Expected Output:** 0 10 20 30 40

## Stack (LIFO)

In C++ Standard Template Library (STL), the stack is a powerful
container adapter that follows the Last In, First Out (LIFO) principle.
It provides a streamlined interface for adding and removing elements
from one end, making it ideal for scenarios requiring
dynamic data management and nested operations.

### 1. push / emplace

The `push` operation adds an element to the top of the stack. The `emplace` operation is similar, but it constructs the element in place, which can be more efficient.

```cpp
#include <bits/stdc++.h>
    using namespace std;

    int main() {
        stack<int> s;
        s.push(10);
        s.emplace(20); // Emplace is similar to push

        cout << "Top element: " << s.top() << endl;
        return 0;
    }
```

**Expected Output:** Top element: 20

### 2. top

The `top` operation returns the element at the top of the stack without removing it.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);

    cout << "Top element: " << s.top() << endl;
    return 0;
}
```

**Expected Output:** Top element: 20

### 3. pop

The `pop` operation removes the top element from the stack.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.pop();

    cout << "Top element after pop: " << s.top() << endl;
    return 0;
}
```

**Expected Output:** Top element after pop: 10

### 4. size

The `size` operation returns the number of elements in the stack.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);

    cout << "Size of stack: " << s.size() << endl;
    return 0;
}
```

**Expected Output:** Size of stack: 2

### 5. swap

The `swap` operation swaps the contents of two stacks.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s1, s2;
    s1.push(10);
    s2.push(20);
    s1.swap(s2);

    cout << "Top element of s1 after swap: " << s1.top() << endl;
    cout << "Top element of s2 after swap: " << s2.top() << endl;
    return 0;
}

```

**Expected Output:**
Top element of s1 after swap: 20
Top element of s2 after swap: 10

### 6. empty

The `empty` operation checks if the stack is empty. It returns `true` if the stack is empty, otherwise `false`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    s.push(10);

    cout << "Is stack empty after push? " << (s.empty() ? "Yes" : "No") << endl;
    return 0;
}

```

**Expected Output:**

Is stack empty? Yes
Is stack empty after push? No

## Queue (FIFO)

In C++ Standard Template Library (STL), the `queue` adapter operates on a First In, First Out (FIFO) basis.

### 1. push / emplace

The `push` operation adds an element to the back; `emplace` constructs in place.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.emplace(20); // Emplace is similar to push

    cout << "Front element: " << q.front() << endl;
    return 0;
}

```

**Expected Output:** Front element: 10

### 2. front

The `front` operation returns the element at the front of the queue without removing it.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);

    cout << "Front element: " << q.front() << endl;
    return 0;
}

```

**Expected Output:** Front element: 10

### 3. pop

The `pop` operation removes the front element from the queue.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.pop();

    cout << "Front element after pop: " << q.front() << endl;
    return 0;
}
```

**Expected Output:** Front element after pop: 20

### 4. size

The `size` operation returns the number of elements in the queue.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    cout << "Size of queue: " << q.size() << endl;
    return 0;
}
```

**Expected Output:** Size of queue: 2

### 5. swap

The `swap` operation swaps the contents of two queues.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q1, q2;
    q1.push(10);
    q2.push(20);
    q1.swap(q2);

    cout << "Front element of q1 after swap: " << q1.front() << endl;
    cout << "Front element of q2 after swap: " << q2.front() << endl;
    return 0;
}

```

**Expected Output:**
Front element of q1 after swap: 20
Front element of q2 after swap: 10

### 6. empty

The `empty` operation checks if the queue is empty. It returns `true` if the queue is empty, otherwise `false`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    q.push(10);

    cout << "Is queue empty after push? " << (q.empty() ? "Yes" : "No") << endl;
    return 0;
}
```

```
Expected Output:
Is queue empty? Yes
Is queue empty after push? No
## Set Container
The `set` container in C++ stores unique elements in a sorted
manner. It automatically removes duplicate entries and provides
efficient search operations.
### Insert / emplace
Elements can be added using `insert` or `emplace`. `insert` returns a pair indicating success and an iterator. `emplace` constructs in place.

```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.emplace(15); // Emplaces an element
    for(int x : s) {
        cout << x << " ";
    }
    return 0;
}
```

```
Expected Output: 10 15 20

Find
    Thefind function searches for a specified element within the set.
    It returns an iterator pointing to the element if found, or to theend()
 of the set if the element is not present.
    This allows for efficient lookups and can be used in combination
with other operations to check for the existence of an element or to
perform actions on it.

```

```cpp
#include <bits/stdc++.h>
    using namespace std;

    int main() {
        set<int> s = {10, 20, 30};
        auto it = s.find(20);
        if(it != s.end()) cout << "Found: " << *it;
        else cout << "Not Found";
        return 0;
    }
```

```
**Expected Output:** Found: 20

### erase
The `erase` function removes elements by iterator or by value.
specifying either an iterator pointing to the element or the element’s
value directly.
    If an iterator is provided, it deletes the element at that position,
 while specifying a value will remove all occurrences of that value

```

```cpp
#include <bits/stdc++.h>
    using namespace std;

    int main() {
        set<int> s = {10, 20, 30};
        s.erase(20);
        for(int x : s) {
            cout << x << " ";
        }
        return 0;
    }
```

````
**Expected Output:** 10 30

### lower_bound
Get an iterator to the first element that is not less than the given value.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {10, 20, 30};
    auto it = s.lower_bound(20);
    cout << "Lower Bound: " << *it;
    return 0;
}
````

````
**Expected Output:** Lower Bound: 20

### upper_bound
Get an iterator to the first element that is greater than the given value.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {10, 20, 30};
    auto it = s.upper_bound(20);
    cout << "Upper Bound: " << *it;
    return 0;
}
````

```
Expected Output: Upper Bound: 30
Multiset
    The `multiset` container allows storing multiple occurrences of the same element.
    It is useful when you need to keep duplicates and still maintain sorted order.
Insert
    Inserting elements into a multiset is similar to a set, but it allows multiple occurrences of the same element.
    Theinsert function can be used to add elements, and unlike a set, it does not enforce uniqueness.
    This makes it ideal for scenarios where duplicate values are needed while still maintaining the sorted order of elements.

```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(10);
    ms.insert(20);
    ms.insert(20);  // Duplicate element
    for(int x : ms) {
        cout << x << " ";
    }
    return 0;
}
```

```
Expected Output: 10 20 20
Erase
Remove elements from the multiset. All occurrences of the element will be removed.
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> ms = {10, 20, 20};
    ms.erase(20);  // Erase all occurrences of 20
    for(int x : ms) {
        cout << x << " ";
    }
    return 0;
}
```

```
**Expected Output:** 10

## Unordered Set
The `unordered_set` container stores unique elements in an unsorted
manner. It provides faster search operations compared to a set due to
hashing.

### Insert / Emplace
Inserting elements into an `unordered_set` can be done using the `insert` or `emplace` methods.
The `insert` function adds unique elements to the container using hashing for efficient insertion.
The `emplace` method constructs elements in place, avoiding unnecessary copies or moves.

```

```cpp
#include <bits/stdc++.h>
    using namespace std;

    int main() {
        unordered_set<int> us;
        us.insert(10);
        us.insert(20);
        us.emplace(30); // Emplaces an element
        for(int x : us) {
            cout << x << " ";
        }
        return 0;
    }
```

```
Expected Output: Elements printed in any order, e.g., 10 20 30
Find
Search for an element in the unordered_set.
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> us = {10, 20, 30};
    auto it = us.find(20);
    if(it != us.end()) cout << "Found: " << *it;
    else cout << "Not Found";
    return 0;
}

```

```
Expected Output: Found: 20
Erase
The
erase function removes elements from anunordered_set by specifying either an iterator pointing to the element or the element’s value directly.
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> us = {10, 20, 30};
    us.erase(20);
    for(int x : us) {
        cout << x << " ";
    }
    return 0;
}
```

```
Expected Output: Elements printed in any order, e.g., 10 30
## Map
The `map` container stores key-value pairs in a sorted order by key and provides efficient lookups and insertions.

### insert / emplace / assignment
Add entries using `insert`, `emplace`, or assignment `m[key] = value`.

```

```cpp
#include <bits/stdc++.h>
    using namespace std;

    int main() {
        map<int, string> m;
        m.insert({1, "one"});
        m.emplace(2, "two");  // Emplaces a key-value pair
        m[3] = "three";       // Assignment
        for(auto &p : m) {
            cout << p.first << ": " << p.second << "\n";
        }
        return 0;
    }
```

````
**Expected Output:**
1: one
2: two
3: three

### find
Search for a key and return an iterator to it; otherwise `end()`.

```cpp
#include <bits/stdc++.h>
    using namespace std;

    int main() {
        map<int, string> m = {{1, "one"}, {2, "two"}, {3, "three"}};
        auto it = m.find(2);
        if(it != m.end()) cout << "Found: " << it->second;
        else cout << "Not Found";
        return 0;
    }
````

````
**Expected Output:** Found: two

### empty
Check whether the map contains any elements.

```cpp
#include <bits/stdc++.h>
    using namespace std;

    int main() {
        map<int, string> m;
        cout << (m.empty() ? "Empty" : "Not Empty");
        return 0;
    }
````

````
**Expected Output:** Empty

### size
Retrieve the number of key-value pairs currently stored in the map.

```cpp
#include <bits/stdc++.h>
    using namespace std;

    int main() {
        map<int, string> m = {{1, "one"}, {2, "two"}, {3, "three"}};
        cout << "Size: " << m.size();
        return 0;
    }
````

````
**Expected Output:** Size: 3

### lower_bound
Get an iterator to the first element that is not less than the given key.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m = {{1, "one"}, {2, "two"}, {3, "three"}};
    auto it = m.lower_bound(2);
    cout << "Lower Bound: " << it->first << ": " << it->second;
    return 0;
}
````

````
**Expected Output:** Lower Bound: 2: two

### upper_bound
Get an iterator to the first element that is greater than the given key.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m = {{1, "one"}, {2, "two"}, {3, "three"}};
    auto it = m.upper_bound(2);
    cout << "Upper Bound: " << it->first << ": " << it->second;
    return 0;
}
````

```
Expected Output: Upper Bound: 3: three
## Multimap
The `multimap` container allows storing multiple values for the same key in a sorted order.

### equal_range
`equal_range` returns a pair of iterators delimiting the range of elements matching a key.

```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mm;
    mm.insert({1, "one"});
    mm.insert({1, "uno"});
    auto range = mm.equal_range(1);
    for(auto it = range.first; it != range.second; ++it) {
        cout << it->first << ": " << it->second << "\n";
    }
    return 0;
}
```

````
**Expected Output:**
1: one
1: uno

## Functions and Algorithms

### sort
The `sort` function sorts elements in ascending order by default. A custom comparator can be provided.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9};
    sort(v.begin(), v.end());
    for(int x : v) {
        cout << x << " ";
    }
    return 0;
}
````

````
Expected Output: 1 1 3 4 5 9
### accumulate
The `accumulate` function calculates the sum of a range of elements [first, last]. It is part of the `<numeric>` header.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum: " << sum;
    return 0;
}
````

````
**Expected Output:** Sum: 15

### count
The `count` function returns the number of occurrences of a value in a range [first, last].

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 1, 2, 1};
    int cnt = count(v.begin(), v.end(), 1);
    cout << "Count of 1: " << cnt;
    return 0;
}

````

````
**Expected Output:** Count of 1: 3

### find
The `find` function searches for the first occurrence of a value in a range [first, last] and returns an iterator to it.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = find(v.begin(), v.end(), 3);
    if(it != v.end()) cout << "Found: " << *it;
    else cout << "Not Found";
    return 0;
}

````

```
Expected Output: Found: 3
Comparator
A comparator is a function or functor that determines the order of
elements during sorting or other operations. It is often passed to
functions like `sort`.
```

/co
