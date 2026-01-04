//判断闰年
/*
#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
*/

//二进制转化为十进制
/*
        #include<iostream>
        #include<string>
        #include<cmath>
        using namespace std;

        int main()
        {
                string str;
                cin>>str;
                int n=str.length();
                int sum=0;
                for(int i=n-1;i>=0;i--)
                {
                sum+=(str[i]-'0')*pow(2,n-1-i);
                }
                cout<<sum;
        }
*/
//十进制转n进制
/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string decimalToN(int num, int n)
{
        if (num == 0) return "0";
        string result = "";
        bool isNegative = false;
        if (num < 0)
        {
                isNegative = true;
                num = -num;
        }
        while (num > 0)
        {
                int remainder = num % n;
                if (remainder < 10) {
                        result += char('0' + remainder);
                } else {
                        result += char('A' + remainder - 10);
                }
                num /= n;
        }
        reverse(result.begin(), result.end());
        if (isNegative)
        {
                result = "-" + result;
        }
        return result;
}

int main() {
        int num, n;
        cin >> num >> n;
        string result = decimalToN(num, n);
        cout << result << endl;
}
*/
//输入若干个整数,以-1标记输入结束。输出其中的最大数
/*
int main()
{
        int a, b;
        cin >> a;
        b = a;
        while (cin >> a)
        {
                if (a == -1)
                {
                        break;
                }
                if(a>b)
                        {
                        b = a;
                }
        }
        cout << b << endl;
}
*/
//计算斐波那契数列前n项之和，n由键盘输入。
/*
使用递归方法实现
int fibo(int n)
{
        if (n == 0)
                return 0;
        else if (n == 1)
                return 1;
        else
        return(fibo(n - 1) + fibo(n - 2));
}
int main()
{
        int x;
        cin >> x;
        int n;
        for (int i = 0; i < x; i++)
        {
                cin >> n;
                cout << fibo(n) << endl;
        }
}
使用非递归方法实现
int main()
{
        int n;
        cin >> n;
        int x;
        int arr[45] = { 0,1 };
        for (int i = 0; i < n; i++)
        {
                cin >> x;
                if (x == 0)
                {
                        cout << 0 <<endl;
                        continue;
                }
                if (x == 1)
                {
                        cout << 1 << endl;
                        continue;
                }
                for (int j = 0; j < x; j++)
                {
                        arr[j + 2] = arr[j] + arr[j + 1];
                }
                cout << arr[x] << endl;
        }
}
*/
//求最大公约数和最小公倍数（可以为负数）
        /*
        #include<iostream>
        #include<cmath>
        using namespace std;

        int main()
        {
                int m,n;
                cin>>m>>n;
                m=abs(m);
                n=abs(n);
                int b=n*m;
                if(m>n)
                {
                int temp=m;
                m=n;
                n=temp;
                }
                int a;
                while(n%m!=0)
                {
                a=n;
                n=m;
                m=a%m;
                }
                if(n%m==0)
                {
                cout<<m<<" "<<b/m;
                }
        }
        */
