



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

    vector<string> graph;
    vector<pii> visited;

    bool isValid(pii nidx)
    {
        int x=nidx.ff; int y=nidx.ss;
        if(x<0 || x>=graph.size() || y<0 || y>=graph[0].size())
            return false;
        return true;
    }

    void dfs(pii idx)
    {
        if(find(visited.begin(),visited.end(),idx)!=visited.end())
            return;

        visited.pb(idx);
        int x=idx.ff;
        int y=idx.ss;

        for(int k=0;k<8;k++)
        {
            int nx=x+dx[k];
            int ny=y+dy[k];

            pii nidx=mp(nx,ny);
            if(find(visited.begin(),visited.end(),nidx)==visited.end() && isValid(nidx) && graph[nx][ny]=='@')
            {
                dfs(nidx);
            }
        }

    }

    int main()
    {
        while(1)
        {
            int m,n;
            scanf("%d",&m);
            scanf("%d",&n);

            if(m==0)break;

            string s;
            for(int i=0;i<m;i++)
            {
                cin>>s;
                graph.pb(s);
            }
            int ans=0;

            for(int i=0;i<graph.size();i++)
            {
                for(int j=0;j<graph[0].size();j++)
                {
                    pii idx=mp(i,j);
                    if(graph[i][j]=='@' && find(visited.begin(),visited.end(),idx)==visited.end())
                    {
                        dfs(idx);
                        ans++;
                    }
                }
            }

            cout<<ans<<endl;
            graph.clear();
            visited.clear();

        }


        return 0;
    }
