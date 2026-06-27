#include <stdio.h>
#include <stdlib.h>
#include "file_util.h" // Include your custom utility header

int main() {
    const char *path = "New Document.txt";
    
    // Call the external utility function
    char *content = read_entire_file(path);
    
    if (content != NULL) {
        printf("--- File Contents ---\n%s\n---------------------\n", content);
        
        // Always free dynamically allocated memory passed to you
        free(content); 
    } else {
        printf("Failed to load file: %s\n", path);
    }

    return 0;
}
