#include "graph_ds.h"

return_status_t initGraph(grapg_ds_t *graph, uint32_t numVertices)
{
  return_status_t retVal = GRAPH_NOK;
  uint32_t index_1 = ZERO_INIT, index_2 = ZERO_INIT;

  if (NULL != graph)
  {
    retVal = GRAPH_OK;
    graph->numVertices = numVertices;

    for (index_1 = 0; index_1 < numVertices; ++index_1)
    {
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

return_status_t addEdge(grapg_ds_t *graph, uint16_t source, uint16_t dest)
{
  return_status_t retVal = GRAPH_NOK;

  if (NULL != graph)
  {
    retVal = GRAPH_OK;

    graph->adjMatrix[source][dest] = ONE;
    graph->adjMatrix[dest][source] = ONE;
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t removeEdge(grapg_ds_t *graph, uint16_t source, uint16_t dest)
{
  return_status_t retVal = GRAPH_NOK;

  if (NULL != graph)
  {
    retVal = GRAPH_OK;

    graph->adjMatrix[source][dest] = ZERO;
    graph->adjMatrix[dest][source] = ZERO;
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

bool_t isAdjacent(grapg_ds_t *graph, uint16_t source, uint16_t dest)
{
  bool_t retVal = ZERO;

  if (NULL != graph)
  {
    retVal = (graph->adjMatrix[source][dest]);
  }

  return retVal;
}

return_status_t getNumVertices(grapg_ds_t *graph, uint32_t *numVerts)
{
  return_status_t retVal = GRAPH_NOK;

  if (NULL != graph)
  {
    retVal = GRAPH_OK;

    *numVerts = graph->numVertices;
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t getNumEdges(grapg_ds_t *graph, uint32_t *numEdges)
{
  return_status_t retVal = GRAPH_NOK;
  uint32_t index_1 = ZERO_INIT, index_2 = ZERO_INIT;

  if (NULL != graph)
  {
    retVal = GRAPH_OK;

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
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t getAdjacentVertices(grapg_ds_t *graph, uint16_t vertex, uint16_t *numAdjacent)
{
  return_status_t retVal = GRAPH_NOK;
  uint32_t *adjacentVertices = NULL;
  uint32_t index_1 = ZERO_INIT;

  if (NULL != graph)
  {
    if (NULL != numAdjacent)
    {
      adjacentVertices = (uint32_t *)calloc(graph->numVertices, sizeof(uint32_t));

      if (!adjacentVertices)
      {
        retVal = GRAPH_ALLOC_FAIL;
      }
      else
      {
        retVal = GRAPH_OK;

        *numAdjacent = ZERO_INIT;

        for (index_1 = 0; index_1 < graph->numVertices; index_1++)
        {
          if (graph->adjMatrix[vertex][index_1])
          {
            adjacentVertices[(*numAdjacent)++] = index_1;
          }
        }
      }
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t printGraph(grapg_ds_t *graph)
{
  return_status_t retVal = GRAPH_NOK;
  uint32_t index_1 = ZERO_INIT, index_2 = ZERO_INIT;

  if (NULL != graph)
  {
    retVal = GRAPH_OK;

    for (index_1 = 0; index_1 < graph->numVertices; ++index_1)
    {
      for (index_2 = 0; index_2 < graph->numVertices; ++index_2)
      {
#ifdef GRAPH_DEBUG
        printf("%u ", graph->adjMatrix[index_1][index_2]);
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