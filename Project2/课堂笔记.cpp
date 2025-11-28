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
}
*/

//转义符
/*
\0 表示串结束符(空字符)
\n 表示换行
\t 表示制表符，体现为长空格
*/

//强制类型转换
/*
类型 (表达式)
如
int ('a')
会把a转成97
把高类型数据转为低类型数据，会造成数据丢失
如把double，转成int，只保留整数
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
cin也可以加
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

//cin.eof()
/*
`cin.eof()` 是 C++ 标准输入流（`cin`）中用来判断输入流（通常是标准输入/键盘）是否到达“文件结束”（EOF, End Of File）标志的方法。
-当输入流遇到文件结束标志（EOF）时，`cin.eof()` 返回 `true`，否则返回 `false`。

- 在读取文件时，EOF 表示已经读到文件末尾，没有更多内容可读。
- 在键盘输入时，用户可以通过特定的键盘操作输入 EOF：
  - Windows：按下 `Ctrl+Z` 然后回车
  - Linux/Mac：按下 `Ctrl+D`

用法:

1. 循环读取输入直到 EOF
#include <iostream>
using namespace std;

int main() {
    int num;
    while (cin >> num) {
        cout << "输入的是：" << num << endl;
    }
    // 当遇到EOF时，cin会进入失败状态，循环结束
    if (cin.eof()) {
        cout << "遇到文件结尾（EOF）!" << endl;
    }
    return 0;
}

 2. 用 cin.eof() 判断是否为 EOF

一般不建议用 `while (!cin.eof())`，因为只有在尝试读取数据失败后，`eof()` 才会变为 `true`，而不是提前变为 `true`。

**错误用法示例：

```cpp
// 不推荐这样用
while (!cin.eof()) {
    int x;
    cin >> x;
    // ... 这样最后一次读取会读到EOF，但x的值未定义
}
推荐用法：

直接用流的返回值作为判断条件：

int x;
while (cin >> x) {
    // 处理x
}


如果需要在循环外判断是否是因为EOF导致退出，可以用 `cin.eof()`：

if (cin.eof()) {
    cout << "输入结束（EOF）" << endl;
}

cin.eof() 的常见场景: 

- **文件输入**：处理文件时判断是否到达文件结尾。
- **多组数据输入**：在线评测或批量处理数据时，循环读取直到EOF。
- **交互式输入**：用户输入数据后用EOF结束输入。


注意事项: 

1. **只有在读取失败后，eof() 才会变为 true。**
   - 例如，`cin >> x` 读取失败（到达EOF），此时 `cin.eof()` 为真。
2. **不要把 `while(!cin.eof())` 作为循环条件。
   - 推荐用 `while (cin >> x)`。
3. **判断是否因为 EOF 退出循环，可以在循环后用 `cin.eof()` 检查**。

示例：
统计输入的所有整数之和，直到EOF

#include <iostream>
using namespace std;

int main() {
    int sum = 0, x;
    while (cin >> x) {
        sum += x;
    }
    cout << "总和: " << sum << endl;
    if (cin.eof()) {
        cout << "遇到EOF，输入结束。" << endl;
    }
    return 0;
}
*/

//静态变量
/*
定义变量时，在类型前加static，即可定义静态变量
否则，为动态变量
不进行初始化时，静态变量默认为0
静态变量创建之后，开辟内存，不会再销毁
例如执行函数时，形参在执行完函数后，会销毁内存，但静态变量不会，
如:用于统计函数被调用的次数：
#include <iostream>
using namespace std;

void printCount() {
    static int count = 0;
 // static静态局部变量，只初始化一次
    count++;
    cout << "这个函数已经被调用了 " << count << " 次" << endl;
}

int main() {
    for(int i = 0; i < 5; i++) {
        printCount();
    }
    return 0;
}

**输出结果：
这个函数已经被调用了 1 次
这个函数已经被调用了 2 次
这个函数已经被调用了 3 次
这个函数已经被调用了 4 次
这个函数已经被调用了 5 次

- `static int count = 0;`  
 这个变量在函数多次调用过程中值不会丢失，只初始化一次。每次`printCount`被调用时，`count`会递增1。
- 静态局部变量常用于需要**记忆状态**的场合。
*/

//标识符作用域
/*
1.块作用域
可用{}划分作用域
如
{
int A=1; 
{
int A=2; 
cout<<A; 
//动态变量只存在于一个块作用域内，出大括号就被销毁
}
cout<<A; 
}
结果为2 1
2.文件作用域变量
不再任何一个{}内定义的变量，作用于它出现之后
如
#include<iostream>
using namespace std ;
int a;
void function()
{}
int b;
int main()
{}
a作用于全局，b作用于function函数外的部分
3.全局变量与局部变量
当全局变量与块内变量同名时，屏蔽全局量，执行块内量
如果想操纵全局量，需要在变量名前加::
全局变量不会因块作用域结束而销毁内存
如:
#include<iostream>
using namespace std ;
int a=0; 
int func()
{
int a=10; 
static int b=100; 
::a+=1; 
a+=10; 
b+=100; 
cout<<::a<<" "; 
cout<<a<<" "; 
cout<<b<<" "; 
return ::a+a+b;
}
int main()
{
cout<<func () <<endl; 
cout<<func () <<endl; 
return 0; 
}
结果为
1 20 200 221
2 20 300 322
*/

//文件包含
/*
#include<文件名>
或
#include"文件名"
系统自带的文件用<>
自己创建的用""
*/

//宏定义
/*
带参数的#define 可用于定义简单函数
如
#define area(r) 3.14*r*r
相当于
double area(double r)
{
    return 3.14 * r * r;
}
*/

//命名空间
/*
定义命名空间
在主函数前面可以定义命名空间
语法:
namespace <标识符>
{语法序列}
例如:
namespace A
{
void f（）；
void d（）；
namespace B
{
void e（）；
}  //可嵌套
}
namespace A  //追加补充
{
void g（）；
}

使用命名空间
using namespace 命名空间；
或
using 命名空间::元素；

例如
标准名空间为 std
using namespace std；
意思是使用std中的所有元素
using std::cin; 
意思是只使用std中的cin命令

调用命名空间内的函数前，需要先使用命名空间
即使已经定义，也需要再写一句
using namespace 命名空间;

嵌套命名空间时，只需要使用最外层的命名空间
但如果想使用内层命名空间中的元素，需标明
如
using namespace std; 
void f();  
namespace A
{
void f(); 
namespace B
{
void f(); 
}
}
f（）; //此时调用f函数，默认调用命名空间A外的函数
using namespace A; 
f（）;   //如此调用，f被当做重载函数，可能调用A
外的，也可能是A内的
A::f（）//如此调用，调用A中的f，但不是B中的
B::f（）//如此调用，才可调用B中的f函数

如果两个命名空间里有同名函数
则使用时需要标明命名空间
例如A::function
指明要执行哪一个函数
否则会被当做重载函数处理

*/

//终止程序执行
/*
1. abort ();
关闭程序执行框
2. assert(整型表达式，例如a>0)
满足条件时关闭程序执行框
3. exit（整型常量）
关闭程序执行框，并将括号中的常量作为退出代码返回操作系统（可省略）
*/

//实现int arr[n];
/*
#include <iostream>
using namespace std;

int n;
cin >> n;
int* arr = new int[n]; // 用 new 分配长度为 n 的数组
// 用完后记得释放
delete[] arr;


#include <iostream>
#include <vector>
using namespace std;

int n;
cin >> n;
vector<int> arr(n);  // 定义一个长度为 n 的数组
*/

//数组
/*
1.数组本质是指针，下标是指针偏移量
例如:
int arr[5];
arr[2]即为arr[0]偏移了2*sizeof（int）个字节
arr+1就是arr[1]的地址，也就是&arr[i]
*（arr+i）就是arr[i]
2. int arr[5]={0}; 可以将数组的所有元素赋成0

3.数组传参
传数组就是传指针，会将数组的头指针传到函数中，函数中修改数组的值，原数组会受影响
为了防止修改原数组，可以在定义函数时，在参数前加const 

f(const int a[]){}
其中的a仅仅是指针，只占一个指针的内存

传数组的值，即只传数组中某个元素，此时函数中修改数组的值，对原数组无影响

定义函数f(int a[]){} 也可以f(int *a){}
主函数中 int arr[7]; 
调用函数f(arr); 将arr数组传给了函数中的a

4.二维数组
相当于往数组里放数组，即数组中的元素都是数组
同理还有更高维的数组
定义时，可省略高维数组长度，不能省略低维数组长度
int arr[3][]={1, 2, 3, 4, 5, 6};  //错误
int arr[3][4]={0}; //可将所有元素初始化为0
*/

//setw()设置数据宽度(右对齐)
/*
需头文件<iomanip>

将他后面的内容右对齐
如cout<<setw(5)<<"123";
会输出  123，123前有两个空格

只作用它后面一个输出内容cout<<setw(5)<<"123"<<"321";
只对"123"生效，不对"321生效"

超过长度不会截取
cout<<sets(3)<<"12345"; 
仍然会输出12345

*/

//动态储存
/*
1. new 动态分配储存空间
语法: 指针变量=new 类型
例如: 
int *p; 
int n; 
cin>>n; 
p=new int[n]; 
或者 int *p=new int[n]; 
p=new int(10);  //可以在定义时赋值
p=new int[n](); //将数组中的元素赋值为0
2. delete 释放内存
语法:delete 指针变量
例如:
delete[]p; //删除数组
delete p;  //删除整型

使用new 后，一定要使用delete, 否则会造成内存泄漏

*/

//vector 
/*
需头文件<vector>

1. 创建
vector<int> vec1;              // 空vector，相当于指针
vector<int> vec2(5, 10);       // 5个元素，每个都是10
vector<int> vec2(10);       //10个元素，默认都是0
vector<int> vec3 = {1, 2, 3};  // 初始化列表
vector<int> vec4(vec3);        // 拷贝构造

2. 访问
vec[0] = 10;           // 下标访问（不检查边界）
vec.at(1) = 20;        // 带边界检查的访问
int first = vec.front(); // 第一个元素
int last = vec.back();   // 最后一个元素
a=b;                  //b赋值给a(复制)
向量比较，同字符串比较法相同(==，!=，>=等等)
从第一个元素开始，比较ASCII码
ASCII码大的，向量较大
如果相等，比较第二个元素
ASCII码大的，向量较大
以此类推
比如ABCAA<ABCBBAAA

3. 添加，删除元素
vec.push_back(30);     // 在末尾添加元素
vec.pop_back();        // 删除末尾元素
vec.insert(vec.begin() + 1, 25); // 在指定位置插入
vec.erase(vec.begin() + 2);      // 删除指定位置元素
vec.clear();           // 清空所有元素
vec.insert(vec.begin, arr.begin, vec.end) //在arr.begin之前插入从vec.begin到vec.end之间的所有元素

4. 容量操作
int size = vec.size();         // 当前元素个数
bool empty = vec.empty();      // 判断是否为空
vec.resize(10);               // 调整大小
int capacity = vec.capacity(); // 当前容量
vec.reserve(100);             // 预分配空间
*/

//字符串
/*
1. C字符串(char型数组)
char str1[]="student";  
//结尾默认添加一个'\0'串结束符，用于识别字符串的结束
char ch[80]; //只能存储79个字符，第80个用于存放'\0'
想输入带有空格的字符串，不能用cin，要用cin.get
2.串处理函数(需头文件<cstring>)
strlen(str)        //求串长(不包括'\0')
strcpy_s(des, str) //把str复制给des
strcmp(a, b).      //串比较，相等返回0，a大于b返回正数，a小于b返回负数
3. string
需头文件<string>
name.size()  //返回串长(包括'\0')
name.length()//返回串长(不包括'\0')
a+=b;        //把b拼接在a后面
a=b;         //把b赋值给a
name.find(c) //查找字符c, 返回第一次出现的下标
s.find(c,idx)//从s[idx]开始查找字符c, 返回第一次出现的下标

reverse(str.begin(), str.end());
//反转字符串(需头文件<algorithm>)
*/

