
    #include <bits/stdc++.h>
    using namespace std;

    #define pii pair<int,int>
    #define pip pair<int,pii>
    #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define MOD 1000000007

    typedef long long ll;
    int dx[]={1,-1,0,0,-1,1,-1,1};
    int dy[]={0,0,1,-1,-1,1,1,-1};
    int counter=0,r=0,c=0;

    char graph[51][51];
    int visited[51][51];

    bool isValid(int x,int y)
    {
        if(x>=0 && x<r && y>=0 && y<c)
            return 1;
        return 0;
    }


    void dfs2(int i,int j)
    {

        graph[i][j]='*';

        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];

            if( graph[x][y]=='X' && isValid(x,y))
                dfs2(x,y);
        }


    }

    void dfs(int i,int j)
    {

        if(visited[i][j] || graph[i][j]=='.')
            return;

        if(graph[i][j]=='X'){
            dfs2(i,j);
            counter++;

        }

        visited[i][j]=1;

        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];

            if (!visited[x][y] && isValid(x,y))
                dfs(x,y);

        }

    }

    int main()
    {
        int t=1;
        while(scanf("%d %d",&c,&r),(r||c))
        {

            for(int i=0;i<r;i++)
                scanf("%s",graph[i]);


            for(int i=0;i<51;i++)
                for(int j=0;j<51;j++)
                    visited[i][j]=0;


            vector<int> ans;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){

                    if(visited[i][j]==1)continue;

                    if(graph[i][j]=='.')
                            visited[i][j]=1;
                    else{
                            dfs(i,j);
                            ans.push_back(counter);
                            counter=0;
                    }
                }
            }
            sort(ans.begin(),ans.end());

            cout<<"Throw "<< (t++) <<endl;
            cout<<ans[0];
            for(int i=1;i<ans.size();i++)
                cout<<" "<<ans[i];
            printf("\n\n");

            ans.clear();

        }


        return 0;
    }

