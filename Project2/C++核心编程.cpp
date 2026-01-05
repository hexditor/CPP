//内存分区模型
/*
内存可以分为四个区
在程序编译之后，生成了.exe可执行程序

程序执行前:
1.代码区:存放函数体的二进制代码，由操作系统进行管理
代码区是共享的，只需在内存中存有一份代码
代码区是只读的，防止被程序意外修改

2.全局区:存放全局变量，静态变量和常量
该区域的数据，在程序结束后，操作系统会将其释放
不含局部常量和宏常量，常量只含全局常量(const修饰变量)和字符串常量

程序执行后:
1. 栈区:开辟的数据由编译器自动释放，存放函数的形式参数，局部变量等
避免返回局部变量的地址，因为局部变量储存在栈区，程序执行后，会被释放，此时返回的地址为野指针，再次执行是，局部变量的地址已经改变

2. 堆区:由程序员管理，如果程序员不释放，系统会在程序结束后释放
new int(10);      
//表示在堆区开辟了一块整型内存，并储存数据10，此语句返回一个地址，需要用指针接收
int *p=new int(10); 
//而指针本质是局部变量，储存在栈区，但指针指向的数据是在堆区的
delete p;           
//释放内存后，不能再访问
int *arr=new int[10];
//创建十个元素的数组
delete []arr;
//释放数组
*/

//引用
/*
int &b=a;
//给a起了一个别名b，对b进行修改，等同于对a进行修改
引用必须初始化，且初始化后不能改变
比如 int &b; 就是错误的

>>引用做函数返回值<<
注意:不要返回局部变量的引用
使用示例:
int& f()
{
static int a=10; 
return &a;
}
int main ()
{
int &b = f();
cout<<b<<endl; 
f()=1000;    //引用类型的函数可以做左值
cout<<b<<endl;
}
输出结果为:
10
1000

>>引用的本质<<
引用的本质是一个指针常量(指谁不变，值可变)
int &ref=a;
相当于 int *const ref=&a; 
之后 对ref=10; 相当于 *ref=10;

>>常量引用<<
const int &ref = 10;
//定义了一个值固定为10的引用，但该引用没有原名

用于修饰函数形参，防止误操作
void show(conat int& val) 
//函数体内无法再修改val的值
{
cout<<val<<endl; 
}
*/

//类和对象
//封装
/*
1.含义:权限不同的结构体(结构体默认public,类默认private)
2.语法
class 类名
{

访问权限

public:

属性

行为

}
例如:
class circle
{
public: 

int r;  //属性

double calculate_girth()
{
return 2*3.14*r; 
}
//行为(求周长)
};

int main()
{
circle c1;  //创建一个circle类对象
c1.r=10;  //对该对象的属性进行修改
cout<<c1.calculate_girth(); //执行该对象的行为
}

3. 权限
(1)public 公共
类内可以访问，类外也可访问
(2)protected 保护
类内可以访问，类外不可以访问
(3)private 私有
类内可以访问，类外不可以访问
例如
class person
{
public: 
string name; 

protected : 
string car; 

private: 
string password; 

public: 
void f()
{
name ="bob"; 
car = "suv"; 
password ="114514"
}
}; 
int main()
{
person p1; 
p1.name="fullhouse"  //可以访问
p1.password="123456" //错误，不可访问
}

私有权限可以用于设置某些属性为只读或只写
还可以检验输入的正确性
例如:
class person
{

public: 
void set_name(string set_name)
{
name=set_name; 
}

string get_name()
{
return name; 
}

int get_age()
{
return age; 
}

private : 
string name;
int age=18; 
}; 

int main()
{
person p1; 
p1.name="fullhouse";  //错误，不可访问
cout<<p1.name;        //错误，不可访问

p1.set_name("fullhouse");
cout<<p1.get_name(); //将name设置为可读可写
cout<<p1.age(); //将age设置为可写
}

*/
//对象的初始化与清理
/*
1.构造函数与析构函数
(1)构造函数:用于在创建对象时为对象成员的属性进行初始化
语法 : 类名 (){}

无返回值，也不用写void
函数名与类名相同
可以有参数，可以重载
程序调用对象时，由编译器自动调用，无需手动调用，且只会调用一次



(2)析构函数:执行清理工作
语法: ~类名 (){}

无返回值，也不用写void
函数名与类名相同，在名称前加~
不可以有参数，不能重载
在对象销毁前，程序自动调用，无需手动调用，只能调用一次

例如
class person 
{

 public: 
 person ()
{
cout <<"调用了构造函数"<<endl;
}

 ~person ()
{
cout <<"调用了析构函数"<<endl;
}

}; 

void f()
{
 person p1; 
}

int main()
{
person p2; 
void(); 
}

结果为
调用了构造函数
调用了构造函数
调用了析构函数
调用了析构函数

最后一行在"调用了析构函数"，是在程序结束后输出的
因为此时p2被销毁，会调用析构函数，但由于程序已经结束，故可能无法察觉

如果不写构造函数和析构函数，系统会自行创建并调用构造函数和析构函数，但都是空函数，只调用，不执行命令

2.构造函数的分类与调用
(1)分类
按参数分:
>>无参构造(默认构造)
person ()
{
cout <<"调用了构造函数"<<endl;
}
>>有参构造
person (int a)
{
cout <<"调用了构造函数"<<endl;
}
按类型分:
>>普通构造
>>拷贝构造
person (const person &p)
{
age=p.age; 
//将传入的成员的属性，拷贝到调用的成员的身上
}

(2)调用
>>括号法
class person 
{
public:
int age; 

person ()
{
age=10; 
}

person (int a)
{
age=20; 
}

person (const person &p)
{
age=p.age;
}
}; 

void test()
{
person p1;     //调用默认构造函数 age为10
person p2(10); //调用有参构造函数 age为20
person p3(p3); //调用拷贝构造函数 age为20

person p1();   //错误，调用默认构造时，不要加()，因为此行代码会被认为是函数的声明
}

>>显式法
void test()
{
person p1;            //调用默认构造函数 age为10
person p2=person(10); //调用有参构造函数 age为20
person p3=person(p2); //调用拷贝构造函数 age为20
}

>>隐式转换法
person p4=10; //相当于 person p4=person(10)
person p4=p5; //相当于 person p4=person(p4)

3.匿名对象
person;     //创建一个匿名对象，调用默认构造函数
person(10); //创建一个匿名对象，调用有参构造函数
匿名对象创建后，会调用构造函数，
执行完该语句后，立即被销毁，并调用析构函数

不要用拷贝构造函数初始化匿名对象
person(p3); //错误，该行代码等价为 person p3
但由于之前已经有一个同名成员p3了，所以会报错
*/
