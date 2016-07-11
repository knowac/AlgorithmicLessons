#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <climits>
#include <iterator>
#include <utility>
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Graph {
public:
    Graph(int size) {
        int i, j;

        n = size;
        
        A = new int*[n];
        for(i = 0; i < n; ++i)
            A[i] = new int[n];
        
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                A[i][j] = 0;
    }
    
    bool isConnected(int u, int v) {
        return (A[u][v] == 1);
    };
    
    void addEdge(int u, int v) {
        A[u][v]=1;
        A[v][u]=1;
    };

    int minDistance(vector<int> dist, vector<int> prev) {
        int min = INT_MAX;
        int min_index;
        
        for(int v = 0; v < n; ++v) {
            if(prev[v] == 0 && dist[v] < min) {
                min = dist[v];
                min_index= v;
            }
        }
        return min_index;
    }
    
    pair<int,int> dijkstra2(int s, int N) {
        deque<int> Q(n);
        vector<int> shortest(n);
        vector<int> prev(n);
        deque<pair<int,int>> test;
        for (int i = 0; i < n; ++i){
            shortest[i] = INT_MAX;
            prev[i] = 0;
            Q.push_back(i);
        }
        shortest[s] = 0;
        
        while(!Q.empty()){
            int u = minDistance(shortest, prev);
            if(u == N || test.size() > 0) break;
            Q.erase(Q.begin()+u);
            for( int v = 0; v < n; ++v) {
                if(isConnected(u,v))
                    if(shortest[u] +1< shortest[v]) {
                        shortest[v] = shortest[u]+1;
                        prev[v] = u;
                        test.push_front(make_pair(u,v));
                }
            }
        }

        for(auto i : test)
            if(i.second == N) {
                //cout<<i.first<<" "<< i.second<<endl;
                return i;
            }
        return test.front();
    }
    bool findMinSolution(const int& S, const int& E, const vector<pair<int,int>>& data) {
        for(auto i : data) {
            cerr<< S << " " << i.first<<" "<<i.second <<endl;
            if((i.second == E && i.first == S) || (i.second == S && i.first == E)) {
                cerr<< "Tutaj1 : "<<S << " " << i.first<<" "<<i.second <<endl;
                cout<< i.first<<" "<<i.second <<endl;
                return true;
            }
        }
        return false;
    }
private:
    int** A;
    int n;
};

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    vector<int> Ei;
    
    cin >> N >> L >> E; cin.ignore();
    Graph g(N);
    for (int i = 0; i < L; ++i) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        g.addEdge(N1, N2);
    }
        
    for (int i = 0; i < E; ++i) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        Ei.push_back(EI);
    }
    
    vector<pair<int,int>> temp;
    while (true) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        temp.clear(); 
        for(auto i: Ei) temp.push_back(g.dijkstra2(SI,i));
        bool flag = false;
        for(auto i: Ei) {
            flag = g.findMinSolution(SI, i, temp);
            if(flag)
                break;
        };
        if(!flag)
            cout<< temp.front().first<<" "<<temp.front().second <<endl;
        //cout << "1 0" << endl; // Example: 0 1 are the indices of the nodes you wish to sever the link between
    }
}
