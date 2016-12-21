#include <stdio.h>

typedef struct _node {
	char data;
	struct _node* next;
}node;

void print(node* r)
{
	while(r)
	{
		printf("[%c] ",r->data);
		r = r->next;
	}
	printf("\n");
}

node* reserve(node *r)
{
	node* previous = NULL;
	node* current = r;
	node* preceding = r->next;
	int i;
	
	while(preceding)
	{
		current->next = previous;
		previous = current;
		current = preceding;
		preceding = preceding->next;
	}
	current->next = previous;
	r = current;
}

int main()
{
	node d = {'d', NULL};
	node c = {'c', &d};
	node b = {'b', &c};
	node a = {'a', &b};
	node* root = &a;
	print(root);
	root = reserve(root);
	print(root);
	return 0;
}
