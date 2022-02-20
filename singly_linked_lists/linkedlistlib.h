#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
  string id;
  short weight;
  struct Node *next;
} ListNode;

ListNode *createListNode(string id, short weight) {
  ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
  temp->id = id;
  temp->weight = weight;
  temp->next = NULL;
  return temp;
}

int listIsEmpty(ListNode *head) {
  if (head == NULL)
    return 1;
  return 0;
}

void printListNodes(ListNode *head) {
  ListNode *temp = head;
  if (listIsEmpty(temp)) {
    cout << "The list is emtpy.\n";
    return;
  }
  while (temp != NULL) {
    cout << "The member with id #" << temp->id << " weights " << temp->weight
         << "kg.\n";
    temp = temp->next;
  }
}

int length(ListNode *head) {
  ListNode *temp = head;
  int counter = 0;
  for (; temp != NULL; counter++)
    temp = temp->next;
  return counter;
}

ListNode *insertAtBeginning(ListNode *head, string id, short weight) {
  ListNode *temp = createListNode(id, weight);
  if (listIsEmpty(head)) {
    head = temp;
    return head;
  }
  temp->next = head;
  head = temp;
  return head;
}

ListNode *insertAtEnd(ListNode *head, string id, short weight) {
  ListNode *temp = createListNode(id, weight);
  ListNode *currentNode = head;
  if (listIsEmpty(head)) {
    head = temp;
    return head;
  }
  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }
  currentNode->next = temp;
  return head;
}

ListNode *insertAtGivenPosition(ListNode *head, string id, short weight,
                                int givenPosition) {
  ListNode *newNode = createListNode(id, weight);
  ListNode *predecessor = head;
  if (givenPosition <= 1) {
    newNode->next = head;
    return newNode;
  }
  while (predecessor != NULL && --givenPosition)
    predecessor = predecessor->next;
  if (predecessor == NULL)
    return NULL;
  newNode->next = predecessor->next;
  predecessor->next = newNode;
  return head;
}

void deleteFirst(ListNode **head) {
  ListNode *temp;
  if (listIsEmpty(*head))
    return;
  temp = *head;
  *head = (*head)->next;
  free(temp);
  return;
}

void deleteLast(ListNode **head) {
  ListNode *temp, *current;
  if (listIsEmpty(*head))
    return;
  current = *head;
  for (; current->next != NULL; current = current->next)
    temp = current;
  temp->next = NULL;
  free(current);
}

void deleteAtGivenPosition(ListNode **head, int givenPosition) {
  int counter = 0;
  ListNode *p, *q;
  if (listIsEmpty(*head))
    return;
  p = *head;

  if (givenPosition == 1) { /*delete the first node*/
    *head = (*head)->next;
    free(p);
    return;
  }
  for (; p != NULL && counter < givenPosition; counter++) {
    q = p;
    p = p->next;
  }
  if (p == NULL) {
    cout << "Position " << givenPosition << " doesn't exist.\n";
    return;
  }
  q->next = p->next;
  free(p);
}

void deleteLinkedList(ListNode **head) {
  cout << "\nDeleting linked list...\n";
  ListNode *auxiliaryNode, *iterator;
  iterator = *head;
  while (iterator != NULL) {
    auxiliaryNode = iterator->next;
    free(iterator);
    iterator = auxiliaryNode;
  }
  *head = NULL;
}
