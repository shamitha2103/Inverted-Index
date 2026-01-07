
#include "invert.h"


void display_DB(main_node_t *head, table_t *arr)
{
    int i = 0;
    
    for(int i = 0; i < 27; i++)
    {
        main_node_t *temp = arr[i].link;
        while(temp != NULL)
        {
            printf("INDEX : %-10d   WORD : %-10s ",i, temp->word);
            printf("FILE COUNT : %-10d ",temp->f_count);

            sub_node_t *temp1 = temp->sub_link;
            while(temp1 != NULL)
            {
                printf("FILE NAME : %-10s ",temp1->f_name);
                printf("WORD COUNT : %-5d ",temp1->w_count);
                temp1 = temp1->link;
            }
            temp = temp->link;
            printf("\n");
        }
        
    }

}
