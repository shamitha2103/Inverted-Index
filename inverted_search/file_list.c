#include "invert.h"

int store_filenames_to_list(char *file, file_node_t **head)
{
    file_node_t *temp = *head;
int flag = 0;

    while(temp != NULL)
    {
        if(strcmp(temp->f_name, file) == 0)
        {
            printf("INFO : Duplicate file\n");
            temp = temp->link;
            flag = 1;
        }
        else
        temp = temp->link;
    }
    if(flag)
        return 0;

    file_node_t *new = malloc(sizeof(file_node_t));
    if(new == NULL)
    return 0;

    strcpy(new->f_name , file);
    new->link = NULL;
  
    if(*head == NULL)
    {
        *head = new;
        return 1;
    }
   
    file_node_t *temp1 = *head;

    while(temp1->link != NULL)
    temp1 = temp1->link;

    temp1->link = new;
   
    return 1;
}

int IsFileValid(char *file_name)
{
    FILE *fptr = fopen(file_name, "r");
    int pos;

    if(fptr != NULL){
       
        printf("INFO : File exists in folder\n");
        fseek(fptr, 0, SEEK_END);
        pos = ftell(fptr);

        if(pos)
        {
            printf("INFO : File is not empty\n");
            return 1;
        }
        else
        {
            printf("ERROR : File is empty\n");
            return 0;
        }
    }
    else
    {
        printf("INFO : File is not exists in present directory\n");
        return 0;
    }
}
