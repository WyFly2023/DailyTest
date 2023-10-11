#include "Contacts.h"

void menu()
{
    printf("****************************\n");
    printf("***** 1.ADD      2.DEL  ****\n");
    printf("***** 3.SEA      4.MOD  ****\n");
    printf("***** 5.SHOW     6.Save ****\n");
    printf("*********  0.Exit  *********\n");
}

int main()
{
    Contacts c;
    InitContacts(&c);
    loadContactsFromFile(&c);
    int input = 0;
    do
    {

        menu();
        printf("请选择:>\n");
        scanf("%d",&input);
        switch(input)
        {
            case EXIT:
                DestroyContact(&c);
                printf("程序退出\n");
                break;
            case ADD:
                AddContact(&c);
                break;
            case DEL:
                DelContact(&c);
                break;
            case SEA:
                SearchContact(&c);
                break;
            case MOD:
                ModifyContact(&c);
                break;
            case SHOW:
                ShowContacts(&c);
                break;
            case Save:
                saveContactsToFile(&c);
                break;
            default :
                printf("选择错误，重新选择\n");
                break;
        }
    }while(input);

    DestroyContact(&c);
    return 0;
}