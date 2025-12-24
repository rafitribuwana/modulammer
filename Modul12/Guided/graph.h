#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef int infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

/* ===== STRUCT ===== */
struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    bool Visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode First;
};

/* ===== PRIMITIF ADT ===== */
void CreateGraph(Graph &G);

adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);

void PrintGraph(Graph G);
void ResetVisited(Graph &G);

void BFS(Graph G, adrNode start);
void DFS(Graph G, adrNode start);

#endif
