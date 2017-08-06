#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE (26)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define INPUT_WORD_SIZE (100)

typedef struct TrieNode{
    struct TrieNode ** children;
    int numChildren;
    char* label;
    bool isEndOfWord;
} TrieNode;

typedef struct TrieNode TrieNode;

TrieNode *createTrieNode();
TrieNode *createTrieNodeWithLabel(char * label);
TrieNode *search(TrieNode *root, char *word, char * prefix);
void traverse(char prefix[], TrieNode *root);
void insert(TrieNode *root, char *word);