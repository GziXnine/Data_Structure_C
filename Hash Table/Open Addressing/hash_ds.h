#ifndef _HASH_DS_H_
#define _HASH_DS_H_

#include "std_types.h"

#define TABLE_SIZE 10

typedef struct Entry
{
  char *key;
  uint32_t value;
  struct Entry *next; /**< Next pointer for separate chaining */

} Entry; /**< Structure representing an entry in the hash table */

typedef struct
{
  Entry *entries[TABLE_SIZE]; /**< Array of pointers to hash table entries */

} HashTable; /**< Structure representing a hash table */

typedef enum
{
  HASH_OK,           /**< Hash operation performed successfully */
  HASH_NOK,          /**< Hash operation not performed successfully */
  HASH_FULL,         /**< Hash is full */
  HASH_HAS_SPACE,    /**< Hash not full */
  HASH_EMPTY,        /**< Hash is empty */
  HASH_NULL_POINTER, /**< NULL pointer passed to the hash operations */
  NULL_POINTER,      /**< Additional NULL pointer status */
  HASH_ALLOC_FAIL    /**< Memory allocation for hash array failed */

} return_status_t; /**< Return status enumeration for hash operations */

/**
 * @brief  Compute the hash value for a given key.
 *
 * @param  key : Pointer to the key string.
 *
 * @return The computed hash value.
 */
uint32_t hash_function(char *key);

/**
 * @brief  Create a hash table.
 *
 * @return Pointer to the created hash table.
 */
HashTable *create_hash_table();

/**
 * @brief  Insert a key-value pair into the hash table.
 *
 * @param  ht : Pointer to the hash table.
 * @param  key : Pointer to the key string.
 * @param  value : Value associated with the key.
 *
 * @return Status indicating success or failure of the operation.
 */
return_status_t insert(HashTable *ht, char *key, uint32_t value);

/**
 * @brief  Search for a key in the hash table and retrieve its value.
 *
 * @param  ht : Pointer to the hash table.
 * @param  key : Pointer to the key string.
 *
 * @return The value associated with the key, or 0 if not found.
 */
uint32_t search(HashTable *ht, char *key);

/**
 * @brief  Delete a key-value pair from the hash table.
 *
 * @param  ht : Pointer to the hash table.
 * @param  key : Pointer to the key string.
 *
 * @return Status indicating success or failure of the operation.
 */
return_status_t Delete(HashTable *ht, char *key);

/**
 * @brief  Display the contents of the hash table.
 *
 * @param  ht : Pointer to the hash table.
 * @return Status indicating success or failure of the operation.
 */
return_status_t display(HashTable *ht);

/**
 * @brief  Check if the hash table is full.
 *
 * @param  ht : Pointer to the hash table.
 *
 * @return 1 if the hash table is full, 0 otherwise.
 */
uint32_t is_full(HashTable *ht);

/**
 * @brief  Check if the hash table is empty.
 *
 * @param  ht : Pointer to the hash table.
 *
 * @return 1 if the hash table is empty, 0 otherwise.
 */
uint32_t is_empty(HashTable *ht);

/**
 * @brief  Get the size of the hash table.
 *
 * @param  ht : Pointer to the hash table.
 *
 * @return The size of the hash table.
 */
uint32_t get_table_size(HashTable *ht);

/**
 * @brief  Resize the hash table to accommodate more entries.
 *
 * @param  ht : Pointer to the hash table.
 *
 * @return Status indicating success or failure of the operation.
 */
return_status_t resize(HashTable *ht);

/**
 * @brief  Clear all entries from the hash table.
 *
 * @param  ht : Pointer to the hash table.
 *
 * @return Status indicating success or failure of the operation.
 */
return_status_t clear(HashTable *ht);

#endif // !_HASH_DS_H_
