#include "AutoCompleteImpl.h"



// create the node with null childrens initialy
TrieNode *createTrieNode() {

    TrieNode * new_node = (TrieNode*) malloc(sizeof(TrieNode));

    int j;
    // in the root node all the childens should be null and return that node
    // then using this node we can implement the others 
	for(j = 0; j < ALPHABET_SIZE; j++){
		new_node->children[j] = NULL;
	}
	return new_node;
}


// insert all the words by creating the new childen nodes that conncted to the root
void insert(TrieNode *root, const char *word) {

    if(root == NULL){

    #ifdef DEBUG
	printf("1:The trie is null");   // debugin perposes only
    #endif

	return;
	}
    

    TrieNode * current_node = root;  // create temp node that represent the root
    
    for(int i = 0; i < strlen(word); i++){

        // create the node with a value that should be unique node that connected to the root
        TrieNode * temp = current_node->children[word[i]- 'a'];  
        // if current node in not null use that to traverse and if the node address null create another node to 
        // store that 
        if(temp != NULL){
            current_node = temp;
            #ifdef DEBUG
            printf("%p",temp);   // debugin perposes only
            #endif

        }
        else{
            temp = createTrieNode();

            if(i == strlen(word) - 1)
                temp->isEndOfWord = true;

            temp->label = word[i];

            // assign the created node to the new child
            current_node->children[word[i] - 'a'] = temp;
     
        }
    }
    
}


// serch up to the prifix node and return that node to get all the posibilities using the 'traverse' function
TrieNode *search(TrieNode *root, const char *word) {

    if(root == NULL){

     #ifdef DEBUG
     printf("2:The trie is null");   // debugin perposes only
     #endif

     return NULL;
    }

    TrieNode * current_node = root;

    int i;
    for(i = 0; i < strlen(word); i++){

        TrieNode * temp = current_node->children[word[i]- 'a'];// get the address if exit 
        if(temp != NULL){
            current_node = temp;
        }
                 
        else
            current_node = NULL;
        
    }

    return current_node;  // return the node according to the final chatacter of the prefix
}


// traversing from end of the prefix node
void traverse(char prefix[], TrieNode *root, int pos) {

    TrieNode * end_prefix_node=root;

    if(root == NULL) {
        #ifdef DEBUG
        printf("2:The trie is null");   // debugin perposes only
        #endif
        return;
    }

    // if the isEndOfWord set at the end of the word we can print whole word only
    if(end_prefix_node->isEndOfWord){
        int i;
        for(i = 0; i < pos; i++){
         printf("%c", prefix[i]);
        }
        printf("\n");
    }

    // othervise we have to traverse all the posibilities if nodes not null
    for(int i = 0; i < ALPHABET_SIZE; i++){

        TrieNode * temp = end_prefix_node->children[i];  // next node

        if(temp != NULL){
            // put the new node character to the prefix and we can get the all the posibilities using the 
            // recursuve approch and after isEndOfWord true above fuction will print the that posibility
            prefix[pos] = temp->label;

            int new_pos = pos++;
            traverse(prefix, temp, new_pos);
        }
    }
}




