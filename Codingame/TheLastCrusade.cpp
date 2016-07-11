#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // number of columns.
    int H; // number of rows.
    cin >> W >> H; cin.ignore();
    int mapa[W][H] = {{0}};
    for (int i = 0; i < H; i++) {
        string LINE; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        getline(cin, LINE);
        stringstream stream(LINE);
        int w = 0;
        while(1) {
            int n;
            stream >> n;
            if(!stream)
                break;
            // cerr << "Found integer: " << n << endl;
            mapa[w][i] = n;
            ++w;
        }
    }
    // for (int i = 0; i < W; ++i){
    //     for (int j = 0; j < H; ++j){
    //         cerr << mapa[j][i] <<" ";
    //     }
    //     cerr << endl;
    // }
    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();

    // game loop
    while (1) {
        int XI;
        int YI;
        string POS;
        cin >> XI >> YI >> POS; cin.ignore();
        cerr << XI << " " << YI << " " << mapa[XI][YI] <<endl;
        int x = XI;
        int y = YI;
        switch(mapa[XI][YI]){
            case 0:
                break;
            case 1:
                if (POS=="TOP"){
                    x+=0;
                    y+=1;
                } else if(POS=="LEFT"){
                    y+=1;
                } else if(POS=="RIGHT"){
                    y+=+1;
                }
                break;
            case 2:
                if (POS=="LEFT"){
                    x+=1;
                } else if(POS=="RIGHT"){
                    x-=1;
                }
                break;
            case 3:
                y+=+1;
                break;
            case 4:
                if (POS=="TOP"){
                    x-=1;
                    y+=0;
                } else if(POS=="RIGHT"){
                    x+=0;
                    y+=1;
                }
                break;
            case 5:
                if (POS=="TOP"){
                    x+=1;
                    y+=0;
                } else if(POS=="LEFT"){
                    x+=0;
                    y+=1;
                }
                break;
            case 6:
                if (POS=="LEFT"){
                    x+=1;
                    y+=0;
                } else if(POS=="RIGHT"){
                    x-=1;
                    y+=0;
                }
                break;
            case 7:
                if (POS=="TOP"){
                    x+=0;
                    y+=1;
                } else if(POS=="RIGHT"){
                    x+=0;
                    y+=1;
                }
                break;
            case 8:
                if (POS=="RIGHT"){
                    x+=0;
                    y+=1;
                } else if(POS=="LEFT"){
                    x+=0;
                    y+=1;
                }
                break;
            case 9:
                if (POS=="TOP"){
                    x+=0;
                    y+=1;
                } else if(POS=="LEFT"){
                    x+=0;
                    y+=1;
                }
                break;
            case 10:
                if (POS=="TOP"){
                    x-=1;
                    y+=0;
                }
                break;
            case 11:
                if (POS=="TOP"){
                    x+=1;
                    y+=0;
                }
                break;
            case 12:
                if(POS=="RIGHT"){
                    x+=0;
                    y+=1;
                }
                break;
            case 13:
                if(POS=="LEFT"){
                    x+=0;
                    y+=1;
                }
                break;
        }
        cout << x << " " << y << endl;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
    }
}
