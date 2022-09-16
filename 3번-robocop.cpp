#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int point[2][n+1];
    int a,b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        point[0][i]=a;
        point[1][i]=b;
    }
    point[0][n]=point[0][0];
    point[1][n]=point[1][0];
// point[][]

    vector <int> v1;
    vector <int> v2;
    v1.push_back(point[0][0]);
    v2.push_back(point[1][0]);
    for(int i=0; i<n; i++)
    {
        if(point[0][i]==point[0][i+1])
        {
            int val = abs(point[1][i+1]-point[1][i]);
            int sub = point[1][i+1]-point[1][i];
            for(int j=1; j<val+1; j++)
            {
                if(sub>0)
                {
                    v1.push_back(point[0][i]);
                    v2.push_back(point[1][i]+j);
                }
                else if(sub<0)
                {
                    v1.push_back(point[0][i]);
                    v2.push_back(point[1][i]-j);
                }
            }
        }
        else if(point[1][i]==point[1][i+1])
        {
            int val = abs(point[0][i+1]-point[0][i]);
            int sub = point[0][i+1]-point[0][i];
            for(int j=1; j<val+1; j++)
            {
                if(sub>0)
                {
                    v1.push_back(point[0][i]+j);
                    v2.push_back(point[1][i]);
                }
                else if(sub<0)
                {
                    v1.push_back(point[0][i]-j);
                    v2.push_back(point[1][i]);
                }
            }
        }
    }
//2 dimension vector
    int t;
    while(cin>>t){
    int remainder;
    remainder = t%(v1.size()-1);
    cout<<v1[remainder]<<"\t"<<v2[remainder]<<endl;
    }
}













