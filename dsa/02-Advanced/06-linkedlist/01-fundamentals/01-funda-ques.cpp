// traversal of linked list
//  Given the head of a singly Linked List. Traverse the entire Linked List and return its elements in an array in the order of their appearance.

// Example 1

// Input: linkedList = [5, 4, 3, 1, 0]

// Output: [5, 4, 3, 1, 0]

// Explanation:

// The nodes in the Linked List are 5 -> 4 -> 3 -> 1 -> 0, with the head pointing to node with value 5.

// Definition of singly linked list
class ListNode
{
public:
    int data;
    ListNode *next;
    // Constructor 1: No arguments - creates node with default values
    ListNode()
    {
        data = 0;
        next = nullptr;
    }

    // Constructor 2: One argument - creates node with given value
    ListNode(int x)
    {
        data = x;
        next = nullptr;
    }

    // Constructor 3: Two arguments - creates node with value and next pointer
    ListNode(int x, ListNode *nextNode)
    {
        data = x;
        next = nextNode;
    }
};

class Solution
{
public:
    // Function for Linked List Traversal
    vector<int> LLTraversal(ListNode *head)
    {
        // Storing a copy of the linked list
        ListNode *temp = head;
        // To store the values
        // Sequentially
        vector<int> ans;

        // Keep traversing
        // Until the nullptr
        // Is not encountered
        while (temp != nullptr)
        {
            // Storing of the values
            ans.push_back(temp->data);
            // Storing the address of the next node
            temp = temp->next;
        }
        // Return answer
        return ans;
    }
};

// Deletion of the head of LL

class Solution
{
public:
    ListNode *deleteHead(ListNode *&head)
    {
        // your code goes here
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};

// Deletion of the tail of LL
class Solution
{
public:
    ListNode *deleteTail(ListNode *&head)
    {
        ListNode *temp = head;
        if (!temp->next)
        {
            head = nullptr;
            delete temp;
            return head;
        }
        while (temp->next->next)
        {
            temp = temp->next;
        }
        ListNode *last = temp->next;
        temp->next = nullptr;
        delete last;
        return head;
    }
};

// Deletion of the kth node of LL
class Solution
{
public:
    ListNode *deleteKthNode(ListNode *&head, int k)
    {
        ListNode *temp = head;
        ListNode *mover = head;
        if (k == 1)
        {
            head = head->next;
            delete temp;
            return head;
        }
        for (int i = 1; i <= k - 1; i++)
        {
            temp = mover;
            mover = mover->next;
        }
        temp->next = mover->next;
        delete mover;
        return head;
    }
};

// deletion of the node having value X
class Solution
{
public:
    ListNode *deleteNodeWithValueX(ListNode *&head, int X)
    {
        // Handle empty list
        if (head == nullptr)
            return head;

        // Handle deletion of head
        if (head->data == X)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode *prev = head;
        ListNode *temp = head->next;

        // Traverse the rest of the list, including the last node
        while (temp != nullptr)
        {
            if (temp->data == X)
            {
                prev->next = temp->next;
                delete temp;
                break; // since at most one node has value X
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};

// insertion of a node at the beginning of LL
class Solution
{
public:
    ListNode *insertAtHead(ListNode *&head, int X)
    {
        ListNode *ele = new ListNode(X, head);

        head = ele;
        return head;
    }
};

// insertion of a node at the end of LL
class Solution
{
public:
    ListNode *insertAtTail(ListNode *&head, int X)
    {
        ListNode *ele = new ListNode(X);
        ListNode *mover = head;
        if (!head)
        {
            head = ele;
            return head;
        }
        while (mover->next)
        {
            mover = mover->next;
        }
        mover->next = ele;
        return head;
    }
};

// insertion of a node at the kth position of LL
class Solution
{
public:
    ListNode *insertAtKthPosition(ListNode *&head, int X, int K)
    {
        ListNode *ele = new ListNode(X);
        ListNode *mover = head;
        ListNode *prev = head;
        if (K == 1)
        {
            ele->next = mover;
            head = ele;
            return head;
        }

        for (int i = 1; i <= K - 1; i++)
        {
            prev = mover;
            mover = mover->next;
        }
        ele->next = mover;
        prev->next = ele;
        return head;
    }
};

// Insertion before the value X in Linked List
class Solution
{
public:
    ListNode *insertBeforeX(ListNode *&head, int X, int val)
    {
        ListNode *ele = new ListNode(val);
        ListNode *mover = head;
        ListNode *prev = mover;
        if (head->data == X)
        {
            ele->next = mover;
            head = ele;
            return head;
        }
        while (mover)
        {
            if (mover->data == X)
            {
                ele->next = mover;
                prev->next = ele;
                return head;
            }
            prev = mover;
            mover = mover->next;
        }
        return head;
    }
};