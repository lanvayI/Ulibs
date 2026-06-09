#ifndef CHARTOOLS_H
#define CHARTOOLS_H

int count_char(char* c);
int count_only_letters(char *c);
int count_vowels(char *c);
int count_consonants(char *c);
int is_palindrome(char *c);
int is_empty(char *c);
int has_only_digits(char *c);
void reverse_string(char *c);
void string_to_upper(char *c);
void string_to_lower(char *c);
int find_char(char *str,char c); // Find first char
//char* find_substring(char *c, char *str); // find where start
#endif 