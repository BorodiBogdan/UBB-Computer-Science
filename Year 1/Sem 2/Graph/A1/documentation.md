# Graph Class Documentation

## Overview

This documentation outlines the implementation of a Graph class, which provides functionalities for managing directed graphs. The Graph class supports operations such as adding and removing vertices and edges, retrieving information about vertices and edges, iterating through inbound and outbound edges of vertices, and reading/writing graphs from/to text files.

## Class: Graph

### Constructors

#### Graph(int n)
- **Description:** Constructs a graph with `n` vertices.
- **Parameters:**
  - `n`: Number of vertices in the graph.
### Destructor

#### ~Graph()

*   **Description:** Destroys the graph object and releases memory.
    

### Public Methods

#### int getNumberOfVertices()

*   **Description:** Gets the number of vertices in the graph.
    
*   **Returns:** Number of vertices.
    

#### int getNumberOfEdges()

*   **Description:** Gets the number of edges in the graph.
    
*   **Returns:** Number of edges.
    

#### bool isEdge(int vertex1, int vertex2)

*   **Description:** Checks if there is an edge from **vertex1** to **vertex2**.
    
*   **Parameters:**
    
    *   **vertex1**: Source vertex.
        
    *   **vertex2**: Destination vertex.
        
*   **Returns:** **true** if there is an edge, otherwise **false**.
    

#### int getOutDegree(int vertex)

*   **Description:** Gets the out degree of a specified vertex.
    
*   **Parameters:**
    
    *   **vertex**: Vertex for which out degree is to be calculated.
        
*   **Returns:** Out degree of the vertex.
    

#### int getInDegree(int vertex)

*   **Description:** Gets the in degree of a specified vertex.
    
*   **Parameters:**
    
    *   **vertex**: Vertex for which in degree is to be calculated.
        
*   **Returns:** In degree of the vertex.
    

#### void addVertex(int vertex)

*   **Description:** Adds a vertex to the graph.
    
*   **Parameters:**
    
    *   **vertex**: Vertex to be added.
        

#### void addEdge(int vertex1, int vertex2)

*   **Description:** Adds an edge from **vertex1** to **vertex2**.
    
*   **Parameters:**
    
    *   **vertex1**: Source vertex.
        
    *   **vertex2**: Destination vertex.
        

#### void removeVertex(int vertex)

*   **Description:** Removes a vertex from the graph.
    
*   **Parameters:**
    
    *   **vertex**: Vertex to be removed.
        

#### void removeEdge(int vertex1, int vertex2)

*   **Description:** Removes the edge from **vertex1** to **vertex2**.
    
*   **Parameters:**
    
    *   **vertex1**: Source vertex.
        
    *   **vertex2**: Destination vertex.
        

#### int retrieveEdgeInformation(int vertex1, int vertex2)

*   **Description:** Retrieves the information attached to the edge from **vertex1** to **vertex2**.
    
*   **Parameters:**
    
    *   **vertex1**: Source vertex.
        
    *   **vertex2**: Destination vertex.
        
*   **Returns:** Information attached to the edge.
    

#### mapIterator getVerticeIterator()

*   **Description:** Gets an iterator to iterate through the set of vertices.
    
*   **Returns:** Iterator pointing to the beginning of the set of vertices.
    

#### mapIterator getEndOfIteration()

*   **Description:** Gets an iterator pointing to the end of the set of vertices.
    
*   **Returns:** Iterator pointing to the end of the set of vertices.
    

#### edgeIterator getIteratorInboundEdges(int vertex)

*   **Description:** Gets an iterator to iterate through the set of inbound edges of a specified vertex.
    
*   **Parameters:**
    
    *   **vertex**: Vertex for which inbound edges are to be iterated.
        
*   **Returns:** Iterator pointing to the beginning of the set of inbound edges.
    

#### edgeIterator getEndOfIterationInboundEdges(int vertex)

*   **Description:** Gets an iterator pointing to the end of the set of inbound edges of a specified vertex.
    
*   **Parameters:**
    
    *   **vertex**: Vertex for which inbound edges are to be iterated.
        
*   **Returns:** Iterator pointing to the end of the set of inbound edges.
    

#### edgeIterator getIteratorOutboundEdges(int vertex)

*   **Description:** Gets an iterator to iterate through the set of outbound edges of a specified vertex.
    
*   **Parameters:**
    
    *   **vertex**: Vertex for which outbound edges are to be iterated.
        
*   **Returns:** Iterator pointing to the beginning of the set of outbound edges.
    

#### edgeIterator getEndOfIterationOutboundEdges(int vertex)

*   **Description:** Gets an iterator pointing to the end of the set of outbound edges of a specified vertex.
    
*   **Parameters:**
    
    *   **vertex**: Vertex for which outbound edges are to be iterated.
        
*   **Returns:** Iterator pointing to the end of the set of outbound edges.
    

#### void modifyEdgeInformation(int vertex1, int vertex2, int information)

*   **Description:** Modifies the information attached to the edge from **vertex1** to **vertex2**.
    
*   **Parameters:**
    
    *   **vertex1**: Source vertex.
        
    *   **vertex2**: Destination vertex.
        
    *   **information**: New information to be attached to the edge.
        

### File I/O Operations

The class supports reading and writing graphs from/to text files. However, the specific format of the files is not documented here.

- **Example:**
  ```cpp
  Graph graph(5);
