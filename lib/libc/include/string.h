#ifndef _XOS_LIBC_STRING_H_
#define _XOS_LIBC_STRING_H_ 1

// #include <stdlib.h>
#include <stddef.h>

int memcmp(const void* lhs, const void* rhs, size_t count);
void* memset(void *dest, int cc, size_t count);
void* memcpy(void *dest, const void *src, size_t count);
void* memmove(void *dest, const void *src, size_t count);

size_t strlen(const char* str);
int strcmp(const char* str1, const char* str2);
int strncmp(const char* str1, const char* str2, int len);
char* strcat(char *dest, const char *src);
char* strchr(char *str, int ch);
char* strcpy(char *dest, const char *src);
// int strsplit(const char *str, char **buffer, char delim = ' ');
long strtol(const char *ptr, char **endptr, int base);

int atoi(const char* str);
double atof(const char* str);
long atol(const char* str);

char* itoa(int value, char *buffer, int base);
char* utoa(unsigned int value, char *buffer, int base);
char* lltoa(long long value, char *buffer, int base);
char* ulltoa(unsigned long long value, char *buffer, int base);
// char* ulltoa(unsigned long long value, char *buffer, int base);

#endif /* _XOS_LIBC_STRING_H_ */