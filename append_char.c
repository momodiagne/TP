#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
        int len;
        char* ptrarr;
} list;

void append(list *l, char n) {
        char* newlist = malloc(sizeof(char) * (l->len + 1));
        if (l->len == 0) {
                newlist = realloc(newlist, sizeof(char));
        }
        else if ((l->len & (l->len - 1)) == 0) {
                newlist = realloc(newlist, sizeof(char) * (l->len * 2));
        }
        for(int i = 0; i < l->len; i++) {
                newlist[i] = l->ptrarr[i];
        }
        free(l->ptrarr);
        l->ptrarr = newlist;
        l->ptrarr[l->len] = n;
        l->len += 1;
}

int main() {
        list l;
        l.len = 0;
        l.ptrarr = NULL;
        char a[7] = "reussi";
        for(int i = 0; i < strlen(a); i++) {
                append(&l, a[i]);
        }

        for(int i = 0; i < strlen(a); i++) {
                printf("%c", l.ptrarr[i]);
        }
        free(l.ptrarr);
        return 0;
}

