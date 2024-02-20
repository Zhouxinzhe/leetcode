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

int minList(vector<ListNode*>& lists)
{
    int minlist = -1;
    for (int i = 0; i < lists.size(); i++)
    {
        if(!lists[i]) continue;
        if(minlist == -1 || lists[i]->val < lists[minlist]->val) minlist = i;   
    }
    return minlist;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = new ListNode(0);
    ListNode* pre = head;
    int t;
    while (true)
    {
        t = minList(lists);
        if(t == -1) break;
        pre->next = lists[t];
        pre = pre->next;
        lists[t] = lists[t]->next;
    }
    ListNode* tmp = head;
    head = head->next;
    delete tmp;
    return head;
}

int main()
{
    ListNode* list1 = createListNode({1,4,5});
    ListNode* list2 = createListNode({1,3,4});
    ListNode* list3 = createListNode({2,6});
    vector<ListNode*> lists = {list1, list2, list3};
    //for(ListNode* list: lists) displayListNode(list);
    ListNode* ans = mergeKLists(lists);
    displayListNode(ans);
    return 0;
}