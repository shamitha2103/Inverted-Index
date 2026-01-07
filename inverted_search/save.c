#include "invert.h"

int copy_data(table_t *arr, char *fname)
{
    FILE *fptr = fopen(fname, "w");
    if(fptr == NULL)
        return 0;

    for(int i = 0; i < 27; i++)
    {
        main_node_t *temp = arr[i].link;
        if(temp == NULL)
        continue;
 
        while(temp != NULL)
        {
            fprintf(fptr, "%c", '#');
            fprintf(fptr, "%d; ",i);
            fprintf(fptr, "%s; ", temp->word);
            fprintf(fptr, "%d; ",temp->f_count);
            
            sub_node_t *temp1 = temp->sub_link;
            while(temp1 != NULL)
            {
                fprintf(fptr, "%s; ",temp1->f_name);
                fprintf(fptr, "%d; ",temp1->w_count);
                fprintf(fptr, "%c ", '#');
                temp1 = temp1->link;
            }
            temp = temp->link;         //  #7; hi; 1; 1.txt; 1; #7; hello; 1; 1.txt; 1; #7; how; 1; 1.txt; 1; # 
            
        }
       // fprintf(fptr, "%c ", '#');
        fprintf(fptr, "%c ",'\n');
    }
    fclose(fptr);
    return 1;
}


int save_DB(main_node_t **mhead, char *fname, table_t *arr, file_node_t **head)
{
    char vali;
    FILE *fptr;
    char *ch = strstr(fname, ".txt");
    if(ch != NULL)
    {
        if(strcmp(ch, ".txt") == 0)
        {
            fptr = fopen(fname, "r");

            if(fptr != NULL)
            {
                 printf("INFO : File exists in folder\n");
                 int pos;
                 fseek(fptr, 0, SEEK_END);
                 pos = ftell(fptr);
         
                 if(pos)
                 {
                     printf("INFO : File is not empty\n");
                     printf("Do you want to overwite  y/ n : ");
                     scanf(" %c",&vali);
                     if(vali == 'y')
                     {
                        printf("INFO : COPYING DATAS...\n");
                       if(copy_data(arr, fname))
                            printf("data base is successfully copied to %s \n",fname);
                        else
                            printf("data base is not copied successfully\n");
                     }
                     else
                     {
                        return 0;
                     }

                 }
                 else
                 {
                     printf("INFO : File is empty\n");
                     printf("INFO : COPYING DATAS...\n");
                     if(copy_data(arr, fname))
                        printf("data base is successfully copied to %s \n",fname);
                    else
                        printf("data base is not copied successfully\n");
                 }
            }
            else
            {
                printf("INFO : File is not exists in present directory\n");
                if(copy_data(arr, fname))
                        printf("data base is successfully copied to %s \n",fname);
                else
                        printf("data base is not copied successfully\n");
            }
             
  
            if(store_filenames_to_list(fname, head))
            {
                printf("INFO : file name is stored into structure\n");
            }
            else
            {
                printf("INFO : file name is not stored into structure properly\n");
            }
        }
        else{
            printf("ERROR : Extension of the file is invalid\n");
            return 0;
        }
    }
    else
    {
       printf("INFO : filename are incorrect\n");
        return 0;
    }
    fclose(fptr);
    return 1;
}