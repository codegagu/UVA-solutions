
#include <bits/stdc++.h>
using namespace std;

char graph[201][201];
int visited[201][201];

int dx[]={-1,0,1,-1,0,1};
int dy[]={-1,-1,0,0,1,1};
int n,t=1;
int solved=0;


bool isValid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    return true;

}

void dfs(int i,int j)
{
    if(visited[i][j])
        return;

    visited[i][j]=1;


        if(i==n-1){
            solved=1;
            cout<<t<<" B"<<endl;
            return;
        }


    for(int k=0;k<6 && solved==0 ;k++){
        int x=i+dx[k];
        int y=j+dy[k];

        if(isValid(x,y) && graph[i][j]==graph[x][y]){
            dfs(x,y);
        }
    }

    return;

}


int main()
{

    while(1)
    {

        solved=0;
        scanf("%d",&n);

        if(n==0)break;

        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                visited[i][j]=0;


        for(int i=0;i<n;i++){
            scanf("%s",graph[i]);
        }



        //black
        for(int i=0;i<1;i++)
            for(int j=0;j<n;j++)
                if(graph[i][j]=='b' && !visited[i][j])
                    dfs(i,j);

        if(solved==0)
            cout<<t<<" W"<<endl;



        t++;
    }

    return 0;
}




