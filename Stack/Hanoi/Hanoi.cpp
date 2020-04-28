#include<iostream>
using namespace std;

/*
    n:出发位置的盘子数
    x:这n个盘子的位置
    y:这n个盘子的前n-1个盘子的转移目的地
    z:中转站，用来构造递归
*/
void Hanoi(int n,char x,char y,char z)
{
    if(n == 1)
    {  
        //若n = 1，直接将唯一的盘子转移到目的地
        cout <<  x << "->" << y << endl; 
    }
    else
    {
        //若n != 1，将最上面n-1个盘子从x移动到z
        Hanoi(n-1,x,z,y);
        // 将原始最底层的盘子转移到目的地y
        cout << x << "->" << y << endl;
        //问题又转变为将z上面的n-1的盘子转移到y了
        Hanoi(n-1,z,y,x);
    }
    
}

int main()
{
    Hanoi(3,'x','z','y');
    return 0;
}