#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/



int main()
{
    int N;
    vector<int> P;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        P.push_back(Pi);
    }
    
    sort(P.begin(), P.end());
    int max = *max_element(P.begin(), P.end());
    
    for (int i = 0; i <P.size(); ++i) {
        if (abs(P[i] -P[i+1]) < max)
            max = abs(P[i] -P[i+1]);
    }
    
    

    
    cout << max  << endl;
}
