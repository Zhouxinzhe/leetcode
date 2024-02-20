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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode(0);
    ListNode* pre = head;
    ListNode* p;
    while (list1 || list2)
    {
        if (!list1 || list2 && list1->val > list2->val) 
        {
            p = list2;
            list2 = list2->next;
        }
        else 
        {
            p = list1;
            list1 = list1->next;
        }
        pre->next = p;
        pre = pre->next;
    }
    ListNode* tmp = head;
    head = head->next;
    delete tmp;
    return head;
}

int main()
{
    ListNode* list1 = createListNode({1,2,4});
    ListNode* list2 = createListNode({1,2,5});
    ListNode* ans = mergeTwoLists(list1, list2);
    displayListNode(ans);
    deleteListNode(ans);
    return 0;
}