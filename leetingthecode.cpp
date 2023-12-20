#include <iostream>
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void addNode(int data)
    {
        Node *node = new Node(data);
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            Node *traverser = head;
            while (traverser->next != NULL)
            {
                traverser = traverser->next;
            }
            traverser->next = node;
        }
    }
    void showList()
    {
        Node *traverser = head;
        while (traverser != NULL)
        {
            std::cout << traverser->data << "\n";
            traverser = traverser->next;
        }
    }
    bool isListPalindromic()
    {
        Node *slow = head;
        Node *fast = head;
        Node *mid;
        Node *prev = NULL;
        Node *curr = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        mid->next = NULL;
        while (slow != NULL)
        {
            curr = slow->next;
            slow->next = prev;
            prev = slow;
            slow = curr;
        }
        Node *left = head;
        Node *right = prev;
        while (right != NULL && left != NULL)
        {
            if (right->data != left->data)
            {
                return false;
            }
            right = right->next;
            left = left->next;
        }
        return true;
    }
    void reverseList()
    {
        Node *curr = head;
        Node *prev = NULL;
        while (head != NULL)
        {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
    }
};
int main()
{
    LinkedList LL;
    LL.addNode(1);
    LL.addNode(2);
    LL.addNode(3);
    LL.addNode(4);
    LL.addNode(3);
    LL.addNode(2);
    LL.addNode(1);
    LL.showList();
    // std::cout << LL.isListPalindromic();
    LL.reverseList();
    LL.showList();
}