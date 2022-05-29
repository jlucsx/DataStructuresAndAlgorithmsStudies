#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct cllNode
{
    string data;
    struct cllNode *next;
} cllNode;

typedef struct cllControl
{
    struct cllNode *head;
    struct cllNode *tail;
    int listLength;
} cllControl;

void printnl()
{
    printf("\n");
}

cllControl *createInformationControl(cllNode *head, cllNode *tail, int listLength)
{
    cllControl *control = (cllControl *)malloc(sizeof(cllControl));
    control->head = head;
    control->tail = tail;
    control->listLength = listLength;
    return control;
}

void addAsNextOf(cllNode *existingNode, cllNode *itsNextNode)
{
    existingNode->next = itsNextNode;
}

void addDataTo(string data, cllNode *node)
{
    node->data = data;
}

cllNode *createListNode(string data)
{
    cllNode *tmp = nullptr;
    tmp = (cllNode *)malloc(sizeof(cllNode));
    addDataTo(data, tmp);
    addAsNextOf(tmp, nullptr);
    return tmp;
}

bool checkIfListIsEmpty(cllNode *head)
{
    if (head == nullptr)
        return true;
    return false;
}

//For testing purposes <
int length(cllNode *head)
{
    cllNode *current = head;
    int count = 0;
    if (head == nullptr)
        return 0;
    do
    {
        current = current->next;
        count++;
    } while (current != head);
    return count;
}
//For testing purposes >

void printList(cllNode *head)
{
    cllNode *current = head;

    if (head == nullptr)
        return;
    do
    {
        printf("[%p <%s>]+=>  ", current, current->data.c_str());
        current = current->next;
    } while (current != head);
    printnl();
}

void insertNodeAtEnd(cllControl *control, string data)
{
    cllNode *newNode = createListNode(data);
    if (!newNode)
    {
        cout << "Memory Error!" << endl;
        return;
    }
    bool listIsEmpty = checkIfListIsEmpty(control->head);
    if (listIsEmpty)
    {
        (control->head) = newNode;
        return;
    }
    addAsNextOf(control->tail, newNode);
    control->tail = newNode;
    addAsNextOf(newNode, control->head);
    control->listLength++;
}