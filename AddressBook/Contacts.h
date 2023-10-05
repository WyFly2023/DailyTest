//
// Created by wyf on 2023/9/28.
//

#ifndef ADDRESSBOOK_CONTACTS_H
#define ADDRESSBOOK_CONTACTS_H

#endif //ADDRESSBOOK_CONTACTS_H
//
// Created by wyf on 2023/9/27.
//

#ifndef TEST_CONTACT_H
#define TEST_CONTACT_H

#endif //TEST_CONTACT_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//定义枚举常量代表用户的选择
enum
{
    EXIT,
    ADD,
    DEL,
    SEA,
    MOD,
    SHOW
};

typedef struct PeopleInfo
{
    int age;
    char name[20];
    char addr[30];
    char tele[30];
}PeopleInfo;

#define maxSize 10

typedef struct Contacts
{
    PeopleInfo * data;
    int size;
    int capacity;
}Contacts;

//初始化通讯录
void InitContacts(Contacts *c);
//添加联系人
void AddContact(Contacts *c);
//显示联系人
void ShowContacts(Contacts* c);
//查找联系人
void SearchContact(Contacts *c);
//修改联系人信息
void ModifyContact(Contacts* c);
//删除联系人
void DelContact(Contacts * c);
//销毁通讯录
void DestroyContact(Contacts * c);
