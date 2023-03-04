#include <iostream>
#include <fstream>
using namespace std;

void writeinFile(ofstream& out){
    int a,b,c;
    cin>>a>>b>>c;

    out << (a+b+c) << " " << (a*b*c);
}

void printDifference(istream& out){
    int sum, product;

    out>> sum>>product;

    cout<< abs(sum-product);
}

int main(){
    ofstream out("results.txt");

     if (!out.is_open()) {
			std::cout << "Error" << std::endl;
			return -1;
		}

    writeinFile(out);
    out.close();

    ifstream in("results.txt");

    if(!in.is_open()){
        cout<<"Error";
        return -1;
    }

    printDifference(in);
    in.close();
}
