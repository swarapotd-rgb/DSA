/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddhead = new ListNode(-1), *oddtail = oddhead;
        ListNode *evenhead = new ListNode(-1), *eventail = evenhead;
        ListNode *curr = head, *temp;
        int pos = 1;
        while(curr)
        {
            temp = curr;
            curr=curr->next;
            temp->next=nullptr;
            
            if(pos %2 == 1)
            {
                oddtail->next = temp;
                oddtail = temp;
            }
            else
            {
                eventail->next = temp;
                eventail = temp;
            }
            pos++;
        }

    oddtail->next=evenhead->next;
    return oddhead->next;
        
    }
    
};