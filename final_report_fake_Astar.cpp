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

    int cases=0;        //�]�w�ܼ�,�}�C����
    int stage=0;
    int er[24]= {};
    int c[3]= {};
    int d[3]= {};
    int e[3]= {};
    cin>>cases;          //��J����Ӽ�
    while(cases--)
    {
        int er[24]= {};
        int c[3]= {};
        int d[3]= {};
        int e[3]= {};
        int m=1000000000;      //�]�w�̤j��
        //c.clear();
        //d.clear();
        for(int i=0; i<24; i++)
        {
            cin>>er[i];       //��J�}�C�@24���C
        }
        cin>>stage;
        switch (stage)
        {
        case 1:
            cout<<min(er[0],min(er[1],er[2]))<<endl;     //�Y�u���@�h�A�h��X�T�Ӫ��̤p�ȡC
            break;
        case 2:
            for(int i=0; i<3; i++)
                c[i]=er[i];                            //�N�Ĥ@�h�T�����|���������J�}�C
            //int m=100000000;
            for(int i=0; i<3; i++)                         //�M��ĤG�h�����|�������̤p��
            {
                m=min(m,min(c[0]+er[i+3],min(c[0]+er[i+6],c[0]+er[i+9])));
            }
            cout<<m<<endl;                             //��X�̤p�Ȧ���
            break;
        case 3:
            for(int i=0; i<3; i++)                             //�N�Ĥ@�h�T�����|���������J�}�C
                c[i]=er[i];
            //int m=100000000;
            //int m=100000000;
            for(int i=0; i<3; i++)                            //�M��ĤG�h�����|�������̤p��
            {
                d[i]=min(c[0]+er[i+3],min(c[1]+er[i+6],c[2]+er[i+9]));
            }
            for(int i=0; i<3; i++)                                 //�M��ĤT�h�����|�������̤p��
            {
                m=min(m,min(d[0]+er[i+12],min(d[1]+er[i+15],d[2]+er[i+18])));
            }
            cout<<m<<endl;                            //��X�̤p�Ȧ���
            break;
        case 4: case 5:
            for(int i=0; i<3; i++)
                c[i]=er[i];                             //�N�Ĥ@�h�T�����|���������J�}�C
            int m=100000000;
            //int m=100000000;
            for(int i=0; i<3; i++)
            {
                d[i]=min(c[0]+er[i+3],min(c[1]+er[i+6],c[2]+er[i+9]));     //�M��ĤG�h�����|�������̤p��
            }
            for(int i=0; i<3; i++)
            {
                e[i]=min(d[0]+er[i+12],min(d[1]+er[i+15],d[2]+er[i+18]));     //�M��ĤT�h�����|���̤p��
            }
            m=min(m,min(e[0]+er[21],min(e[1]+er[22],e[2]+er[23])));     //�M��ĥ|���h�����|�������̤p��
            cout<<m<<endl;                           //��X�̤p�Ȧ���
            break;
        }

    }


}
