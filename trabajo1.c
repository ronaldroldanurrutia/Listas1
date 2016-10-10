#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAXWORD 100
#include<stdlib.h>
struct tnode{
    char *word,*sec;
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
        printf("%d %s\n",p->cout,p->word);
        treeprint(p->left);
        treeprint(p->right);
    }
}
char *hola(char *s){
    char *p;
    p=(char *)malloc(strlen(s)+1);
    if(p!=NULL){
        strcpy(p,s);
    }
    return p;
}
int cambio(struct tnode *p,struct tnode *q,char *w,char *r){
    int cond;
    if(p!=NULL && q==NULL){
        cond=strcmp(r,p->word);
        if(cond==0){
            p->cout++;
        }
        else{
            if(cond<0){
                p->sec=hola(p->word);
                p->word=hola(w);
                w=hola(p->sec);
                q=talloc();
                q->word=hola(r);
                q->cout=1;
                q->left=q->right=NULL;
            }
            else{
                q=talloc();
                p->sec=hola(w);
                w=hola(r);
                q->word=hola(p->sec);
                q->cout=1;
                q->left=q->right=NULL;
            }
        }
        return 1;
    }
    return 0;
}
int cambio1(struct tnode *p,struct tnode *q,char *w,char *r){
    int cond;
    if(p!=NULL && q==NULL){
        cond=strcmp(w,p->word);
        if(cond==0){
            p->cout++;
        }
        else{
            if(cond>0){
                p->sec=hola(p->word);
                p->word=hola(w);
                w=hola(p->sec);
                q=talloc();
                q->word=hola(r);
                q->cout=1;
                q->left=q->right=NULL;
            }
            else{
                q=talloc();
                p->sec=hola(w);
                w=hola(r);
                q->word=hola(p->sec);
                q->cout=1;
                q->left=q->right=NULL;
            }
        }
        return 1;
    }
    return 0;
}
struct tnode *addtree(struct tnode *p,char *w){
    int cond;
    if(p==NULL){
        p=talloc();
        p->word=hola(w);
        p->cout=1;
        p->left=p->right=NULL;
    }
    else{
        if((cond=strcmp(w,p->word))==0){
            p->cout++;
        }
        else{
            if(cond<0){
                cond=cambio(p->left,p->right,p->word,w);
                if(cond==0){
                    p->left=addtree(p->left,w);
                }
            }
            else{
                cond=cambio1(p->right,p->left,p->word,w);
                if(cond==0){
                    p->right=addtree(p->right,w);
                }
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
        if(isalpha(word[0])){
            root=addtree(root,word);
        }
    }
    treeprint(root);
    return 0;
}
