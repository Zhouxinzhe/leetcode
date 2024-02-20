#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ans = l1;
    int v1, v2, v, c = 0;
    while(true)
    {
        v1 = l1->val;
        v2 = l2->val;
        v = (v1 + v2 + c) % 10;
        c = (v1 + v2 + c - v) / 10;
        l1->val = v;
        if(l1->next && l2->next)
        {
            l1 = l1->next;
            l2 = l2->next;
        }
        else if(l1->next && !l2->next)
        {
            l1 = l1->next;
            l2->next = new ListNode(0);
            l2 = l2->next;
        }
        else if(!l1->next && l2->next)
        {
            l1->next = new ListNode(0);
            l1 = l1->next;
            l2 = l2->next;
        }
        else
        {
            if(c > 0) l1->next = new ListNode(c);
            break;
        }
    }
    return ans;
}

// official solution
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = nullptr, *tail = nullptr;
    int carry = 0;
    while (l1 || l2) {
        int n1 = l1 ? l1->val: 0;
        int n2 = l2 ? l2->val: 0;
        int sum = n1 + n2 + carry;
        if (!head) {
            head = tail = new ListNode(sum % 10);
        } else {
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        carry = sum / 10;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry > 0) {
        tail->next = new ListNode(carry);
    }
    return head;
}