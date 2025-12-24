#include "graph.h"

void CreateGraph(Graph *G) {
    G->first = NULL;
}

void InsertNode(Graph *G, infoGraph X) {
    adrNode P = (adrNode) malloc(sizeof(ElmNode));
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;

    if (G->first == NULL) {
        G->first = P;
    } else {
        adrNode Q = G->first;
        while (Q->Next != NULL) {
            Q = Q->Next;
        }
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E = (adrEdge) malloc(sizeof(ElmEdge));
    E->Node = N2;
    E->Next = NULL;

    if (N1->firstEdge == NULL) {
        N1->firstEdge = E;
    } else {
        adrEdge P = N1->firstEdge;
        while (P->Next != NULL) {
            P = P->Next;
        }
        P->Next = E;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        printf("%c -> ", P->info);
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            printf("%c ", E->Node->info);
            E = E->Next;
        }
        printf("\n");
        P = P->Next;
    }
}

void ResetVisited(Graph *G) {
    adrNode P = G->first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}
void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1) return;

    printf("%c ", N->info);
    N->visited = 1;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->Node);
        E = E->Next;
    }
}
void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    adrNode queue[50];
    int front = 0, rear = 0;

    N->visited = 1;
    queue[rear++] = N;

    while (front < rear) {
        adrNode P = queue[front++];
        printf("%c ", P->info);

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                queue[rear++] = E->Node;
            }
            E = E->Next;
        }
    }
}
