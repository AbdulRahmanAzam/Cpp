// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// using recursion
// class Solution {
// public:
//     int toGetLength(ListNode* head){
//         ListNode* temp = head;
//         int n = 0;
//         while(temp != NULL){
//             temp = temp -> next;
//             n++;
//         }
//         return n;
//     }

//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head == NULL)
//             return head;

//         int len = toGetLength(head);
//         if(k > len)
//             return head;

//         ListNode* nextn = NULL;
//         ListNode* curr  = head;
//         ListNode* prev = NULL;

//         int cnt = 0;
//         while(cnt < k){
//             nextn = curr -> next;
//             curr -> next = prev;
//             prev = curr;
//             curr = nextn;
//             cnt++;
//         }

//         if(nextn != NULL)
//             head -> next = reverseKGroup(nextn, k);

//         return prev;
//     }
// };

// without using recursion
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) 
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;
        ListNode* prev = &dummy;
        ListNode* next = NULL;

        int count = 0;

        // Count the number of nodes in the list
        while (curr -> next != NULL) {
            curr = curr->next;
            count++;
        }

        // While there are at least k nodes left to process
        while (count >= k) {
            curr = prev -> next; // The current node to process

            for (int i = 1; i < k; i++) { // Reverse the k nodes
                next = curr -> next;
                curr -> next = next -> next;
                next -> next = prev -> next;
                prev -> next = next;
            }

            prev = curr;
            count -= k; // Decrement count by k since we have processed k nodes
        }

        return dummy.next;
    }
};
