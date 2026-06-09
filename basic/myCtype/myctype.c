#include "myctype.h"

int is_digit(char c){
	if(c >= '0' && c<= '9'){return 1;}
	return 0;
}

int is_alpha(char c){
	if((c>='a' && c<='z') || (c>='A' && c<='Z')){return 1;}
	return 0;
}

void to_lower(char *c){
	*c-=32;
}

void to_upper(char *c){
	*c+=32;
}