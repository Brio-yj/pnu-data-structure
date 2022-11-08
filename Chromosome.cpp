#include <bits/stdc++.h>

using namespace std;
typedef list<char>::iterator list_itr;
typedef pair<list_itr,list_itr> list_iter_pair;
list<char> chromosome1;

void make_chromosome(){
    string line;
    ifstream infile("sapiens.txt");
    getline(infile,line);
    while (getline(infile, line)) {
        copy(line.begin(), line.end(), back_inserter(chromosome1));
    }
    infile.close();
}

list_iter_pair ijthitr(int i, int j){//list�� i��°, j��° iterator�� ã�� return
    list_itr start = chromosome1.begin();
    advance(start,i-1);
    list_itr ith = start;
    advance(start,j-i+1);
    list_itr jth = start;
    return {ith,jth};
}

void exe(int i, int j, int e){//i,j�ְ� �����ɾ� �Է�
    list_iter_pair ijth = ijthitr(i,j);
    list<char> inst(ijth.first,ijth.second);//chromosome�� i~j������ ������ list����

    switch (e) {
        case 0://front���
            chromosome1.erase(ijth.first,ijth.second);
            chromosome1.insert(chromosome1.begin(),inst.begin(),inst.end());//�� ������ �ֱ�
            break;
        case 1://back
            chromosome1.erase(ijth.first, ijth.second);
            chromosome1.insert(chromosome1.end(), inst.begin(), inst.end());//�� �ڿ� �ֱ�
            break;
        case 2://cut
            chromosome1.erase(ijth.first,ijth.second);
            break;
        case 3://double
            chromosome1.insert(ijth.second,inst.begin(),inst.end());//j��° �ڿ� �ֱ�
            break;
        case 4://flip
            chromosome1.erase(ijth.first,ijth.second);
            chromosome1.insert(ijth.second,inst.rbegin(),inst.rend());//rbegin,rend�� ������ �ֱ�
            break;
    }

}


void Report(int i, int j){
    list_iter_pair ijth = ijthitr(i,j);
    if (i>chromosome1.size()) cout<<"NONE"<<endl;//i�� chromosome ũ�⺸�� ũ�� NONE���
    else{
        for(auto i = ijth.first; i != ijth.second;i++){
            cout<<*i;
        }cout<<endl;
    }
}

void command(string cmd, int i, int j){//����� ����
    if     (cmd == "front")  exe(i,j,0);
    else if(cmd == "back")   exe(i,j,1);
    else if(cmd == "cut")    exe(i,j,2);
    else if(cmd == "double") exe(i,j,3);
    else if(cmd == "flip")   exe(i,j,4);
    else if(cmd == "report") Report(i,j);
}
int main() {
    make_chromosome();

    int N;
    cin>>N;

    while(N--){
        string cmd;
        int i,j;
        cin>>cmd>>i>>j;
        if (j>chromosome1.size()) j = chromosome1.size();// j�� chromosome size���� ũ�� j�� end()�� �ٲ�

        command(cmd,i,j);
    }
    return 0;
}
