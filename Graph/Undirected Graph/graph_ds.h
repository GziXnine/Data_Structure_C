#ifndef _GRAPH_DS_H_
#define _GRAPH_DS_H_

#include "std_types.h" // Include necessary header file for standard data types

#define MAX_VERTICES 100 // Define maximum size for the graph
#define GRAPH_DEBUG

typedef struct Graph 
{
  uint32_t adjMatrix[MAX_VERTICES][MAX_VERTICES];
  uint32_t numVertices;

} grapg_ds_t;

typedef enum
{
  GRAPH_OK,               /* Graph operation performed successfully */
  GRAPH_NOK,              /* Graph operation not performed successfully */
  GRAPH_FULL,             /* Graph is full */
  GRAPH_HAS_SPACE,        /* Graph not full */
  GRAPH_EMPTY,            /* Graph is empty */
  GRAPH_NULL_POINTER,     /* NULL pointer passed to the Graph operations */
  GRAPH_ALLOC_FAIL,       /* Memory allocation for Graph array failed */
  NULL_POINTER            /* Additional NULL pointer status */

} return_status_t;        // Define return status enumeration

return_status_t initGraph(grapg_ds_t *graph, uint32_t numVertices);
return_status_t addEdge(grapg_ds_t *graph, uint16_t src, uint16_t dest);
return_status_t removeEdge(grapg_ds_t *graph, uint16_t src, uint16_t dest);
bool_t isAdjacent(grapg_ds_t *graph, uint16_t src, uint16_t dest);
return_status_t getNumVertices(grapg_ds_t *graph, uint32_t *numVerts);
return_status_t getNumEdges(grapg_ds_t *graph, uint32_t *numEdges);
return_status_t getAdjacentVertices(grapg_ds_t *graph, uint16_t vertex, uint16_t *numAdjacent);
return_status_t printGraph(grapg_ds_t *graph);

#endif // !_GRAPH_DS_H_