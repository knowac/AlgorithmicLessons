#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 int LX, LY, initialTX, initialTY, thorX, thorY;
 int x, y, bin;
 int MAX_X = 40;
 int MIN_X = 0;
 int MAX_Y = 18;
 int MIN_Y = 0;

void actualize(){
    
}
string getDir()
{
    x = thorX-LX;
    y = thorY-LY;
        
    bin = 0;
        
    cerr << thorX-LX << " " << thorY-LY <<endl;
        
    if ( thorX >= MIN_X && thorX <= MAX_X ) {
        if ( x > 0 )
            bin += 1;
        if ( x < 0)
            bin += 10;
    }
    if ( thorY >= MIN_Y && thorY <= MAX_Y ) {
        if ( y > 0 )
            bin += 100;
        if ( y < 0 )
            bin += 1000;
    }
        
    switch(bin) {
        case 1:
            thorX += -1;
            thorY += 0;
            return "W";
        case 10:
            thorX += 1;
            thorY += 0;
            return "E";
        case 100:
            thorX += 0;
            thorY += -1;
            return "N";
        case 1000:
            thorX += 0;
            thorY += 1;
            return "S";
        case 101:
            thorX += -1;
            thorY += -1;
            return "NW";
        case 110:
            thorX += 1;
            thorY += -1;
            return "NE";
        case 1001:
            thorX += -1;
            thorY += 1;
            return "SW";
        case 1010:
            thorX += 1;
            thorY += 1;
            return "SE";
    }
};
int main()
{
    cin >> LX >> LY >> initialTX >> initialTY; cin.ignore();
    thorX = initialTX;
    thorY = initialTY;
    // game loop
    while (true) {
        int E;
        cin >> E; cin.ignore();
        cout<<getDir()<<endl;
    }
}
