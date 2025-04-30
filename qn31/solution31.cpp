//Code to implement seperate chaining
#include<cstdio>
#include<cstdlib>
const int TABLE_SIZE = 10;
class hash_table{
    struct node{
    int data;
    struct node*next;
   };
   struct node*table[TABLE_SIZE];
   public:
        hash_table(){
            for(int i=0;i<TABLE_SIZE;i++){
                table[i]=NULL;
            }
        }
        int hash_fn(int);
        void insert(int);
        void deletion(int);
        void search(int);
        void display();
};
int main(){
    int key;
    int choice;
    hash_table obj;
    do {
        printf("\nMenu:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Search\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the key to be inserted\n");
                scanf("%d",&key);
                obj.insert(key);
                break;
            case 2:
                printf("Enter the key to be deleted\n");
                scanf("%d",&key);
                obj.deletion(key);
                break;
            case 3:
                printf("Enter the key to be searched:\n");
                scanf("%d",&key);
                obj.search(key);
                break;
            case 4:
                obj.display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
         }
     }     while (choice != 5);
    
    return 0;
    }
    int hash_table::hash_fn(int key){
        return key%TABLE_SIZE;
    }
    void hash_table:: insert(int key){
        int index=hash_fn(key);
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data = key; 
        newnode->next=table[index];
        table[index]=newnode;
        printf("Inserted %d at %d\n",key,index);
    }
    void hash_table::deletion(int key){
        int index=hash_fn(key);
        struct node*curr=table[index];
        struct node*prev=NULL;
        while(curr!=NULL){
            if(curr->data==key){
                if(prev==NULL){
                    table[index]=curr->next;
                }
                else{
                    prev->next=curr->next;
                }
                free(curr);
                printf("Deleted %d in %d",key,index);
                return;
            }
            prev=curr;
            curr=curr->next;
        }
        printf("%d is not found",key);
    }
    void hash_table:: search(int key){
        int index=hash_fn(key);
        struct node*curr=table[index];
        while(curr!=NULL){
            if(curr->data==key){
                printf("%d is found at index %d",key,index);
                return;
            }
            curr=curr->next;
        }
        printf("Key not found\n");
    }
    void hash_table::display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            printf("%d ", i);
            hash_table::node* curr = table[i];
            while (curr != NULL) {
                printf("%d ->", curr->data);
                curr = curr->next;
            }
            printf("NULL\n");
        }
    }
