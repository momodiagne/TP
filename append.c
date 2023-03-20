#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	int len;
	int* ptrarr;

}list;
void append(list *l, int n){
	int* newlist=malloc(sizeof(int)*1);
	if (l->len==0)
		*newlist=realloc(newlist,sizeof(int)*(l->len+1)); 
	if(l->len & (l->len-1) == 0)
		*newlist=realloc(newlist,sizeof(int)*(l->len*2)); 
	for(int i=0;i<l->len;i++)
		newlist[i]=l->ptrarr[i];
	if(l->ptrarr!=0)
		free(l->ptrarr);
	l->ptrarr=newlist;
	l->ptrarr[l->len]=n;
	l->len+=1;
}
int main()
{
	list l;
	l.len=0;
	l.ptrarr=0;
	for(int i=0;i<5;i++)
               append(&l,i);
	for(int i=0;i<5;i++)
		printf("%d",l.ptrarr[i]);
	return 0;
}
// J'ai voulu poser la condition que la longueur est un multiple de 2 par exemple 4 ou 8 ... d'allouer directement len*2 mais ça ne marche pas
