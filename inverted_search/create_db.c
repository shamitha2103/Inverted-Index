
#include "invert.h"

int create_DB(file_node_t *file_head, table_t *arr)
{
    FILE *fptr;
    char word1[20];
    int indx;
    int flag = 0;
    file_node_t *temp = file_head;

	while(temp!= NULL)
    {
        fptr = fopen(temp->f_name, "r");
        if(fptr == NULL)
        {
            printf("INFO : File is not opening properly\n");
            return 0;
        }
        printf("%s is opened\n",temp->f_name);
        
        while(fscanf(fptr, "%s", word1) != EOF)
        {
            indx = tolower(word1[0]) - 97; 
            if(indx < 0 || indx > 25)
                indx = 26;

            if(arr[indx].link == NULL)
            {
                main_node_t *new = malloc(sizeof(main_node_t));
                sub_node_t *snew = malloc(sizeof(sub_node_t));

                if(new == NULL)
                return 0;
            
                if(snew == NULL)
                return 0;
                
                new->f_count = 1;
                new->link = NULL;
                new->sub_link = snew;
                strcpy(new->word , word1);

                strcpy(snew->f_name , temp->f_name);
                snew->link = NULL;
                snew->w_count = 1;

                arr[indx].link = new;
               
            }
            else
            {
                flag = 0;
                main_node_t *temp1 = arr[indx].link;
                main_node_t *prev = NULL;
                while(temp1 != NULL)
                {
                    if(strcmp(temp1->word, word1) == 0)
                    {
                        flag = 1;
                        sub_node_t *t = temp1->sub_link;
                        sub_node_t *p = NULL;
                        while(t != NULL)
                        {
                            if(strcmp(t->f_name , temp->f_name) == 0)
                            {
                                t->w_count = t->w_count + 1;
                                break;
                            }
                            
                            p = t;
                            t = t->link;
                        }
                        if(t == NULL)
                        {
                            sub_node_t *sub = malloc(sizeof(sub_node_t));
                            if(sub == NULL)
                                return 0;

                            sub->w_count = 1;
                            strcpy(sub->f_name, temp->f_name);
                            sub->link = NULL;
                            temp1->f_count = temp1->f_count + 1;
                            p->link = sub;
                        }
                    }
                    prev = temp1;
                    temp1 = temp1->link;
                    
                }

                if(flag == 0)
                {
                    main_node_t *new = malloc(sizeof(main_node_t));
                    if(new == NULL)
                        return 0;
                    sub_node_t *snew = malloc(sizeof(sub_node_t));
                    if(snew == NULL)
                        return 0;
                    
                    new->f_count = 1;
                    new->sub_link = snew;
                    strcpy(new->word, word1);
                    new->link = NULL;

                    snew->w_count = 1;
                    strcpy(snew->f_name, temp->f_name);
                    snew->link = NULL;

                    prev->link = new;
                   
                }

            }
            
        }
        fclose(fptr);
        temp = temp->link;
    }
   return 1;
}
