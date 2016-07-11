#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    
    string extensions[10000];
    string mimetypes[10000];
    string file[10000];
    string end;
    for (int i = 0; i < N; i++) {
        cin >> extensions[i] >> mimetypes[i]; cin.ignore();
        transform(extensions[i].begin(), extensions[i].end(), extensions[i].begin(), ::tolower);
    }
    
    for (int i = 0; i < Q; i++)
        getline(cin, file[i]);
    
    for (int i = 0; i < Q; ++i) {
        size_t pos = file[i].find_last_of('.');
        if (pos == 18446744073709551615) {
            cout << "UNKNOWN" << endl;
        } else {
            end = file[i].substr(pos+1);
            transform(end.begin(), end.end(), end.begin(), ::tolower);
            for (int j = 0; j < N; ++j) {
                if(end == extensions[j]) {
                    cerr <<"GOOD: " << end<< " "<< extensions[j] << " "<< mimetypes[j] <<endl;
                    cout<<mimetypes[j]<<endl;
                    break;
                }
                if (j >= N-1) {
                    cerr <<"WRONG: "<<end<< " "<< extensions[j] << " "<< mimetypes[j] <<endl;
                    cout << "UNKNOWN" << endl;
                }
            }
        }
    }
}
