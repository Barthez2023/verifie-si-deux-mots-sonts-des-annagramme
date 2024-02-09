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
        return;
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
//cette fonction permet d'ajouter un element au milieu de la liste
Liste liste_push_meduim_liste(Liste li,int x,int val){//ici ont vas insirer apres la valeur
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
        return element;
    }
    ListeElement *temp=li;
    while (temp!=NULL && temp->value!=val)
    {
        temp=temp->next;
    }
    if (temp == NULL) {
        fprintf(stderr, "Valeur spécifiée non trouvée dans la liste\n");
        free(element); // Libère l'élément alloué
        return li;     // Retourne la liste inchangée
    }
    // Insérer l'élément après l'élément avec la valeur spécifiée
    element->next=temp->next;
    temp->next=element;
    return li;

    
}

//*************************************************************************************//
//cette fonction permet d'ajouter un element au milieu de la liste
Liste liste_push_meduim_liste1(Liste li,int x,int val){//ici ont vas insirer avant la valeur
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
        return element;
    }
    ListeElement *temp=li->next;
    ListeElement *before=li;
    while (temp!=NULL && temp->value!=val)
    {
        temp=temp->next;
        before=before->next;
    }
    if (temp == NULL) {
        fprintf(stderr, "Valeur spécifiée non trouvée dans la liste\n");
        free(element); // Libère l'élément alloué
        return li;     // Retourne la liste inchangée
    }
    // Insérer l'élément après l'élément avec la valeur spécifiée
    element->next=temp;
    before->next=element;
    return li;

    
}

//*************************************************************************************//
//cette fonction permet de retirer un element en milieu de la liste
Liste liste_pop_medium_liste(Liste li,int val){//on vas supprimer apres la valeur
    //si a liste est vide
    if (liste_isempty(li))
    {
        return new_liste();
    }
    //si la liste ne comporte que un element
    if (li->next==NULL)
    {
        free(li);
        li=NULL;
        return new_liste();
    }
    //si la liste a plusieurs elements
    ListeElement *temp=li;
    ListeElement *after=li->next;
    while (temp!=NULL && temp->value!=val)
    {
        temp=temp->next;
        after=after->next;
    }
    // Si l'élément à supprimer n'est pas trouvé dans la liste
    if (temp == NULL) {
        printf("Valeur spécifiée non trouvée dans la liste\n");
        return li; // Renvoie la liste inchangée
    }
    // Suppression de l'élément apres la valeur spécifiée
    temp->next=after->next;
    after->next=NULL;
    free( after);
    after=NULL;

    return li; 
}

//*************************************************************************************//
//cette fonction permet de retirer un element en milieu de la liste
Liste liste_pop_medium_liste1(Liste li,int val){//on vas supprimer avant la valeur
    //si a liste est vide
    if (liste_isempty(li))
    {
        return new_liste();
    }
    //si la liste ne comporte que un element
    if (li->next==NULL)
    {
        free(li);
        li=NULL;
        return new_liste();
    }
    //si la liste a plusieurs elements
    ListeElement *temp=li->next;
    ListeElement *before=li;
    ListeElement *before1=NULL;
    while (temp!=NULL && temp->value!=val)
    {    
        before1=before;
        before=before->next;
        temp=temp->next;
        
       
    }
    // Si l'élément à supprimer n'est pas trouvé dans la liste
    if (temp == NULL) {
        printf("Valeur spécifiée non trouvée dans la liste\n");
        return li; // Renvoie la liste inchangée
    }
    // Suppression de l'élément avant la valeur spécifiée
    before1->next=temp;
    //before->next=NULL;
    free( before);
    before=NULL;

    return li; 
}


//*************************************************************************************//
//cette fonction permet de retirer un element en fin de la liste
Liste liste_pop_back_liste(Liste li){
    //si a liste est vide
    if (liste_isempty(li))
    {
        return new_liste();
    }
    //si la liste ne comporte que un element
    else
    {
        if (li->next==NULL)
        {
           free(li);
           li=NULL;
           return new_liste();
        }
        //si la liste a plusieurs elements
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
    //si a liste est vide
    if (liste_isempty(li))
    {
        return new_liste();
    }
    //si la liste ne comporte que un element
    else
    {
        if (li->next==NULL)
        {
           free(li);
           li=NULL;
           return new_liste();
        }
        //si la liste a plusieurs elements
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
    if (liste_isempty(li))
    {
      exit(1);
    }
    else
    {
        ListeElement *temp;
        temp=li->next;
        return li->value; 
    }
    
    
    
}
int last_element_list(Liste li){
    if (liste_isempty(li))
    {
        exit(1);
    }
    else
    {
        while (li->next!=NULL)
            {
                li=li->next;
            }
        return li->value;
    }
    
    
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
 myliste=liste_push_meduim_liste(myliste,100,70);
 myliste=liste_push_meduim_liste1(myliste,200,45);
 printf_liste(myliste);
 myliste=liste_pop_medium_liste(myliste,45);
 printf_liste(myliste);
 //******
 myliste=liste_pop_medium_liste1(myliste,200);
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
