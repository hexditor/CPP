//选择排序
/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *p = new int[n](); 
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int t, max;
    for(int i = 0; i < n - 1; i++)
    {
    t=i;
        for(int j = i+1; j < n ; j++)
        {
            if(p[j] > p[t])
            {
                t=j;
            }
        }
        if(t!=i)
        {
            max=p[i];
            p[i]=p[t];
            p[t]=max;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << p[i] << " ";  
    }
    delete[] p;
}
*/

//冒泡排序
/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *p = new int[n](); 
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(p[j] > p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << p[i] << " ";  
    }
    delete[] p;
}
*/