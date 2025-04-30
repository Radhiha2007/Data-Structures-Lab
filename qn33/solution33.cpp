//Program to implement adjacency list using graph adt
#include<cstdio>
#include<list>
using namespace std;
class graph_adt {
    private:
        int V;                     
        list<int>* adj;             
    public:
        graph_adt(int vertices) {
            V = vertices;
            adj = new list<int>[V]; 
        }
        bool isvalid(int);
        void insert(int,int);
        void deletion(int,int);
        void search(int,int);
        void display();
        ~graph_adt(){
            delete[]adj;
        }
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
        bool graph_adt:: isvalid(int v) {
            return (v >= 0 && v < V);
        }
        //Function to insert an edge
        void graph_adt::insert(int u,int v){
            if(isvalid(u)&&isvalid(v)){
                adj[u].push_back(v);
                adj[v].push_back(u);
                printf("Edge inserted between %d and %d\n",u,v);
            }
            else{
                printf("Invalid vertex number\n");
            }
        }
        void graph_adt::deletion(int u,int v){
            if(isvalid(u)&&isvalid(v)){
                adj[u].remove(v);
                adj[v].remove(u);
                printf("Edge deleted between %d and %d\n",u,v);
            }
            else{
                printf("Invalid vertex number\n");
            }
        }
        void graph_adt::search(int u,int v){
            if(isvalid(u)&&isvalid(v)){
                bool found=false;
                for(int val:adj[u]){
                    if(val==v){
                        found=true;
                        break;
                    }
                }
                if(found){
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
        void graph_adt::display(){
            printf("ADJACENCY LIST\n");
            for(int i=0;i<V;i++){
                printf("%d:",i);
                for(int x:adj[i]){
                    printf("%d ->",x);
                }
            printf("\n");
            }
        }
