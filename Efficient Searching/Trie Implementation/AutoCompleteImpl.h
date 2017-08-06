#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE (26)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    char label;
    bool isEndOfWord;
} TrieNode;

typedef struct TrieNode TrieNode;

TrieNode *createTrieNode();
TrieNode *search(TrieNode *root, const char *word);
void traverse(char prefix[], TrieNode *root, int pos);
void insert(TrieNode *root, const char *word);
void deleteTrie(TrieNode * root);