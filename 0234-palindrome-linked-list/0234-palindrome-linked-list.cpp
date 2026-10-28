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
    ListNode *reverse(ListNode *head){
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while(curr != nullptr){
            ListNode *temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return true;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *first = head;
        while(fast -> next != nullptr && fast -> next -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *last = reverse(slow -> next);
        while(last != nullptr){
            if(first-> val != last -> val){
                slow -> next = reverse(slow -> next);
                return false;
            }
            first = first -> next;
            last = last -> next;
        }
        slow -> next = reverse(slow -> next);
        return true;
    }
};