#ifndef _H_GRAPH 
#define _H_GRAPH

#include <vector>
#include <iostream>
#include <queue>


class Graph
{
    private:
        int V;                  // グラフに含まれる vertices の数
        std::vector<int>* adj;  // ある Node に繋がっている Node のリスト
                                // int* adj[i] に Node i に繋がっている
                                // Node のリストへのポインタが入っている
    public:
        Graph( int V ): V(V), adj(new std::vector<int>[V]) {}
        // from から to へエッジを繋ぐ
        void addEdge( int from, int to ){ adj[from].push_back(to); }
        bool isRoute( int from, int to );
};

// from から to に行けるか queue を使って幅優先探索(BFS)
bool Graph::isRoute( int from, int to )
{
    std::vector<bool> visited(V,false);
    std::queue<int> q;

    q.push( from );

    while( !q.empty() )
    {
        int curr = q.front();
        q.pop();
        if( curr == to ) return true;
        visited[curr] = true;
        for( int i = 0; i < adj[curr].size(); ++i ){
            if( !visited[adj[curr][i]] ) q.push( adj[curr][i] );
        }
    }
    return false;
}


# endif