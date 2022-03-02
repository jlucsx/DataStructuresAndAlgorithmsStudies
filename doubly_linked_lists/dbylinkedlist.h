#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct ListNode {
  int id;
  struct ListNode *next;
  struct ListNode *previous;
} Node;

Node *createListNode(int id) {
  Node *nodeScaffold = (Node *)malloc(sizeof(Node));
  nodeScaffold->id = id;
  nodeScaffold->next = NULL;
  nodeScaffold->previous = NULL;
  return nodeScaffold;
}

bool checkIfListIsEmpty(Node *head) {
  if (head == NULL)
    return true;
  return false;
}

void printTheList(Node *head) {
  bool listIsEmpty = checkIfListIsEmpty(head);
  if (listIsEmpty) {
    cout << "There's nothing to do here! The list is empty >:(" << endl;
    return;
  }
  Node *currentNode = head;
  while (currentNode != NULL) {
    printf("%p ~> User registed under id #%d.\n", currentNode, currentNode->id);
    currentNode = currentNode->next;
  }
}

void insertAtTheBeginning(Node **head, int id) {
  Node *current = *head;
  Node *newNode = createListNode(id);
  if (!newNode) {
    printf("Memory Error.\n");
    return;
  }
  bool listIsEmpty = checkIfListIsEmpty(current);
  if (listIsEmpty) {
    *head = newNode;
    return;
  }
  newNode->next = *head;
  (*head)->previous = newNode;
  *head = newNode;
}

void insertAtTheEnd(Node **head, int id) {
  Node *current = *head;
  Node *newNode = createListNode(id);
  if (!newNode) {
    printf("Memory Error.\n");
    return;
  }
  bool listIsEmpty = checkIfListIsEmpty(current);
  if (listIsEmpty) {
    *head = newNode;
    return;
  }
  while (current->next != NULL)
    current = current->next;
  newNode->previous = current;
  current->next = newNode;
}
