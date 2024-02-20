#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createListNode(vector<int> nums);
void displayListNode(ListNode* head);


ListNode* createListNode(vector<int> nums)
{
    ListNode* head = new ListNode(-1);
    ListNode* p = head;
    for(int num: nums)
    {
        p->next = new ListNode(num);
        p = p->next;
    }
    p->next = nullptr;
    ListNode* tmp = head;
    head = head->next;
    delete tmp;
    return head;
}

void displayListNode(ListNode* head)
{
    while (head)
    {
        cout<<head->val<<' ';
        head = head->next;
    }
    cout<<endl;
}

void deleteListNode(ListNode* head)
{
    ListNode* tmp;
    while(head)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *p1 = new ListNode(0, head);
    ListNode *p2 = p1, *p3 = nullptr;
    ListNode *ans = p1;

    for (int i = 0; i < k; i++)
    {
        if(p2) p2 = p2->next;
        else break;
        if(i == k-2) p3 = p2;
    }
    if(!p2) return head;
    while (p2)
    {
        for (int i = 0; i < k-1; i++)
        {
            p3->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p1->next;
            p2 = p3;
            p3 = p1;
            while(p3->next != p2) p3 = p3->next;
        }
        p1 = p2;
        for (int i = 0; i < k; i++)
        {
            if(p2) p2 = p2->next;
            else break;
            if(i == k-2) p3 = p2;
        }
    }
    return ans->next;
}

int main()
{
    ListNode* head = createListNode({1,2,3,4});
    displayListNode(head);
    ListNode* ans = reverseKGroup(head, 4);
    displayListNode(ans);
    deleteListNode(ans);
    return 0;
}