#include "charTools.h"
#include <stdio.h>
int count_char(char* c){
	int result=0;
	while(*c != '\0'){
		if(*c == '\n'){break;}
		result++;
		*c++;
	}
	return result;
}

int count_only_letters(char*c){
	int result=0;
	while(*c != '\0'){
		if(*c == '\n'){break;}
		if(*c != ' '){result++;}
		*c++;
	}
	return result;
}

int count_vowels(char* c){
	int result=0;
	while(*c != '\0'){
		if(*c == '\n'){break;}
		switch(*c){
			case 'a':
				result++;
				break;
			case 'e':
				result++;
				break;
			case 'i':
				result++;
				break;
			case 'o':
				result++;
				break;
			case 'u':
				result++;
				break;
			case 'A':
				result++;
				break;
			case 'E':
				result++;
				break;
			case 'I':
				result++;
				break;
			case 'O':
				result++;
				break;
			case 'U':
				result++;
				break;
			default:
				break;
		}
		*c++;
	}
	return result;
}

int count_consonants(char* c){
	int result=0;
	while(*c != '\0'){
		if(*c == '\n'){break;}
		switch(*c){
			case 'a':
				break;
			case 'e':
				break;
			case 'i':
				break;
			case 'o':
				break;
			case 'u':
				break;
			case 'A':
				break;
			case 'E':
				break;
			case 'I':
				break;
			case 'O':
				break;
			case 'U':
				break;
			default:
				if(*c != ' '){result++;}
				break;
		}
		*c++;
	}
	return result;
}

int is_palindrome(char* c){
	int start = 0;
	int end = 0;
	while(c[end] !='\0'){end++;}
	end--;
	while(start < end){
		if(c[start] != c[end]){return 0;}
		start++;
		end--;
	}
	return 1;
}

int is_empty(char* c){
	int i = 0;
	if(c[i] == '\0'){return 1;}
	return 0;
}

int has_only_digits(char* c){
	while(*c != '\0'){
		if( (int)*c < 48 || (int)*c > 57){return 0;}
		*c++;
	}
	return 1;
}

void reverse_string(char* c){
	int length = count_char(c);

	for(int i=0; i < length / 2; i++){
		char temp = c[i];
		c[i] = c[length - 1 - i];
        c[length - 1 - i] = temp;
	}
}

void string_to_upper(char* c){
	while(*c != '\0'){
		if(*c > 96 && *c < 123){*c -= 32;}
		*c++;
	}
}

void string_to_lower(char* c){
	while(*c != '\0'){
		if(*c >= 65 && *c <= 90){*c += 32;}
		*c++;
	}
}

int find_char(char* str, char c){
	int i=0;
	while(*str != '\0'){
		if(*str == c){return i;}
		*str++;
		i++;
	}
	return -1;
}