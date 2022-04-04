# Implemetetation of Graph using matrix

- ## Compiling program

```bash
$: make
```

- ## Running program

### for Linux

```bash
$: ./main graph_file.csv
```

### for Windows

```cmd
> main.exe graph_file.csv
```

## Class MatrixGraph

Class MatrixGraph is a class that represents a hash set and has such methods and constructors:

````c++
    // Constrctor
    MatrixGraph(int vertices = MAX_SIZE);
    // Destructor
    ~MatrixGraph();

    // Function to create connection between two vertices
    void addEdge(const int &v1, const int &v2, const int &value);
    // Function to remove connection between two vertices
    void removeEdge(const int &v1, const int &v2);
    // Function to check if there is a connection between two vertices and get value of weight
    int checkEdge(const int &v1, const int &v2);
    // Function to clear graph and set up new settings
    void createVertices(int number);

    // Function to get number of neighbours of vertex
    int vertexDegree(const int &v);
    // Function to get all neihgbour vertices
    std::vector<int> getNeighbourIndices(const int &v);
    // Function to print all neihgbour vertices
    void printNeighbourIndices(const int &v);
    // Function to get number of edges
    int getNumberOfEdges();
    // Function to add edges from a file
    void read_graph(std::string path);
    // Function to export graph to a file
    void to_dot(std::string fileName);
    // Function to check wheather graph is a complete
    bool isComplete();
    // Function to check if given vertice is in graph
    bool contains(const int &v);
````

- ### Constructors

```C++
MatrixGraph(int vertices = MAX_SIZE);
```

> Constructor with arguments, creates empty graph. MAX_SIZE = 500 by default.

- ### Destructors

```C++
~MatrixGraph();
```

> Frees the allocated memory.

- ### Public methods

```C++
void addEdge(const int &v1, const int &v2, const int &value);
```

> Function to create connection between two vertices

Parameters:

v1 - first vertex.
v2 - second vertex.
value - weight of edge.

---

```C++
void removeEdge(const int &v1, const int &v2);
```

> Function to remove connection between two vertices.

Parameters:

v1 - first vertex.
v2 - second vertex.

---

```C++
int checkEdge(const int &v1, const int &v2);
```

> Function to check if there is a connection between two vertices and get value of weight.  

Parameters:

v1 - first vertex.
v2 - second vertex.

---

```C++
void createVertices(int number);
```

> Function to clear graph and set up new settings.

Parameters:

number - number of new vertices.

---

```C++
int vertexDegree(const int &v);
```

> Function to get number of neighbours of vertex

Parameters:

v - vertex that we are interested in.

---

```C++
std::vector<int> getNeighbourIndices(const int &v);
```

> Function to get all neihgbour vertices.

Parameters:

v - vertex that we are interested in.

---

```C++
void printNeighbourIndices(const int &v);
```

> Function to print all neihgbour vertices.

Parameters:

v - vertex that we are interested in.

---

```C++
int getNumberOfEdges();
```

> Function to get number of edges.

---

```C++
void read_graph(std::string path);
```

> Function to add edges from a file.

Parameters:

path - path to a file that contains data capable to read by the program.

---

```C++
void to_dot(std::string fileName);
```

> Function to export graph to a file that has .dot extension.

Parameters:

filename - name of file in which the graph will be exported.

---

```C++
bool isComplete();
```

> Function to check wheather graph is a complete.

---

```C++
bool contains(const int &v);
```

> Function to check if given vertice is in graph.

Parameters:

v - vertex that we are interested in.

---
