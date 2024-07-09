#include<iostream>
#include"GraphDFS.h"

using namespace std;

int main()
{
    GraphDFS g;
    g.addEdge("Dallas", "Houston", true, 239);
    g.addEdge("Dallas", "Kansas City", true, 496);
    g.addEdge("Dallas", "Atlanta", true, 781);
    g.addEdge("Dallas", "Los Angeles", true, 1435);
    g.addEdge("Houston", "Atlanta", true, 810);
    g.addEdge("Houston", "Miami", true, 1187);
    g.addEdge("Miami", "Atlanta", true, 661);
    g.addEdge("Kansas City", "Atlanta", true, 864);
    g.addEdge("Kansas City", "Los Angeles",true, 1663);
    g.addEdge("Kansas City", "Denver", true, 599);
    g.addEdge("Kansas City", "Chicago", true, 533);
    g.addEdge("Kansas City", "New York", true, 1260);
    g.addEdge("Kansas City", "Atlanta", true, 864);
    g.addEdge("Atlanta", "New York", true, 888);
    g.addEdge("Los Angeles", "Denver", true, 1015);
    g.addEdge("Los Angeles", "San Francisco", true, 381);
    g.addEdge("San Francisco", "Seattle", true, 807);
    g.addEdge("Seattle", "Denver", true, 1331);
    g.addEdge("Seattle", "Chicago", true, 2097);
    g.addEdge("Denver", "Chicago", true, 1003);
    g.addEdge("Chicago", "Boston", true, 983);
    g.addEdge("Chicago", "New York", true, 787);
    g.addEdge("Boston", "New York", true, 214);

    g.printAdjList();
    cout << endl << endl;

    g.dfs("Dallas");
    //cout << endl << endl;
    //g.printAdjList();

    return 0;
}