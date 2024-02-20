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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p1 = head;
    ListNode* p2 = head;
    for (int i = 0; i < n; i++) p2 = p2->next;
    ListNode* front = new ListNode(-1, head);
    ListNode* tmp = front;
    while(p2)
    {
        front = front->next;
        p1 = p1->next;
        p2 = p2->next;
    }
    front->next = p1->next;
    delete p1;
    head = tmp->next;
    delete tmp;
    return head;
}

int main()
{
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = createListNode(nums);
    int n = 5;
    displayListNode(head);
    head = removeNthFromEnd(head, n);
    displayListNode(head);
    deleteListNode(head);
    return 0;
}