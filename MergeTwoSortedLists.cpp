/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        //in l1
        if(l1==NULL) 
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *result,*aux,*ret;
        if(l1->val < l2->val){
                aux = l1;
                l1 = l1->next;
                result = new ListNode(aux->val);
                //delete aux;
            }
            else{
                aux = l2;
                l2 = l2->next;
                result = new ListNode(aux->val);
               //delete aux; 
            }
          //  return result;
        ret = result;
        while(l1 !=NULL && l2!=NULL){
            if(l1->val <l2->val){
                aux = l1;
                l1 = l1->next;
                result->next = new ListNode(aux->val);
                result = result->next;
            }
             else{
                aux = l2;
                l2 = l2->next;
                result -> next = new ListNode(aux->val);
                result = result->next;
                delete aux; 
            }
        }
        if (l1!=NULL){
            result->next = l1;
        }
        if (l2!=NULL){
            result->next = l2;
        }
        return ret;
    }
};
