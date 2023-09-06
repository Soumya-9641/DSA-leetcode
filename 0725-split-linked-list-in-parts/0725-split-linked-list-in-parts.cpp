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
    
    int getLength(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length= getLength(head);
        int listPart= length/k;
        int extraPart= length%k;
        ListNode *curr=head,*prev=NULL;
        vector<ListNode*>ans;
        while(head){
            int eachPart= listPart;
            ans.push_back(curr);
            while(eachPart>0){
                prev=curr;
                curr=curr->next;
                eachPart--;
                
            }
            if(extraPart!=0 && curr!=NULL){
                extraPart--;
                prev=curr;
                curr=curr->next;
            }
            if(prev!=NULL){
                head=curr;
                prev->next=NULL;
            }
            
        }
        while(ans.size()!=k){
            ans.push_back(NULL);
        }
        return ans;
    }
};