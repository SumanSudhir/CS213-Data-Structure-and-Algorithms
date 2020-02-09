#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream file;
    file.open ("testcase.txt");

    cout << "Write text to be written on file." << endl;

    int n = 50;
    file << n << endl;
    for(int j=0;j<n;j++){
        int r = rand()%10000+1;
        file << r << " ";
    }
    // Writing on file
    // file << text << endl;

    file.close();
    return 0;
}
