/*
=============================================================================
                    ARRAYS vs LINKED LISTS vs VECTORS
=============================================================================

1. ARRAYS (Static Arrays)
   -----------------------
   - Memory: Stored in CONTIGUOUS memory locations (stack or data segment)
   - Size: Fixed at compile time, cannot be changed
   - Access: O(1) random access using index
   - Insertion/Deletion: O(n) - need to shift elements
   - Memory allocation: Stack (local) or Data segment (global)

   Example: int arr[5]; // All 5 integers stored side by side in memory
   Memory: [10][20][30][40][50] <- contiguous blocks

2. LINKED LISTS
   -------------
   - Memory: Stored in NON-CONTIGUOUS memory locations (heap)
   - Size: Dynamic, can grow/shrink at runtime
   - Access: O(n) - must traverse from head
   - Insertion/Deletion: O(1) if position known (just change pointers)
   - Memory allocation: Heap (dynamic allocation using new/malloc)

   Example: Each node stored anywhere in heap, connected via pointers
   Memory: [10|ptr] ---> [20|ptr] ---> [30|ptr] ---> [40|NULL]
           (addr 100)    (addr 500)    (addr 200)    (addr 800)

3. VECTORS (Dynamic Arrays)
   -------------------------
   - Memory: Stored in CONTIGUOUS memory locations (heap)
   - Size: Dynamic, automatically resizes (doubles capacity when full)
   - Access: O(1) random access using index
   - Insertion/Deletion: O(n) - still need to shift elements
   - Memory allocation: Heap (managed internally by STL)

=============================================================================
                    WHY USE LINKED LISTS INSTEAD OF VECTORS?
=============================================================================

| Operation              | Vector      | Linked List |
|------------------------|-------------|-------------|
| Access by index        | O(1) ✓      | O(n)        |
| Insert at beginning    | O(n)        | O(1) ✓      |
| Insert at end          | O(1)*       | O(1) ✓      |
| Insert in middle       | O(n)        | O(1)** ✓    |
| Delete at beginning    | O(n)        | O(1) ✓      |
| Memory overhead        | Low ✓       | High (pointers) |
| Cache performance      | Good ✓      | Poor        |

* Amortized O(1), occasionally O(n) when resizing
** O(1) if you have pointer to position, O(n) to find position

USE LINKED LIST WHEN:
- Frequent insertions/deletions at beginning or middle
- Don't need random access
- Size changes frequently and unpredictably
- Implementing stacks, queues, or graphs

USE VECTOR WHEN:
- Need random access
- Mostly reading data
- Cache performance matters
- Memory efficiency is important

=============================================================================
                    WHERE ELEMENTS ARE STORED
=============================================================================

1. Static Array:    STACK (if local) or DATA SEGMENT (if global)
2. Dynamic Array:   HEAP (pointer on stack, data on heap)
3. Vector:          HEAP (vector object on stack, elements on heap)
4. Linked List:     HEAP (each node allocated dynamically)

=============================================================================
*/

/*
=============================================================================
                    POINTERS AND MEMORY - DEEP DIVE
=============================================================================

Example Code:
    int n = 2;
    int *ptr = &n;
    cout << ptr << endl;

WHAT HAPPENS BEHIND THE SCENES:
-------------------------------

1. int n = 2;
   -----------
   - 'n' is a LOCAL variable (automatic storage)
   - Stored on the STACK
   - Takes 4 bytes (typically) for int
   - Has a memory address (e.g., 0x7ffd5c3a4b2c)
   - Value 2 is stored at that address

   STACK MEMORY:
   +------------------+
   | Address          | Value |
   +------------------+-------+
   | 0x7ffd5c3a4b2c   |   2   |  <-- 'n' lives here
   +------------------+-------+

2. int *ptr = &n;
   ---------------
   - 'ptr' is ALSO a local variable → stored on STACK
   - Takes 8 bytes (on 64-bit system) for pointer
   - '&n' gets the ADDRESS of n
   - ptr STORES that address as its VALUE

   STACK MEMORY:
   +------------------+------------------+
   | Address          | Value            |
   +------------------+------------------+
   | 0x7ffd5c3a4b2c   | 2                |  <-- 'n'
   | 0x7ffd5c3a4b30   | 0x7ffd5c3a4b2c   |  <-- 'ptr' (stores n's address)
   +------------------+------------------+

3. cout << ptr << endl;
   ---------------------
   - Prints the VALUE stored in ptr
   - Which is the ADDRESS of n
   - Output: 0x7ffd5c3a4b2c (or similar hex address)

VISUAL REPRESENTATION:
----------------------

    STACK MEMORY
    ┌─────────────────────────────────────┐
    │                                     │
    │   ptr ──────────┐                   │
    │   [0x...4b30]   │                   │
    │   Value: addr   │                   │
    │        of n     │                   │
    │                 │                   │
    │                 ▼                   │
    │   n ────────────────                │
    │   [0x...4b2c]                       │
    │   Value: 2                          │
    │                                     │
    └─────────────────────────────────────┘

KEY CONCEPTS:
-------------

| Variable | Type   | Stored In | Size    | Contains              |
|----------|--------|-----------|---------|------------------------|
| n        | int    | Stack     | 4 bytes | The value 2            |
| ptr      | int*   | Stack     | 8 bytes | Address of n           |

IMPORTANT DISTINCTIONS:
-----------------------
- ptr     → gives the address stored in ptr (address of n)
- *ptr    → DEREFERENCES ptr, gives value at that address (2)
- &ptr    → gives the address of ptr itself
- &n      → gives the address of n

Example:
    cout << ptr << endl;    // 0x7ffd5c3a4b2c (address of n)
    cout << *ptr << endl;   // 2 (value at that address)
    cout << &ptr << endl;   // 0x7ffd5c3a4b30 (address of ptr)
    cout << &n << endl;     // 0x7ffd5c3a4b2c (same as ptr)

WHY POINTERS ARE ON STACK (in this case):
-----------------------------------------
- Both 'n' and 'ptr' are LOCAL variables
- Local variables have AUTOMATIC storage duration
- They are allocated on stack when function is called
- They are deallocated when function returns

CONTRAST WITH HEAP:
-------------------
    int *heapPtr = new int(2);  // Value 2 is on HEAP
                                 // heapPtr itself is on STACK
                                 // heapPtr points to heap memory

    STACK                          HEAP
    ┌──────────────┐              ┌──────────────┐
    │ heapPtr      │──────────────│ 2            │
    │ [0x...stack] │              │ [0x...heap]  │
    └──────────────┘              └──────────────┘

=============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/*
=============================================================================
                    LINKED LIST NODE STRUCTURE - UNDER THE HOOD
=============================================================================

STRUCT DEFINITION:
------------------
A struct in C++ is similar to a class (default public access).
Each Node contains:
  - data (int): 4 bytes - stores the actual value
  - next (Node*): 8 bytes (on 64-bit) - stores address of next node

MEMORY LAYOUT OF A SINGLE NODE:
-------------------------------
    ┌─────────────────────────────────┐
    │         Node Object             │
    │  (Total: ~12-16 bytes*)         │
    ├─────────────────────────────────┤
    │  data (int)     │  next (Node*) │
    │  [4 bytes]      │  [8 bytes]    │
    │  Value: ???     │  Address: ??? │
    └─────────────────────────────────┘
    * May have padding for alignment

=============================================================================
*/

struct Node
{
public:
    int data;
    Node *next;

public:
    // Constructor - called when 'new Node(...)' is executed
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

/*
=============================================================================
                    MAIN FUNCTION - STEP BY STEP BREAKDOWN
=============================================================================
*/

int main()
{
    vector<int> arr = {2, 5, 8, 7};

    /*
    =========================================================================
    STEP 1: NODE CREATION WITH 'new' KEYWORD
    =========================================================================

    What happens when we write: Node* y1 = new Node(arr[0], nullptr);

    BREAKDOWN:
    ----------
    1. 'new Node(arr[0], nullptr)' does THREE things:
       a) Allocates memory on HEAP for a Node object (~12-16 bytes)
       b) Calls the constructor with arguments (2, nullptr)
       c) Returns the ADDRESS of the allocated memory

    2. 'Node* y1' creates a POINTER variable on STACK

    3. Assignment stores the heap address into y1

    MEMORY STATE AFTER ALL 4 NODES CREATED:
    ----------------------------------------

        STACK                              HEAP
        (Local Variables)                  (Dynamic Memory)
        ┌──────────────┐
        │ arr          │
        │ {2,5,8,7}    │
        ├──────────────┤                   ┌─────────────────┐
        │ y1           │───────────────────│ Node @ 0x1000   │
        │ [0x1000]     │                   │ data: 2         │
        ├──────────────┤                   │ next: nullptr   │
        │ y2           │──────────┐        └─────────────────┘
        │ [0x1020]     │          │
        ├──────────────┤          │        ┌─────────────────┐
        │ y3           │──────┐   └────────│ Node @ 0x1020   │
        │ [0x1040]     │      │            │ data: 5         │
        ├──────────────┤      │            │ next: nullptr   │
        │ y4           │──┐   │            └─────────────────┘
        │ [0x1060]     │  │   │
        └──────────────┘  │   │            ┌─────────────────┐
                          │   └────────────│ Node @ 0x1040   │
                          │                │ data: 8         │
                          │                │ next: nullptr   │
                          │                └─────────────────┘
                          │
                          │                ┌─────────────────┐
                          └────────────────│ Node @ 0x1060   │
                                           │ data: 7         │
                                           │ next: nullptr   │
                                           └─────────────────┘

    NOTE: Addresses (0x1000, etc.) are illustrative. Actual addresses vary.
    */
    Node *y1 = new Node(arr[0], nullptr);
    Node *y2 = new Node(arr[1], nullptr);
    Node *y3 = new Node(arr[2], nullptr);
    Node *y4 = new Node(arr[3], nullptr);

    /*
    =========================================================================
    STEP 2: LINKING NODES - CREATING THE CHAIN
    =========================================================================

    What happens when we write: y1->next = y2;

    BREAKDOWN:
    ----------
    1. y1 contains address 0x1000 (address of first Node on heap)
    2. y1->next is equivalent to (*y1).next
       - First DEREFERENCE y1 to get the Node object
       - Then access its 'next' member
    3. y2 contains address 0x1020
    4. Assignment: Store 0x1020 into the 'next' field of Node at 0x1000

    ARROW OPERATOR (->):
    --------------------
    ptr->member  is syntactic sugar for  (*ptr).member

    - (*ptr) dereferences the pointer to get the object
    - .member accesses the member of that object

    MEMORY STATE AFTER LINKING:
    ---------------------------

        STACK                              HEAP
        ┌──────────────┐
        │ y1 [0x1000]  │───────────────────┌─────────────────┐
        │ y2 [0x1020]  │──────────┐        │ Node @ 0x1000   │
        │ y3 [0x1040]  │──────┐   │        │ data: 2         │
        │ y4 [0x1060]  │──┐   │   │        │ next: 0x1020 ───────┐
        └──────────────┘  │   │   │        └─────────────────┘   │
                          │   │   │                              │
                          │   │   │        ┌─────────────────┐   │
                          │   │   └────────│ Node @ 0x1020   │◄──┘
                          │   │            │ data: 5         │
                          │   │            │ next: 0x1040 ───────┐
                          │   │            └─────────────────┘   │
                          │   │                                  │
                          │   │            ┌─────────────────┐   │
                          │   └────────────│ Node @ 0x1040   │◄──┘
                          │                │ data: 8         │
                          │                │ next: 0x1060 ───────┐
                          │                └─────────────────┘   │
                          │                                      │
                          │                ┌─────────────────┐   │
                          └────────────────│ Node @ 0x1060   │◄──┘
                                           │ data: 7         │
                                           │ next: nullptr   │
                                           └─────────────────┘

    THE LINKED LIST IS NOW:
    -----------------------

    y1 ──► [2|•]──► [5|•]──► [8|•]──► [7|null]
           Node1    Node2    Node3    Node4

    */
    y1->next = y2;
    y2->next = y3;
    y3->next = y4;

    /*
    =========================================================================
    STEP 3: ACCESSING NODE DATA
    =========================================================================

    What happens when we write: y1->data

    1. y1 holds address 0x1000
    2. Go to memory location 0x1000
    3. Read the 'data' field (first 4 bytes) → value is 2

    What happens when we write: y1->next

    1. y1 holds address 0x1000
    2. Go to memory location 0x1000
    3. Read the 'next' field (bytes 4-11) → value is 0x1020
    4. This prints as a hexadecimal address

    TRAVERSAL CONCEPT:
    ------------------
    To traverse the entire list starting from y1:

    Node* current = y1;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;  // Move to next node
    }

    Step-by-step:
    - current = 0x1000 → data = 2 → next = 0x1020
    - current = 0x1020 → data = 5 → next = 0x1040
    - current = 0x1040 → data = 8 → next = 0x1060
    - current = 0x1060 → data = 7 → next = nullptr
    - current = nullptr → STOP

    =========================================================================
    IMPORTANT: MEMORY LEAK WARNING!
    =========================================================================

    This code has a MEMORY LEAK because we never call 'delete' on the nodes.

    When main() returns:
    - Stack variables (y1, y2, y3, y4) are automatically destroyed
    - BUT the heap memory they point to is NOT freed
    - Those 4 Node objects remain allocated until program ends

    PROPER CLEANUP:
    ---------------
    delete y4;  // Free node at 0x1060
    delete y3;  // Free node at 0x1040
    delete y2;  // Free node at 0x1020
    delete y1;  // Free node at 0x1000

    Or traverse and delete:
    while (y1 != nullptr) {
        Node* temp = y1;
        y1 = y1->next;
        delete temp;
    }

    =========================================================================
    */
    cout << y1->data << " " << y1->next << "\n";
    cout << y2->data << " " << y2->next << "\n";
    cout << y3->data << " " << y3->next << "\n";
    cout << y4->data << " " << y4->next << "\n";

    return 0;
}

/*
=============================================================================
                    SUMMARY: KEY TAKEAWAYS
=============================================================================

1. STACK vs HEAP:
   - Pointers (y1, y2, y3, y4) live on STACK
   - Actual Node objects live on HEAP (because of 'new')

2. POINTER ARITHMETIC:
   - y1         → Address stored in y1 (e.g., 0x1000)
   - *y1        → The Node object at that address
   - y1->data   → Same as (*y1).data, the data field
   - y1->next   → Same as (*y1).next, address of next node

3. LINKING:
   - Each node's 'next' pointer stores the ADDRESS of the next node
   - Last node's 'next' is nullptr (end of list)

4. WHY LINKED LISTS?
   - Dynamic size (can grow/shrink at runtime)
   - Efficient insertion/deletion at any position (O(1) if you have pointer)
   - No need to shift elements like arrays
   - Trade-off: No random access (must traverse from head)

=============================================================================
*/
/*
=============================================================================
                    MEMORY SIZE REFERENCE: 32-BIT vs 64-BIT SYSTEMS
=============================================================================

┌─────────────────┬──────────────────┬──────────────────┐
│   Data Type     │   32-bit System  │   64-bit System  │
├─────────────────┼──────────────────┼──────────────────┤
│   int           │     4 bytes      │     4 bytes      │
│   pointer (*)   │     4 bytes      │     8 bytes      │
│   Node struct   │   ~8 bytes       │   ~12-16 bytes   │
│                 │   (4 + 4)        │   (4 + 8 + pad)  │
└─────────────────┴──────────────────┴──────────────────┘

NOTE: Struct size may include padding for memory alignment.
      Use sizeof(Node) to get the exact size on your system.

=============================================================================
*/

/*
=============================================================================
                    ARRAY TO LINKED LIST CONVERSION
=============================================================================

This function converts a vector/array into a linked list.

APPROACH:
---------
1. Handle edge case: empty array returns nullptr
2. Create head node with first element
3. Iterate through remaining elements, creating nodes and linking them

TIME COMPLEXITY: O(n) - we visit each element once
SPACE COMPLEXITY: O(n) - we create n nodes on the heap

=============================================================================
*/

Node *arrayToLinkedList(vector<int> &arr)
{
    // Edge case: empty array
    if (arr.empty())
    {
        return nullptr;
    }

    // Create head node with first element
    Node *head = new Node(arr[0], nullptr);

    // Keep track of the last node to append new nodes
    Node *current = head;

    // Iterate through remaining elements
    for (int i = 1; i < arr.size(); i++)
    {
        // Create new node
        Node *newNode = new Node(arr[i], nullptr);

        // Link current node to new node
        current->next = newNode;

        // Move current pointer forward
        current = newNode;
    }

    return head;
}

/*
VISUAL EXAMPLE:
---------------
Input: arr = {2, 5, 8, 7}

Step 1: Create head
    head → [2|nullptr]

Step 2: Add 5
    head → [2|•] → [5|nullptr]

Step 3: Add 8
    head → [2|•] → [5|•] → [8|nullptr]

Step 4: Add 7
    head → [2|•] → [5|•] → [8|•] → [7|nullptr]

USAGE EXAMPLE:
--------------
    vector<int> arr = {2, 5, 8, 7};
    Node* head = arrayToLinkedList(arr);

    // Traverse and print
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;

    // Output: 2 -> 5 -> 8 -> 7 -> nullptr

=============================================================================
*/