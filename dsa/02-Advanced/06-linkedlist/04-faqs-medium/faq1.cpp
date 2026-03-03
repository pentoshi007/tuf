// Add one to a number represented by LL
// iterative brute force
class Solution
{
public:
  // Function to reverse the linked list
  ListNode *reverseList(ListNode *head)
  {
    // Initialize pointers
    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *next = NULL;

    while (current != NULL)
    {
      // Store next node
      next = current->next;
      // Reverse the link
      current->next = prev;
      // Move prev to current
      prev = current;
      // Move current to next
      current = next;
    }

    return prev;
  }
  // Function to add one to Linked List
  ListNode *addOne(ListNode *head)
  {
    // Reverse the linked list
    head = reverseList(head);

    // Create a dummy node
    ListNode *current = head;
    // Initialize carry with 1
    int carry = 1;

    while (current != NULL)
    {
      /*Sum the current node's value
      and the carry*/
      int sum = current->val + carry;
      // Update carry
      carry = sum / 10;
      // Update the node's value
      current->val = sum % 10;

      /*If no carry left
      break the loop*/
      if (carry == 0)
      {
        break;
      }

      /*If we've reached the end of the list
      there's still a carry,
      add a new node with the carry value*/
      if (current->next == NULL && carry != 0)
      {
        current->next = new ListNode(carry);
        break;
      }

      // Move to the next node
      current = current->next;
    }

    // Reverse the list
    head = reverseList(head);

    // New head
    return head;
  }
};

// optimal recursion+backtracking
class Solution
{
private:
  int helper(ListNode *head)
  {
    if (!head)
      return 1;
    int carry = helper(head->next);
    if ((head->val + carry) >= 10)
    {
      head->val = 0;
      return 1;
    }
    else
    {
      head->val += carry;
      return 0;
    }
  }

public:
  ListNode *addOne(ListNode *head)
  {
    int carry = helper(head);
    if (carry == 1)
    {
      ListNode *el = new ListNode(carry, head);
      head = el;
    }
    return head;
  }
};
// Find Middle of Linked List
// brute force
class Solution
{
public:
  // Function to get the middle node of linked list
  ListNode *middleOfLinkedList(ListNode *head)
  {
    ListNode *temp = head;
    int count = 0;

    // Traverse the linked list
    while (temp != NULL)
    {
      count += 1; // Increment the count by one
      temp = temp->next;
    }

    int midPosition = (count) / 2 + 1;

    ListNode *middleNode = head;
    for (int i = 1; i < midPosition; i++)
    {
      middleNode = middleNode->next;
    }

    return middleNode;
  }
};

// optimal
class Solution
{
public:
  ListNode *middleOfLinkedList(ListNode *head)
  {
    ListNode *fastp = head;
    ListNode *slowp = head;
    while (fastp && fastp->next)
    {
      slowp = slowp->next;
      fastp = fastp->next->next;
    }
    return slowp;
  }
};

// Delete the middle node in LL
// brute force
class Solution
{
public:
  // Function to delete middle node of linked list
  ListNode *deleteMiddle(ListNode *head)
  {
    /* Edge case: if the list is empty
     * or has only one node, return null */
    if (head == nullptr || head->next == nullptr)
    {
      delete head;
      return nullptr;
    }

    // Temporary node to traverse
    ListNode *temp = head;

    // Variable to store number of nodes
    int n = 0;

    /* Loop to count the number of nodes
    in the linked list */
    while (temp != nullptr)
    {
      n++;
      temp = temp->next;
    }

    // Index of the middle node
    int middleIndex = n / 2;

    // Reset temporary node
    // to beginning of linked list
    temp = head;

    /* Loop to find the node
    just before the middle node */
    for (int i = 1; i < middleIndex; i++)
    {
      temp = temp->next;
    }

    // If the middle node is found
    if (temp->next != nullptr)
    {
      // Create pointer to the middle node
      ListNode *middle = temp->next;

      // Adjust pointers to skip middle node
      temp->next = temp->next->next;

      /* Free the memory allocated
       * to the middle node */
      delete middle;
    }

    // Return head
    return head;
  }
};

// optimal
class Solution
{
public:
  ListNode *deleteMiddle(ListNode *head)
  {
    if (!head || !head->next)
      return nullptr;
    ListNode *slowp = head;
    ListNode *fastp = head->next->next;
    while (fastp && fastp->next)
    {
      slowp = slowp->next;
      fastp = fastp->next->next;
    }
    ListNode *temp = slowp->next;
    slowp->next = temp->next;
    delete temp;
    return head;
  }
};

// Check if LL is palindrome or not
// brute force approach:using stack
class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    /*Create an empty stack
    to store values*/
    stack<int> st;

    /*Initialize temporary pointer
    to the head of the linked list*/
    ListNode *temp = head;

    /*Traverse the linked list
    and push values onto the stack*/
    while (temp != NULL)
    {
      /*Push the data from
      the current node onto the stack*/
      st.push(temp->val);

      // Move to the next node
      temp = temp->next;
    }

    /*Reset temporary pointer
    back to the head of
    the linked list*/
    temp = head;

    /*Compare values by popping
    from the stack and checking
    \against linked list nodes*/
    while (temp != NULL)
    {
      if (temp->val != st.top())
      {
        /*If values don't match,
        it's not a palindrome*/
        return false;
      }

      // Pop the value
      st.pop();

      /*Move to the next node
      in the linked list*/
      temp = temp->next;
    }

    /*If all values match,
    it's a palindrome*/
    return true;
  }
};

// optimal:
class Solution
{
private:
  ListNode *reverseLinkedList(ListNode *head)
  {
    if (!head || !head->next)
      return head; // we will get last node as
                   // head;

    ListNode *newHead = reverseLinkedList(head->next);
    ListNode *frontNode = head->next;
    frontNode->next = head;
    head->next = nullptr;
    return newHead;
  }

public:
  bool isPalindrome(ListNode *head)
  {
    /* Check if the linked list is empty
              or has only one node */
    if (head == NULL || head->next == NULL)
    {
      // It's a palindrome by definition
      return true;
    }

    /* Initialize two pointers, slow and fast,
       to find the middle of the linked list */
    ListNode *slow = head;
    ListNode *fast = head;

    /* Traverse the linked list using the
       slow and fast pointer approach to
       locate the middle node */
    while (fast->next != NULL && fast->next->next != NULL)
    {
      // Move slow pointer one step
      slow = slow->next;

      // Move fast pointer two steps
      fast = fast->next->next;
    }

    /* Reverse the second half of the linked list
       starting from the node after the middle */
    ListNode *newHead = reverseLinkedList(slow->next);

    // Pointer to the first half
    ListNode *first = head;

    // Pointer to the reversed second half
    ListNode *second = newHead;

    /* Compare nodes from both halves
       one by one to check for palindrome */
    while (second != NULL)
    {
      // If mismatch found, not a palindrome
      if (first->val != second->val)
      {
        // Restore the original list before returning
        reverseLinkedList(newHead);

        return false;
      }

      // Move both pointers one step ahead
      first = first->next;
      second = second->next;
    }

    /* Restore the second half of the linked list
       to its original order */
    reverseLinkedList(newHead);

    // All values matched, it's a palindrome
    return true;
  }
};
