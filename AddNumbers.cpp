tion for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
       
       int rez, t = 0;
       ListNode * result = l1;
       
       while ( l1->next != NULL && l2->next != NULL ){
           rez = t + l1->val + l2->val;
           t = rez / 10;
           rez = rez % 10;
           l1 -> val = rez;
           l1 = l1 -> next;
           l2 = l2 -> next;
       }
       
       if ( l1->next == NULL && l2->next == NULL ){
           if ( l1 != NULL && l2 != NULL ){
                rez = t + l1->val + l2->val;
                t = rez / 10;
                rez = rez % 10;
                l1 -> val = rez;
                if(t > 0 ){
                    l1->next = new ListNode(t);
                }
                return result;
            }
            if(l1!=NULL){
                rez = t + l1->val;
                t = rez / 10;
                rez = rez % 10;
                l1 -> val = rez;
                if(t > 0 ){
                    l1->next = new ListNode(t);
                }
                return result;
            }
            if(l2!=NULL){
                l1->next = l2->next;
            }
       }
       
       if ( l1->next == NULL){
            rez = t + l1->val + l2->val;
            t = rez / 10;
            rez = rez % 10;
            l1 -> val = rez;
            l1 -> next = l2->next;
            l1 = l1 -> next;
            while(l1 != NULL){
                rez = t + l1->val;
                t = rez / 10;
                rez = rez % 10;
                l1 -> val = rez;
                l1 = l1 -> next;
            }
       }
       return result;       
    }
};
