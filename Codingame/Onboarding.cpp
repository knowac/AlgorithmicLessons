#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<string, int> MyPairType;
struct CompareSecond
{
    bool operator()(const MyPairType& left, const MyPairType& right) const
    {
        return left.second < right.second;
    }
};

std::pair<std::string, int> getMin(std::map<string, int> mymap) 
{
  return *min_element(mymap.begin(), mymap.end(), CompareSecond());
};

int main()
{
    map<string, int> mapSta;
    while (1) {
        int count; // The number of current enemy ships within range
        cin >> count; cin.ignore();
        
        for (int i = 0; i < count; i++) {
            string enemy; // The name of this enemy
            int dist; // The distance to your cannon of this enemy
            cin >> enemy >> dist; cin.ignore();
            mapSta[enemy] = dist;
        }
        
        std::pair<std::string, int> min = getMin(mapSta);
        cout<<min.first<<endl;
        mapSta.erase(min.first);
    }
}

