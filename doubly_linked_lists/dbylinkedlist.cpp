#include "dbylinkedlist.h"

int main(void) {
  Node *doublyLinkedList = NULL;
  insertAtTheBeginning(&doublyLinkedList, 7);
  insertAtTheBeginning(&doublyLinkedList, 15);
  insertAtTheBeginning(&doublyLinkedList, 4);
  insertAtTheEnd(&doublyLinkedList, 40);
  insertAtGivenPosition(&doublyLinkedList, 74, 4);
  printTheList(doublyLinkedList);
  return 0;
}
