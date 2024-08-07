#include<bits/stdc++.h>
using namespace std;


// Structure to represent a graph
struct Graph
{
    vector< pair<int, pair<string, string> > > edges;

    // Utility function to add an edge
    void addEdge(string src, string dest, int weight)
    {
        edges.push_back({weight, {src, dest}});
    }

    // Function to find MST using Kruskal's
    // MST algorithm
    int kruskalMST();
};

// To represent Disjoint Sets
struct DisjointSets
{
    unordered_map<string, string> parent;
    unordered_map<string, int> rnk;

    // Constructor.
    DisjointSets(vector<string> cities)
    {
        // Initially, all vertices are in
        // different sets and have rank 0.
        for (const string& city : cities)
        {
            rnk[city] = 0;

            //every element is parent of itself
            parent[city] = city;
        }
    }

    // Find the parent of a node 'u'
    // Path Compression
    string find(string u)
    {
        /* Make the parent of the nodes in the path
        from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union by rank
    void merge(string x, string y)
    {
        x = find(x), y = find(y);

        /* Make tree with smaller height
        a subtree of the other tree */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

/* Functions returns weight of the MST*/

int Graph::kruskalMST()
{
    int mst_wt = 0; // Initialize result

    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());

    // Extract all cities
    vector<string> cities;
    for (const auto& e : edges) {
        cities.push_back(e.second.first);
        cities.push_back(e.second.second);
    }
    sort(cities.begin(), cities.end());
    cities.erase(unique(cities.begin(), cities.end()), cities.end());

    // Create disjoint sets
    DisjointSets ds(cities);

    // Iterate through all sorted edges
    for (const auto& e : edges)
    {
        int weight = e.first;
        string src = e.second.first;
        string dest = e.second.second;

        string set_src = ds.find(src);
        string set_dest = ds.find(dest);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if src
        // and dest belong to same set)
        if (set_src != set_dest)
        {
            // Current edge will be in the MST
            // so print it with its weight
            cout << src << " - " << dest << " : " << weight << endl;

            // Update MST weight
            mst_wt += weight;

            // Merge two sets
            ds.merge(set_src, set_dest);
        }
    }

    return mst_wt;
}

int main(){
    Graph g;
    
    cout << "/***********************************************************************************\n";
    cout << "* This program will determine the minimum spanning tree for the graph with edges\n";
    cout << "* and total distance.\n";
    cout << "***********************************************************************************/\n";

    // Adding edges
    g.addEdge("Dallas", "Houston", 239);
    g.addEdge("Dallas", "Kansas City",496);
    g.addEdge("Dallas", "Atlanta", 781);
    g.addEdge("Dallas", "Los Angeles",1435);
    g.addEdge("Houston", "Atlanta",810);
    g.addEdge("Houston", "Miami",1187);
    g.addEdge("Miami", "Atlanta",661);
    g.addEdge("Kansas City", "Atlanta",864);
    g.addEdge("Kansas City", "Los Angeles", 1663);
    g.addEdge("Kansas City", "Denver", 599);
    g.addEdge("Kansas City", "Chicago", 533);
    g.addEdge("Kansas City", "New York", 1260);
    g.addEdge("Kansas City", "Atlanta", 864);
    g.addEdge("Atlanta", "New York", 888);
    g.addEdge("Los Angeles", "Denver", 1015);
    g.addEdge("Los Angeles", "San Francisco",381);
    g.addEdge("San Francisco", "Seattle", 807);
    g.addEdge("Seattle", "Denver", 1331);
    g.addEdge("Seattle", "Chicago",  2907);
    g.addEdge("Denver", "Chicago",  1003);
    g.addEdge("Chicago", "Boston", 983);
    g.addEdge("Chicago", "New York", 787);
    g.addEdge("Boston", "New York", 214);
    // Finding MST using Kruskal's algorithm
    int totalDistance = g.kruskalMST();
    cout << "Total distance: " << totalDistance << endl;

    return 0;
}