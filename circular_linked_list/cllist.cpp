#include "cllist.h"

int main(void)
{
    cllNode *head = createListNode("28/05/2022");
    cllControl *circularListControl = createInformationControl(head, head, 1);

    insertNodeAtEnd(circularListControl, "29/05/2022");
    insertNodeAtEnd(circularListControl, "30/05/2022");
    insertNodeAtEnd(circularListControl, "31/05/2022");
    insertNodeAtBeginning(circularListControl, "27/05/2022");

    printList(circularListControl->head);
    printf("Length of the list is %d.\n", length(head));
    return 0;
}
