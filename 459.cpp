
#include <bits/stdc++.h>
using namespace std;

vector <int> graph[30];
int visited[26];


void dfs(int i)
{

    if(visited[i])
        return;

    visited[i]=1;

    for(int k=0;k<graph[i].size();k++)
    {
        int j=graph[i][k];
        if(!visited[j])
            dfs(j);
    }

}


int main()
{

    int t;
    scanf("%d",&t);
    while(t--)
    {

        for(int i=0;i<26;i++)
        {
            graph[i].clear();
            visited[i]=0;
        }


        char c;
        cin>>c;
        int nodes=c-'A'+1;

        string str;
        getline(cin,str);

        while(getline(cin,str))
        {
            if(str.size()==0)
                break;

            int a=str[0]-'A';
            int b=str[1]-'A';

            graph[a].push_back(b);
            graph[b].push_back(a);

        }

        int ans=0;

        for(int i=0;i<nodes;i++)
        {
            if(!visited[i])
            {
                ans++;
                dfs(i);
            }

        }

        cout<<ans<<endl;
        if(t)
            cout<<endl;



    }

    return 0;
}
