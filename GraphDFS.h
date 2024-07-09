#ifndef GRAPHDFS_H
#define GRAPHDFS_H

#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class GraphDFS{
private:
    unordered_map<string, list<pair<string,int> > > l;
public: 
    void addEdge(string x, string y, bool bidir, int weight)
    {
        l[x].push_back(make_pair(y,weight));
        if(bidir)
        {
            l[y].push_back(make_pair(x, weight));
        }
    }

    void printAdjList()
    {
        for (auto p: l)
        {
            string city = p.first;
            list<pair<string,int> > nbrs = p.second;
            cout << city << "->";

            for(auto nbr : nbrs)
            {
                string dest = nbr.first;
                int dist = nbr.second;
                cout << dest << " " << dist << ",";
            }
            cout << endl;
        }
    }

    void dfs(string src)
    {
        // nodes or keys in this are string
        unordered_map<string, bool> visited;

        // mark all the nodes as not visited in the beginning
        for (auto p : l)
        {
            string node = p.first;
            visited[node] = false;
        }

        unordered_map<string, pair<string, string> > edges;

        int totalDistance = 0;

        dfsHelper(src, visited, edges, totalDistance, "");

        for(auto p : edges)
        {
            string dest = p.first;
            string src = p.second.first;
            string type = p.second.second;
            if(type == "Discovery")
            {
                cout << "Edge: " << src << "->" << dest << ", Type: " << type << endl;
            }
            else if (type == "Back")
            {
                cout << "Edge: " << src << "->" << dest << ", Type: "  << type << endl;
            }
        }

        cout << "Total distance travelled on discovery edges: " << totalDistance << endl;
    }

    void dfsHelper(string src, unordered_map<string, bool>& visited, unordered_map<string, pair<string, string>>& edges, int& totalDistance, string parent) {
        cout << src << " ";
        visited[src] = true;

        for (auto nbr : l[src]) {
            string dest = nbr.first;
            int dist = nbr.second;

            if (!visited[dest]) {
                edges[dest] = make_pair(src, "Discovery");
                totalDistance += dist;
                dfsHelper(dest, visited, edges, totalDistance, src);
            }
            else if (visited[dest] && dest != parent) {
                edges[dest] = make_pair(src, "Back");
            }
        }
    }
};

#endif