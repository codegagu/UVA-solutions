

    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {

        int b1,b2,b3,g1,g2,g3,c1,c2,c3;
        while(cin>>b1>>g1>>c1>>b2>>g2>>c2>>b3>>g3>>c3)
        {
            int bcg=b2+b3+c1+c3+g1+g2;
            int bgc=b2+b3+g1+g3+c1+c2;

            int cbg=c2+c3+b1+b3+g1+g2;
            int cgb=c2+c3+g1+g3+b1+b2;

            int gbc=g2+g3+b1+b3+c1+c2;
            int gcb=g2+g3+c1+c3+b1+b2;

            int mini=min(bcg,min(bgc,min(cbg,min(cgb,min(gbc,gcb)))));

            if(mini==bcg)
                cout<<"BCG "<<mini<<endl;
            else if(mini==bgc)
                cout<<"BGC "<<mini<<endl;
            else if(mini==cbg)
                cout<<"CBG "<<mini<<endl;
            else if(mini==cgb)
                cout<<"CGB "<<mini<<endl;
            else if(mini==gbc)
                cout<<"GBC "<<mini<<endl;
            else
                cout<<"GCB "<<mini<<endl;

        }
        return 0;
    }
