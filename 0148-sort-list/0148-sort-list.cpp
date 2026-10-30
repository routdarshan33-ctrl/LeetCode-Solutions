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
    ListNode *merge(ListNode* slow, ListNode* fast){
        ListNode *temp = new ListNode(0);
        ListNode *ptr = temp;
        while(slow != nullptr && fast != nullptr){
            if(slow -> val <= fast -> val){
                temp -> next = slow;
                slow = slow -> next;
            }
            else{
                temp -> next = fast;
                fast = fast -> next;
            }
            temp = temp -> next;
        }
        if(slow != nullptr) temp -> next = slow;
        if(fast != nullptr) temp -> next = fast;
        return ptr -> next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while(fast != nullptr && fast -> next != nullptr){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        return merge(left, right);
    }
};