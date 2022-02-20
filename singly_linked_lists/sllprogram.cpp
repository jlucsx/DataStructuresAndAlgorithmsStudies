#include "linkedlistlib.h"

int main(void) {
  ListNode *list = NULL;
  list = insertAtBeginning(list, "1", 98);
  list = insertAtBeginning(list, "2", 132);
  list = insertAtBeginning(list, "3", 78);
  list = insertAtEnd(list, "4", 91);
  list = insertAtEnd(list, "5", 89);
  list = insertAtGivenPosition(list, "6", 99, 2);
  deleteAtGivenPosition(&list, 2);
  printListNodes(list);
  deleteLinkedList(&list);
  printListNodes(list);
  return 0;
}
