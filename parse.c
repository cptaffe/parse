
// abstract syntax tree
struct astree {

	// child trees
	struct astree **children;

	// data
	void *data;
};

typedef struct astree astree;

// parse struct
struct parse {

	// abstract syntax tree
	astree *tree;

	// default state function
	void *(*)(struct parse *) func;
};

typedef struct parse parse;



// finite state machine!
void parse_state(parse *p) {
	// loop until a state function returns NULL.
	while (p->func != NULL) {
		// type conversion for simplicity.
		p->func = (void *(*)(parse *)) p->func(p);
	}
}
