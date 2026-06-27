#include <stdio.h>
#include <stdlib.h>
#include "file_util.h"

char* read_entire_file(const char *filename) {
    // 1. Open the file in binary mode to accurately count bytes
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // 2. Seek to the end to determine file size
    if (fseek(file, 0, SEEK_END) != 0) {
        perror("Error seeking file");
        fclose(file);
        return NULL;
    }

    long file_size = ftell(file);
    if (file_size < 0) {
        perror("Error telling file size");
        fclose(file);
        return NULL;
    }

    // 3. Rewind back to the beginning to prepare for reading
    rewind(file);

    // 4. Allocate memory for content + null terminator
    char *buffer = (char*)malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    // 5. Read the content into the buffer
    size_t bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read < (size_t)file_size) {
        if (ferror(file)) {
            perror("Error reading file");
            free(buffer);
            fclose(file);
            return NULL;
        }
    }

    // 6. Null-terminate the string and clean up
    buffer[bytes_read] = '\0';
    fclose(file);

    return buffer;
}
