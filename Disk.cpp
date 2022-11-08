#include <bits/stdc++.h>

using namespace std;

struct file_x{
    int first;
    int last;
    string file_name;
};
typedef list<file_x>::iterator disk_iter;
list<file_x> DISK;
const string empty = "Empty";
int empty_size;

void add_element(disk_iter &empty_space, int file_size, string file_name){
    int FIR = empty_space->first, LAS = empty_space->last;
    if (LAS - FIR <= file_size) empty_space->file_name = file_name;
    else{
        file_x inst{FIR, FIR+file_size,file_name};
        DISK.insert(empty_space,inst);
        empty_space->first = FIR+file_size;
    }
}

void write(string file_name, int file_size){
    if(empty_size<file_size) {
        cout << "diskfull" << endl;
        return;
    }

    auto searchfile = find_if(DISK.begin(),DISK.end(),[=](file_x &x){return x.file_name==file_name;});
    if(searchfile != DISK.end()) {
        cout << "error" << endl;
        return;
    }

    empty_size -= file_size;

    auto empty_space = find_if(DISK.begin(),DISK.end(),[=](file_x &x){return (x.file_name == empty)&(x.last - x.first >= file_size);});

    if(empty_space != DISK.end()) add_element(empty_space,file_size,file_name);
    else{
        empty_space = find_if(DISK.begin(),DISK.end(),[=](file_x &x){return (x.file_name == empty);});
        while(true){
            add_element(empty_space,file_size,file_name);
            if(file_size<=0) break;
            file_size -= (empty_space->last-empty_space->first);
            empty_space = find_if(next(empty_space),DISK.end(),[=](file_x &x){return (x.file_name == empty);});
        }

    }



}

void combine(disk_iter &arrange){
    while(true){
        int temp = arrange->first;
        arrange = DISK.erase(arrange);
        arrange->first = temp;
        arrange = adjacent_find(arrange,DISK.end(),[](file_x &a,file_x &b){return a.file_name==b.file_name;});
        if(arrange == DISK.end()) break;
    }
}

void del(string file_name){
    auto searchfile = find_if(DISK.begin(),DISK.end(),[=](file_x &x){return x.file_name==file_name;});
    if(searchfile == DISK.end()) {
        cout << "error" << endl;
        return;
    }

    for(auto &w:DISK){
        if(w.file_name == file_name){
            w.file_name = empty;
            empty_size += (w.last-w.first);
        }
    }

    auto arrange = adjacent_find(DISK.begin(),DISK.end(),[](file_x &a,file_x &b){return a.file_name==b.file_name;});
    if(arrange != DISK.end()) combine(arrange);
}

void show(string file_name){
    auto searchfile = find_if(DISK.begin(),DISK.end(),[=](file_x &x){return x.file_name==file_name;});
    if(searchfile == DISK.end()) {
        cout << "error" << endl;
        return;
    }

    for(auto &w:DISK){
        if(w.file_name==file_name) cout<<w.first<<" ";
    }
    cout<<endl;
}

void compact(){
    auto resize = remove_if(DISK.begin(),DISK.end(),[](file_x x){return x.file_name == empty;});
    DISK.erase(resize,DISK.end());
    int accu = 0;
    int diff;

    for(auto &w:DISK){
        diff = w.last-w.first;
        w.first = accu;
        w.last = w.first+diff;
        accu = w.last;
    }
    auto arrange = adjacent_find(DISK.begin(),DISK.end(),[](file_x &a,file_x &b){return a.file_name==b.file_name;});
    if(arrange != DISK.end()) combine(arrange);

    file_x back{ accu, accu+empty_size,empty};
    DISK.push_back(back);
}

void operate(){

    string command = "start";
    while(true){

        cin>>command;

        string file_name;

        if (command == "end") break;
        else if(command == "write"){
            int file_size;
            cin>>file_name>>file_size;
            write(file_name,file_size);
        }else if(command == "delete"){
            cin>>file_name;
            del(file_name);
        }else if(command == "show"){
            cin>>file_name;
            show(file_name);
        }else if(command == "compact"){
            compact();
        }
      for(auto &w:DISK) {
          cout << w.first << " " << w.last << " " << w.file_name << " " << endl;
      }
    }
}




int main() {
    int N;
    cin>>N;
    empty_size = N;
    file_x start{0,N,empty};

    DISK.push_back(start);
    operate();

    return 0;
}
