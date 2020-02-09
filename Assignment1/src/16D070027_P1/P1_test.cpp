#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream file;
    file.open ("testcase.txt");

    cout << "Write text to be written on file." << endl;

    int n = 15;
    int q = 10;
    file << n << endl;
    for(int j=0;j<n;j++){
        int r = rand()%10000+1;
        int marks = rand()%100+1;
        file<<r<< " "<<marks<<endl;
    }
    file<<q<<endl;
    for(int i = 0;i<q;i++){
        int l = rand()%50+1;
        int r = l + rand()%100+1;
        file<<l<< " "<<r<<endl;
    }
    // Writing on file
    // file << text << endl;

    file.close();
    return 0;
}
