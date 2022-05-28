#include "dbylinkedlist.h"

int main(void) {
  Node *doublyLinkedList = NULL;
  insertAtTheBeginning(&doublyLinkedList, 7);
  insertAtTheBeginning(&doublyLinkedList, 15);
  insertAtTheBeginning(&doublyLinkedList, 4);
  insertAtTheEnd(&doublyLinkedList, 40);
  insertAtGivenPosition(&doublyLinkedList, 74, 4);
  deleteFirstNode(&doublyLinkedList);
  deleteLastNode(&doublyLinkedList);
  insertAtTheBeginning(&doublyLinkedList, 441);
  insertAtTheBeginning(&doublyLinkedList, 21);
  insertAtTheBeginning(&doublyLinkedList, 41);
  insertAtGivenPosition(&doublyLinkedList, 89, 3);
  insertAtTheEnd(&doublyLinkedList, 888);
  deleteNodeAtGivenPosition(&doublyLinkedList, 5);
  printTheList(doublyLinkedList);
  printf("\n\n");
  printf("The list has %d nodes.\n", listLength(&doublyLinkedList));
  printf("Node registered under id #%d is at position %d on the list.\n", 441, searchForGivenId(&doublyLinkedList, 441));
  return 0;
}
