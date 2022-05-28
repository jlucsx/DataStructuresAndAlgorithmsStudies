#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct ListNode
{
    int id;
    struct ListNode *next;
    struct ListNode *previous;
} Node;

Node *createListNode(int id)
{
    Node *nodeScaffold = (Node *)malloc(sizeof(Node));
    nodeScaffold->id = id;
    nodeScaffold->next = NULL;
    nodeScaffold->previous = NULL;
    return nodeScaffold;
}

bool checkIfListIsEmpty(Node *head)
{
    if (head == NULL)
        return true;
    return false;
}

void printTheList(Node *head)
{
    bool listIsEmpty = checkIfListIsEmpty(head);
    if (listIsEmpty)
    {
        cout << "There's nothing to do here! The list is empty >:(" << endl;
        return;
    }
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        printf("%p ~> User registed under id #%d.\n", currentNode, currentNode->id);
        currentNode = currentNode->next;
    }
}

int listLength(Node **head)
{
    int counter = 0;
    Node *current = *head;
    while (current != NULL)
    {
        current = current->next;
        counter++;
    }
    return counter;
}

int searchForGivenId(Node **head, int id)
{
    int position = 0;
    Node *current = *head;
    while (current != NULL && current->id != id)
    {
        current = current->next;
        position++;
    }
    if (current == NULL)
    {
        printf("There is no Node registered under id #%d.\n", id);
        return -1;
    }
    else {
        return position;
    }
}