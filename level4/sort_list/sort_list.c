#include "sort_list.h"
#include <stdlib.h>

/**
 * @def: Sort the list using function pointer cmp
 * @param: lst
 * @param: cmp - Function pointer which sorts list
 * @return: pointer to first element of sorted list
 * 
*/
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int     swap_value;

    t_list  *orginal_node1 = lst;
    
    //while the node and next node is not null
    while (lst != NULL && lst->next != NULL){
        if ((*cmp)(lst->data, lst->next->data) == 0){
            //bubble sort - switch in place
            swap_value = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap_value;

            lst = orginal_node1;
        }
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

    node1.data = 1000;
    node2.data = 19;
    node3.data = 1;
    node4.data = 983;
    node5.data = 2;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    
    printf("Old nodes: \n");
    printf("%i | ", node1.data);
    printf("%i | ", node2.data);
    printf("%i | ", node3.data);
    printf("%i | ", node4.data);
    printf("%i | \n\n", node5.data);

    sort_list(&node1, ascending);

    printf("New nodes: \n");
    printf("%i | ", node1.data);
    printf("%i | ", node2.data);
    printf("%i | ", node3.data);
    printf("%i | ", node4.data);
    printf("%i | \n\n", node5.data);
}