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

ListNode* swapPairs(ListNode* head) {
    ListNode *p1 = new ListNode(0, head);
    ListNode *p2 = nullptr, *p3 = nullptr;
    ListNode *ans = p1;
    if(p1) p2 = p1->next;
    if(p2) p3 = p2->next;
    while (p3)
    {
        p1->next = p3;
        p2->next = p3->next;
        p3->next = p2;
        p1 = p2;
        p2 = p1?p1->next:nullptr;
        p3 = p2?p2->next:nullptr;
    }
    return ans->next;
}

int main()
{
    ListNode* head = createListNode({1,2,3,4});
    displayListNode(head);
    ListNode* ans = swapPairs(head);
    displayListNode(ans);
    deleteListNode(ans);
    return 0;
}