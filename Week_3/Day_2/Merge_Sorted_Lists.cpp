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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                temp->next = list1;
                list1=list1->next;
            }
            else
            {
                temp->next = list2;
                list2=list2->next;
            }
            temp = temp->next;
        }
        if(list1 != NULL)
        {
            temp->next = list1;
        }
        else
        {
            temp->next = list2;
        }
    return dummy->next;
    }
};

void printlist(ListNode* head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    ListNode* list1=new ListNode(1);
    list1->next=new ListNode(2);
    list1->next->next=new ListNode(5);
    
    ListNode* list2=new ListNode(1);
    list2->next=new ListNode(3);
    list2->next->next=new ListNode(4);

    Solution obj;
    ListNode* merged=obj.mergeTwoLists(list1,list2);

    cout<<"Merged List:";
    printlist(merged);

    return 0;

}