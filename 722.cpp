

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
    char graph[105][105];
    bool visited[105][105];
    char inp[105];
    int n,a,b,m;


    int dfs(int x,int y)
    {

        if(x<0 || x>n || y<0 || y>=m || visited[x][y] || graph[x][y]=='1')
            return 0;
        //cout<<"now visiting "<<x<<" "<<y<<endl;


        visited[x][y]=true;
        int ans=1;

        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];

            ans+=dfs(nx,ny);
        }

        return ans;
    }

    int main()
    {
        int T;
        scanf("%d",&T);
        while(T--)
        {

            scanf("%d%d\n",&a,&b);

            a--;b--;
            n=0;//rows
            while(gets(inp) && strlen(inp)>0 )
            {
                strcpy(graph[n],inp);
                n++;
            }

            n--;

            m=strlen(graph[0]);//columns
            memset(visited, false, sizeof visited);



            cout<<dfs(a,b)<<endl;
            if(T)cout<<endl;

        }

        return 0;
    }
