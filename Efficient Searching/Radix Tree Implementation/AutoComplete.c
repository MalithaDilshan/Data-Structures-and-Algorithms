#include "AutoCompleteImpl.h"

#define NUMBER_OF_WORDS (354935)
#define INPUT_WORD_SIZE (100)

char *receiveInput(char *s) {
    scanf("%99s", s);
    return s;
}

int main() {
    int word_count = 0;

    FILE *fp = fopen("resources/dictionary.txt", "r");
    if (fp == 0){
        fprintf(stderr, "Error while opening dictionary file");
        exit(1);
    }

    char * word = malloc(INPUT_WORD_SIZE);

    TrieNode * root = createTrieNode();

    while (fgets(word, INPUT_WORD_SIZE, fp)) {
        word[strcspn(word, "\r\n")] = 0;
        if(strlen(word) == 0) continue;
        insert(root, word);
        word_count++;
        if(word_count > NUMBER_OF_WORDS) break;
    }

    while (1) {
        printf("Enter keyword: ");
        char str[100];
        receiveInput(str);
        printf("\n==========================================================\n");
        printf("\n********************* Possible Words ********************\n");

        char bar[100]; bar[0] = '\0';
        TrieNode * startOfEnd = search(root, str, bar);
        if(startOfEnd == NULL) continue;
        strcat(bar, startOfEnd->label);
        traverse(bar, startOfEnd);

        printf("==========================================================\n");
    }

}