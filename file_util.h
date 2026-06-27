#ifndef FILE_UTIL_H
#define FILE_UTIL_H

/**
 * Reads the entire contents of a file into a dynamically allocated string.
 * @param filename The path to the file.
 * @return A pointer to the file contents (null-terminated), or NULL on failure.
 *         NOTE: The caller is responsible for freeing this memory.
 */
char* read_entire_file(const char *filename);

#endif // FILE_UTIL_H
