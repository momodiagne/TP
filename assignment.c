#include <stdio.h>
#include <stdlib.h>

// Linked list
typedef struct s_node {
	int value;
    	struct s_node* next;
	struct s_node* previous;
} node;

void append(node* head, int val){
	node* add=(node*)malloc(sizeof(node));
	add->value = val;
	add->next = NULL;
	head->next = add;
}

void delete(node** head, int val){
    	node* current = *head;
    	while (current != NULL) {
        	if (current->value == val) {
            		node* node_to_delete = current;
            		current = current->next;
            		if (*head == node_to_delete)
                		*head = current;
            		if (node_to_delete->next != NULL) 
                		node_to_delete->next->previous = node_to_delete->previous;
            		if (node_to_delete->previous != NULL)
                		node_to_delete->previous->next = node_to_delete->next;
            		free(node_to_delete);
			else
            			current = current->next;
    }
}


/*int main(int argc, char* argv[]){
	int num_nodes = atoi(argv[1]), num_edges = atoi(argv[2]);
	int i;
	for(int i = 1; i <= num_nodes; i++){
		
	
	
	}
    	int current, next;
    	for (i = 0; i < num_edges; i++) {
        	scanf("%d %d", &scurrent, &next);
    	}
}*/
int main(){
	return 0;
}
