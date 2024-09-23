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
    int temp_value;

    t_list *orginal_node1 = lst;

    while (lst != NULL && lst->next != NULL)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            temp_value = lst->data;
            lst->data = lst->next->data;
            lst->next->data = temp_value;
        
            //now that value has swopped
            //reset current node to node1
            lst = orginal_node1;
        }
        //set current node to next node
        else
            lst = lst->next;
    }
    return (orginal_node1);
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
    printf("\n\n");
    //Run the function
    sort_list(&node1, ascending);

    printf("New Node: \n\n");
    printf("Node: %i | ", node1.data);
    printf("Node: %i | ", node2.data);
    printf("Node: %i | ", node3.data);
    printf("Node: %i | ", node4.data);
    printf("Node: %i | ", node5.data);
}