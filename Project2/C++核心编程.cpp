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
还可以用于检验输入的正确性
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

(3)注意事项
如果不写构造函数和析构函数，系统会为每个类，自行创建并调用构造函数和析构函数，但都是空函数，只调用，不执行命令
其中构造函数会创建两种(默认构造，拷贝构造函数)
如果写了其中一种，系统就只会提供其他的函数

即使没有自行定义拷贝构造函数，在试图使用拷贝构造初始化成员时，也能够初始化
例如
person p(p1); 
会将p1的所有属性都赋值给p

如果写了一个有参数的构造函数(不是拷贝构造)
那么系统就将不提供无参数默认构造函数，但会提供拷贝构造函数
此时如果试图通过默认构造初始化成员
例如
person p;
则会报错，因为没有合适的构造函数可用
必须写成 person p(参数);的形式，或者再定义一个合适的构造函数

如果自行定义了一个拷贝构造函数，系统将不会提供任何构造函数

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

拷贝构造会在通过值传递的方式给函数传参被调用
例如 

//接收到p后，会调用一次拷贝构造函数，将接收到的p拷贝到形参上，还会执行一次析构函数(相当于执行了一次 person p=p)
void dowork(person p)
{

}

void test()
{
person p; //会调用一次普通构造函数，和一次析构函数
dowork(p); //传递给dowork函数中
}

会调用一次普通构造函数
一次拷贝构造函数
两次析构函数

还会被通过返回值方式返回对象时调用
例如
person dowork()
{
person 1;.  //调用一次普通构造，和一次析构
return p1;  //将p1返回给p
}

void test ()
{
person p=dowork(); 
}
//会将接收到的p1拷贝给p, 调用一次拷贝构造，一次析构

会调用一次普通构造函数
一次拷贝构造函数
两次析构函数

拷贝分为深拷贝与浅拷贝
浅拷贝 仅复制地址，新旧对象指向同一块内存
两个对象互相影响，改一个另一个也会变
析构时，会将同一快内存释放多次，引起崩溃
例如
class String {
public:
    char* data;
    String(const char* str) 
    {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    // 默认浅拷贝构造函数
    ~String() { delete[] data; }
};

int main() {
    String s1("Hello");
    String s2 = s1; // 浅拷贝：s1.data 和 s2.data 指向同一内存
    return 0;       // 析构时两次释放同一内存，导致未定义行为
}

深拷贝 则需要在堆区重新申请空间，再进行拷贝
新的对象有新的内存，二者互不影响
例如
class GoodString {
public:
    char* data;
    size_t len;

    // 构造函数
    GoodString(const char* str) {
        len = strlen(str);
        data = new char[len + 1];
        strcpy(data, str);
    }

    // 深拷贝构造函数
    GoodString(const GoodString& other) {
        len = other.len;
        data = new char[len + 1];
        strcpy(data, other.data);
    }

    // 深拷贝赋值运算符
    GoodString& operator=(const GoodString& other) {
        if (this != &other) { // 防止自我赋值
            delete[] data;    // 释放原有资源
            len = other.len;
            data = new char[len + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    ~GoodString() { delete[] data; }
};

int main() {
    GoodString s1("Hello");
    GoodString s2 = s1; // 调用深拷贝构造函数
    s2.data[0] = 'h';   // 修改s2不影响s1
    return 0;
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

4.初始化列表
用于初始化属性
语法
构造函数():属性1(值1)，属性2(值2)……{}
例如
class person
{
public: 
person(): A(10), B(20), C(30)
{

}
int A; 
int B; 
int C; 
}; 
也可以
class person
{
public: 
person(int a, int b, int c): A(a), B(b), C(c)
{

}
}; 
void ()
{
person p(30 20 10); 
}

5. 类对象作为类成员
类的成员可以是另一个类的对象，称该成员为成员对象
class A
{
int m; 
}
class B
{
A a; 
}
在B类中创建一个A类型的属性，这个A类型还是一个类
创建一个B的成员时，会先构造一个A的成员，再构造自身
析构的顺序与构造相反

6.静态成员
>>静态成员变量
所有成员共用同一份数据
在编译阶段分配内存
类内声明，类外初始化
可以设置权限
例如
class person
{
public: 
static int a; 
}; 

int person: : a=100; 
void test()
{
person p1; //此时p1.a=100
person p2; //此时p2.a=100
p1.a=200;  //此时p1.a和p2.a都是200
cout<<person: : a; //可以直接通过类名访问
}

>>静态成员函数
所有对象共享同一函数
静态成员函数只能访问静态成员变量
可以设置权限
例如
class person
{
public: 
static void f()
{
a=100; 
b=200; //错误，不能访问非静态变量
}
static int a; 
int b; 
}; 
void()
{
person p; 
p.f();         //可以通过成员访问
person: : f(); //可以通过类名访问
}
*/
