#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* append(char *a,char *b){
	char* result=(char*)malloc((strlen(a)+strlen(b))*sizeof(char));
	strcpy(result,a);
	strcat(result,b);
	return result;
}
int main(){
	return 0;
}
