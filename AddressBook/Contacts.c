//
// Created by wyf on 2023/9/28.
//
//
// Created by wyf on 2023/9/27.
//
#include "Contacts.h"


int FindByName(Contacts *c, char *name)
{
    assert(c);
    int i = 0;
    for(i = 0;i < c->size; i++)
    {
        if((strcmp(c->data[i].name,name)) == 0)
            return i;   //找到返回下标
    }
    return -1;  //找不到
}

void InitContacts(Contacts *c)
{
    assert(c);
    c->size = 0;
    c->capacity = maxSize;
    c->data = malloc(sizeof(PeopleInfo)*c->capacity);
    if(c->data == NULL)
        return;
    loadContactsFromFile(c);
}

//增容
void AddCapacity(Contacts* c)
{
    if (c->size == c->capacity)
    {
        PeopleInfo *tmp = realloc(c->data,sizeof(Contacts) * c->capacity * 2);
        if (tmp != NULL)
        {
            c->data = tmp;
            c->capacity += maxSize;
            printf("增容成功\n");
        }
        else
        {
            perror("AddContact->realloc");
            return;
        }
    }
}

void AddContact(Contacts *c)
{
    assert(c);
    AddCapacity(c);

    printf("姓名：\n");
    scanf("%s",c->data[c->size].name);
    printf("年龄：\n");
    scanf("%d",&c->data[c->size].age);
    printf("联系电话：\n");
    scanf("%s",c->data[c->size].tele);
    printf("地址：\n");
    scanf("%s",c->data[c->size].addr);

    c->size++;
    printf("添加成功\n");
}

void ShowContacts(Contacts* c)
{
    assert(c);
    printf("%-15s%-10s%-18s%-30s\n",
           "姓名", "年龄", "电话号码", "地址");
    int i = 0;
    for(i = 0; i < c->size; i++)
        printf("%-15s%-5d%-18s%-30s\n",
               c->data[i].name, c->data[i].age, c->data[i].tele, c->data[i].addr);
    printf("\n");
}

void SearchContact(Contacts *c)
{
    assert(c);
    char name[20];
    printf("输入要查找姓名：\n");
    scanf("%s",name);

    int ret = FindByName(c,name);

    if(ret==-1)
    {
        printf("不存在\n");
        return;
    }


    printf("%-15s%-5s%-18s%-30s\n",
           "姓名", "年龄", "电话号码", "地址");
    printf("%-15s%-5d%-18s%-30s\n",
           c->data[ret].name, c->data[ret].age, c->data[ret].tele, c->data[ret].addr);
}


void ModifyContact(Contacts* c)
{
    char name[20];
    assert(c);
    printf("请输入要修改人的名字:");
    scanf("%s", name);
    int ret = FindByName(c, name);
    if (ret == -1)
    {
        printf("要修改的人不存在\n");
        return;
    }
    //修改
    printf("请输入名字:");
    scanf("%s", c->data[ret].name);
    printf("请输入年龄:");
    scanf("%d", &(c->data[ret].age));
    printf("请输入电话:");
    scanf("%s", c->data[ret].tele);
    printf("请输入地址:");
    scanf("%s", c->data[ret].addr);

    printf("修改成功\n");
}

void DelContact(Contacts * c)
{
    char name[20];
    assert(c);
    if (c->size == 0)
    {
        printf("通讯录为空，无法删除\n");
        return;
    }
    printf("输入要删除人的名字:");
    scanf("%s", name);
    //找到名字为name的人
    int ret = FindByName(c, name);
    if (ret == -1)
    {
        printf("要删除的人不存在\n");
        return;
    }
    //删除这个人
    int i = 0;

    for (i = ret; i < c->size-1; i++)
    {
        c->data[i] = c->data[i + 1];
    }

    c->size--;
    printf("删除成功\n");
}

void DestroyContact(Contacts * c)
{
    assert(c);
    free(c->data);
    c->data = NULL;
    c->size = c->capacity = 0;
}


void saveContactsToFile(Contacts* c)
{
    FILE* file = fopen("contacts.txt", "wb");
    if (file == NULL)
    {
        perror(saveContactsToFile);
        return;
    }

    //将信息写到文件
    for (int i = 0; i < c->size; i++)
       fwrite(c->data + i,sizeof(PeopleInfo),1,file);

    fclose(file);
    printf("Contacts saved to file.\n");
}

void loadContactsFromFile(Contacts* c)
{
    FILE* file = fopen("contacts.txt", "rb");
    if (file == NULL) {
        perror(loadContactsFromFile);
        return;
    }

    //读
    PeopleInfo tmp = { 0 };

    while(fread(&tmp,sizeof(PeopleInfo),1,file))
    {
        AddCapacity(c);
        c->data[c->size] = tmp;
        c->size++;
    }
    fclose(file);
    printf("Contacts loaded from file.\n");
}