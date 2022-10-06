#include <bits/stdc++.h>

#define INF 10000000

using namespace std;

int main()
{
    int points=0;

    int cases=0;
    char start;
    char ends;
    int cost=0;
    int ac_start=0, ac_end=0;
    cin>>points>>cases;
    int dis[26][26]= {};
    int point[26]= {0};
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<26; j++)
        {
            if(i!=j) dis[i][j]=INF;
            else dis[i][j]=0;
        }
    }
    while(cases--)
    {
        cin>>start>>ends>>cost;
        ac_start=start;
        ac_end=ends;
        dis[ac_start-97][ac_end-97]=cost;
    }

    for (int i = 0; i < points; i++)
    {

        for (int j = 0; j < points; j++)
        {
            for (int k = 0; k < points; k++)
            {
                if (dis[j][i] == INF || dis[i][k] == INF) continue;
                if (dis[j][k] > dis[j][i] + dis[i][k])
                {
                    dis[j][k] = dis[j][i] + dis[i][k];
                }
            }

        }
    }
    for(int i=0; i<points; i++)
    {
        for(int j=0; j<points; j++)
        {
            if(dis[i][j]==INF) cout<<"INF";
            else cout<<dis[i][j];
            if (j<points-1) cout<<" ";
        }
        if(i<points-1) cout<<endl;
    }
}
