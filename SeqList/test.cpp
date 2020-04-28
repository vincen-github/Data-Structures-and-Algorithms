#include<iostream>
#include "SeqList.cpp"
using namespace std;

int main()
{
    seqlist LA = (seqlist)malloc(sizeof(seqlist));
    seqlist LB = (seqlist)malloc(sizeof(seqlist));
    LA->last = 0;
    LB->last = 0;
    // 给LA，LB赋值
    int a[5] = {2,2,3,7,9};
    int b[4] = {1,3,3,4};
    for(int i = 0;i < 5;i++)
    {
        LA->elem[i] = a[i];
        LA->last++;
    }
    for(int j  = 0;j < 4;j++)
    {
        LB->elem[j] = b[j];
        LB->last++;
    }
    //test function merge
    seqlist LC = (seqlist)malloc(sizeof(seqlist));
    LC = merge(LA,LB);
    cout << LC->last << endl;
    for(int i = 0;i < 9;i++)
    {
        cout << LC->elem[i] << ' ';
    }
    return 0;
}
