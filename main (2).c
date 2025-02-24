#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 10000
#define MAX_WORDS 1000

// Function to compare two strings for sorting
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char input[MAX_INPUT];
    char *words[MAX_WORDS];
    int word_count = 0;
    
    // Read input
    if (!fgets(input, MAX_INPUT, stdin)) {
        return 0;
    }
    
    // Tokenize input into words
    char *token = strtok(input, " \t\n");
    while (token) {
        words[word_count++] = token;
        token = strtok(NULL, " \t\n");
    }
    
    if (word_count == 0) {
        return 0;
    }
    
    // Sort words in ASCII order
    qsort(words, word_count, sizeof(char *), compare);
    
    // Remove duplicates and print
    printf("%s", words[0]);
    for (int i = 1; i < word_count; i++) {
        if (strcmp(words[i], words[i - 1]) != 0) {
            printf(",%s", words[i]);
        }
    }
    printf("\n");
    
    return 0;
}
