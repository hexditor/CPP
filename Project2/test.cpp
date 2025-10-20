#include <iostream>
using namespace std;

//输入a、b、c三个值，输出其中最大值。
/*int main()
{
	int a;
	int b;
	int c;
	cin >> a >> b >> c;
	if (a>b && a>c)
	{
		cout << a << endl;
	}
	else if (b>a && b>c)
	{
		cout << b << endl;
	}
	else
	{
		cout << c << endl;
	}

}
*/

//从键盘输入长方形的长和宽，输出该长方形的周长和面积。
/*
int main()
{
	int a;
	int b;
	cin >> a >> b;
	cout <<  2 * (a + b);
	cout <<  a * b ;
}
*/

//输入一个华氏温度，要求输出摄氏温度。(保留两位小数)
/*int main()
{
	double f;
	cin >> f;
	double c= (f - 32) * 5.0 / 9.0;
	printf("%.2f\n",c);
}
*/

//设圆半径r，圆柱高h 求圆周长C1、圆面积Sa、圆球表面积Sb、圆球体积Va、圆柱体积Vb。 输入数据，输出计算结果，输出时要求文字说明，取小数点后两位数字。圆周率取值3.14
/*int main()
{
	double r, h;
	cin >> r >> h;
	double pi = 3.14;
	double C1 = 2 * pi * r;
	double Sa = pi * r * r;
	double Sb = 4 * pi * r * r;
	double Va = (4.0 / 3.0) * pi * r * r * r;
	double Vb = pi * r * r * h;
	printf("C1=%.2f\n", C1);
	printf("Sa=%.2f\n", Sa);
	printf("Sb=%.2f\n", Sb);
	printf("Va=%.2f\n", Va);
	printf("Vb=%.2f\n", Vb);
}
*/
//给出一百分制成绩，要求输出成绩等级‘A’、‘B’、‘C’、‘D’、‘E’。 90分以上为A 80-89分为B 70-79分为C 60-69分为D 60分以下为E
/*int main()
{
	int score;
	cin >> score;
	if (score >= 90)
	{
		cout << "A" << endl;
	}
	else if (score >= 80&&score<90)
	{
		cout << "B" << endl;
	}
	else if (score >= 70&&score<80)
	{
		cout << "C" << endl;
	}
	else if (score >= 60&&score<70)
	{
		cout << "D" << endl;
	}
	else
	{
		cout << "E" << endl;
	}
}
*/
/*企业发放的奖金根据利润提成。利润低于或等于100000元的，奖金可提10%;
 利润高于100000元，低于200000元（100000 < I≤200000）时，低于100000元的部分按10％提成，高于100000元的部分，可提成 7.5 %;
 200000 < I≤400000时，低于200000元部分仍按上述办法提成，（下同），高于200000元的部分按5％提成；
	400000 < I≤600000元时，高于400000元的部分按3％提成；600000 < I≤1000000时，高于600000元的部分按1.5 % 提成；
	I>1000000时，超过1000000元的部分按1 % 提成。从键盘输入当月利润I, 求应发奖金总数。

	输入格式
	一个整数，当月利润。

	输出格式
	一个整数，奖金。
	*/
/*int main()
	{
		int I;
		cin >> I;
		double bonus ;
		if (I <= 100000)
		{
			bonus = I * 0.1;
		}
		else if (I <= 200000&&I>100000)
		{
			bonus = 100000 * 0.1 + (I - 100000) * 0.075;
		}
		else if (I <= 400000&&I>200000)
		{
			bonus = 100000 * 0.1 + 100000 * 0.075 + (I - 200000) * 0.05;
		}
		else if (I <= 600000&&I>400000)
		{
			bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + (I - 400000) * 0.03;
		}
		else if (I <= 1000000&&I>600000)
		{
			bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + (I - 600000) * 0.015;
		}
		else
		{
			bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + 400000 * 0.015 + (I - 1000000) * 0.01;
		}
		printf("%.0f\n", bonus);
	}
	*/


/*int main()
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
		{
			cout << a << b;
		}
		else
		{
			cout << b << a;
		}
	}
	*/

	//给出一个不多于5位的整数，要求 1、求出它是几位数 2、分别输出每一位数字 3、按逆序输出各位数字
/*int main()
{
	int a;
	cin >> a;
	int b, c, d, e, f;
	if (a >= 10000)
	{
		cout << 5 << endl;
	}
	else if (a >= 1000 && a < 10000)
	{
		cout << 4 << endl;
	}
	else if (a >= 100 && a < 1000)
	{
		cout << 3 << endl;
	}
	else if (a >= 10 && a < 100)
	{
		cout << 2 << endl;
	}
	else
	{
		cout << 1 << endl;
	}
	b = a / 10000;
	c = (a - b * 10000) / 1000;
	d = (a - b * 10000 - c * 1000) / 100;
	e = (a - b * 10000 - c * 1000 - d * 100) / 10;
	f = (a - b * 10000 - c * 1000 - d * 100 - e * 10);
	cout << b << " " << c << " " << d << " " << e << " " << f << endl;
	cout << f << e << d << c << b << endl;

}
*/
/*int main()
{
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	printf("%.2f\n", distance);
}
*/




//求Sn=a+aa+aaa+…+aa…aaa（有n个a）之值，其中a是一个数字。例如：2+22+222+2222+22222（n=5），n由键盘输入。假定a为2.
/*int main()
{
	int n;
	cin >> n;
	int a = 2;
	int sum = 0;
	int term = 0;
	for (int i = 1; i <= n; i++)
	{
		term = term * 10 + a;
		sum = sum + term;
	}
	cout << sum << endl;
}
*/

//输入两个正整数m和n，求其最大公约数和最小公倍数。
/*
int main()
{
	int m, n;
	cin >> m >> n;
	int a = m;
	int b = n;
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	int gcd = a; 
	int lcm = m * n / gcd; 
	cout << gcd << endl;
	cout << lcm << endl;
}
*/

//求Sn=1!+2!+3!+4!+5!+…+n!之值，其中n是一个数字。

/*
int main()
{
	int n;
	cin >> n;
	int sum = 0;
	int fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact *= i;      
		sum += fact;    
	}
	cout << sum << endl;
}
*/

//求以下三个数的和，结果保留2位小数。三个数分别是： 1~a之和、 1~b的平方和、 1~c的倒数和,其中，a、b、c均为正整数。
/*
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	double sum1 = 0;
	double sum2 = 0;
	double sum3 = 0;
	for (int i = 1; i <= a; i++)
	{
		sum1 += i;
	}
	for (int i = 1; i <= b; i++)
	{
		sum2 += i * i;
	}
	for (int i = 1; i <= c; i++)
	{
		sum3 += 1.0 / i;
	}
	double sum = sum1 + sum2 + sum3;
	printf("%.2f\n", sum);
}
*/

//打印出所有"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该本身。
/*int main()
{
	for (int i = 100; i <= 999; i++)
	{
		int a = i / 100;
		int b = (i / 10) % 10;
		int c = i % 10;
		if (i == a * a * a + b * b * b + c * c * c)
		{
			cout << i << endl;
		}
	}
}
*/


//求出10至1000之内能同时被2、3、7整除的数，并输出。每行一个
/*int main()
{
	for (int i = 10; i <= 1000; i++)
	{
		if (i % 2 == 0 && i % 3 == 0 && i % 7 == 0)
		{
			cout << i << endl;
		}
	}
}
*/


//有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前N项之和，其中N由键盘输入。
/*int main()
{
    int N;
    cin >> N;
    double sum = 0.0;
    double numerator = 2.0, denominator = 1.0;
    for (int i = 1; i <= N; i++)
    {
        sum += numerator / denominator;
        double temp = numerator;
        numerator = numerator + denominator;
        denominator = temp;
    }
    printf("%.2f\n", sum);
}
*/

//筛选出N以内的素数，N由键盘输入。
/*
int main()
{
    int N;
    cin >> N;
    cout<<"2"<<endl;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
            else if (j==i-1)
            {
            cout<<i<<endl; 
            }
        }
    }
}
*/

//判断一个数是否是素数
/*
#include<iostream>
using namespace std;

int main()
{
    int n; 
    cin>>n; 
    for (int i=2; i<n; i++)
    {
    if(n%i==0)
    {cout<<"not prime"; 
    break; }
    else if(i==n-1)
    {cout<<"prime";
    break;  }
    }
}
*/

/*
打印图形
   *
  ***
 *****
*******
*/
/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    for(int j=1;j<=n;j++)
    {
    if(j<=n-i)
    {
    cout<<" ";
    }
    else
    {
    cout<<"*";
    }
    }
    for(int k=1; k<i; k++)
    {
    cout<<"*"; 
    }
    cout<<endl;
    }
}
*/

//输入二次方程ax^2+bx+c=0的三个系数a, b, c, 计算方程的根
/*
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    if (delta < 0)
     {
        double r=(-b)/(2*a); 
        double i=sqrt(-delta)/(2*a); 
        if(r==0)
        {
        cout <<i<<"i"<<' '<<"-"<<i<<"i";
        }
        else
        {
        cout <<r<<"+"<<i<<"i"<<' '<<r<<"-"<<i<<"i";
        }
    }
    else
    {
    double x1 = (-b + sqrt(delta)) / (2 * a);
    double x2 = (-b - sqrt(delta)) / (2 * a);
    if (x2 > x1) swap(x1, x2);
    cout << x1 << " " << x2 << endl;
    }
}
*/

/*输入数字和图形，打印图形
输入:
5
*
输出:
  *
 ***
*****
 ***
  *
*/
/*
int main()
{
    int N;
    cin>>N;
    int n ;
    n=(N+1)/2;
    char ch; 
    cin>>ch; 
    for(int i=1;i<=n;i++)
    {
    for(int j=1;j<=n;j++)
    {
    if(j<=n-i)
    {
    cout<<" ";
    }
    else
    {
    cout<<ch;
    }
    }
    for(int k=1; k<i; k++)
    {
    cout<<ch; 
    }
    cout<<endl;
    }
    for(int a=n; a>=1; a--)
    {
    for(int b=n; b>=1; b--)
    {
    if(b>=a)
    {
    cout<<" ";
    }
    else
    {
    cout<<ch; 
    }
    }
    for(int c=a-1; c>=2;c--)
    {
    cout<<ch;
    }
    cout<<endl; 
    }
}
*/
//A每天给B 10万元，b每天给A2^(n-1)元，即第一天一元，第二天两元，第三天4元，求第N天后，A开始赚钱
/*
int main()
{
    double a;
    int b;
    int n;
    for(n=1; n>0; n++)
    {
        a=pow(2, n)-1;
        b=100000*n;
        if(a>b)
        {
            break;
        }
    }
    cout<<n;
}
*/