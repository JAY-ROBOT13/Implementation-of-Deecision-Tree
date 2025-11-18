// They directly decide they are interested in study or not
// Example:
//                  Is it exam time?
    //             /               \
    //          Yes                 No
    //         /                     \
    //    Study hard               Relax and chill



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char question[100];
    struct Node *yes;
    struct Node *no;
} Node;

// Function to create a new node
Node* createNode(char *question) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->question, question);
    newNode->yes = newNode->no = NULL;
    return newNode;
}

// Function to run decision tree
void askQuestions(Node *root) {
    char answer[5];

    if (root == NULL) return;

    // If leaf node → final decision
    if (root->yes == NULL && root->no == NULL) {
        printf("\nDecision: %s\n", root->question);
        return;
    }

    printf("%s (yes/no): ", root->question);
    scanf("%s", answer);

    if (strcmp(answer, "yes") == 0)
        askQuestions(root->yes);
    else
        askQuestions(root->no);
}

int main() {
    // Creating nodes
    Node *root = createNode("Is it exam time?");
    root->yes = createNode("Study hard");
    root->no  = createNode("Relax and chill");

    printf("---- Decision Tree ----\n");
    askQuestions(root);

    return 0;
}
