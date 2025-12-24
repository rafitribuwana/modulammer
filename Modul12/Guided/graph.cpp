#include "graph.h"
#include <queue>
#include <stack>

/* ===== CREATE ===== */
void CreateGraph(Graph &G) {
    G.First = NULL;
}

/* ===== ALLOCATE ===== */
adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->Visited = false;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

/* ===== INSERT NODE ===== */
void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.First == NULL) {
        G.First = P;
    } else {
        adrNode Q = G.First;
        while (Q->Next != NULL)
            Q = Q->Next;
        Q->Next = P;
    }
}

/* ===== FIND NODE ===== */
adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.First;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->Next;
    }
    return NULL;
}

/* ===== CONNECT NODE (DIRECTED) ===== */
void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E = AllocateEdge(N2);
    E->Next = N1->firstEdge;
    N1->firstEdge = E;
}

/* ===== PRINT GRAPH ===== */
void PrintGraph(Graph G) {
    adrNode P = G.First;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

/* ===== RESET VISITED ===== */
void ResetVisited(Graph &G) {
    adrNode P = G.First;
    while (P != NULL) {
        P->Visited = false;
        P = P->Next;
    }
}

/* ===== BFS ===== */
void BFS(Graph G, adrNode start) {
    queue<adrNode> Q;
    Q.push(start);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        if (!P->Visited) {
            P->Visited = true;
            cout << P->info << " ";

            adrEdge E = P->firstEdge;
            while (E != NULL) {
                if (!E->Node->Visited)
                    Q.push(E->Node);
                E = E->Next;
            }
        }
    }
}

/* ===== DFS ===== */
void DFS(Graph G, adrNode start) {
    stack<adrNode> S;
    S.push(start);

    while (!S.empty()) {
        adrNode P = S.top();
        S.pop();

        if (!P->Visited) {
            P->Visited = true;
            cout << P->info << " ";

            adrEdge E = P->firstEdge;
            while (E != NULL) {
                if (!E->Node->Visited)
                    S.push(E->Node);
                E = E->Next;
            }
        }
    }
}
