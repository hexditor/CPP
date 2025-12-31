//输入若干个（小于100）值为0~9的数字，各个数字之间以空格分隔，以-1表示输入结束。要求统计出现次数最多的数字，并将出现次数最多的数字、出现次数、出现的位置分别输出。
/*
        #include <iostream>
        using namespace std;

        int main()
        {
                int x = 0;
                int arr[100] = { 0 };
                int number[10] = { 0 };
                for (int i = 0; i < 100; i++)
                {
                        cin >> arr[i];
                        if (arr[i] == -1)
                        {
                                break;
                        }
                        number[arr[i]]++;
                        x++;
                }
                int max = number[0];
                int num=0;
                for (int i = 1; i < 10; i++)
                {
                        if(number[i]>max)
                        {
                                max=number[i];
                                num = i;
                        }
                }

                int location[100] = { 0 };
                int xx = 0;
                for (int i = 0; i < x; i++)
                {
                        if (arr[i] == num)
                        {
                                location[xx] = i+1;
                                xx++;
                        }
                }
                cout << num << endl << max << endl;
                for (int i = 0; i < xx; i++)
                {
                        cout << location[i] << ' ';
                }
        }
*/
//整理一下电话号码列表，使其按照名字升序排序。
/*
        #include<iostream>
        #include<string>
        using namespace std;

        int main()
        {
                struct person
                {
                        string name;
                        string number;
                };
                person people[100];
                int n=0;
                while (cin>>people[n].name>>people[n].number)
                {
                        n++;
                }
                for(int i=0; i<n-1; i++)
                {
                        for(int j=0; j<n-i-1; j++)
                        {
                                if(people[j].name>people[j+1].name)
                                {
                                        string temp1 =people[j].name;
                                        people[j].name=people[j+1].name;
                                        people[j+1].name=temp1;
                                        string temp2 =people[j].number;
                                        people[j].number=people[j+1].number;
                                        people[j+1].number=temp2;
                                }
                        }
                }
                for(int i=0; i<n; i++)
                {
                        cout<<people[i].name<<"  "<<people[i].number<<endl;
                }
        }
*/
//处理3*4整型矩阵Array[3][4]，找出每行中最大元素并与改行首个元素交换，每行最大元素无重复。
/*
        #include<iostream>
        using namespace std;
        void f(int array[3][4])
        {
        int temp;
        int arr[3][4];
        for(int i=0;i<3;i++)
                {
                for(int j=0;j<4;j++)
                {
                arr[i][j]=array[i][j];
                }
                }
                for(int i=0;i<3;i++)
                {
                for(int j=0;j<3;j++)
                {
                for(int k=0;k<3-j;k++)
                {
                if(arr[i][k]<arr[i][k+1])
                {
                temp=arr[i][k];
                arr[i][k]=arr[i][k+1];
                arr[i][k+1]=temp;
                }
                }
                }
                }
                int max[3];
                for(int i=0;i<3;i++)
                {
                max[i]=arr[i][0];
                }
                for(int i=0;i<3;i++)
                {
                for(int j=0;j<4;j++)
                {
                if(array[i][j]==max[i])
                {
                temp=array[i][0];
                array[i][0]=max[i];
                array[i][j]=temp;
                }
                }
                }
                for(int i=0;i<3;i++)
                {
                for(int j=0;j<4;j++)
                {
                cout<<array[i][j]<<" ";
                }
                cout<<endl;
                }
        }
        int main()
        {
                int arr[3][4];
                for(int i=0;i<3;i++)
                {
                for(int j=0;j<4;j++)
                {
                cin>>arr[i][j];
                }
                }
                f(arr);
        }
*/

