#include "base_functions.h"

void insertAtTheBeginning(Node **head, int id)
{
    Node *current = *head;
    Node *newNode = createListNode(id);
    if (!newNode)
    {
        printf("Memory Error.\n");
        return;
    }
    bool listIsEmpty = checkIfListIsEmpty(current);
    if (listIsEmpty)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->previous = newNode;
    *head = newNode;
}

void insertAtTheEnd(Node **head, int id)
{
    Node *current = *head;
    Node *newNode = createListNode(id);
    if (!newNode)
    {
        printf("Memory Error.\n");
        return;
    }
    bool listIsEmpty = checkIfListIsEmpty(current);
    if (listIsEmpty)
    {
        *head = newNode;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    newNode->previous = current;
    current->next = newNode;
}

void insertAtGivenPosition(Node **head, int id, int position)
{
    Node *current = *head;
    Node *newNode = createListNode(id);
    bool listIsEmpty = checkIfListIsEmpty(current);
    if (listIsEmpty)
    {
        *head = newNode;
        return;
    }
    if (position < 0)
    {
        printf("There's no such nonsense as position %d in this list.\n", position);
        return;
    }
    if (position == 0)
    {
        newNode->next = *head;
        (*head)->previous = newNode;
        *head = newNode;
        return;
    }
    int currentPos = 0;
    if (!newNode)
    {
        printf("Memory Error\n");
        return;
    }
    while (currentPos < position - 1 &&
           current != NULL)
    {
        current = current->next;
        currentPos++;
    }
    if (currentPos < position - 1)
    {
        printf("Position %d do not exist.\n", position);
        return;
    }
    if (current->next == NULL)
    {
        newNode->next = NULL;
        current->next = newNode;
        newNode->previous = current;
        return;
    }
    newNode->next = current->next;
    newNode->previous = current;
    current->next = newNode;
}

void deleteFirstNode(Node **head)
{
    Node *firstNode = *head;
    bool listIsEmpty = checkIfListIsEmpty(firstNode);
    if (listIsEmpty)
    {
        printf("There's nothing to do here then.\n");
        return;
    }
    (*head) = firstNode->next;
    (*head)->previous = NULL;
    //deletion
    free(firstNode);
}

void deleteLastNode(Node **head)
{
    Node *current = *head;
    bool listIsEmpty = checkIfListIsEmpty(current);
    if (listIsEmpty)
    {
        printf("There's nothing to do here then.\n");
        return;
    }
    while (current->next != NULL)
        current = current->next;
    Node *penultimateNode = current->previous;
    penultimateNode->next = NULL;
    free(current);
}
