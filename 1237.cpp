
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


    int main()
    {


        int D,L,H,Q,price;
        map<string,pii> Map;

        int t;
        scanf("%d",&t);
        while(t--)
        {
            char name[25];
            scanf("%d",&D);
            while(D--){
                scanf("%s%d%d",&name,&L,&H);
                pii lh=mp(L,H);
                Map.insert(pair<string,pii>(name,lh) );
            }

            map<string,pii>::iterator it;

            scanf("%d",&Q);

            while(Q--)
            {
                int flag=0,counter=0;
                string ans;

                scanf("%d",&price);
                for(it=Map.begin();it!=Map.end();++it){
                    pii lh=it->ss;
                    int l=lh.ff;
                    int h=lh.ss;
                    if(l<= price && price<=h){
                        ans=it->ff;
                        flag=1;
                        counter++;
                    }
                }
                if(counter==1)
                    cout<<ans<<endl;
                if(!flag || counter>1)
                    cout<<"UNDETERMINED"<<endl;
            }
            Map.clear();

            if(t)cout<<endl;
        }

        return 0;
    }
