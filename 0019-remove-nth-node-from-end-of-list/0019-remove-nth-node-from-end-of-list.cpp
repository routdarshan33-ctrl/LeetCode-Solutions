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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr){
            temp = temp -> next;
            count ++;
        }
        temp = head;
        if(count == n){
            ListNode* ptr = head;
            head = head -> next;
            delete ptr;
            return head;
        }
        int i = 1;
        while(temp != nullptr && i < count - n){
            temp = temp -> next;
            i ++;
        }
        if(temp == nullptr) return head;
        ListNode* curr = temp -> next;
        temp -> next = curr -> next;
        delete curr;
        return head;
    }
};