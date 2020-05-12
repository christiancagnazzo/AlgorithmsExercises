typedef struct _Graph Graph;
typedef struct _Node Node;

typedef struct _Edge {
	int src;
  int dest;
  int weight;
} Edge;

Graph * Graph_create(Edge *, int);

void Graph_print(Graph *);

void Graph_add_edge(Graph *, Edge *);

void Graph_remove_edge(Graph *, Edge *);

int Graph_is_connected(Graph *);
