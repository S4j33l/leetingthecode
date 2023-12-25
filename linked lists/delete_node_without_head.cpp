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
    void deleteNode(Node *node)
    {
        *node = *node->next;
    }
};
int main()
{
    LinkedList *LL = new LinkedList();
    LL->addNode(1);
    LL->addNode(2);
    LL->addNode(3);
    LL->addNode(4);
    LL->addNode(5);
    LL->showList();
}