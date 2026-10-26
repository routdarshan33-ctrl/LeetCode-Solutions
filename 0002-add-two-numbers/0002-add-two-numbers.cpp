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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* curr = temp;
        int d = 0;
        while(l1 != nullptr || l2 != nullptr || d != 0){
            int sum = d;
            if(l1 != nullptr){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != nullptr){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            int e = sum % 10;
            d = sum / 10;
            curr -> next = new ListNode(e);
            curr = curr -> next;
        }
        return temp -> next;
    }
};