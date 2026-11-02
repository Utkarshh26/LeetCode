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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* temp = head;
        while (temp!= nullptr) {
            if(temp->val == val){
                prev->next=temp->next;
                ListNode* ele = temp;
                temp = temp->next;
                delete ele;
            }else {
                prev = temp;
                temp = temp->next;
            }
        }
        return dummy.next;
    }
};