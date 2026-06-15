#include<iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int x)
    {
        val=x;
        next=NULL;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

int main()
{
    ListNode* head=new ListNode(1);
    ListNode* second=new ListNode(2);
    ListNode* third=new ListNode(3);
    ListNode* fourth=new ListNode(4);
    ListNode* fifth=new ListNode(5);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    Solution obj;
    ListNode* middle=obj.middleNode(head);
    cout<<"Middle Node: "<<middle->val<<endl;

    return 0;
}