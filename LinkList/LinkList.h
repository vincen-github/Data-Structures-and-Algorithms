#include<iostream>
#pragma once
using namespace std;
//定义结点类型的结构体
typedef struct Node 
{
    int elem;
    struct Node *next;
}*linklist;

//*************************************************************************************************

/*
    function name:init_link_list

    function:初始化带头结点的链表

    input:None

    output:None

    return:指向头结点的表头指针,头结点的elem域为linklist的长度
*/
linklist init_linklist()
{
    linklist L;                         //声明表头指针;
    Node *head_node;
    head_node = (Node*)malloc(sizeof(Node));                            //声明头结点
    int(head_node->elem);                 //强制转化，防止head_node.elem是非int类型的
    head_node->elem = 0;             // 头结点的elem域设定为表的长度
    head_node->next = NULL;
    L = head_node;
    return L;
}

//****************************************************************************************************
/*
    function name:isnull

    function:
        判空

    input: 
        L:要判空的链表头指针      type:linklist

    output:
        null

    return:
        True or false   
*/
inline bool isnull(linklist L)
{
    return !(L->elem);          // 若L为空，则L->elem = 0，bool类型为false，！代表取逻辑反
}

//****************************************************************************************************

/*
    function name:display

    function:
        打印所有linklist中结点的elem

    input: 
        L:要求表长的链表头指针      type:linklist

    output:
        所有linklist的结点的elem

    return:
        None    
*/
void display(linklist L)
{
    Node *cur = L->next;   //声明游标
    if (cur == NULL)    //若linklist为空
    {
        cout << "linklist is empty" << endl;
    }
    else
    {
        while(cur->next != NULL)
    {
        cout << cur->elem << ' ';
        cur = cur->next;
    }
    cout << cur->elem << endl;
    }
}

//****************************************************************************************************
/*
    function name:
        len

    function:
        求表长

    input: 
        L:要求表长的链表头指针      type:linklist

    output:
        None

    return:
        表长    type:int
*/
inline int len(linklist L)
{
    return L->elem; 
}

//********************************************************************************************************

/*
    function name:add

    function:头插法

    input:
        L:要插入结点的链表头指针      type:linklist
        elem:要插入结点的数据域       type:与所定义结构体的elem的type一致

    output:None

    return:None
*/
void add(linklist L,int elem)
{
    Node *new_node;              //新建Node
    new_node = (Node*)malloc(sizeof(Node));      
    new_node -> elem = elem;                //数据域赋值
    new_node->next = L->next;     //挂链
    L->next = new_node; 
    L->elem++;                  //表长+1     
}

//***********************************************************************************************

/*
    function name:append

    function:尾插法建表

    input:
        L:要插入结点的链表头指针      type:linklist
        elem:要插入结点的数据域       type:与所定义结构体的elem的type一致

    output:None

    return:None
*/
void append(linklist L,int elem)
{
    Node *new_node;              //新建Node
    new_node = (Node*)malloc(sizeof(Node));      
    new_node -> elem = elem;                //数据域赋值
    //找到表尾位置
    Node *cur = L;               //声明游标
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new_node;     //挂链
    new_node->next = NULL;    //尾插结点next域置空
    L->elem++;                  //表长+1     
}

//****************************************************************************************************

/*
    function name:remove

    function:按value删除结点，若linklist中存在多个elem值与value相同的结点，删除第一个。

    input:
        L:要插入结点的链表头指针      type:linklist
        value:要删除结点的elem值       type:与所定义结构体的elem的type一致

    output:当满足条件结点不存在时，打印"No nodes found that meet the conditions"

    return:None
*/
void remove(linklist L,int value)
{
    //找到第一个符合elem = value条件的结点位置和前一个结点的位置
    Node *pre = L;            //声明游标
    Node *cur = L->next;
    if(cur == NULL)  //若linklist是一个空表，打印value未找到
    {
        cout <<  "No nodes found that meet the conditions" << endl;
    }
    else
    {
        while( cur->elem != value && cur->next != NULL)
        {
            cur = cur->next;
            pre = pre->next;
        }
        // 若因cur->elem == value而跳出while循环，pre->next跳跃一个结点赋值即可
        if(pre->next->elem == value)
        {
            pre->next = cur->next;    //pre->next跳跃一个结点赋值
            free(cur);            //释放删除结点空间
            L->elem--;                  //表长-1
        }
        //若因cur->next == NULL && cur->elem != value 而跳出while循环，打印value未找到
        else
        {
            cout <<  "No nodes found that meet the conditions" << endl;
        }
    }
}

//******************************************************************************************************

/*
    function name:pop

    function:按index删除结点,从1开始

    input:
        L:要插入结点的链表头指针      type:linklist
        pos:要删除结点的位置(默认删除最后一个结点)       type:int

    output:
        当pos超出索引时,打印"linklist index out of range."
        当L为空时,打印""linklist is empty."

    return:删除的value type:与所定义结构体的elem的type一致
*/
int pop(linklist L,int pos = -1)
{
    Node *cur = L->next;
    Node *pre = L;
    int pop_value;
    //判空
    if(cur == NULL)
    {
        cout << "linklist is empty." << endl;
        return false;
    }
    //若pos是默认值-1，删除最后一个结点
    else if (pos == -1)
    {
        while(cur->next != NULL)
        {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = NULL;
        pop_value = cur->elem;
        free(cur);
        L->elem--;                // 表长-1
        return pop_value;
    }
     //判断pos是否合法
    else if(L->elem < pos || pos <= 0)
    {
        cout << "linklist index out of range." << endl;
        return false;
    }
    //输入pos合法
    else
    {
        int count = 1;              //计数器
        while(cur != NULL)
        {
            if(count == pos)              //若cur到达指定位置
            {
                pre->next = cur->next;
                pop_value = cur->elem;
                free(cur);
                L->elem--;
                return pop_value;
            }
            else
            {
                cur = cur->next;
                pre = pre->next;
                count++;
            }
        }
        return false;
    }
}

//****************************************************************************************************
/*
    function name:insert

    function:按index插入结点

    input:
        L:要插入结点的链表头指针      type:linklist
        pos:要插入结点的位置(默认插入最后一个结点)       type:int
        elem:要插入结点的elem的值

    output:
        当pos超出索引时,打印"linklist index out of range."

    return:None
*/
void insert(linklist L,int elem,int pos = -1)
{
    //声明
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));     //申请连续空间
    new_node->elem = elem;
    Node *cur = L->next;                        //游标
    Node *pre = L;
    //若pos = -1或linklist的长度+1时,为普通的尾插法
    if(pos == -1 || pos == (L->elem + 1))
    {
        append(L,elem);
    }
    //pos不合法，打印"linklist index out of range."
    else if(((L->elem + 1) < pos) || (pos < 0))
    {
        cout << "linklist index out of range." << endl;
    }
    else
    {
        int count = 1;              //计数器
        while(cur != NULL)                //注意这里无法处理当pos = 表长+1的情形，我把它放在了第一个if分支实现
        {
            if(count == pos)              //若cur到达指定位置
            {
                new_node->next = cur;     //挂链
                pre->next = new_node;
                L->elem++;
                break;
            }
            cur = cur->next;
            pre = pre->next;
            count++;
        }
    }
}