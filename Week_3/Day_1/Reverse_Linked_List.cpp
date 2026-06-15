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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
};

void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

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

    printList(head);

    Solution obj;
    head=obj.reverseList(head);
    cout<<"New List: ";
    printList(head);

    return 0;
}