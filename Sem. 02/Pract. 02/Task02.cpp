#include <iostream>
#include <fstream>

using namespace std;

int lengthOfFile(ifstream& in){
    size_t currentPosition = in.tellg();
    in.seekg(0,ios::beg);

    if(!in.is_open()){
        return -1;
    }

    unsigned int count = 0;
    while(true){
        char current = in.get();

        if(in.eof()){
            break;
        }

        if(current == '\n'){
            continue;
        }
        count++;
    }
    in.clear();
    in.seekg(currentPosition);

    return count;
}

int main(){
    ofstream out("task02.txt");

    if(!out.is_open()){
        cout<<"Error";
        return -1;
    }
    out<<"123456"<<endl;
    out<<"1234"<<endl;//total of 10 symbols
    out<<"1234"<<endl;

    out.close();

    ifstream in("task02.txt");
    cout<<lengthOfFile(in);

    in.close();
}
