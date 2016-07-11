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
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();

    double x = X0;
    double y = Y0;
    double border_xl = 0;
    double border_xr = W-1;
    double border_yu = 0;
    double border_yd = H-1;

    while (1) {
        string BOMB_DIR; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> BOMB_DIR; cin.ignore();

        if(BOMB_DIR.find("U")!=std::string::npos){
            border_yd = y;
            y-= max(abs(border_yu - y)/2,1.0);}
        if(BOMB_DIR.find("D")!=std::string::npos){
            border_yu = y;
            y+= max(abs(border_yd - y)/2,1.0);}
        if(BOMB_DIR.find("L")!=std::string::npos){
            border_xr = x;
            x-= max(abs(border_xl - x)/2,1.0);}
        if(BOMB_DIR.find("R")!=std::string::npos){
            border_xl = x;
            x+= max(abs(border_xr - x)/2,1.0);}
        
        cout << static_cast<int>(x) <<" " << static_cast<int>(y) << endl; // the location of the next window Batman should jump to.
    }
}
