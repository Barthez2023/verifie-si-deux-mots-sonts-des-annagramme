#include<stdio.h>
#include <string.h>
#include <stdlib.h>
//creation du type booleen
typedef enum{
    false,
    true
}Bool;
//*************************************************************************************//
//definition de la file
typedef struct QueueElement 
{
    int value;
    struct QueueElement *next;
}QueueElement,*Queue;
//*************************************************************************************//
//parametres de la file
static QueueElement *first=NULL;
static QueueElement *last=NULL;
static int Nbr_element=0; 
//avec ces diferents parametre nous avons deja par defaut une file vide dont ne n'avons plus besoins de declarer une file vide
//prototypes
 Bool  queue_isempty(void){
    if (first==NULL && last==NULL)
       return 1;
    return 0;
}
//*************************************************************************************//
//cette fonction retourne le nombre d'element contenu dans la files
int length_queue(void){
    if (Nbr_element==0)
       return 0;
    return Nbr_element;
} 
//*************************************************************************************//
//cette fonction retourne le premier elemnt de la file
int queue_first(void){
    if(queue_isempty())
        exit(1);
    else
        return first->value;
} 
//*************************************************************************************//
//cette fonction retourne le dernier element de la pile
int queue_last(void){
    if(queue_isempty())
        exit(1);
    else
        return last->value;
} 
//*************************************************************************************//
//fonction permet d'afficher la file
void printf_queue(void){
    if (queue_isempty())
    {
        printf("Rien a afficher la file est vide\n");
    }
    else
    {
        QueueElement *temp=first;
        /*ici,a la variable temp ont affecte le premiere valeur de la file qui est first et on se balade avec le le pointeurr temp pour eviter de bouger
        le pointeur qui pointe normelement sur firts car pour afficher la premiere valeur il faut que le pointeur soit sur first.*/
        while (temp!=NULL)
        {
            printf("[%d] ",temp->value);
            temp=temp->next;
        }
        printf("\n");
    }
}

//*************************************************************************************//
//fonction permet d'ajouter les elments dans la file
void push_queue(int x){
    QueueElement *element;
    element=malloc(sizeof(*element));
    if (element==NULL)
    {
        exit(EXIT_FAILURE);
    }
    element->value=x;
    element->next=NULL;
    if (queue_isempty())
    {
        last=element;
        first=element;
    }
    else
    {
        last->next=element;
        last=element;
    }
    Nbr_element++;
}
//*************************************************************************************//
//fonction permet de retirer  les elments dans la file
void pop_queue(void){
    if (queue_isempty())
    {
        printf("Rien a retirer la file est deja vide\n");
        return;
    }
    QueueElement *temp=first;
    if (first==last)
    {
        first=NULL;
        last=NULL;
    }
    else
        first=first->next;
    free(temp);
    Nbr_element--;
}
//*************************************************************************************//
//fonction permet de nettoyer la file
void clear_queue(void){
    if (queue_isempty())
    {
        printf("Rien a retirer la file est deja vide\n");
        return;
    }
    
    while (first!=NULL)
    {
        pop_queue();
    }
    
}
//*************************************************************************************//
//fonction permet de calculer la somme des elments dans la file
int sum_elements(void){
    int sum=0;
    if (queue_isempty())
    {
        printf("La file est vide par consequent la somme de ces elemnts est nul\n");
        return 0;
    }
    else
    {
        QueueElement *temp=first;
        while (temp!=last)
        {
            sum+=temp->value;
            temp=temp->next;
        }
        sum=sum+last->value;
        return sum;
    }
       
}
int queue_top(void){
    return first->value;
}
int queue_bas(void){
    return last->value;
}
    
//*************************************************************************************//
//fonction principale(main)
int main(){
 /*if(queue_isempty())
    printf("La file est bel et bien vide\n");
 else   
    printf("La file n'est pas vide\n");
 if(length_queue())
    printf("La file n'a aucun element\n");
 else   
    printf("La file compte %d elements\n",length_queue());
 printf_queue();*/
 //ont teste la file ici elle ne contient aucun element
 printf("la taille de la pile est de:%d\n",length_queue());
 printf_queue();
 printf("La somme des elements est de:%d\n",sum_elements());
 //on ajoute un element
 push_queue(20);
 push_queue(30);
 push_queue(40);
 push_queue(50);
 push_queue(60);
 push_queue(70);
 printf("la taille de la pile est de:%d\n",length_queue());
 printf_queue();
 printf("La somme des elements est de:%d\n",sum_elements());
 printf("Le sommet de la file est :%d\n",queue_top());
 printf("Le dernier element de la file est :%d\n",queue_bas());
 //on supprime un elemnt
 pop_queue();
 printf("la taille de la pile est de:%d\n",length_queue());
 printf_queue();
 printf("La somme des elements est de:%d\n",sum_elements());
 clear_queue();
 printf("la taille de la pile est de:%d\n",length_queue());
 printf_queue();
 printf("La somme des elements est de:%d\n",sum_elements());




    return 0;
}