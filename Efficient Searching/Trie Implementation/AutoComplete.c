#include "AutoCompleteImpl.h"

#define NUMBER_OF_WORDS (354935)
#define INPUT_WORD_SIZE (100)

// scan the word/prefix
char *receiveInput(char *s) {
    scanf("%99s", s);
    return s;
}

int main() {
    int word_count = 0;
    // word array:  this will create char pointers that ponter to all words in the dictionary that given
    char* words[NUMBER_OF_WORDS];

    // FILE* fopen("file path,const char* mode)      reading the file
    FILE *fp = fopen("resources/dictionary.txt", "r");
    if (fp == 0){
        fprintf(stderr, "Error while opening dictionary file");
        exit(1);
    }
    // first word space 
    

    words[word_count] = malloc(INPUT_WORD_SIZE);
    // char * fgets(char* str,int n, FILE *stream)    returns : same str* on succsess.
    //( str:poiner to array,n:maximum number of caracters,stream: resorces reading)
    while (fgets(words[word_count], INPUT_WORD_SIZE, fp)) {
        word_count++;
        // alow spaces if the first word has a space already in the heap
        words[word_count] = malloc(INPUT_WORD_SIZE);
    }
 	// create the root node 
    TrieNode * root = createTrieNode();

    int i = 0;
    //  store ascii value 

    for(i = 0; i < NUMBER_OF_WORDS; i++){
    	int count=0;

    	while(words[i][count]!='\n'){
    		count++;
    	}
    	words[i][count-1]=0;
    	//printf("%d",count-1);
    	
        insert(root, words[i]);
    }


    while (1) {
        printf("Enter keyword: ");
        char str[100];
        receiveInput(str);
        printf("\n==========================================================\n");
        printf("\n********************* Possible Words ********************\n");

        int length = strlen(str);
        TrieNode * prefix_end_node;
        // get the node that equal to final character of the prefix
        prefix_end_node = search(root, str);
        // travers and get all posibilities according to the prefix
        traverse(str, prefix_end_node, length);

        printf("==========================================================\n");
    }

    //deleteTrie(root);

    return 0;

}
