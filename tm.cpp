#include<iostream> 
#include<string>
#define max_node 5
#define right 1
#define left -1
using namespace std;
// +1 for right and -1 for left
int dir=right; 
int mxsize;

struct link{
	char input;
	char change;
 	int dir;
	// if you are going to use the class which is nt declared yet then .... you have to add class keyword
 	class node *next;
	// for the other links connected to node
 	link *neigh_link;
};

class node{
	public :
  	int node_no;
   	int link_no;
   	link *links;//for link linked list
		//Default constructor is calling the parameterized constructor
  	node(){
			node(-1);
     	}
  	node(int n){
			node_no=n;
     	link_no=0;
     	links=NULL;
     }
		//links are establish
		void linker(char in,char ch,int dir,node *next){
			link *tmp=new link;
    	tmp->input=in;
    	tmp->change=ch;
    	tmp->dir=dir;
    	tmp->next=next;
    	tmp->neigh_link=links;
    	links=tmp;
    	link_no++;
   	}
 	link* check(char in){
		link *tmp;
    tmp=links;
    while(tmp!=NULL){
			if(tmp->input==in)
        break;
      tmp=tmp->neigh_link;
   	}
    return tmp;
  }
// trans is to move from one to node
} no[max_node],*trans;

node* node_add(int n){
	if(n>mxsize)
  	return NULL;
	
  return &no[n];
   }

int main(){
	int ch,no,dir,next,i;
 	char input,change,str[40];
 	node *trans,*temp;//
 	link *aj;//links 
 	cout<<"Enter the no node : ";
 	cin>>mxsize; 
 	do{
		cout<<"\nMenu : ";
    cout<<"\n1.Establish links : ";
    cout<<"\n2.Enter the string to check : ";
    cout<<"\n0.Exit:";
    cout<<"\nEnter your choice ";
    cin>>ch;
    switch(ch)
		{case 1: cout<<"Enter the no of node : ";
            cin>>no;
            temp=node_add(no);
            cout<<"Enter the input character : ";
            cin>>input;
            cout<<"Enter the replacing character : ";
            cin>>change;
            cout<<"Enter the next node :";
	    cin>>next;
            cout<<"Direction : 1.right 2.Left ";
            cin>>dir;
            dir=dir==1?right:left;
	    temp->linker(input,change,dir,node_add(next));
            break;
   case 2: trans=node_add(0);
           cout<<"Enter the string ";
	   cin>>str;
           strcat(str,".");
           for(i=0;trans!=NULL;)
           {aj=trans->check(str[i]);
            if(aj==NULL)
               break;
            str[i]=aj->change;
            i=i+aj->dir;
            trans=aj->next;
	     } 
           if(trans->link_no==0||str[i]=='\0')
            cout<<"String is accepted by turing machine ";
           else
            cout<<"string is not accepted ";
           cout<<str;
           break;
   }
}while(ch);

}
