#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
void slow(int speed, int gap) {
    if (speed > gap + 1)
        cout<<"SLOW"<<endl;
}

void speedto(int speed, int gap) {
    if (speed < gap + 1)
        cout<<"SPEED"<<endl;
}
int main()
{
    int R; // the length of the road before the gap.
    cin >> R; cin.ignore();
    int G; // the length of the gap.
    cin >> G; cin.ignore();
    int L; // the length of the landing platform.
    cin >> L; cin.ignore();
    bool isjump = false;

    while (1) {
        int S; // the motorbike's speed.
        cin >> S; cin.ignore();
        int X; // the position on the road of the motorbike.
        cin >> X; cin.ignore();
        
        int before_gap = R - X;
        if (S < G +1 && isjump != true)
            speedto(S, G);
        else if(S > G+1)
            slow(S , G);
        else if (before_gap == 1) {
            cout<<"JUMP"<<endl;
            isjump = true;
        } else if (isjump != true)
            cout<<"WAIT"<<endl;
        else
            cout<<"SLOW"<<endl;
    }
}

