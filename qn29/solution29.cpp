//Program to implement linear probing
#include<cstdio>
#include<cstdlib>
#define SIZE 10
class hash_table{
    private:
        int table[SIZE];
        bool deleted[SIZE];
    public:
        hash_table(){
        table[SIZE];
        deleted[SIZE];
        for(int i=0;i<SIZE;++i){
            table[i]=-1;
            deleted[i]=false;
        }
        }
        int hash_fn(int);
        void insert(int);
        void deletion(int);
        void search(int);
        void display(int);
};
int main(){
int key;
int choice;
//int size;
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
            obj.display(key);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
        } while (choice != 5);

        return 0;
        }
    int hash_table::hash_fn(int key){
        return key%SIZE;
    }
    //Function to insert
    void hash_table::insert(int key){
        int index=hash_fn(key);
        int start_index=index;
        do{
            if(table[index]==-1||deleted[index]){
                table[index]=key;
                deleted[index]=false;
                printf("The %d key is inserted at index %d\n",key,index);
                return;
            }
         index=(index+1)%SIZE;
         }while(index!=start_index);
    }
    //Function to delete
    void hash_table::deletion(int key){
        int index=hash_fn(key);
        int start_index=index;
        do{
            if(table[index]==key&&!deleted[index]){
                deleted[index]=true;
                printf("The %d key is deleted at index %d\n",key,index);
                return;
            }
            if(table[index]==-1&&!deleted[index]){
            break;
            }
            index=(index+1)%SIZE;
            }while(index!=start_index);
            printf("The key not found\n");
            }
    //Function to search
    void hash_table::search(int key){
        int index=hash_fn(key);
        int start_index=index;
        do{
            if(table[index]==key&&!deleted[index]){
            printf("The %d key is found at index %d\n",key,index);
            return;
        }
            if(table[index]==-1&&!deleted[index]){
            break;
        }
            index=(index+1)%SIZE;
        }   while(index!=start_index);
        printf("The key not found\n");

    }
    //Function to display
    void hash_table::display(int key){
        for (int i = 0; i < SIZE; ++i) {
            if (table[i] == -1 && !deleted[i]) {
            printf("Slot %d: Empty\n", i);
            }
            else if (deleted[i]) {
            printf("Slot %d: Deleted\n", i);
        }
            else {
            printf("Slot %d: %d\n", i, table[i]);
        }
        }
    }

