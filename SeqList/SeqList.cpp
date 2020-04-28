#include<iostream>
using namespace std;
#define MAXSIZE 100

typedef struct 
{
    int elem[MAXSIZE];
    int last;                    //last始终指向当前顺序表中最后一个元素的后一个位置
}*seqlist;

/*
    function name:remove
    function:删除顺序表中指定索引的元素
    input:
        L:要删除元素的顺序表    type:seqlist
    output:None
    return:None
*/
void remove(seqlist L,int loc)
{
    int i;
    for(i = loc;i < 20;i++)
    {
        L->elem[i-1] = L->elem[i];
    }
    L->last--;
}

/*
    function name:merge
    function:将两个元素非递减的顺序表合并为一个元素非递减的顺序表并返回
    input:
        LA,LB:要合并的两个非递减顺序表     type:seqlist
    output:None
    return:
        LC:合并的元素非递减的顺序表
*/
seqlist merge(seqlist LA,seqlist LB)
{
    // 声明新的顺序表
    seqlist LC = (seqlist)malloc(sizeof(seqlist));
    LC->last = 0;
    // 声明LA,LB的移动下标
    int i = 0,j = 0;
    while(i < LA->last && j < LB->last)
    {
        if(LA->elem[i] < LB->elem[j])
        {
            LC->elem[LC->last] = LA->elem[i];
            LC->last++;
            i++;
        }
        else
        {
            LC->elem[LC->last] = LB->elem[j];
            LC->last++;
            j++;
        }
    }
    //LA元素未全部放入LC时
    while(i < LA->last)
    {
        LC->elem[LC->last] = LA->elem[i];
        LC->last++;
        i++;
    }
    //LB元素未全部放入LC时
    while(j < LB->last)
    {
        LC->elem[LC->last] = LB->elem[j];
        LC->last++;
        j++;
    }
    return LC;
}
