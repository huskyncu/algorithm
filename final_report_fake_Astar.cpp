#include<bits/stdc++.h>
#include<math.h>
#include<iostream>

using namespace std;

int main()
{
        /*int a=4;
    int b=3;
    int k=min(a,b);
    cout<<k<<endl;*/

    int cases=0;        //設定變數,陣列等等
    int stage=0;
    int er[24]= {};
    int c[3]= {};
    int d[3]= {};
    int e[3]= {};
    cin>>cases;          //輸入測資個數
    while(cases--)
    {
        int er[24]= {};
        int c[3]= {};
        int d[3]= {};
        int e[3]= {};
        int m=1000000000;      //設定最大值
        //c.clear();
        //d.clear();
        for(int i=0; i<24; i++)
        {
            cin>>er[i];       //輸入陣列共24筆。
        }
        cin>>stage;
        switch (stage)
        {
        case 1:
            cout<<min(er[0],min(er[1],er[2]))<<endl;     //若只有一層，則找出三個的最小值。
            break;
        case 2:
            for(int i=0; i<3; i++)
                c[i]=er[i];                            //將第一層三條路徑成本的遞入陣列
            //int m=100000000;
            for(int i=0; i<3; i++)                         //尋找第二層的路徑成本的最小值
            {
                m=min(m,min(c[0]+er[i+3],min(c[0]+er[i+6],c[0]+er[i+9])));
            }
            cout<<m<<endl;                             //輸出最小值成本
            break;
        case 3:
            for(int i=0; i<3; i++)                             //將第一層三條路徑成本的遞入陣列
                c[i]=er[i];
            //int m=100000000;
            //int m=100000000;
            for(int i=0; i<3; i++)                            //尋找第二層的路徑成本的最小值
            {
                d[i]=min(c[0]+er[i+3],min(c[1]+er[i+6],c[2]+er[i+9]));
            }
            for(int i=0; i<3; i++)                                 //尋找第三層的路徑成本的最小值
            {
                m=min(m,min(d[0]+er[i+12],min(d[1]+er[i+15],d[2]+er[i+18])));
            }
            cout<<m<<endl;                            //輸出最小值成本
            break;
        case 4: case 5:
            for(int i=0; i<3; i++)
                c[i]=er[i];                             //將第一層三條路徑成本的遞入陣列
            int m=100000000;
            //int m=100000000;
            for(int i=0; i<3; i++)
            {
                d[i]=min(c[0]+er[i+3],min(c[1]+er[i+6],c[2]+er[i+9]));     //尋找第二層的路徑成本的最小值
            }
            for(int i=0; i<3; i++)
            {
                e[i]=min(d[0]+er[i+12],min(d[1]+er[i+15],d[2]+er[i+18]));     //尋找第三層的路徑的最小值
            }
            m=min(m,min(e[0]+er[21],min(e[1]+er[22],e[2]+er[23])));     //尋找第四五層的路徑成本的最小值
            cout<<m<<endl;                           //輸出最小值成本
            break;
        }

    }


}
