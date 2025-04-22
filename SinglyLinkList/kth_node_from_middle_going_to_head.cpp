#include <iostream> // Including input-output stream header file

using namespace std; // Using standard namespace

struct Node // Declare a structure for defining a Node
{   
    int num; // Data field to store a number
    Node *next; // Pointer to the next node
}; // Node constructed

int sizen = 0; // Initializing variable to keep track of the size of the linked list

// Function to insert a node at the start of the linked list
void insert(Node** head, int num){
    Node* new_Node = new Node(); // Creating a new node
    new_Node->num = num; // Assigning data to the new node
    new_Node->next = *head; // Pointing the new node to the current head
    *head = new_Node; // Making the new node as the head
    sizen++; // Increasing the size of the linked list
}

// Function to find the kth node from the middle of the linked list towards the head
int Kth_Node_From_Middle(Node* node, int pos) {
    if(!node) // If the linked list is empty
        return -1; // Return -1 (Invalid position)

    Node* ff = node, *ss = node, *mid = NULL; // Initialize pointers for finding the middle and kth nodes
    int k = 0; // Initializing a variable to count the nodes from the middle

    // Find the middle node using the two-pointer approach
    while(ff && ff->next)
    {
        k++; // Increment count
        ss = ss->next; // Move ss one step
        ff = ff->next->next; // Move ff two steps
    }

    if(pos > k) // If the given position is greater than the nodes from the middle
        return -1; // Return -1 (Invalid position)

    mid = ss; // Set mid as the middle node
    ff = node, ss = node; // Reset pointers ff and ss to the head

    // Move ff to the kth node from the middle
    for(int i = 0; i < pos; i++)
    {
        ff = ff->next;
    }

    // Move ff and ss until ff reaches the middle node
    while(ff != mid)
    {
        ss = ss->next;
        ff = ff->next;
    }

    return ss->num; // Return the value of the kth node from the middle
}

// Function to display all nodes in the linked list
void display_all_nodes(Node* node)
{ 
    while(node!=NULL){ // Loop through all nodes until the end is reached
        cout << node->num << " "; // Displaying the data in the current node
        node = node->next; // Move to the next node
    } 
}

int main()
{
    Node* head = NULL; // Initializing the head of the linked list as NULL

    insert(&head,1); // Inserting a node with value 1
    insert(&head,3); // Inserting a node with value 3
    insert(&head,5); // Inserting a node with value 5
    insert(&head,7); // Inserting a node with value 7
    insert(&head,9); // Inserting a node with value 9

    cout << "Original list:\n"; // Displaying message for the original list
    display_all_nodes(head); // Displaying all nodes in the original list

    int pos = 2; // Position of the node to be found from the middle
    cout << "\nkth node of a linked list by starting at \nthe middle and moving towards the head:";
    cout << "\nPosition = " << pos;
    int result = Kth_Node_From_Middle(head, pos); // Find the kth node from the middle towards the head
    cout << "\nValue = " << result; // Display the value of the kth node
    cout<<endl; // Displaying newline
    return 0; // Returning from the main function
}
