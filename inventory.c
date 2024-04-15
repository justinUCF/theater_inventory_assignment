#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 19 
#define TABLESIZE 300007 

typedef struct item { 
    char name[MAXLEN+1]; 
    int quantity;
    int saleprice;
} item;

typedef struct node { 
    item* iPtr;
    struct node* next;
} node;

typedef struct hashtable { 
    node** lists;
    int size;
} hashtable;

int hashfunc(char* word, int size); 
void initHashTable(hashtable* hash);
void fillHashTable(hashtable* hashTable);
void validateArguments(int argc);

int main(int agrc, char* argv[]){
    validateArguments(argc); //Ensures argument amount is valid.
    hashtable hash; //Declare hash variable;
    initHashTable(&hash); //Initializes hash variable.

    return 0;
}

int hashfunc(char* word, int size) { 
    int len = strlen(word);
    int res = 0;
    for (int i=0; i<len; i++)
        res = (1151*res + (word[i]-'a'))%size; 
    return res;
}

void validateArguments(int argc){
    if(argc != 3){
        fprintf(stderr, "Error: invalid amount of arguments:\ninventory.exe/.o input.in output.out.");
        exit(-1);
    }
    else{
        return;
    }
}

void initHashTable(hashtable* hash){
    hash->lists = (node**)malloc(sizeof(node*)*TABLESIZE);
    if(hash->lists == NULL){
        fprintf(stderr, "Error: initHashTable() failed");
        exit(-1);
    }
    for(int i = 0; i < TABLESIZE; ++i){//Fill array with NULL pointers
        hash->lists[i] = NULL;
    }
    hash->size = 0;
}

