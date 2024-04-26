#ifndef _GRAPH_DS_H_
#define _GRAPH_DS_H_

#include "std_types.h" // Include necessary header file for standard data types

#define MAX_VERTICES 100 // Define maximum size for the graph
#define GRAPH_DEBUG

typedef struct GraphVertex 
{
  uint32_t data; // Data associated with the vertex

} GraphVertex;

typedef struct Graph 
{
  uint32_t adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix to represent edges between vertices
  uint32_t numVertices; // Number of vertices in the graph
  GraphVertex vertices[MAX_VERTICES]; // Array to store data associated with each vertex

} graph_ds_t;

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
return_status_t initGraph(graph_ds_t *graph, uint32_t numVertices, uint32_t defaultData);

/**
 * Removes a vertex from the graph and updates the adjacency matrix accordingly.
 *
 * @param graph  : Pointer to the graph structure.
 * @param vertex : Vertex to be removed.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t removeVertex(graph_ds_t *graph, uint16_t vertex);

/**
 * Adds an edge between two vertices in the graph.
 *
 * @param graph  : Pointer to the graph structure.
 * @param source : Source vertex.
 * @param dest   : Destination vertex.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t addEdge(graph_ds_t *graph, uint16_t src, uint16_t dest);

/**
 * Removes an edge between two vertices in the graph.
 *
 * @param graph  : Pointer to the graph structure.
 * @param source : Source vertex.
 * @param dest   : Destination vertex.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t removeEdge(graph_ds_t *graph, uint16_t src, uint16_t dest);

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
bool_t isAdjacent(graph_ds_t *graph, uint16_t source, uint16_t dest, return_status_t *retVal);

/**
 * Retrieves the number of vertices in the graph.
 *
 * @param graph   : Pointer to the graph structure.
 * @param numVerts: Pointer to store the number of vertices.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t getNumVertices(graph_ds_t *graph, uint32_t *numVerts);

/**
 * Retrieves the number of edges in the graph.
 *
 * @param graph    : Pointer to the graph structure.
 * @param numEdges : Pointer to store the number of edges.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t getNumEdges(graph_ds_t *graph, uint32_t *numEdges);

/**
 * Retrieves the degree of a given vertex in the graph.
 *
 * @param graph  : Pointer to the graph structure.
 * @param vertex : Vertex for which degree is to be retrieved.
 * @param degree : Pointer to store the degree of the vertex.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t getDegree(graph_ds_t *graph, uint16_t vertex, uint32_t *degree);

/**
 * Retrieves the adjacent vertices of a given vertex in the graph along with their associated data.
 *
 * @param graph          : Pointer to the graph structure.
 * @param vertex         : Vertex for which adjacent vertices are to be retrieved.
 * @param numAdjacent    : Pointer to store the number of adjacent vertices.
 * @param adjacentData   : Pointer to store the associated data of adjacent vertices.
 * @param retVal         : Pointer to store the return status of the operation.
 * 
 * @return uint32_t array containing adjacent vertices.
 */
uint32_t *getAdjacentVertices(graph_ds_t *graph, uint16_t vertex, uint32_t *numAdjacent, uint32_t **adjacentData, return_status_t *retVal);

/**
 * Prints the adjacency matrix representation of the graph.
 *
 * @param graph : Pointer to the graph structure.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t printGraph(graph_ds_t *graph);

/**
 * Sets the data associated with a vertex in the graph.
 *
 * @param graph  : Pointer to the graph structure.
 * @param vertex : Vertex for which data is to be set.
 * @param data   : Data to be associated with the vertex.
 * 
 * @return return_status_t indicating success or failure of the operation.
 */
return_status_t setVertexData(graph_ds_t *graph, sint16_t vertex, uint32_t data);

#endif // !_GRAPH_DS_H_