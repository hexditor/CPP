//保留小数的方法:
#include <iomanip>
#include <iostream>
using namespace std;
/*int main()
{

    double k = 0.123456;
    //变量必须是浮点型
    //前三种作用于全局且需要头文件，最后一种只作用于一个变量
    cout << setiosflags(ios::fixed) << setprecision(2) << endl;

    cout.setf(ios::fixed);
    cout << setprecision(2) << endl;

    cout << fixed << setprecision(2) << endl;


    printf("%.3f", k);
//为了防止程序报错，也可以加头文件<studio.h>
//如果想使用科学计数法，要用printf("%.3e", k);
//    \n表示回车
}
*/


//指针:
/*
1.取址符:&
double <<a;
cout <<&a; //会输出a的地址(也叫指针)
2.间址符:*
cout <<*(&a);
//表示变量a的地址所指的对象，即变量a
3.整型指针: int *
int *a;    //此时a储存的是地址
int p=55;
a=&p;      //此时a储存的是p的地址
cout <<a;  //输出p的地址
cout <<*a; //输出"55"
a++;
//将指针右移一位，此时a储存p后侧一位的内存的地址
//同理，还有double *a; 浮点型指针
4.空指针
char *s=0;
double *p=NULL;
*/

//引用: *
/*
语法: 类型 &引用名 = 对象名;
int a;
int &A=a;
//此时变量a有了两个名字，a和A
输出A，与输出a效果一致
*/

//常量
/*
1.  const int p = 1;    //锁值
2.  const int *p;       //锁值
    int const *p;       //锁值
3.  int *const p;       //锁地址
4.  const int *const p; //锁值和地址
    int const *const p; //锁值和地址

*/

//进制
/*
int a =10
cout<<oct<<a; //输出八进制数12
cout<<dec<<a; //输出十进制数10
cout<<hex<<a; //输出十六进制数a
*/

//数学
/*
需头文件#include <cmath>
平方根      sqrt()
绝对值      abs()
浮点型绝对值 fabs()
幂运算      pow (底数, 指数)
余弦        cos()
*/

//cin.get()
/*
从键盘读取字符的函数，用于读取字符，包括空格、回车等不可见字符
（1）读取单个字符
char ch;
cin.get(ch);
输入一个字符并存入 ch
char ch = cin.get(); 
输入一个字符并返回其ASCII值（int类型），并将ASCII码值存入ch
（2）读取一整行（含空格）
char line[100];
cin.get(line, 100); 
读取一行，最多99个字符，遇到换行符停止

cin.get() 适合需要精确控制输入、逐字符处理、读取包含空格/回车的场合
与 cin >> 相比，cin.get() 能读取空格和回车，不会自动跳过它们。
*/

//函数
/*
函数中执行到return时，立刻结束函数，不执行后续语句
一个函数可以有多个return，但只能执行一个
如果返回值类型与函数类型不一致，会将返回值强制转换为函数类型

return x++
会将x返回，而非x+1
return ++x
会返回x+1
*/

//while(cin>>)
/*
重复输入变量，每输入一次变量之后，执行一次循环体，再进行下一次输入
直至输入终止符(Ctrl+z+Enter)，或者达成结束条件

即，当从标准输入成功读取数据到变量时，循环继续；否则，循环停止。
*/

