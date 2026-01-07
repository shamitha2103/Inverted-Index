
#include "invert.h"

int search_DB(main_node_t *head, char word[], table_t *arr)
{
    int ind = tolower(word[0]) - 97;
	
	main_node_t *temp = arr[ind].link;
	
	while(temp != NULL)
	{
		if((strcmp(temp->word , word)) == 0)
		{
			printf("INDEX : %-2d 	WORD : %-10s  ",ind, word);
			printf("FILE COUNT : %-10d ",temp->f_count);

			sub_node_t *temp1 = temp->sub_link;
			while(temp1 != NULL)
			{
				printf("FILE NAME : %-10s	WORD COUNT : %-10d ",temp1->f_name, temp1->w_count);
				
				temp1 = temp1->link;
			}
			printf("\n");
			return 1;
		}
		temp = temp->link;
	}
	return 0;
}


