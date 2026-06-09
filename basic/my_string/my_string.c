#include "my_string.h"

int my_strlen(char *c){
	int i=0;
	while(*c != '\0'){i++;c++;}
	return i;
}

void my_strcpy(char* origin, char* destiny){
	while(*origin != '\0'){
		*destiny = *origin;
		destiny++;
		origin++;
	}
	*destiny = '\0';
}

int my_strcmp(char* one, char* two){
	if(my_strlen(one) < my_strlen(two)){return -1;}
	if(my_strlen(one) > my_strlen(two)){return 1;}
	while(*one != '\0'){
		if(*one > *two){return 1;}
		if(*one < *two){return -1;}
		one++;
		two++;
	}
	return -1;
}

char* my_strcat(char* string1,char string2){
	while(*string1 != '\0'){string1++;}
	while(string2 != '\0'){
		*string1++ = string2++;
	}
	*string1 = '\0';
	
	return string1;
}