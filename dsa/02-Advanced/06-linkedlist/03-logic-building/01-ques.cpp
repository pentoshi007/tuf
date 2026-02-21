// add two numbers represented by linked list
// Given two non-empty linked lists linkedList1 and linkedList2 which represent
// two non-negative integers.

// The digits are stored in reverse order with each node storing one digit.

// Add two numbers and return the sum as a linked list.

// The sum Linked List will be in reverse order as well.

// The Two given Linked Lists represent numbers without any leading zeros,
// except when the number is zero itself.

// Example 1

// Input: linkedList1 = [5, 4], linkedList2 = [4]

// Output: [9, 4]

// Explanation: linkedList1 = 45, linkedList2 = 4.

// linkedList1 + linkedList2 = 45 + 4 = 49.

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    int carry = 0;

    while (l1 || l2 || carry)
    {
      int x = l1 ? l1->data : 0;
      int y = l2 ? l2->data : 0;

      int sum = x + y + carry;
      carry = sum / 10;
      int digit = sum % 10;

      tail->next = new ListNode(digit);
      tail = tail->next;

      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }

    return dummy.next;
  }
};

// segregate odd and even nodes in linked list
// brue:
class Solution
{
public:
  ListNode *oddEvenList(ListNode *&head)
  {
    ListNode *temp = head;
    if (!head || !head->next)
      return head;

    vector<int> list;

    while (temp)
    {
      list.push_back(temp->data);

      if (temp->next)
      {
        temp = temp->next->next;
      }
      else
      {
        break;
      };
    }
    temp = head->next;
    while (temp)
    {
      list.push_back(temp->data);
      if (temp->next)
      {
        temp = temp->next->next;
      }
      else
      {
        break;
      };
    }
    temp = head;
    for (int j = 0; j < list.size(); j++)
    {
      temp->data = list[j];
      temp = temp->next;
    }
    return head;
  }
};

// optimal:
class Solution
{
public:
  ListNode *oddEvenList(ListNode *&head)
  {
    if (!head || !head->next)
      return head;

    ListNode *oddTemp = head;        // odd
    ListNode *evenTemp = head->next; // even
    ListNode *evenHead = evenTemp;   // first even

    // Safe loop condition
    while (evenTemp && evenTemp->next)
    {
      oddTemp->next = oddTemp->next->next;
      evenTemp->next = evenTemp->next->next;
      oddTemp = oddTemp->next;
      evenTemp = evenTemp->next;
    }

    oddTemp->next = evenHead;
    return head;
  }
};

// Sort a Linked List of 0's 1's and 2's
// brute force approach
class Solution
{
public:
  // Function to sort the linked list
  ListNode *sortList(ListNode *head)
  {
    // Initialize counts
    int c0 = 0, c1 = 0, c2 = 0;
    ListNode *temp = head;

    /* Count the number of 0s,
    1s, and 2s in the list*/
    while (temp != NULL)
    {
      if (temp->data == 0)
        c0++;
      else if (temp->data == 1)
        c1++;
      else if (temp->data == 2)
        c2++;
      temp = temp->next;
    }

    temp = head;

    /* Reassign values to
    the nodes based on
    the counts*/
    while (temp != NULL)
    {
      if (c0 > 0)
      {
        temp->data = 0;
        c0--;
      }
      else if (c1 > 0)
      {
        temp->data = 1;
        c1--;
      }
      else if (c2 > 0)
      {
        temp->data = 2;
        c2--;
      }
      temp = temp->next;
    }

    return head;
  }
};
// optimal:
class Solution
{
public:
  ListNode *sortList(ListNode *&head)
  {
    if (!head || !head->next)
      return head;
    ListNode *zeroHead = new ListNode(-1);
    ListNode *zero = zeroHead;
    ListNode *oneHead = new ListNode(-1);
    ListNode *one = oneHead;
    ListNode *twoHead = new ListNode(-1);
    ListNode *two = twoHead;
    ListNode *temp = head;

    while (temp)
    {
      if (temp->data == 0)
      {
        zero->next = temp;
        zero = zero->next;
      }
      else if (temp->data == 1)
      {
        one->next = temp;
        one = one->next;
      }
      else
      {
        two->next = temp;
        two = two->next;
      }
      temp = temp->next;
    }
    if (oneHead->next)
    {
      zero->next = oneHead->next;
    }
    else
    {
      zero->next = twoHead->next;
    }
    one->next = twoHead->next;
    head = zeroHead->next;
    two->next = nullptr;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
  };
};

// delete nth node from end of linked list
// brute force approach
class Solution
{
public:
  // Function to remove the nth node from end
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    if (head == NULL)
    {
      return NULL;
    }
    int cnt = 0;
    ListNode *temp = head;

    // Count the number of nodes
    while (temp != NULL)
    {
      cnt++;
      temp = temp->next;
    }

    /*If N equals
    the total number of nodes
    delete the head*/
    if (cnt == n)
    {
      ListNode *newhead = head->next;
      delete (head);
      return newhead;
    }

    /* Calculate the position
     of the node to delete (res)*/
    int res = cnt - n;
    temp = head;

    /*Traverse to the node
    just before the one to delete*/
    while (temp != NULL)
    {
      res--;
      if (res == 0)
      {
        break;
      }
      temp = temp->next;
    }

    // Delete the Nth node from the end
    ListNode *delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
  }
};

// optimal approach
class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *fastp = head;
    ListNode *slowp = head;
    for (int i = 0; i < n; i++)
    {
      // run till n times, fastp will be at n+1, if n==listnode length,
      // fastp==NULL
      fastp = fastp->next;
    }
    if (fastp == NULL)
    {
      return head->next;
    }
    while (fastp->next)
    {
      fastp = fastp->next;
      slowp = slowp->next;
    }
    // now fastp will be at the last element of the node, and slowp will be
    // just before the node to be deleted
    ListNode *delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
  }
};
// reverse a linked list
// iterative approach:1- store in stack and then pop and add to new list
// iterative approach:2- 3 pointers, prev, curr, next
class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    if (!head || !head->next)
    {
      return head;
    }
    ListNode *nextEl = head->next;
    ListNode *current = head;
    ListNode *prev = nullptr;

    while (current)
    {
      current->next = prev;
      prev = current;
      current = nextEl;
      if (nextEl)
      {
        nextEl = nextEl->next;
      }
      else
      {
        break;
      }
    }
    head = prev;
    return head;
  }
};

// recursive approach:
class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    if (!head || !head->next)
    {
      return head;
    }
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }
};