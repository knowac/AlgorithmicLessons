#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <climits>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // the number of temperatures to analyse
    cin >> N; cin.ignore();
    
    string input;
    vector<int> inputs;
    int min_dist(INT_MIN+1);
    int i(0);
    while(getline( std::cin, input) )
    {
      istringstream in(input);
      copy( std::istream_iterator<int>( in ), std::istream_iterator<int>(), back_inserter(inputs) );
    
        for(auto it:inputs){
            if(abs(it)<=abs(min_dist)){
            min_dist=it;
            }
        }
        if(input.size()>N){
            cout<<min_dist<<endl;
        }
        ++i;
        cerr<<i<<endl;
   }
   if(min_dist==INT_MIN+1)
    cout<<0<<endl;
    //cout<<0<<endl;
}
