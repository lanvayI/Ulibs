#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readfile(FILE* file);
void writefile(FILE* file);

int main(){
	//open file
	char filepath[128];
	int option = 0;
	
	printf("\nwant to edit? if yes press 1, no -> 0 ");
	scanf("%d",&option);
	
	printf("\n enter file path: ");
	scanf("%s",&filepath);
	printf(filepath);
	
	
	
	//read and printf
	FILE* file;
	if(option){file = fopen(filepath,"a");}else{file = fopen(filepath,"r");}
	
	
	if(file == NULL){
		puts("deu pra abrir n");
		return 1;
	}
	////////////////
	printf("\n");
	readfile(file);
	while(option){
		writefile(file);
		printf("\n wants to edit again? 1 - yes, 0 - no ");
		scanf("%d",&option);
	}
	fclose(file);
	
	file = fopen(filepath,"r");
	printf("result: \n");
	readfile(file);
	
	fclose(file);
	return 0;
}

void readfile(FILE* file){
	char bit;
	while(true){
		int k = fscanf(file,"%c",&bit);
		if(k==EOF){break;}
		putchar(bit);
	}
}

void writefile(FILE* file){
	char buffer[128];
	char *str;
	
	printf("\n begin editing: ");
	scanf("%s",buffer);
	
	int size = strlen(buffer);
	str = (char*)malloc(size*sizeof(char));
	if(str == NULL){return;}
	strcpy(str,buffer);
	
	fprintf(file,str);
	free(str);
}
