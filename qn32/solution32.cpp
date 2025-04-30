//Program to execute adjacency matrix using graph adt
#include<cstdio>
class graph_adt{
    private:
        int matrix[100][100];
        int n;
    public:
        graph_adt(int vertices){
            n=vertices;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        bool isvalid(int);
        void insert(int,int);
        void deletion(int,int);
        void search(int,int);
        void display();
};
int main(){
    int n;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    graph_adt obj(n);
    int u,v,choice;
    do{
        printf("\nMENU\n1.Insertion of edge\n2.Deletion of edge\n3.Search edge\n4.Display edge\n5.Exit\n");
        printf("ENTER YOUR CHOICE:\n");
        scanf("%d",&choice);
        
            switch(choice){           
                case 1:
                    printf("Enter the u vertice to insert an edge:\n");
                    scanf("%d",&u);
                    printf("Enter the v vertice to insert an edge:\n");
                    scanf("%d",&v);
                    obj.insert(u,v);
                    break;
                case 2:
                    printf("Enter the u vertice to delete an edge:\n");
                    scanf("%d",&u);
                    printf("Enter the v vertice to delete an edge:\n");
                    scanf("%d",&v);
                    obj.deletion(u,v);
                    break;
                case 3:
                    printf("Enter the u vertice to search an edge:\n");
                    scanf("%d",&u);
                    printf("Enter the v vertice to search an edge:\n");
                    scanf("%d",&v);
                    obj.search(u,v);
                    break;
                case 4:
                    obj.display();
                    break;
                case 5:
                    printf("Exiting the program....");
                    break;
                default:
                    printf("Invalid choice\n");
                }
            }while(choice!=5);
            return 0;
    }
    //valid check function
    bool graph_adt::isvalid(int v){
        return (v>=0&&v<n);
    }
    //Function to insert an edge
    void graph_adt:: insert(int u,int v){
        if(isvalid(u)&&isvalid(v)){
            matrix[u][v]=1;
            matrix[v][u]=1;
            printf("Edge inserted between %d and %d\n",u,v);
        }
        else{
            printf("Invalid vertex number\n");
        }
    }
    //Function to delete an edge
    void graph_adt::deletion(int u,int v){
        if(isvalid(u)&&isvalid(v)){
            matrix[u][v]=0;
            matrix[v][u]=0;
            printf("Edge deleted between %d and %d\n",u,v);
        }
        else{
            printf("Invalid vertex number\n");
        }
    }
    //Function to search an edge
    void graph_adt::search(int u,int v){
        if(isvalid(u)&&isvalid(v)){
            if(matrix[u][v]==1){
                printf("Edge exist between %d and %d\n",u,v);
            }
            else{
                printf("Edge does not exist between %d and %d\n",u,v);
            }
        }
        else{
            printf("invalid vertex\n");
        }
    }
    //Function to dispaly the matrix
    void graph_adt::display(){
        printf("ADJACENCY MATRIX\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d",matrix[i][j]);
            }
            printf("\n");
        }
    }
