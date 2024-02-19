#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 50000

unsigned long hash_function(char *string){
    unsigned long i =0;
    for(int j=0; string[j];j++)
        i+=string[j];

    return i % CAPACITY;
}

typedef struct HashTableItem{
    char * key;
    char * value;

} HashTableItem;

typedef struct HashTable{
    HashTableItem ** items;
    int count;
    int size;

} HashTable;

HashTableItem * create_item(char* key, char* value){
    HashTableItem* item = (HashTableItem*)malloc(sizeof(HashTableItem));
    item->key=(char*)malloc(strlen(key)+1);
    item->value= (char*)malloc(strlen(value)+1);
    strcpy(item->key, key);
    strcpy(item->value,value);
    return item;
}


HashTable* create_table(int size){
    HashTable* hashtable = (HashTable*)malloc(sizeof(HashTable));
    hashtable->size= size;
    hashtable->count = 0;
    hashtable->items = (HashTableItem**)malloc(sizeof(HashTableItem*));
    for(int i; i<hashtable->size; i++){
        hashtable->items[i]=NULL;
    }
    return hashtable;
}

void free_item(HashTableItem* item){
    free(item->key);
    free(item->value);
    free(item);
}

void free_item(HashTable* table){
    for(int i; i< table->size; i++){
        HashTableItem* item= table->items[i];
        if(item != NULL){
            free(item);
        }
    }
    free(table->items);
    free(table);
}

void print_table(HashTable * table){
    printf("\nHashTable\n------------------\n");
    for(int i; i<table->size; i++){
        if(table->items[i]){
            printf("Index: %d, Key: %s, Value: %d \n", i, table->items[i], table->items[i]->value);
        }
    }
    printf("------------------\n");
}

void handle_collision (HashTable *table, HashTableItem * item){


}

void insert(HashTable*  table, char* key, char* value){
   HashTableItem * item = create_item(key, value) ;
   int index = hash_function(key);
   HashTableItem* current_item = table->items[index];
   if(current_item == NULL){
    if(table->count == table->size){
        printf("Hashtable is full. Insert error/n");
        free_item(item);
        return ;
    }
    table->items[index]= item;
    table->count ++ ;
   }
   else{
    if(strcmp(current_item->key , key) == 0){
        strcpy(table->items[index]->value , value);
        return; 
    }
    else{
        handle_collision(table, item);
        return;
    }
   }
}

char * search (HashTable * table, char * key){
    int index = hash_function(key);
    HashTableItem * item = table->items[index];
    if(item != NULL){
        if(strcmp(item->key , key)== 0){
            return item->value;
        }
    }
    return NULL;
}

void print_search(HashTable * table, char * key){
    char * value;
    if((value = search(table, key))== NULL){
        printf("Key: %s does not exist", key);
        return;
    }
    else{
        printf("Key: %s value: %s", key, value);
    }
}

