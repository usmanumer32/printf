#ifndef MAIN_H
#define MAIN_H

#define BUFSIZE 1025
#include <stdarg.h>

/**
* struct validTypes - structure to lookup functions for valid types
* @valid: flags are preceded by a '%' character.
* @f: pointer to function
*/
typedef struct validTypes
{
char *valid;
char *(*f)();
} v_types;

int _printf(const char *format, ...);
char *(*get_valid_type(char s))(va_list);
char *found_nothing(char c);
int _strlen(char *s);
int alloc_buffer(char *hold, int hlen, char *buffer, int blen, double *total);
char *_memcpy(char *dest, char *src, unsigned int n, unsigned int bufferlen);
void _puts(char *buffer, int size);
char *ctos(char c);

#endif
