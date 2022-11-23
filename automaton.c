#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef struct _node
{
    void *data;
    struct _node *next;
} Node;

typedef struct _list
{
    Node *head;
    Node *current;
    Node *tail;
}List;

typedef struct _sigma{
    char title;
    char result;
    char edgetype;
    
} Sigma;

typedef struct _automaton {
    char states[MAX_LENGTH];
    char edges[MAX_LENGTH];
    char start[MAX_LENGTH];
    char end[MAX_LENGTH];
    Sigma fucntions[MAX_LENGTH];
} Automaton;

typedef struct _state{
    char title;
    struct _state *parent;
    char children;
}State;


void init_automaton(Automaton *automaton);
void print_automaton(Automaton *automaton);
void init_sig(Sigma* operation,char titl,char edgetype,char res);
void print_sig(Sigma* sigma);
int empty_sig(Sigma* sigma);
void ini_list(List *list);
void add_tail(List *list,void *data);
State* init_state(char title, State* parent,char child);
int strlen(char *str);
void displaylist(List *list);
void displaylistS(List *list);
int is_final(Automaton* automaton,char state);


int main(){
    FILE *txt;
    char line[MAX_LENGTH];
    txt=fopen("automaton.txt","r");
    char ch;
    char str[MAX_LENGTH];

    if(txt == NULL){
        printf("file not found\n");
        return -1;}

    Automaton automaton;
    init_automaton(&automaton);
    Automaton *ptr = &automaton;
    int count=0;

    while(fgets(line,MAX_LENGTH,txt)){

         if (count==0){
            int i=0;
            int j=0;
            while(line[i]){
                if(line[i]!=',' && line[i]!='\n'){
                    ptr->states[j]=line[i];
                    j++;
                }
                i++;
            }
         }

         else if (count==1){
            int i=0;
            int j=0;
            while(line[i]){
                if(line[i]!=',' && line[i]!='\n'){
                    ptr->edges[j]=line[i];
                    j++;
                }
                i++;
            }
         }

        else if (count==2){
            int i=0;
            int j=0;
            while(line[i]){
                if(line[i]!=',' && line[i]!='\n'){
                    ptr->start[j]=line[i];
                    j++;
                }
                i++;
            }
         }

        else if (count==3){
            int i=0;
            int j=0;
            while(line[i]){
                if(line[i]!=',' && line[i]!='\n'){
                    ptr->end[j]=line[i];
                    j++;
                }
                i++;
            }
         }

         else{
            char a,b,c;
            a=line[0];
            b=line[2];
            c=line[4];
            Sigma *lolptr = &(ptr->fucntions[count-4]);
            init_sig(lolptr,a,b,c);
         }
         

         count++;
    }

    print_automaton(ptr);

    printf("str: ");
    scanf("%s",&str);
    int length=strlen(str);
    int n_op=0;
    
    while(empty_sig(&(ptr->fucntions[n_op]))==0){
        n_op++;
    }
    printf("n_op: %d\n",n_op);

    List results[length+1];

for (int i=0;i<length+1;i++){
    ini_list(&results[i]);
}


State *q0=init_state(*(ptr->start),NULL,'1');
add_tail(&results[0],q0);


State *cstate;
Node *cnode;
List *cres;
int k=1;
char lol;
for(int i=0;i<length;i++){
    cres= &results[k-1];
    cnode= cres->head;
    cstate=cnode->data;
   
    while(cnode!=NULL){
        cstate=cnode->data;
        List *res=&results[k];
        for(int j=0;j<n_op;j++){
            Sigma* sigma = &(ptr->fucntions[j]);
            if(sigma->title==cstate->title && sigma->edgetype==str[i]) {
                cstate->children='1';
                State *state = init_state(sigma->result,cstate,'0');

                add_tail(res,state);
            }
        }
        // if(res->head==NULL){
        //     State *state = init_state('n',NULL,'0');
        //     add_tail(res,state);
        //     break;
        // }
        cnode=cnode->next;
    }
  k++;
}
for(int j=1;j<=length+1;j++){
    printf("%d ",j);
    displaylistS(&results[j-1]);
    }
    printf("\n");

for(int j=0;j<length+1;j++){
    int l=length;
    List *clist=&results[l-j];
    Node *cnode=clist->head;
    State *cstate=cnode->data;
    while (cnode!=NULL){
        cstate=cnode->data;
        if(is_final(ptr,cstate->title)==1 && cstate->children=='0'){
            printf("Solution Path: ");
            while(cstate->parent!=NULL){
                State *parent=cstate->parent;
                printf("%c <- ",cstate->title);
                cstate=parent;
            }
            printf("%c\n",*(automaton.start));
        }
        cnode=cnode->next;
    }
}

printf("progam end :)");
}
void init_automaton(Automaton *automaton){

for(int i=0;i<MAX_LENGTH;i++){
    automaton->states[i] = '\0';
    automaton->start[i] = '\0';
    automaton->edges[i] = '\0';
    automaton->end[i] = '\0';
    Sigma *sigptr = &(automaton->fucntions[i]);
    sigptr->edgetype = '\0';
    sigptr->title = '\0';
    sigptr->result = '\0';



}
}

void print_automaton(Automaton *automaton){
    int i=0;
    char *states=automaton->states;
    char *edges=automaton->edges;
    char *start=automaton->start;
    char *end=automaton->end;
   

    printf("Q: ");
    while(states[i]){
        printf("%c, ",states[i]);
        i++;
    }
    i=0;
    printf("\n");

    printf("Ed: ");
    while(edges[i]){
        printf("%c, ",edges[i]);
        i++;
    }
    i=0;
    printf("\n");

    printf("S: ");
    while(start[i]){
        printf("%c, ",start[i]);
        i++;
    }
    i=0;
    printf("\n");

    printf("F: ");
    while(end[i]){
        printf("%c, ",end[i]);
        i++;
    }
    i=0;
    printf("\n");

    printf("Fun: ");
     Sigma* funptr=&(automaton->fucntions[i]);
    while(empty_sig(funptr)==0){
        
        print_sig(funptr);
        i++;
        funptr=&(automaton->fucntions[i]);
    }
    i=0;
    printf("\n");
    
}

void init_sig(Sigma* operation,char titl,char edgetype,char res){
    operation->title = titl;
    operation->edgetype = edgetype;
    operation->result = res;
}

void print_sig(Sigma* sigma){

    printf("f(%c,%c)=%c\n",sigma->title,sigma->edgetype,sigma->result);
}

int empty_sig(Sigma* sigma){
    if (sigma->title=='\0' && sigma->title=='\0' && sigma->title=='\0')
        return 1;
    else
        return 0;
}

void ini_list(List *list){
    list->head=NULL;
    list->current=NULL;
    list->tail=NULL;
}

void add_tail(List *list,void *data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;

        if( (node) == NULL )
{
     printf("MEMORY ALLOCATION FAILED ");
     }

    if(list->head==NULL){
        list->head=node;
    }
    else{
        list->tail->next=node;
    }
    list->tail = node;
}

State* init_state(char title, State* parent,char child){
    State* state = (State*)malloc(sizeof(State));
    state->title=title;
    state->parent=parent;
    state->children=child;
    return state;
}

int strlen(char *str) {
    int rtn=0; 
    for (rtn = 0; str[rtn] != '\0'; ++rtn);
    return rtn; 
}

void displaylist(List *list) {
if(list!=NULL){
 Node *current = list->head;
 while (current != NULL) {
 printf("%s, " ,current->data);
 current = current->next;
 }
 printf("\n");
 }
}

void displaylistS(List *list) {
if(list!=NULL){
 Node *current = list->head;
 State *state;
 while (current != NULL) {
    state=current->data;
 printf("%c, " ,state->title);
 current = current->next;
 }
 printf("\n");
 }
}

int is_final(Automaton* automaton,char state){
    int i =0;
char *end_s = &(automaton->end[i]);
while(end_s[i]){
if(end_s[i]==state)
return 1;
i++;
}
return 0;
}