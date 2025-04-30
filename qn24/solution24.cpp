//Program to implement preorder,postorder and inorder using bst
#include <cstdio>
#include <cstdlib>

class bst {
    struct node {
        int data;
        node* left;
        node* right;
    };

    struct node* root;

public:
    bst() {
        root = NULL;
    }
    void insert(int);
    node* insert(node*, int);
    void inorder(node*);
    void inorder_display();
    void preorder(node*);
    void preorder_display();
    void postorder(node*);
    void postorder_display();
    int search(node*, int);
    void search_display(int);
};
int main() {
    bst obj;
    int choice;
    int value;
    int key;

    do {
        printf("\nMENU\n\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted:\n");
                scanf("%d", &value);
                obj.insert(value);
                printf("The value %d is inserted\n", value);
                break;
            case 2:
                obj.inorder_display();
                break;
            case 3:
                obj.preorder_display();
                break;
            case 4:
                obj.postorder_display();
                break;
            case 5:
                printf("Enter the key:\n");
                scanf("%d", &key);
                obj.search_display(key);
                break;
            case 6:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Insert function (recursive)
bst::node* bst::insert(node* root, int key) {
    if (root == NULL) {
        node* newnode = new node();
        newnode->data = key;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

void bst::insert(int key) {
    root = insert(root, key);
}

// Inorder traversal
void bst::inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Inorder display function
void bst::inorder_display() {
    inorder(root);
    printf("\n");
}

// Preorder traversal
void bst::preorder(node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Preorder display function
void bst::preorder_display() {
    preorder(root);
    printf("\n");
}

// Postorder traversal
void bst::postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Postorder display function
void bst::postorder_display() {
    postorder(root);
    printf("\n");
}

// Search function
int bst::search(node* root, int key) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == key) {
        return 0;
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Search display function
void bst::search_display(int key) {
    int result = search(root, key);
    if (result == 0) {
        printf("Key %d is found\n", key);
    } else {
        printf("Key %d is not found\n", key);
    }
}
