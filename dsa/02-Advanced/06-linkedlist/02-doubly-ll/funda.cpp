// convert array to doubly linked list
class Solution
{
public:
    ListNode *arrayToDoublyLinkedList(vector<int> &arr)
    {
        if (arr.size() == 0)
        {
            return nullptr;
        }
        ListNode *head = new ListNode(arr[0]);
        ListNode *pre = head;
        for (int i = 1; i < arr.size(); i++)
        {
            ListNode *ele = new ListNode(arr[i]);
            ele->prev = pre;
            pre->next = ele;

            pre = ele;
        }
        return head;
    }
};

// delete head of doubly linked list
class Solution
{
public:
    ListNode *deleteHead(ListNode *&head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return head;
    }
};

// delete tail of doubly linked list
class Solution
{
public:
    ListNode *deleteTail(ListNode *&head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        ListNode *prev = temp->prev;
        prev->next = nullptr;
        delete temp;
        return head;
    }
};

// delete kth node of doubly linked list
class Solution
{
public:
    ListNode *deleteKthElement(ListNode *&head, int k)
    {
        if (head == nullptr || k <= 0)
            return head;

        // delete head (k == 1)
        if (k == 1)
        {
            ListNode *temp = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete temp;
            return head;
        }

        ListNode *temp = head;
        // move temp to (k-1)th node, or stop if list ends
        for (int i = 1; i < k - 1; i++)
        {
            temp = temp->next;
        }

        ListNode *ele = temp->next; // kth node
        temp->next = ele->next;     // bypass kth

        // if ele was not the tail, fix prev pointer of (k+1)th node
        if (ele->next != nullptr)
        {
            ele->next->prev = temp;
        }

        delete ele;
        return head;
    }
};
// Removing given node in Doubly Linked List

// Given a node's reference within a doubly linked list, remove that node from the linked list while preserving the list's integrity.

// You will only be given the node's reference, not the head of the list. It is guaranteed that the given node will not be the head of the list.

// Example 1

// Input: head = [1, 3, 5], node = 3

// Output: [1, 5]

// Explanation:

// The referenced node with value 3 was removed.

class Solution
{
public:
    void deleteGivenNode(ListNode *node)
    {

        ListNode *pre = node->prev;
        ListNode *next = node->next;
        pre->next = next;
        if (next)
        {
            next->prev = pre;
        }
        delete node;
        //     while (pre->prev) {
        //         pre = pre->prev;
        //     }
        //     return pre;
    }
};

// insert before head of doubly linked list
class Solution
{
public:
    ListNode *insertBeforeHead(ListNode *head, int X)
    {
        ListNode *ele = new ListNode(X, nullptr, head);
        if (head == nullptr)
            return ele;
        head->prev = ele;
        head = ele;
        return ele;
    }
};

// insert node before tail of doubly linked list
class Solution
{
public:
    ListNode *insertBeforeTail(ListNode *head, int X)
    {
        ListNode *ele = new ListNode(X);
        if (!head)
        {
            return ele;
        }

        ListNode *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }

        // temp is tail

        // Case: only one node in list (head == tail)
        if (temp->prev == nullptr)
        {
            ele->next = head;
            head->prev = ele;
            return ele; // new head
        }

        // General case: more than one node
        ele->next = temp;
        ele->prev = temp->prev;
        temp->prev->next = ele;
        temp->prev = ele;

        return head;
    }
};

// insert node before kth node of doubly linked list
class Solution
{
public:
    ListNode *insertBeforeKthPosition(ListNode *head, int X, int K)
    {
        ListNode *ele = new ListNode(X);
        ListNode *temp = head;
        if (K == 1)
        {
            ele->next = temp;
            temp->prev = ele;
            head = ele;
            return ele;
        }
        for (int i = 1; i <= K - 1; i++)
        {
            temp = temp->next;
        }
        ele->next = temp;
        ele->prev = temp->prev;
        temp->prev->next = ele;
        temp->prev = ele;
        return head;
    }
};

// insert before given node of doubly linked list
class Solution
{
public:
    void insertBeforeGivenNode(ListNode *node, int X)
    {
        ListNode *ele = new ListNode(X);
        ele->next = node;
        ele->prev = node->prev;
        if (node->prev)
        {
            node->prev->next = ele;
        }
        node->prev = ele;
    }
};