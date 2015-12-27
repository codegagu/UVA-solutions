

    #include<bits/stdc++.h>
    using namespace std;

    vector<int> store;

    void precompute(){
        for(int i=0;i<=10000;i++)
            store.push_back(i*i);
    }

    int main()
    {
        precompute();
        int N;
        while(scanf("%d",&N)==1){

            for(int i=0;i<store.size();i++){
                if(store[i] >= (int) pow(10,N))
                    break;

                int q=store[i] / (int) pow(10,N/2);
                int r=store[i] % (int) pow(10,N/2);

                int ans=(int) pow(q+r,2);
                if(store[i]== ans)
                    cout<<setw(N)<<setfill('0')<<store[i]<<endl;
                    
            }
        }

        return 0;
    }
