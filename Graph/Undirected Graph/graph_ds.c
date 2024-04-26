#include "graph_ds.h"

/**
 * Checks the status of the graph.
 *
 * @param graph : Pointer to the graph structure.
 * 
 * @return return_status_t indicating the current state of the graph.
 */
static return_status_t graph_status(graph_ds_t *graph)
{
  return ((!graph) ?                              GRAPH_NULL_POINTER : 
          (graph->numVertices  == MAX_VERTICES) ? GRAPH_FULL : 
          (graph->numVertices  == ZERO) ?         GRAPH_EMPTY  : 
                                                  GRAPH_HAS_SPACE);  
}

return_status_t initGraph(graph_ds_t *graph, uint32_t numVertices, uint32_t defaultData)
{
  return_status_t retVal = GRAPH_NOK;
  uint16_t index_1 = ZERO_INIT, index_2 = ZERO_INIT;

  if (NULL != graph)
  {
    retVal = GRAPH_OK;
    graph->numVertices = numVertices;

    for (index_1 = 0; index_1 < numVertices; ++index_1)
    {
      graph->vertices[index_1].data = defaultData;

      for (index_2 = 0; index_2 < numVertices; ++index_2)
      {
        graph->adjMatrix[index_1][index_2] = ZERO;
      }
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t setVertexData(graph_ds_t *graph, sint16_t vertex, uint32_t data)
{
  return_status_t retVal = GRAPH_NOK;

  if (NULL != graph)
  {
    retVal = GRAPH_OK;

    if (vertex >= 0 && vertex < (sint16_t)graph->numVertices)
    {
      graph->vertices[vertex].data = data;
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t removeVertex(graph_ds_t *graph, uint16_t vertex)
{
  return_status_t retVal = GRAPH_NOK;
  uint16_t index_1 = ZERO_INIT, index_2 = ZERO_INIT;

  if (NULL != graph)
  {
    if (vertex >= graph->numVertices)
    {
      retVal = GRAPH_NOK;

      // Shift rows up
      for (index_1 = vertex; index_1 < graph->numVertices - 1; ++index_1)
      {
        for (index_2 = 0; index_2 < graph->numVertices; ++index_2)
        {
          graph->adjMatrix[index_1][index_2] = graph->adjMatrix[index_1 + 1][index_2];
        }
      }

      // Shift columns left
      for (index_1 = vertex; index_1 < graph->numVertices - 1; ++index_1)
      {
        for (index_2 = 0; index_2 < graph->numVertices; ++index_2)
        {
          graph->adjMatrix[index_1][index_2] = graph->adjMatrix[index_1][index_2 + 1];
        }
      }

      (graph->numVertices)--;
    }
    else
    {
      retVal = INVALID_POSITION;
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t addEdge(graph_ds_t *graph, uint16_t source, uint16_t dest)
{
  return_status_t retVal = GRAPH_NOK;

  if (NULL != graph)
  {
    if (source < graph->numVertices && dest < graph->numVertices)
    {
      retVal = GRAPH_OK;

      graph->adjMatrix[source][dest] = ONE;
      graph->adjMatrix[dest][source] = ONE;
    }
    else
    {
      retVal = INVALID_POSITION;
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t removeEdge(graph_ds_t *graph, uint16_t source, uint16_t dest)
{
  return_status_t retVal = GRAPH_NOK;

  if (NULL != graph)
  {
    if (source < graph->numVertices && dest < graph->numVertices)
    {
      retVal = GRAPH_OK;

      graph->adjMatrix[source][dest] = ZERO;
      graph->adjMatrix[dest][source] = ZERO;
    }
    else
    {
      retVal = INVALID_POSITION;
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

bool_t isAdjacent(graph_ds_t *graph, uint16_t source, uint16_t dest, return_status_t *retVal)
{
  bool_t check = ZERO;

  if (NULL != graph)
  {
    if (source < graph->numVertices && dest < graph->numVertices)
    {
      *retVal = GRAPH_OK;
      
      check = (graph->adjMatrix[source][dest]);
    }
    else
    {
      *retVal = INVALID_POSITION;
    }
  }
  else
  {
    *retVal = GRAPH_NULL_POINTER;
  }
      
  return check;
}

return_status_t getNumVertices(graph_ds_t *graph, uint32_t *numVerts)
{
  return_status_t retVal = GRAPH_NOK;

  if (NULL != graph)
  {

    if (graph_status(graph) != GRAPH_EMPTY)
    {
      retVal = GRAPH_OK;

      *numVerts = graph->numVertices;
    }
    else
    {
      retVal = GRAPH_EMPTY;
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t getNumEdges(graph_ds_t *graph, uint32_t *numEdges)
{
  return_status_t retVal = GRAPH_NOK;
  uint16_t index_1 = ZERO_INIT, index_2 = ZERO_INIT;

  if (NULL != graph)
  {
    if (graph_status(graph) != GRAPH_EMPTY)
    {
      retVal = GRAPH_OK;
      *numEdges = ZERO;

      for (index_1 = 0; index_1 < graph->numVertices; ++index_1)
      {
        for (index_2 = 0; index_2 < graph->numVertices; ++index_2)
        {
          if (graph->adjMatrix[index_1][index_2])
          {
            (*numEdges)++;
          }
        }
      }
    }
    else
    {
      retVal = GRAPH_EMPTY;
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

uint32_t *getAdjacentVertices(graph_ds_t *graph, uint16_t vertex, uint32_t *numAdjacent, uint32_t **adjacentData, return_status_t *retVal)
{
  uint32_t *adjacentVertices = NULL;
  uint16_t index_1 = ZERO_INIT;

  if (NULL != graph)
  {
    if (NULL != numAdjacent)
    {
      adjacentVertices = (uint32_t *)calloc(graph->numVertices, sizeof(uint32_t));

      if (!adjacentVertices)
      {
        *retVal = GRAPH_ALLOC_FAIL;
      }
      else
      {
        *retVal = GRAPH_OK;

        *numAdjacent = ZERO_INIT;

        for (index_1 = 0; index_1 < graph->numVertices; index_1++)
        {
          if (graph->adjMatrix[vertex][index_1])
          {
            adjacentVertices[(*numAdjacent)++] = index_1;
          }
        }
      }
      *adjacentData = (uint32_t *)calloc(*numAdjacent, sizeof(uint32_t));

      if (!(*adjacentData))
      {
        *retVal = GRAPH_ALLOC_FAIL;
      }
      else
      {
        *retVal = GRAPH_OK;

        // Copy data associated with adjacent vertices
        for (index_1 = 0; index_1 < *numAdjacent; index_1++)
        {
          (*adjacentData)[index_1] = graph->vertices[adjacentVertices[index_1]].data;
        }
      }
    }
    else
    {
      *retVal = NULL_POINTER;
    }
  }
  else
  {
    *retVal = GRAPH_NULL_POINTER;
  }

  return adjacentVertices;
}

return_status_t printGraph(graph_ds_t *graph)
{
  return_status_t retVal = GRAPH_NOK;
  uint16_t index_1 = ZERO_INIT, index_2 = ZERO_INIT;

  if (NULL != graph)
  {
    retVal = GRAPH_OK;

    for (index_1 = 0; index_1 < graph->numVertices; ++index_1)
    {
      for (index_2 = 0; index_2 < graph->numVertices; ++index_2)
      {
#ifdef GRAPH_DEBUG
        printf("(%u, %u) ", graph->adjMatrix[index_1][index_2], graph->vertices[index_1].data);
#endif // GRAPH_DEBUG
      }
      printf("\n");
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t getDegree(graph_ds_t *graph, uint16_t vertex, uint32_t *degree)
{
  return_status_t retVal = GRAPH_NOK;
  uint16_t index_1 = ZERO_INIT;
  *degree = ZERO_INIT;

  if (NULL != graph)
  {
    if (vertex < graph->numVertices)
    {
      retVal = GRAPH_OK;

      for (index_1 = 0; index_1 < graph->numVertices; ++index_1)
      {
        if (graph->adjMatrix[vertex][index_1])
        {
          (*degree)++;
        }
      }
    }
    else
    {
      retVal = INVALID_POSITION;
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}