#include <iostream>
#include <fstream>

using namespace std;

void preparingFiles(){
    ofstream placeholder("placeholder.txt");

    if(!placeholder.is_open()){
        return;
    }

    placeholder<<"title Veliki"<<endl;
    placeholder<<"recipient_name Pop Armeniya"<<endl;
    placeholder<<"message Iskam da se oplacha!!! "<<endl;
    placeholder<<"sender_name FMI-student"<<endl;

    placeholder.close();

    ofstream out("task03.txt");
    if(!out.is_open()){
        return;
    }
    out<<"Dear, {title} {recipient_name}."<<endl;
    out<<"{message}"<<endl<<endl;
    out<<"Sincerely,"<<endl;
    out<<"{sender_name}"<<endl;

    out.close();
}

int strLen(const char* arr){
    int count=0;

    while(arr[count]!='\0'){
        count++;
    }
    return count;
}

bool strCmp(const char* arr1,const char* arr2){
  if(strLen(arr1)!=strLen(arr2)){
    return false;
  }

  for(int i=0;i<strLen(arr1);i++){
    if(arr1[i]!=arr2[i]){
        return false;
    }
  }
  return true;
}

void writeReplacementFromPlaceholder(const char* name,ofstream& out,ifstream& placeholder){

            while(true){
                char type_placeholder[100];
                placeholder>>type_placeholder;
                placeholder.ignore();

                if(placeholder.eof()){
                    break;
                }

                if(strCmp(type_placeholder,name)){
                    char replacement [100];
                    placeholder.getline(replacement,100);
                    out<<replacement;
                    break;
                }
            }
}

int replacingPlaceholder(){
    ifstream in("task03.txt");

    ofstream out("task03_copy.txt");

    ifstream placeholder("placeholder.txt");

    size_t currentPosition = in.tellg();
    in.seekg(0,ios::beg);

    if(!in.is_open() || !out.is_open() || !placeholder.is_open()){
        cout<<"Error";
        return -1;
    }

    while(true){
        placeholder.clear();
        placeholder.seekg(0,ios::beg);

        char current = in.get();

        if(in.eof()){
            break;
        }

        if(current == '{'){
            char name[100];

            in.getline(name,100,'}');

            writeReplacementFromPlaceholder(name,out,placeholder);
            continue;
        }

        out<<current;
    }
    in.seekg(currentPosition);
    in.close();
    out.close();
    placeholder.close();
}

int main(){
    preparingFiles();

    replacingPlaceholder();
}
