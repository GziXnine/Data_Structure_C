#include "hash_ds.h"

uint32_t hash_function(char *key)
{
  uint32_t hash = ZERO_INIT, index = ZERO_INIT;

  for (index = 0; key[index] != '\0'; index++)
  {
    hash = ((uint32_t)hash * 31 + (uint32_t)key[index]) % TABLE_SIZE;
  }

  return hash;
}

HashTable *create_hash_table()
{
  HashTable *tempNode = (HashTable *)malloc(sizeof(HashTable));
  uint32_t index = ZERO_INIT;

  if (tempNode != NULL)
  {
    for (index = 0; index < TABLE_SIZE; index++)
    {
      tempNode->entries[index] = NULL;
    }
  }

  return tempNode;
}

return_status_t insert(HashTable *ht, char *key, uint32_t value)
{
  return_status_t retVal = HASH_NOK;
  uint32_t index = ZERO_INIT;
  Entry *new_entry = NULL;

  if (ht != NULL)
  {
    if (key != NULL)
    {
      index = hash_function(key);
      new_entry = (Entry *)malloc(sizeof(Entry));

      if (new_entry != NULL)
      {
        retVal = HASH_OK;

        new_entry->key = strdup(key);
        new_entry->value = value;

        if (ht->entries[index] == NULL)
        {
          ht->entries[index] = new_entry;
          return HASH_OK;
        }

        new_entry->next = ht->entries[index];
        ht->entries[index] = new_entry;
      }
      else
      {
        retVal = HASH_NOK;
      }
    }
    else
    {
      retVal = NULL_POINTER;
    }
  }
  else
  {
    retVal = HASH_NULL_POINTER;
  }

  return retVal;
}

uint32_t search(HashTable *ht, char *key)
{
  uint32_t index = ZERO_INIT;
  Entry *entry = NULL;

  if (ht != NULL)
  {
    if (key != NULL)
    {
      index = hash_function(key);
      entry = ht->entries[index];

      while (entry != NULL)
      {
        if (strcmp(entry->key, key) == ZERO)
        {
          return entry->value;
        }
        entry = entry->next;
      }
      return HASH_NOK;
    }
    else
    {
      return NULL_POINTER;
    }
  }
  else
  {
    return HASH_NULL_POINTER;
  }
}

return_status_t Delete(HashTable *ht, char *key)
{
  return_status_t retVal = HASH_NOK;
  uint32_t index = ZERO_INIT;
  Entry *current = NULL, *prev = NULL;
  ;

  if (ht != NULL)
  {
    if (key != NULL)
    {
      retVal = HASH_OK;

      index = hash_function(key);
      current = ht->entries[index];

      while (current != NULL)
      {
        if (strcmp(current->key, key) == ZERO)
        {
          if (prev == NULL)
          {
            ht->entries[index] = current->next;
          }
          else
          {
            prev->next = current->next;
          }
          free(current->key);
          free(current);
        }
        else
        {
          prev = current;
          current = current->next;
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
    retVal = HASH_NULL_POINTER;
  }

  return retVal;
}

return_status_t display(HashTable *ht)
{
  return_status_t retVal = HASH_NOK;
  Entry *entry = NULL;

  if (ht != NULL)
  {
    retVal = HASH_OK;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
      printf("Bucket %d: ", i);
      entry = ht->entries[i];

      while (entry != NULL)
      {
        printf("(%s, %d) ", entry->key, entry->value);
        entry = entry->next;
      }

      printf("\n");
    }
  }
  else
  {
    retVal = HASH_NULL_POINTER;
  }

  return retVal;
}

uint32_t is_full(HashTable *ht)
{
  uint32_t index = ZERO_INIT;

  for (index = 0; index < TABLE_SIZE; index++)
  {
    if (ht->entries[index] == NULL)
    {
      return ZERO;
    }
  }

  return ONE;
}

uint32_t is_empty(HashTable *ht)
{
  uint32_t index = ZERO_INIT;

  for (index = 0; index < TABLE_SIZE; index++)
  {
    if (ht->entries[index] != NULL)
    {
      return ZERO;
    }
  }

  return ONE;
}

uint32_t get_table_size(HashTable *ht)
{
  (void)ht; // Suppress unused parameter warning
  return TABLE_SIZE;
}

return_status_t resize(HashTable *ht)
{
  return_status_t retVal = HASH_NOK;
  uint32_t index = ZERO_INIT;
  HashTable *new_ht = NULL;
  Entry *entry = NULL, *temp = NULL;

  if (ht != NULL)
  {
    new_ht = create_hash_table();

    if (new_ht != NULL)
    {
      retVal = HASH_OK;

      for (index = 0; index < TABLE_SIZE; index++)
      {
        entry = ht->entries[index];
        while (entry != NULL)
        {
          insert(new_ht, entry->key, entry->value);
          temp = entry;
          entry = entry->next;
          free(temp->key);
          free(temp);
        }
      }

      clear(ht);
      memcpy(ht, new_ht, sizeof(HashTable));
      free(new_ht);
    }
    else
    {
      retVal = HASH_ALLOC_FAIL;
    }
  }
  else
  {
    retVal = HASH_NULL_POINTER;
  }

  return retVal;
}

return_status_t clear(HashTable *ht)
{
  return_status_t retVal = HASH_NOK;
  uint32_t index = ZERO_INIT;
  Entry *entry = NULL, *temp = NULL;

  if (ht != NULL)
  {
    retVal = HASH_OK;

    for (index = 0; index < TABLE_SIZE; index++)
    {

      entry = ht->entries[index];
      while (entry != NULL)
      {
        temp = entry;
        entry = entry->next;
        free(temp->key);
        free(temp);
      }

      ht->entries[index] = NULL;
    }
  }
  else
  {
    retVal = HASH_NULL_POINTER;
  }

  return retVal;
}