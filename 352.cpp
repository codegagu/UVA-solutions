


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
    int grid[25][25];
    bool visited[25][25];
    int n;


    bool isValid(int x,int y)
    {
        if(x<0 || x>=n || y<0 || y>=n)
            return false;
        return true;
    }

    void dfs(int i,int j,int symbol)
    {
        if(visited[i][j])
            return;

        visited[i][j]=1;

        grid[i][j]=symbol;
        int x,y;
        for(int k=0;k<8;k++)
        {
            x=i+dx[k];
            y=j+dy[k];

            if(isValid(x,y) && !visited[x][y] && grid[x][y]==1)
            {
                grid[x][y]=symbol;
                dfs(x,y,symbol);
            }
        }
    }

    int main()
    {
        int imagecount=0;
        while(scanf("%d",&n)>0)
        {
            imagecount++;
            string s;
            for(int i=0;i<n;i++)
            {
                cin>>s;
                for(int j=0;j<n;j++)
                {
                    grid[i][j]=s[j]-'0';
                    visited[i][j]=0;
                }
            }

            int symbol=1;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==1 && !visited[i][j])
                    {
                        dfs(i,j,symbol);
                        symbol++;
                    }
                }
            }

            symbol--;
            cout<<"Image number "<<imagecount<<" contains "<<symbol<<" war eagles."<<endl;


        }

        return 0;
    }
