#include <bits/stdc++.h>

using namespace std;

typedef struct matrix
{
    int a[3][3];
    int blank[2];
};

bool find(vector<matrix> e, matrix m)
{
    bool same= true;
    for(int k=0; k<e.size(); k++)
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(e[k].a[i][j]!=m.a[i][j])
                {
                    //cout<<"not same"<<endl;
                    same= false;
                    break;
                }
            }
            if(!same)
            {
                break;
            }
        }
        if(same)
        {
            return  true;
        }
    }
    return false;

}
int main()
{
    queue<matrix> q;
    vector<matrix> exist;
    //int blank[2]= {};
    matrix input,ans,tmp,t;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>input.a[i][j];
            if (input.a[i][j]==0)
            {
                input.blank[0]=i;
                input.blank[1]=j;
            }
        }
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>ans.a[i][j];
        }
    }
    q.push(input);
    exist.push_back(input);
    int sum=0;
    int time=0;
    while(q.size()!=0)
    {
        time++;
        sum=0;
        t=q.front();
        q.pop();
        //cout<<q<<endl;
        //cout<<"the size of the quene "<<q.size()<<endl;
        //cout<<"Answer:"<<endl;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(t.a[i][j]==ans.a[i][j])
                {
                    sum++;
                }
            }
        }
        /*for(int i=0; i<3; i++)
        {
            for(int j=0; j<2; j++)
            {
                cout<<ans.a[i][j]<<" ";
            }
            cout<<ans.a[i][2]<<endl;
        }*/
        //cout<<"first in quene:"<<endl;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<2; j++)
            {
                cout<<t.a[i][j]<<" ";
            }
            if (sum ==9 && i==2)
                cout<<t.a[i][2];
            else
                cout<<t.a[i][2]<<endl;
        }
        //cout<<time<<endl;
        if(sum<9)
        {
            for(int i=0; i<4; i++)
            {

                if(i==0 && t.blank[0]!=0) // up
                {
                    //a=blank[0];
                    //b=blank[1];
                    tmp=t;
                    swap(tmp.a[tmp.blank[0]-1][tmp.blank[1]],tmp.a[tmp.blank[0]][tmp.blank[1]]);
                    tmp.blank[0]-=1;
                    /*cout<<"in up move"<<endl;
                    for(int i=0; i<3; i++)
                    {
                        for(int j=0; j<2; j++)
                        {
                            cout<<tmp.a[i][j]<<" ";
                        }
                        cout<<tmp.a[i][2]<<endl;
                    }*/
                    if(find(exist,tmp)!=true)
                    {
                        //cout<<"the up move not exist"<<endl;
                        q.push(tmp);
                        exist.push_back(tmp);
                    }
                }
                if(i==2 && t.blank[0]!=2) // down
                {
                    tmp=t;
                    //cout<<"in down move"<<endl;
                    swap(tmp.a[tmp.blank[0]+1][tmp.blank[1]],tmp.a[tmp.blank[0]][tmp.blank[1]]);
                    tmp.blank[0]+=1;
                     /*for(int i=0; i<3; i++)
                    {
                        for(int j=0; j<2; j++)
                        {
                            cout<<tmp.a[i][j]<<" ";
                        }
                        cout<<tmp.a[i][2]<<endl;
                    }*/
                    if(find(exist,tmp)!=true)
                    {
                        //cout<<"in 1 not exist"<<endl;
                        q.push(tmp);
                        exist.push_back(tmp);
                    }
                }
                if(i==3 && t.blank[1]!=0) // left
                {
                    tmp=t;
                    //cout<<"in left move"<<endl;
                    swap(tmp.a[tmp.blank[0]][tmp.blank[1]-1],tmp.a[tmp.blank[0]][tmp.blank[1]]);
                   tmp.blank[1]-=1;
                     /*for(int i=0; i<3; i++)
                    {
                        for(int j=0; j<2; j++)
                        {
                            cout<<tmp.a[i][j]<<" ";
                        }
                        cout<<tmp.a[i][2]<<endl;
                    }*/
                    if(find(exist,tmp)!=true)
                    {
                        //cout<<"in 2 not exist"<<endl;
                        q.push(tmp);
                        exist.push_back(tmp);
                    }
                }
                if(i==1 && t.blank[1]!=2) // right
                {
                    tmp=t;
                    //cout<<"in right move"<<endl;
                    swap(tmp.a[tmp.blank[0]][tmp.blank[1]+1],tmp.a[tmp.blank[0]][tmp.blank[1]]);
                    tmp.blank[1]+=1;
                     /*for(int i=0; i<3; i++)
                    {
                        for(int j=0; j<2; j++)
                        {
                            cout<<tmp.a[i][j]<<" ";
                        }
                        cout<<tmp.a[i][2]<<endl;
                    }*/
                    if(find(exist,tmp)!=true)
                    {
                        //cout<<"in 3 not exist"<<endl;
                        q.push(tmp);
                        exist.push_back(tmp);
                    }
                }
            }
        }
        else break;
        //time++;
        //if(time==10)
            //break;
    }
}
