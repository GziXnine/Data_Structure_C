#include "graph_ds.h"

return_status_t initGraph(Graph *graph, uint32_t numVertices, uint32_t defaultData)
{
  return_status_t retVal = GRAPH_NOK;
  uint16_t index_1 = ZERO_INIT;

  if (graph != NULL)
  {
    if (numVertices > MAX_VERTICES)
    {
      retVal = GRAPH_FULL;
    }
    else
    {
      retVal = GRAPH_OK;

      graph->numVertices = numVertices;

      for (index_1 = 0; index_1 < numVertices; ++index_1)
      {
        graph->vertices[index_1].data = defaultData;
        graph->vertices[index_1].edges = NULL;
      }
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t clearGraph(Graph *graph)
{
  return_status_t retVal = GRAPH_NOK;
  EdgeNode *current = NULL, *temp = NULL;
  uint16_t index_1 = ZERO_INIT;

  if (graph != NULL)
  {
    retVal = GRAPH_OK;

    for (index_1 = 0; index_1 < graph->numVertices; ++index_1)
    {
      current = graph->vertices[index_1].edges;
      while (current)
      {
        temp = current;
        current = current->next;

        free(temp);
      }
      graph->vertices[index_1].edges = NULL;
      graph->vertices[index_1].data = ZERO;
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t getNumVertices(Graph *graph, uint32_t *numVer)
{
  return_status_t retVal = GRAPH_NOK;

  if (graph != NULL)
  {
    retVal = GRAPH_OK;

    *numVer = graph->numVertices;
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t getNumEdges(Graph *graph, uint32_t *numEdges)
{
  return_status_t retVal = GRAPH_NOK;
  EdgeNode *current = NULL;
  uint16_t index_1 = ZERO_INIT;
  *numEdges = ZERO;

  if (graph != NULL)
  {
    retVal = GRAPH_OK;

    for (index_1 = 0; index_1 < graph->numVertices; ++index_1)
    {
      current = graph->vertices[index_1].edges;

      while (current)
      {
        ++(*numEdges);
        current = current->next;
      }
    }

    (*numEdges) /= 2;
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t getAdjacentVertices(Graph *graph, uint32_t vertex, uint32_t *adjacentVertices, uint32_t *numAdjacent)
{
  return_status_t retVal = GRAPH_NOK;
  EdgeNode *current = NULL;
  uint32_t count = ZERO;

  if (graph != NULL)
  {
    if (adjacentVertices != NULL && numAdjacent != NULL)
    {
      if (vertex < graph->numVertices)
      {
        retVal = GRAPH_OK;

        current = graph->vertices[vertex].edges;

        while (current)
        {
          adjacentVertices[count++] = (uint32_t)current->dest;
          current = current->next;
        }

        *numAdjacent = count;
      }
      else
      {
        retVal = INVALID_POSITION;
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

return_status_t destroyGraph(Graph *graph)
{
  return_status_t retVal = GRAPH_NOK;

  if (graph != NULL)
  {
    retVal = GRAPH_OK;

    clearGraph(graph);
    graph->numVertices = ZERO;
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t getVertexData(Graph *graph, uint32_t vertex, uint32_t *data)
{
  return_status_t retVal = GRAPH_NOK;

  if (graph != NULL)
  {
    if (vertex < graph->numVertices)
    {
      retVal = GRAPH_OK;

      *data = graph->vertices[vertex].data;
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

return_status_t setVertexData(Graph *graph, sint32_t vertex, uint32_t data)
{
  return_status_t retVal = GRAPH_NOK;

  if (graph != NULL)
  {
    if (vertex < 0 || vertex >= (sint32_t)graph->numVertices)
    {
      retVal = INVALID_POSITION;
    }
    else
    {
      retVal = GRAPH_OK;

      graph->vertices[vertex].data = data;
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

return_status_t addEdge(Graph *graph, sint32_t source, sint32_t dest)
{
  return_status_t retVal = GRAPH_NOK;
  EdgeNode *newEdge = NULL;

  if (graph != NULL)
  {
    if (source < 0 || source >= (sint32_t)graph->numVertices || dest < 0 || dest >= (sint32_t)graph->numVertices)
    {
      retVal = INVALID_POSITION;
    }
    else
    {
      newEdge = (EdgeNode *)malloc(sizeof(EdgeNode));
      if (!newEdge)
      {
        retVal = GRAPH_ALLOC_FAIL;
      }
      else
      {
        newEdge->dest = dest;
        newEdge->next = graph->vertices[source].edges;
        graph->vertices[source].edges = newEdge;

        newEdge = (EdgeNode *)malloc(sizeof(EdgeNode));
        if (!newEdge)
        {
          retVal = GRAPH_ALLOC_FAIL;
        }
        else
        {
          retVal = GRAPH_OK;

          newEdge->dest = source;
          newEdge->next = graph->vertices[dest].edges;
          graph->vertices[dest].edges = newEdge;
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

return_status_t removeEdge(Graph *graph, sint32_t source, sint32_t dest)
{
  return_status_t retVal = GRAPH_NOK;
  EdgeNode *current = NULL, *prev = NULL;

  if (graph != NULL)
  {
    if (source < 0 || source >= (sint32_t)graph->numVertices || dest < 0 || dest >= (sint32_t)graph->numVertices)
    {
      retVal = INVALID_POSITION;
    }
    else
    {
      current = graph->vertices[source].edges;

      while (current)
      {
        if (current->dest == dest)
        {
          retVal = GRAPH_OK;

          if (prev)
          {
            prev->next = current->next;
          }
          else
          {
            graph->vertices[source].edges = current->next;
          }
          free(current);

          break;
        }
        prev = current;
        current = current->next;
      }

      current = graph->vertices[dest].edges;
      prev = NULL;

      while (current)
      {
        if (current->dest == source)
        {
          retVal = GRAPH_OK;

          if (prev)
          {
            prev->next = current->next;
          }
          else
          {
            graph->vertices[dest].edges = current->next;
          }

          free(current);
          break;
        }
        prev = current;
        current = current->next;
      }
    }
  }
  else
  {
    retVal = GRAPH_NULL_POINTER;
  }

  return retVal;
}

bool_t isAdjacent(Graph *graph, sint32_t source, sint32_t dest, return_status_t *retVal)
{
  EdgeNode *current = NULL;
  *retVal = GRAPH_NOK;

  if (!graph)
  {
    *retVal = GRAPH_NULL_POINTER;
  }
  else
  {
    if (source < 0 || source >= (sint32_t)graph->numVertices || dest < 0 || dest >= (sint32_t)graph->numVertices)
    {
      *retVal = INVALID_POSITION;
    }
    else
    {
      current = graph->vertices[source].edges;

      while (current)
      {
        if (current->dest == dest)
        {
          *retVal = GRAPH_OK;
        }
        current = current->next;
      }
    }
  }

  return 0;
}

return_status_t printGraph(Graph *graph)
{
  return_status_t retVal = GRAPH_NOK;
  EdgeNode *current = NULL;
  uint16_t index_1 = ZERO_INIT;

  if (graph == NULL)
  {
    retVal = GRAPH_NULL_POINTER;
  }
  else
  {
    retVal = GRAPH_OK;

    for (index_1 = 0; index_1 < graph->numVertices; ++index_1)
    {
      printf("Vertex %d (%d): ", index_1, graph->vertices[index_1].data);
      current = graph->vertices[index_1].edges;

      while (current)
      {
        printf("%d ", current->dest);
        current = current->next;
      }
      printf("\n");
    }
  }

  return retVal;
}