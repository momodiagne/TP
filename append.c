#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    	int len;
    	int* ptrarr;
} list;

void append(list* l, int n) {
    	int* newlist;
    	if (l->len == 0) {
        	newlist = malloc(sizeof(int));
    	} else if ((l->len & (l->len - 1)) == 0) {
        	newlist = realloc(l->ptrarr, sizeof(int) * (l->len * 2));
    	} else {
        	newlist = l->ptrarr;
    	}
    	if (newlist == NULL) {
        	exit(1);
    	}
    	newlist[l->len] = n;
    	l->len += 1;
    	l->ptrarr = newlist;
}

int main() {
    	list l;
    	l.len = 0;
    	l.ptrarr = NULL;
    	for (int i = 0; i < 1000000; i++) {
        	append(&l, i);
    	}
    	for (int i = 0; i < l.len; i++) {
        	printf("%d ", l.ptrarr[i]);
    	}
    	free(l.ptrarr);
    	return 0;
}

