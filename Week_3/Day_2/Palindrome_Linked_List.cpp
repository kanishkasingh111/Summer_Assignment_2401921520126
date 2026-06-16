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

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondHalf=reverseList(slow);
        ListNode* firstHalf=head;

        while(secondHalf!=NULL)
        {
            if(firstHalf->val!=secondHalf->val)
            return false;
            firstHalf=firstHalf->next;
            secondHalf=secondHalf->next;
        }
        return true;
    }
};

int main()
{
    ListNode* list1=new ListNode(1);
    list1->next=new ListNode(2);
    list1->next->next=new ListNode(2);
    list1->next->next->next=new ListNode(1);

    Solution obj;
    if(obj.isPalindrome(list1))
    cout<<"Palindrome "<<endl;
    else
    cout<<"Not Palindrome "<<endl;

    return 0;

}