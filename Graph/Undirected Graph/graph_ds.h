#ifndef _GRAPH_DS_H_
#define _GRAPH_DS_H_

#include "std_types.h" // Include necessary header file for standard data types

#define MAX_VERTICES 100 // Define maximum size for the graph
#define GRAPH_DEBUG

typedef struct EdgeNode 
{
  sint32_t dest;
  struct EdgeNode* next;

} EdgeNode;

typedef struct Vertex 
{
  uint32_t data;
  EdgeNode* edges;

} Vertex;

typedef struct Graph 
{
  uint32_t numVertices;
  Vertex vertices[MAX_VERTICES];

} Graph;

typedef enum
{
  GRAPH_OK,               /* Graph operation performed successfully */
  GRAPH_NOK,              /* Graph operation not performed successfully */
  INVALID_POSITION,       /* Invalid position provided for the Graph operation */
  GRAPH_FULL,             /* Graph is full */
  GRAPH_HAS_SPACE,        /* Graph not full */
  GRAPH_EMPTY,            /* Graph is empty */
  GRAPH_NULL_POINTER,     /* NULL pointer passed to the Graph operations */
  GRAPH_ALLOC_FAIL,       /* Memory allocation for Graph array failed */
  NULL_POINTER            /* Additional NULL pointer status */

} return_status_t;        // Define return status enumeration

/**
 * Initializes a graph with the given number of vertices and default data for each vertex.
 *
 * @param graph       : Pointer to the graph structure to be initialized.
 * @param numVertices : Number of vertices in the graph.
 * @param defaultData : Default data to be associated with each vertex.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t initGraph(Graph *graph, uint32_t numVertices, uint32_t defaultData);

/**
 * Clears all vertices and edges in the graph.
 *
 * @param graph : Pointer to the graph structure to be cleared.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t clearGraph(Graph *graph);

/**
 * Retrieves the number of vertices in the graph.
 *
 * @param graph   : Pointer to the graph structure.
 * @param numVer  : Pointer to store the number of vertices.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t getNumVertices(Graph *graph, uint32_t *numVer);

/**
 * Retrieves the number of edges in the graph.
 *
 * @param graph    : Pointer to the graph structure.
 * @param numEdges : Pointer to store the number of edges.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t getNumEdges(Graph *graph, uint32_t *numEdges);

/**
 * Retrieves the adjacent vertices of a given vertex in the graph.
 *
 * @param graph          : Pointer to the graph structure.
 * @param vertex         : Vertex for which adjacent vertices are to be retrieved.
 * @param adjacentVertices: Pointer to store the adjacent vertices.
 * @param numAdjacent    : Pointer to store the number of adjacent vertices.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t getAdjacentVertices(Graph *graph, uint32_t vertex, uint32_t *adjacentVertices, uint32_t *numAdjacent);

/**
 * Destroys the graph by freeing all memory allocated to vertices and edges.
 *
 * @param graph : Pointer to the graph structure to be destroyed.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t destroyGraph(Graph *graph);

/**
 * Retrieves the data associated with a vertex in the graph.
 *
 * @param graph  : Pointer to the graph structure.
 * @param vertex : Vertex for which data is to be retrieved.
 * @param data   : Pointer to store the data associated with the vertex.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t getVertexData(Graph *graph, uint32_t vertex, uint32_t *data);

/**
 * Sets the data associated with a vertex in the graph.
 *
 * @param graph  : Pointer to the graph structure.
 * @param vertex : Vertex for which data is to be set.
 * @param data   : Data to be associated with the vertex.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t setVertexData(Graph *graph, sint32_t vertex, uint32_t data);

/**
 * Adds an edge between two vertices in the graph.
 *
 * @param graph  : Pointer to the graph structure.
 * @param source : Source vertex.
 * @param dest   : Destination vertex.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t addEdge(Graph *graph, sint32_t source, sint32_t dest);

/**
 * Removes an edge between two vertices in the graph.
 *
 * @param graph  : Pointer to the graph structure.
 * @param source : Source vertex.
 * @param dest   : Destination vertex.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t removeEdge(Graph *graph, sint32_t source, sint32_t dest);

/**
 * Checks if there is an edge between two vertices in the graph.
 *
 * @param graph  : Pointer to the graph structure.
 * @param source : Source vertex.
 * @param dest   : Destination vertex.
 * @param retVal : Pointer to store the return status of the operation.
 * 
 * @return bool_t indicating whether there is an edge between the source and destination vertices.
 */
bool_t isAdjacent(Graph *graph, sint32_t source, sint32_t dest, return_status_t *retVal);

/**
 * Prints the adjacency list representation of the graph.
 *
 * @param graph : Pointer to the graph structure.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t printGraph(Graph *graph);

#endif // !_GRAPH_DS_H_