#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <algorithm>
using namespace std;
void M(int num1,int num2,vector<int> z)
{
    int A = *max_element(z.begin()+num1, z.begin()+num2+1);

    int B = *min_element(z.begin()+num1, z.begin()+num2+1);

    cout<<B<<" "<<A<<endl;
}
int main ()
{

    string line, line1, line2;
    ifstream myfile ("zsignal.txt");
    int input1;
    int input2;
    vector <int> zvector;

    int i = 0 ;
    int cnt=0;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {

            if(cnt==0)
            {
                int num=atoi(line.c_str());
                cnt++;
                zvector.push_back(num);
            }
            else
            {
                if(line.find('0')!= string::npos)
                {
                    line1 = line.substr(0, line.find(" "));
                    line2 = line.substr(line.find(" ")+1, line.length());
                    input1 = atoi(line1.c_str());
                    input2 = atoi(line2.c_str());
                    zvector.push_back(input1);
                    zvector.push_back(input2);
                }
                else
                {
                    input1 = atoi(line.c_str());
                    zvector.push_back(input1);
                }
            }

        }
        myfile.close();
    }
    else cout << "zsignal.txt을 열 수 없네요.";
//zsignal.txt >> zvector
    vector <int> z;
    int znum;
    z.push_back(zvector[0]);
    znum=zvector[0];

    for(int i=1; i<zvector.size(); i++)
    {
        if(zvector[i]!=0)
        {
            znum+=zvector[i];
            z.push_back(znum);
        }
        else
        {
            for(int j=0; j<zvector[i+1]; j++)
            {
                z.push_back(znum);
            }
            i++;
        }
    }



//zsignal list
    while(true)
    {
    if(cin.eof()==true){
    break;
    }
    else{
        char x;
        int  a=0,b=0;
        cin>> x;
        if(x=='T')
        {
            cin>>a;
            if(a>z.size()-1)
            {
                cout<<"-1"<<endl;
                continue;

            }
            cout<<z[a]<<endl;
        }
        else if(x=='M')
        {
            cin>>a>>b;
            if(a>z.size()-1 || b>z.size()-1)
            {
                cout<<"-1"<<endl;
                continue;
            }
            else M(a,b,z);
        }
        else continue;

    }
    }
//solution


    return 0;
}


