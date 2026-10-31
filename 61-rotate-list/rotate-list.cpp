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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp =head; int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        if(len ==0){
            return head;
        }
        k=k%len;
        if(k ==0){
            return head;
        }

        int skip =len-k;
        temp =head;
        while(skip){
            skip--;
            if(skip ==0){
                ListNode* newhead = temp->next;
                ListNode* tail = temp->next;
                while(tail ->next !=nullptr){
                    tail=tail->next;
                }
                tail->next =head;
                temp ->next =nullptr;
                return newhead;
            }
            temp=temp->next;
        }
        return head;
    }
};