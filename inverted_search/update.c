#include "invert.h"

int update_DB(file_node_t **head, main_node_t **mhead, table_t *arr)
{
    char file_name[50];
    FILE *fptr;
    int pos = 0;
    char ch, ch1;
    
    char word[50];
    int indx = 0;
    char fname[50];
    int word_c;
    int fcount;

    printf("INFO : enter data base file for updation : ");
    scanf(" %[^\n]",file_name);

    for(int i = 0; i < 27; i++)
    {
        if(arr[i].link != NULL)
        {
            printf("INFO : Hash table is not empty\n");
            return 0;
        }
    }

    if(strcmp(strstr(file_name, "."), ".txt") == 0)
    {
        fptr = fopen(file_name, "r");
        if(fptr != NULL)
        {
            fseek(fptr, 0, SEEK_END);
            pos = ftell(fptr);
            if(pos)
            {
                printf("INFO : Given data base file is valid\n");
            }
            else
            {
                printf("INFO : File is empty\n");
                return 0;
            }
        }
        else{
            printf("INFO : file is not present in current directory\n");
            return 0;
        }
    }
    else{
        printf("INFO : File extension is not valid\n");
        return 0;
    }
   // rewind(fptr);
    fseek(fptr, 0, SEEK_SET);
   fscanf(fptr, " %c", &ch);
  rewind(fptr);
   if(ch == '#')
   {
    printf("INFO : Given file is database file\n");
   }
   else{
    printf("INFO : Given file is not a data base file\n");
    return 0;
   }
    //output.txt
    //create_table(arr, SIZE);

   while(fscanf(fptr, " #%d; %[^;]; %d; %[^;]; %d; # ", &indx, word, &fcount, fname, &word_c) != EOF)   //#0; aRE; 1; 1.txt; 1; # 
   {
        arr[indx].ind = indx;
        printf(" %d ",indx);
            main_node_t *mnew = malloc(sizeof(main_node_t));
            sub_node_t *snew = malloc(sizeof(sub_node_t));
            sub_node_t *temp;

            if(snew == NULL)
                return 0;

            if(mnew == NULL)
                return 0;

            strcpy(mnew->word, word);
            mnew->f_count = fcount;
            mnew->sub_link = snew;
            mnew->link = NULL;

            strcpy(snew->f_name, fname);
            snew->w_count = word_c;
            snew->link = NULL;

            temp = snew;

            for(int i = 1; i < mnew->f_count; i++)
            {
                sub_node_t *new = malloc(sizeof(sub_node_t));
                if(new == NULL)
                return 0;
                
                new->link = NULL;
                strcpy(new->f_name, fname);
                new->w_count = word_c;

                temp->link = new;

                temp = new;
            }
         
        if (arr[indx].link == NULL)
        {
            arr[indx].link = mnew;
        }
        else
        {
            main_node_t *temp1 = arr[indx].link;
            while (temp1->link != NULL)
            {
                temp1 = temp1->link;
            }
            temp1->link = mnew;
        }
   }
   fclose(fptr);
   return 1;
}