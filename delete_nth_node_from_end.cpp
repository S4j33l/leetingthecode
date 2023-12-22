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
private:
    Node *head;

public:
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
    void removeNthFromEnd(int n)
    {
        Node *dummyNode = new Node(0);
        dummyNode->next = head;
        Node *slow = dummyNode;
        Node *fast = dummyNode;
        int i = 0;
        while (i <= n)
        {
            fast = fast->next;
            i++;
        }
        while (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
    }
};
int main()
{
    LinkedList LL;
    LL.addNode(1);
    LL.addNode(2);
    LL.addNode(3);
    LL.addNode(4);
    LL.removeNthFromEnd(3);
    LL.showList();
};