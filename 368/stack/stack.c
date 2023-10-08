// Node structure used in LL or stack or queue... etc.
typedef struct _Node {
    char ch; // val
    struct _Node* next; // next field is a node
} Node; // alias for struct _Node not effective until after this line

void linked_list_operations(Node** a_top)
{
    // IMPORTANT NOTE: We pass **a_top since we are interested in modifying *a_top ITSELF (pass by reference)

    // init a new top node using compound literal
    Node* new_top = malloc(sizeof(*new_top)); // reference the type
    *new_top = (Node) { .next = NULL, .ch = ch }; // compound literal

    // adding our new node to the top of the stack
    *a_top = new_top; // set top of our list to point to new node
    new_top -> next = *a_top; // make our new top node point to old top node

    if(*a_top == NULL)
    {
        *a_top = new_top; // make a_top point to this new node
        // we only use *a_top since we are changing where *a_top refers t
    }
}

// pushing to a stack just means adding to the top of the stack like above
void push(Node** a_top, char ch)
{
    // init a new top node using compound literal
    Node* new_top = malloc(sizeof(*new_top)); // reference the type
    *new_top = (Node) { .next = NULL, .ch = ch }; // compound literal

    // adding our new node to the top of the stack
    *a_top = new_top; // set top of our list to point to new node
    new_top -> next = *a_top; // make our new top node point to old top node (fixing the chain)
}

// popping from the stack means removing from the top of the stack:
//  1. make a temp pointer to the top node (to free it later)
//  2. make the top node point to the next node
//  3. free the temp pointer
char pop(Node** a_top)
{
    Node* temp = *a_top; // make a pointer to the top node
    char ch = (*a_top) -> ch; // get the value of the top node
    *a_top = (*a_top) -> next; // make the top node point to the next node
    free(temp); // free temp (it points to the old top node)
    return ch;
}