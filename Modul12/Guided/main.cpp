#include "graph.h"
#include "graph.cpp"

int main() {
    Graph G;
    CreateGraph(G);

    // tambah node
    InsertNode(G, 1);
    InsertNode(G, 2);
    InsertNode(G, 3);
    InsertNode(G, 4);

    // ambil alamat node
    adrNode N1 = FindNode(G, 1);
    adrNode N2 = FindNode(G, 2);
    adrNode N3 = FindNode(G, 3);
    adrNode N4 = FindNode(G, 4);

    // hubungkan node (graph berarah)
    ConnectNode(N1, N2);
    ConnectNode(N1, N3);
    ConnectNode(N2, N4);
    ConnectNode(N3, N4);

    cout << "Graph:\n";
    PrintGraph(G);

    cout << "\nBFS: ";
    BFS(G, N1);

    ResetVisited(G);

    cout << "\nDFS: ";
    DFS(G, N1);

    return 0;
}
