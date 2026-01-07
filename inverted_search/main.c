
#include "invert.h"

int main(int argc, char *argv[])
{
    file_node_t *head = NULL;
    main_node_t *mhead = NULL;
    sub_node_t *subhead = NULL;

    char *fname;
    int option;
    table_t arr[27];

    if(argc <= 1)
    {
        printf("INFO : arguments are not sufficient\n");
        return 0;
    }

    for(int i = 1; i < argc; i++)
    {
        char *ch = strstr(argv[i], ".txt");
        if(ch != NULL)
        {
            if(strcmp(ch, ".txt") == 0)
            {
                if(IsFileValid(argv[i]))
                {
                    if(store_filenames_to_list(argv[i], &head))
                    {
                        printf("INFO : file name is stored into structure\n");
                    }
                    else
                    {
                        printf("INFO : file name is not stored into structure properly\n");
                    }
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
    } 

    printf("selet the option :\n");
    printf("1.Create data base\n2.Display data base\n3.Search data base\n4.Update data base\n5.Save data base\n6.Exit");
    if(create_table(arr, SIZE) == 1)
    {
            printf("INFO : Hash table is created successfully\n");
    }
  
    char word[50];
    char file_name[50];
   while(1){
       
    printf("enter the option : ");
    scanf("%d",&option);

        switch(option)
        {
            case 1:

                if(create_DB(head, arr) == 1)
                {
                    printf("INFO : Data base is Created successfully\n");
                }
                else
                {
                    printf("INFO : Data base is not created\n");
                    break;
                }
                break;
           case 2:
                display_DB(mhead, arr);
                break;
            case 3:
               
                 printf("enter the word you want to search : ");
                 scanf(" %s",word);
                 if(search_DB(mhead, word, arr) == 0)
                 {
                    printf("%s is not found\n",word);
                 }
                
                 break;
            case 4:
                 printf("Enter the file you want to save this data base: ");
                 scanf(" %[^\n]", file_name);
                 if(save_DB(&mhead, file_name, arr, &head) == 1)
                 printf("data base saved.\n");
                 else
                 printf("data base is not saved.\n");
                 break;

            case 5:
                    if(update_DB(&head, &mhead, arr) == 1){
                        printf("INFO : update data base is completed\n");
                    }
                    else{
                        printf("INFO : Update data base is not successfully completed\n");
                    }
            break;

            case 6:
                return 0;
       
       }
    }
}

