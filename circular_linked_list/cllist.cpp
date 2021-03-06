#include "cllist.h"

int main(void)
{
    cllNode *head = createListNode("28/05/2022");
    cllControl *circularListControl = createInformationControl(head, head, 1);

    insertNodeAtEnd(circularListControl, "29/05/2022");
    insertNodeAtEnd(circularListControl, "30/05/2022");
    insertNodeAtEnd(circularListControl, "31/05/2022");
    insertNodeAtBeginning(circularListControl, "27/05/2022");
    insertNodeAtBeginning(circularListControl, "26/05/2022");
    deletedLastNode(circularListControl);
    deleteFirstNode(circularListControl);

    printList(circularListControl->head);
    printf("Length of the list is %d.\n", circularListControl->listLength);
    return 0;
}
