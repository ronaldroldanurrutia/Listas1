#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAXWORD 100
#include<stdlib.h>
struct tnode{
    char *word;
    int cout;
    struct tnode *left;
    struct tnode *right;
};
struct tnode *talloc(void){
    return (struct tnode*) malloc(sizeof(struct tnode));
};
char buf[MAXWORD];
int bufp=0;
int getch(void){
    return (bufp>0) ? buf[--bufp]:getchar();
}
void ungetch(int c){
    if(bufp>=MAXWORD){
        printf("Too many characteres\n");
    }
    else{
        buf[bufp++]=c;
    }
}
int getword(char *word,int lim){
    int c,getch(void);
    void ungetch(int);
    char *w=word;
    while(isspace(c=getch()));
    if(c!=EOF){
        *w++=c;
    }
    if(!isalpha(c)){
        *w='\0';
        return c;
    }
    for(;--lim>0;w++){
        if(!isalnum(*w=getch())){
            ungetch(*w);
            break;
        }
    }
    *w='\0';
    return word[0];
}
void treeprint(struct tnode *p){
    if(p != NULL){
        treeprint(p->left);
        printf("%d %s\n",p->cout,p->word);
        treeprint(p->right);
    }
}
char *strdup(char s){
    char *p;
    p=(char *)malloc(strlen(s)+1);
    if(p!=NULL){
        strcpy(p,s);
    }
    return p;
}
struct tnode *addtree(struct *p,char *w){
    int cond;
    if(p==NULL){
        p=talloc();
        p->word=strdup(w);
        p->cout=1;
        p->left=p->right=NULL;
    }
    else{
        if((cond=strcmp(w,p->word)==0){
            p->cout++;
        }
        else{
            if(cond<0){
                p->addtree(p->left,w);
            }
            else{
                p->addtree(p->right,w);
            }
        }
    }
    return p;
};
main(){
    struct tnode *root;
    char word[MAXWORD];
    root=NULL;
    while(getword(word,MAXWORD)!=EOF){
        if(issalpha(word[0])){
            root=addtrees(root,word);
        }
    }
    treeprint(root);
    return 0;
}

