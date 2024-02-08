#include<stdio.h>
#include <string.h>
#include <stdlib.h>
//creation du type booleen
typedef enum{
    false,
    true
}bool;
//definition de la liste
typedef struct ListeElement 
{
    int value;
    struct ListeElement *next;
}ListeElement,*Liste;

//*************************************************************************************//
//cette fonction permet de creer une liste
Liste new_liste(void){
   return NULL;
}

//************************************************************************************//
//cette fonction permet de tester si une liste est vide ou pas
bool liste_isempty(Liste li){
    if (li==NULL)
       return true;
    return false;
}
//*************************************************************************************//
//cette fonction retourne le nombre d'element contenu dans la liste
int length_liste(Liste li){
    int size=0;
    if (!liste_isempty(li))
    {
         while (li!=NULL)
    {
        size++;
        li=li->next;
    }
        
    }
    return size;
    
    
} 
//*************************************************************************************//
//fonction permet d'afficher la liste
void printf_liste(Liste li){
    if (liste_isempty(li))
    {
        printf("Rien a afficher la listee est vide\n");
    }
    else
    {
        while (li!=NULL)
        {
            printf("[%d] ",li->value);
            li=li->next;
        }
        printf("\n");
    }
}
//*************************************************************************************//
//cette fonction permet d'ajouter un element en fin de la liste
Liste liste_push_back_liste(Liste li,int x){
    ListeElement *element;
    element=malloc(sizeof(*element));
    if (element==NULL)
    {
        fprintf(stderr,"Error lors de l'allocation\n");
        exit(EXIT_FAILURE);
    }
    element->value=x;
    element->next=NULL;
    if (liste_isempty(li))
    {
        return element;
    }
    ListeElement *temps;
    temps=li;
    while (temps->next!=NULL)
    {
        temps=temps->next;
       
    }
    temps->next=element;
    return li;
}
//*************************************************************************************//
//cette fonction permet d'ajouter un element en debut de la liste
Liste liste_push_front_liste(Liste li,int x){
    ListeElement *element;
    element=malloc(sizeof(*element));
    if (element==NULL)
    {
        fprintf(stderr,"Error lors de l'allocation\n");
        exit(EXIT_FAILURE);
    }
    element->value=x;
    if (liste_isempty(li))
    {
        element->next=NULL;
    }
    else
    {
        element->next=li;
    }
    return element;
}
//*************************************************************************************//
//cette fonction permet de retirer un element en fin de la liste
Liste liste_pop_back_liste(Liste li){
    if (liste_isempty(li))
    {
        return new_liste();
    }
    else
    {
        if (li->next==NULL)
        {
           free(li);
           li=NULL;
           return new_liste();
        }
        else
        {
            ListeElement *temp=li;
            ListeElement *before=li;
            while (temp->next!=NULL)
            {
                before=temp;
                temp=temp->next;
            }
            before->next=NULL;
            free(temp);
            temp=NULL;
        }
    }
    return li; 
}

//*************************************************************************************//
//cette fonction permet de retirer un element en debut de la liste
Liste liste_pop_front_liste(Liste li){
    if (liste_isempty(li))
    {
        return new_liste();
    }
    else
    {
        if (li->next==NULL)
        {
           free(li);
           li=NULL;
           return new_liste();
        }

        else
        {
            ListeElement *element;
            element=malloc(sizeof(*element));
            if (element==NULL)
            {
                fprintf(stderr,"Error lors de l'allocation\n");
                exit(EXIT_FAILURE);
            }
            element=li->next;
            free(li);
            li=NULL;  
            return element;
        }
    }
    
}

//*************************************************************************************//
//cette fonction permet de vider de la liste
Liste clear_liste(Liste li){
    if (liste_isempty(li))
    {
        return new_liste();
    }

    while (li!=NULL)
    {
       li=liste_pop_front_liste(li);
    }
}
int sum_elements(Liste li){
    int sum=0;
    while (li!=NULL)
    {
        sum+=li->value;
        li=li->next;
    }
    return sum;
}
int first_element_list(Liste li){
    ListeElement *temp;
    temp=li->next;
    return li->value;
}
int last_element_list(Liste li){

    while (li->next!=NULL)
            {
                li=li->next;
            }
    return li->value;
}


//*************************************************************************************//
//fonction principale(main)
int main(){
    Liste myliste=new_liste();
 if(liste_isempty(myliste))
    printf("La liste est bel et bien vide\n");
 else   
    printf("La liste n'est pas vide\n");
 if(length_liste(myliste))
    printf("La liste n'a aucun element\n");
 else   
    printf("La liste compte %d elements\n",length_liste(myliste));
 printf_liste(myliste);

 myliste=liste_push_back_liste(myliste,45);
 printf_liste(myliste);
 printf("La liste compte %d elements\n",length_liste(myliste));
 myliste=liste_push_back_liste(myliste,50);
 myliste=liste_push_front_liste(myliste,70);
 myliste=liste_push_back_liste(myliste,80);
 printf_liste(myliste);
 printf("La liste compte %d elements\n",length_liste(myliste));
 printf("La somme des elements de la liste est de : %d \n",sum_elements(myliste));
 printf("Le premier element de la liste est de : %d \n",first_element_list(myliste));
 printf("Le dernier element de la liste est de : %d \n",last_element_list(myliste));

 myliste=liste_pop_back_liste(myliste);
 myliste=liste_pop_front_liste(myliste);
 printf_liste(myliste);
 printf("La liste compte %d elements\n",length_liste(myliste));

 myliste=clear_liste(myliste);
 printf_liste(myliste);
 printf("La liste compte %d elements\n",length_liste(myliste));
























    return 0;
} 