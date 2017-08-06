#include "AutoCompleteImpl.h"

TrieNode *createTrieNode() {
    TrieNode * node = (TrieNode*) malloc(sizeof(TrieNode));
    node->children = (TrieNode**) malloc(sizeof(TrieNode*));
    node->numChildren = 0;
    node->label;
    node->isEndOfWord  = false;
	return node;
}

TrieNode *createTrieNodeWithLabel(char * label) {
    TrieNode * node = createTrieNode();
    node->label = strdup(label);
    node->isEndOfWord = true;
    return node;
}

void addChild(TrieNode * parent, TrieNode* child){
    int n = parent->numChildren;
    parent->children = (TrieNode**)realloc(parent->children, (n + 1)* sizeof(TrieNode*));
    parent->children[n] = child;
    parent->numChildren = n + 1;
}

char * substr(char * word, int s, int l){
    int w = strlen(word);
    char* nextWord = (char*) malloc(l + 1);
    memcpy(nextWord, &word[s], l);
    nextWord[l] = '\0';
    return nextWord;
}

int longestPrefix(char * a, char * b){
    int m = strlen(a), n = strlen(b);

    int k = m > n ? n : m;

    int p = 0, i;
    for(i = 0;i < k;i++){
        if(a[i] == b[i]) p++;
        else break;
    } 
    return p;
}

void insert(TrieNode *root, char *word) {

    if(root == NULL) return;
    TrieNode * current = root;
    int iter = 0;
    while(1){

        int i;
        bool found = false;
        for(i = 0; i < current->numChildren; i++){

            TrieNode * temp = current->children[i];
            int p = longestPrefix(temp->label, word);
            
            if(p > 0){
                if(p == strlen(temp->label)){
                    
                    if(p == strlen(word)){
                        temp->isEndOfWord =  true;
                        return;
                    }
                    
                    current = temp;
                    word = substr(word, p, strlen(word) - p);
                    found = true;
                    break;
                }
                else{

                    TrieNode * child = createTrieNode();

                    child->label = substr(temp->label, p, strlen(temp->label) - p);
                    child->children = malloc(sizeof(TrieNode*)*temp->numChildren);

                    memcpy(child->children, temp->children, sizeof(TrieNode*)*temp->numChildren);

                    child->numChildren = temp->numChildren;
                    child->isEndOfWord = temp->isEndOfWord;

                    temp->label = substr(temp->label, 0, p);

                    temp->numChildren = 0;
                    temp->children = (TrieNode**) malloc(sizeof(TrieNode*));
                    temp->isEndOfWord = false;

                    addChild(temp, child);

                    if(strlen(word) == p){
                        temp->isEndOfWord = true;
                        return;
                    }

                    addChild(temp, createTrieNodeWithLabel(substr(word, p, strlen(word) - p)));

                    return;
                }
            }
        }
        if(!found){
            TrieNode * temp = createTrieNodeWithLabel(word);
            
            addChild(current, temp);
            return;
        }    
    }
    
    
}

TrieNode *search(TrieNode *root, char *word, char * prefix) {
    if(root == NULL) return NULL;
    TrieNode * current = root;

    int i;

    while(strlen(word) > 0){
        bool found = false;
        for(i = 0; i < current->numChildren; i++){
            TrieNode * temp = current->children[i];
            int p = longestPrefix(temp->label, word);
            if(p > 0){
                if(p == strlen(word)){
                    return temp;
                }
                else{
                    current = temp;
                    strcat(prefix, substr(word, 0, p));
                    word = substr(word, p, strlen(word) - p);
                    found = true;
                    break;
                }
            }
        }
        if(!found) return NULL;
    }

    return current;
}

void traverse(char prefix[], TrieNode *root) {

    if(root == NULL) return;

    if(root->isEndOfWord){
        printf("%s\n", prefix);
    }

    int i, curr = strlen(prefix);
    for(i = 0; i < root->numChildren; i++){
        TrieNode * temp = root->children[i];
        prefix[curr] =  '\0';
        strcat(prefix, temp->label);
        traverse(prefix, temp);
    }
}
