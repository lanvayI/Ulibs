#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "../charTools/charTools.h"
#include "../charTools/charTools.c"
#include "../type_converter/my_converter.h"
#include "../type_converter/my_converter.c"

void my_printf(char* format,...);

void intToString(int n, char* str);
int decimalSize(int n);

int main(){
	my_printf("aaaa%saaaa","adasd");
	return 0;
} 

void my_printf(char* format,...){
	char buffer[16];
	va_list args;
	int startCheck = 0;
	
	va_start(args,format);
	for(int i=0; i < strlen(format); i++){
		if(startCheck == 2){
			switch(format[i]){
				case 'd':
					int temp = va_arg(args,int);
					intToString(temp,buffer);
					fputs(buffer,stdout);
					break;
				case 'c':
					fputchar(va_arg(args,int));
					break;
				case 's':
					fputs(va_arg(args,char*),stdout);
					break;
			}
		}
		if(startCheck > 0){startCheck--;}
		if(format[i] == '%'){startCheck = 2;}
		if(!startCheck){putchar(format[i]);}
		
	va_end(args);
	}
}

void intToString(int N, char* str){
	int i=0;
	int temp = N;
	if(N<0){N = -N;}
	
	while(N>0){
		str[i] = N % 10 + '0';
		N/=10; i++;
	}
	if(temp < 0){
		i++; str[i] = '-';
	}
	reverse_string(str);
}

int decimalSize(int n){
	int i=1;
	if(n<0){n = -n;}
	while(n>1){
		i++;
		n/=10;
	}
	return i;
}