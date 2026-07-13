/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int length(ListNode* temp){
        int len =0;
        while(temp){
            len++;
            temp =temp->next;
        }
        return len;
    }  
    ListNode* commonNode(ListNode* tempA, ListNode* tempB, int dis){
        while(dis){
            dis--;
            tempA = tempA -> next;
        }
        while(tempA != tempB){
            tempA =tempA ->next;
            tempB =tempB -> next;
        }
        return tempA;
    }  
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = length(headA);
        int len2 = length(headB);
        if(len1 > len2){
            return commonNode(headA, headB, len1-len2);
        }else{
            return commonNode(headB,headA,len2-len1);
        }
        return nullptr;
    }
};