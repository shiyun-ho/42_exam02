#include "sort_list.h"
#include <stdlib.h>
/**
 * @def: Sorts the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.
* @param: list
* @param: function pointer cmp
* @return: pointer to the first element of the sorted list
*/
// Functions passed as cmp will always return a value different from
// 0 if a and b are in the right order, 0 otherwise.
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *temp;
    t_list *temp_head;

    //created a temp list to store node1
    temp = lst;
    temp_head = lst;
    //if it is not sorted in right order
    while (lst->next != NULL)
    {
        if (cmp(lst->data, lst->next->data) == 0)
        {
            lst = lst->next; 
            lst->next = temp;
        }
        lst = lst->next;
        lst->next = lst->next->next;
    }
    return temp_head;
}

int ascending(int a, int b)
{
	return (a <= b);
}
#include <stdio.h>

int main()
{
    t_list node1;
    t_list node2;
    t_list node3;
    t_list node4;
    t_list node5;
    
    node1.data = 4;
    node2.data = 123;
    node3.data = 2;
    node4.data = -1;
    node5.data = 10;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;


    printf("Original Node: \n\n");
    printf("Node: %i | ", node1.data);
    printf("Node: %i | ", node2.data);
    printf("Node: %i | ", node3.data);
    printf("Node: %i | ", node4.data);
    printf("Node: %i | ", node5.data);
    //Run the function
    sort_list(&node1, ascending);

    printf("New Node: \n\n");
    printf("Node: %i | ", node1.data);
    printf("Node: %i | ", node2.data);
    printf("Node: %i | ", node3.data);
    printf("Node: %i | ", node4.data);
    printf("Node: %i | ", node5.data);
}