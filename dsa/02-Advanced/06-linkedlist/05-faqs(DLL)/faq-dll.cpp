// Delete all occurrences of a key in DLL
class Solution
{
public:
    ListNode *deleteAllOccurrences(ListNode *head, int target)
    {
        ListNode *temp = head;
        ListNode *prevNode;
        ListNode *nextNode;

        while (temp)
        {
            if (temp->val == target)
            {
                if (temp == head)
                {
                    head = head->next;
                }

                prevNode = temp->prev;
                nextNode = temp->next;
                if (prevNode)
                {
                    prevNode->next = nextNode;
                }
                if (nextNode)
                {
                    nextNode->prev = prevNode;
                }

                delete temp;
                temp = nextNode;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};

// Remove duplicated from sorted DLL
class Solution
{
public:
    ListNode *removeDuplicates(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *nextNode;

        while (temp && temp->next)
        {
            nextNode = temp->next;
            while (nextNode && nextNode->val == temp->val)
            {
                ListNode *el = nextNode;
                nextNode = nextNode->next;
                delete el;
            }
            temp->next = nextNode;
            if (nextNode)
            {
                nextNode->prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};