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
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();

    string T;
    string ROW;
    getline(cin, T);
    int dlugosc = T.length();
    
    for (int i = 0; i < H; ++i) {
        getline(cin, ROW);
        // cerr<<ROW.length()<<" "<<L<<endl;
        for (int x = 0; x < dlugosc; ++x) {
            int com = static_cast<int>(T[x])-65;
            if (com >= 27)
                com -=32;
            if (com < 0)
                com = 26;
            // cerr<<com<<endl;
            int pr = com * L;
            int er = (com * L) + L;
            for (int j = pr; j < er; ++j)
                cout<<ROW[j];
        }
        cout<<endl;
    }
}
