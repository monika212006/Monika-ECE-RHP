**
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
        if(k==0 || head==NULL || head->next==NULL){
            return head;
        }
        int n=1;
        ListNode* tail=head;
        while(tail->next!=NULL){
            n++;
            tail=tail->next;
        }
        k=k%n;
        if(k==0){
            return head;
        }
        int steps=n-k;
        tail->next=head;
        ListNode* newtail=head;
        for(int i=1;i<steps;i++){
            newtail=newtail->next;
        }
        ListNode* newhead=newtail->next;
        newtail->next=NULL;
        return newhead;

        
    }
};
