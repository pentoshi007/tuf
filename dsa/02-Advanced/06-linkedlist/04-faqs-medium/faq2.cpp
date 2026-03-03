// Find the intersection point of Y LL

// Given the heads of two linked lists A and B, containing positive integers.
// Find the node at which the two linked lists intersect. If they do intersect,
// return the node at which the intersection begins, otherwise return null.

// The Linked List will not contain any cycles. The linked lists must retain
// their original structure, given as per the input, after the function returns.

// Note: for custom input, the following parameters are required(your program is
// not provided with these parameters):

// intersectVal - The value of the node where the intersection occurs. This is
// -1 if there is no intersected node. skipA - The number of nodes to skip ahead
// in listA (starting from the head) to get to the intersected node(-1 if no
// intersection). skipB - The number of nodes to skip ahead in listB (starting
// from the head) to get to the intersected node(-1 if no intersection). listA -
// The first linked list. listB - The second linked list.

// brute force
class Solution
{
public:
  // Function to find the intersection node of two linked lists
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    // Create a hash set to store the nodes
    // Of the first list
    unordered_set<ListNode *> nodes_set;

    // Traverse the first linked list
    // And add all its nodes to the set
    while (headA != NULL)
    {
      nodes_set.insert(headA);
      headA = headA->next;
    }

    // Traverse the second linked list
    // And check for intersection
    while (headB != NULL)
    {
      // If a node from the second list is found in the set,
      // It means there is an intersection
      if (nodes_set.find(headB) != nodes_set.end())
      {
        return headB;
      }
      headB = headB->next;
    }

    // No intersection found, return NULL
    return NULL;
  }
};

// Utility function to insert a node at the end of the linked list
void insertNode(ListNode *&head, int val)
{
  // Create a new node with the given value
  ListNode *newNode = new ListNode(val);

  // If the list is empty, set the new node as the head
  if (head == NULL)
  {
    head = newNode;
    return;
  }

  // Otherwise, traverse to the end of the list
  ListNode *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  // Insert the new node at the end of the list
  temp->next = newNode;
}

// better
class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;
    int n1 = 0, n2 = 0;

    // Get the length of first linked list
    while (temp1 != NULL)
    {
      n1++;
      temp1 = temp1->next;
    }

    // Get the length of second linked list
    while (temp2 != NULL)
    {
      n2++;
      temp2 = temp2->next;
    }

    // Traverse the longer list and bring the pointers to same level
    if (n1 < n2)
      return collisionPoint(headA, headB, n2 - n1);

    // otherwise
    return collisionPoint(headB, headA, n1 - n2);
  }

private:
  // Function to get the collision point
  ListNode *collisionPoint(ListNode *smallerListHead, ListNode *longerListHead,
                           int len)
  {
    ListNode *temp1 = smallerListHead;
    ListNode *temp2 = longerListHead;

    // Adjust the pointers to same level
    for (int i = 0; i < len; i++)
      temp2 = temp2->next;

    while (temp1 != temp2)
    {
      temp1 = temp1->next;
      temp2 = temp2->next;
    }

    return temp1;
  }
};

// Utility function to insert a node at the end of the linked list
void insertNode(ListNode *&head, int val)
{
  // Create a new node with the given value
  ListNode *newNode = new ListNode(val);
  // If the list is empty, set the new node as the head
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  // Otherwise, traverse to the end of the list
  ListNode *temp = head;
  while (temp->next != NULL)
    temp = temp->next;
  // Insert the new node at the end of the list
  temp->next = newNode;
}
// optimal
class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    if (!headA || !headB)
      return headA;

    ListNode *t1 = headA;
    ListNode *t2 = headB;

    while (t1 != t2)
    {
      t1 = t1->next;
      t2 = t2->next;

      if (t1 == t2)
        return t1;
      if (t1 == nullptr)
      {
        t1 = headB;
      }
      if (t2 == nullptr)
      {
        t2 = headA;
      }
    }
    return t1;
  }
};

// detect a loop in a linkedlist
// brute force
class Solution
{
public:
  // Function to detect a loop in the linked list
  bool hasCycle(ListNode *head)
  {
    // Initialize a pointer 'temp'
    // At the head of the linked list
    ListNode *temp = head;

    // Create a set to keep track of
    // Encountered nodes
    std::unordered_set<ListNode *> nodeSet;

    // Traverse the linked list
    while (temp != nullptr)
    {
      // If the node is already in the
      // Set, there is a loop
      if (nodeSet.find(temp) != nodeSet.end())
      {
        return true;
      }
      // Store the current node
      // In the set
      nodeSet.insert(temp);

      // Move to the next node
      temp = temp->next;
    }

    // If the list is successfully traversed
    // Without a loop, return false
    return false;
  }
};
// optimal
class Solution
{
public:
  // Function to detect a loop in a linked
  // list using the Tortoise and Hare Algorithm
  bool hasCycle(ListNode *head)
  {
    // Initialize two pointers, slow and fast,
    // to the head of the linked list
    ListNode *slow = head;
    ListNode *fast = head;

    // Step 2: Traverse the linked list with
    // the slow and fast pointers
    while (fast != nullptr && fast->next != nullptr)
    {
      // Move slow one step
      slow = slow->next;
      // Move fast two steps
      fast = fast->next->next;

      // Check if slow and fast pointers meet
      if (slow == fast)
      {
        return true; // Loop detected
      }
    }

    // If fast reaches the end of the list,
    // there is no loop
    return false;
  }
};

// Find the starting point in LL
//  brute force
class Solution
{
public:
  // Function to find the starting point of the loop
  // in a linked list using hashing technique
  ListNode *findStartingPoint(ListNode *head)
  {
    // Use temp to traverse the linked list
    ListNode *temp = head;

    // hashmap to store all visited nodes
    std::unordered_map<ListNode *, int> mp;

    // Traverse the list using temp
    while (temp != nullptr)
    {
      // Check if temp has been encountered again
      if (mp.count(temp) != 0)
      {
        // A loop is detected hence return temp
        return temp;
      }
      // Store temp as visited
      mp[temp] = 1;
      // Move to the next node
      temp = temp->next;
    }

    // If no loop is detected, return nullptr
    return nullptr;
  }
};

// optimal
class Solution
{
public:
  // Function to find the first node
  // Of the loop in a linked list
  ListNode *findStartingPoint(ListNode *head)
  {
    // Initialize a slow and fast
    // Pointers to the head of the list
    ListNode *slow = head;
    ListNode *fast = head;

    // Phase 1: Detect the loop
    while (fast != NULL && fast->next != NULL)
    {

      // Move slow one step
      slow = slow->next;

      // Move fast two steps
      fast = fast->next->next;

      // If slow and fast meet,
      // a loop is detected
      if (slow == fast)
      {

        // Reset the slow pointer
        // To the head of the list
        slow = head;

        // Phase 2: Find the first node of the loop
        while (slow != fast)
        {

          // Move slow and fast one step
          // At a time
          slow = slow->next;
          fast = fast->next;

          // When slow and fast meet again,
          // It's the first node of the loop
        }

        // Return the first node of the loop
        return slow;
      }
    }

    // If no loop is found,
    // Return NULL
    return NULL;
  }
};

// Length of loop in LL
//  brute force
class Solution
{
public:
  // Function to find length
  int findLengthOfLoop(ListNode *head)
  {
    // Hashmap to store visited nodes and their timer values
    unordered_map<ListNode *, int> visitedNodes;

    // Initialize pointer to traverse the linked list
    ListNode *temp = head;

    // Initialize timer
    // to track visited nodes
    int timer = 0;

    // Traverse the linked list
    // till temp reaches nullptr
    while (temp != NULL)
    {
      // If revisiting a node return difference of timer values
      if (visitedNodes.find(temp) != visitedNodes.end())
      {
        // Calculate the length of the loop
        int loopLength = timer - visitedNodes[temp];

        // Return length of loop
        return loopLength;
      }
      /* Store the current node
      and its timer value in
      the hashmap */
      visitedNodes[temp] = timer;

      // Move to the next node
      temp = temp->next;

      // Increment the timer
      timer++;
    }

    /** If traversal is completed
     * and we reach the end
     * of the list (null)
     * means there is no loop */
    return 0;
  }
};
// optimal
class Solution
{
public:
  // Function to find the length of the loop
  int findLength(ListNode *slow, ListNode *fast)
  {
    // Count to keep track of nodes encountered in loop
    int cnt = 1;

    // Move fast by one step
    fast = fast->next;

    // Traverse fast till it reaches back to slow
    while (slow != fast)
    {
      /* At each node
      increase count by 1
      move fast forward
      by one step */
      cnt++;
      fast = fast->next;
    }

    /* Loop terminates
    when fast reaches slow again
    and the count is returned*/
    return cnt;
  }

  // Function to find the length of the loop
  int findLengthOfLoop(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;

    // Traverse the list to detect a loop
    while (fast != nullptr && fast->next != nullptr)
    {
      // Move slow one step
      slow = slow->next;
      // Move fast two steps
      fast = fast->next->next;

      // If the slow and fast pointers meet
      // there is a loop
      if (slow == fast)
      {
        // return the number of nodes
        return findLength(slow, fast);
      }
    }

    /*If the fast pointer
    reaches the end,
    there is no loop*/
    return 0;
  }
};