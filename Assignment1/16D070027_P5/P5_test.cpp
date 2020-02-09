#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream file;
    file.open ("testcase.txt");

    cout << "Write text to be written on file." << endl;

    int n = 50;
    int k = 5000;
    file << n << " " << k << endl;;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            int r = i+j + 200;
            file << r << " ";
        }
        file<< endl;
    }

    // Writing on file
    // file << text << endl;

    file.close();
    return 0;
}
