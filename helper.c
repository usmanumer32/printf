#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
/**
* get_valid_type - ID the type specifier passed by printf with a valid_type
* @s: Type to check given as char
* Return: pointer function of char type, valid_type matched
*/
char *(*get_valid_type(char s))(va_list)
{
int i;
v_types valid_types[] = {
{"c", found_char},
{"s", found_string},
{"%", found_percent},
{"d", found_int},
{"i", found_int},
{"u", found_unsigned},
{"o", found_octal},
{"r", found_reverse},
{"R", found_rot13},
{NULL, NULL}
};

for (i = 0; valid_types[i].valid; i++)
{
if (s == *valid_types[i].valid)
{
return (valid_types[i].f);
}
}
return (NULL);
}
/**
* found_nothing - no matches found but % passed
* @c: character unmatched to return and store
* Return: string with percent and character.
*/
char *found_nothing(char c)
{
char string[3];
char *p;

p = string;
string[0] = '%';
string[1] = c;
string[2] = '\0';
return (p);
}
/**
* _strlen - gets length of the string
* @s: input string
* Return: length of string
*/
int _strlen(char *s)
{
int i;

for (i = 0; *(s + i); i++)
;
return (i);
}
/**
* alloc_buffer - allocates characters to buffer, handling overflows
* @hold: string to allocate into buffer
* @hlen: hold length
* @buffer: buffer char array
* @blen: pointer to end of buffer
* @total: pointer to total character counter
* Return: buffer length
*/
int alloc_buffer(char *hold, int hlen, char *buffer, int blen, double *total)
{
int sizecpy = 0;

if (hlen + blen > BUFSIZE)
{
sizecpy = BUFSIZE - blen;
_memcpy(buffer, hold, sizecpy, blen);
_puts(buffer, BUFSIZE);
hold += sizecpy;
_memcpy(buffer, hold, hlen - sizecpy, 0);
blen = hlen - sizecpy;
*total += BUFSIZE;
}
else
{
_memcpy(buffer, hold, hlen, blen);
blen += hlen;
}
return (blen);
}
/**
* _memcpy - copies memory area
* @dest: pointer to destination memory area
* @src: pointer to source memory area
* @n: number of bytes to copy
* @bufferlen: current number of bytes taken by buffer
* Return: pointer to destination memory area
*/
char *_memcpy(char *dest, char *src, unsigned int n, unsigned int bufferlen)
{
unsigned int i;

for (i = 0; i < n; i++)
dest[i + bufferlen] = src[i];
return (dest);
}
/**
* _puts - print a buffer.
* @buffer: buffer passed
* @size: number of bytes to print
*/
void _puts(char *buffer, int size)
{
write(1, buffer, size);
}
/**
  * ctos - converts a character to a string
  * @c: character to convert
  * Return: pointer to string
  */
char *ctos(char c)
{
char string[1];
char *p;

p = string;
string[0] = c;
return (p);
}
