#include<stdio.h>
#include <string.h>
#include <stdlib.h>
//creation du type booleen
typedef enum{
    false,
    true
}bool;
//*************************************************************************************//
/*ici ont definir un element car tout element qui vas entrer dans la liste doublement chainee doit etre constituer de deux pointeur et d'une valeur*/
typedef struct ListeNode 
{
    int value;
    struct ListeNode *next;
    struct ListeNode *back;
}ListeNode;
//*************************************************************************************//
//definition de la liste doublement chaine
/*ici ont definir la liste doublement chainee en general*/
typedef struct ListeD 
{
    int length;
    struct ListeNode *begin;
    struct ListeNode *end;
}*ListeD;
ListeD liste_pop_front_liste(ListeD li);
//*************************************************************************************//
//cette fonction permet de creer une liste
ListeD new_listeD(void){
   return NULL;
}
//************************************************************************************//
//cette fonction permet de tester si une liste doublement chainee est vide ou pas
bool listeD_isempty(ListeD li){
    if (li==NULL)
       return true;
    return false;
}
//*************************************************************************************//
//cette fonction retourne le nombre d'element contenu dans la liste
int length_listeD(ListeD li){
    if (listeD_isempty(li))
        return 0;
    return li->length;
} 
//*************************************************************************************//
//cette fonction retourne le premier element de la liste
int first_element_list(ListeD li){
    if (listeD_isempty(li))
    {
        exit(1);
    }
    return li->begin->value;
}
//*************************************************************************************//
//cette fonction retourne le dernier element de la liste
int last_element_list(ListeD li){
    if (listeD_isempty(li))
    {
        exit(1);
    }
    return li->end->value;
}
//*************************************************************************************//
//fonction permet d'afficher la liste doublement chaine
void printf_listeD(ListeD li){
    if (listeD_isempty(li))
    {
        printf("Rien a afficher la listee est vide\n");
        return;
    }
    ListeNode *temp=li->begin;//cette variable temporaire vas nous permettre de parcourrie toute laliste et nous eviter de boujer le pointeru beging ou end
    while (temp!=NULL)
        {
            printf("[%d] ",temp->value);
            temp=temp->next;
        }        
        printf("\n");
    
}
//*************************************************************************************//
//cette fonction permet d'ajouter un element en fin de la liste
ListeD liste_push_back_liste(ListeD li,int x){
    ListeNode *element; //ici on cree l'element a inserer dans la liste
    element=malloc(sizeof(*element));
    if (element==NULL)
    {
        fprintf(stderr,"Error :Allocation impossible\n");
        exit(EXIT_FAILURE);
    }
    element->value=x;
    element->next=NULL;  //ici les pointeur next ne pointe encore sur rien dont il est initialiser a NULL
    element->back=NULL;   //ici les pointeur back ne pointe encore sur rien dont il est initialiser a NULL
    if (listeD_isempty(li))
    {
        li=malloc(sizeof(*li));
        if (li==NULL)
        {
            fprintf(stderr,"Error :Allocation impossible\n");
            exit(EXIT_FAILURE);
        }
        li->length=0;
        li->begin=element;//ici l'element qu'on vient de creer est en meme temps premier et dernier element c'est pour cette raison que begin=element te end=element
        li->end=element;
    }
    else
    {
        li->end->next=element; //le pointeur next de l'element qu'on viens de creer pointe sur le dernier element de la liste precedente
        element->back=li->end;  //le pointeur back de l'element qu'on viens de creer pointe sur le end de l'ancien dernier element de l'ancienne liste autrement dit l'avant dernier element de la nouvelle liste
        li->end=element; //le dernier element de la liste est belle et bien l'element que nous avons ajouter en fin de liste
    }
    
    li->length++;
    return li;
    }

//*************************************************************************************//
//cette fonction permet d'ajouter un element en debut de la liste
ListeD liste_push_front_liste(ListeD li,int x){
    ListeNode *element; //ici on cree l'element a inserer dans la liste
    element=malloc(sizeof(*element));
    if (element==NULL)
    {
        fprintf(stderr,"Error :Allocation impossible\n");
        exit(EXIT_FAILURE);
    }
    element->value=x;
    element->next=NULL;  //ici les pointeur next ne pointe encore sur rien dont il est initialiser a NULL
    element->back=NULL;   //ici les pointeur back ne pointe encore sur rien dont il est initialiser a NULL
    if (listeD_isempty(li))
    {
        li=malloc(sizeof(*li));
        if (li==NULL)
        {
            fprintf(stderr,"Error :Allocation impossible\n");
            exit(EXIT_FAILURE);
        }
        li->length=0;
        li->begin=element;//ici l'element qu'on vient de creer est en meme temps premier et dernier element c'est pour cette raison que begin=element te end=element
        li->end=element;
    }
    else
    {
        li->begin->back=element;//le pointeur back de l'element qu'on viens de creer pointe sur le debut(begin) de la liste precedente
        element->next=li->begin; //le pointeur next de l'element qu'on viens de creer pointe sur  l'ancien premier element de l'ancienne liste autrement dit le  deuxieme element de la nouvelle liste
        li->begin=element;//le premier element de la liste est belle et bien l'element que nous avons ajouter en debut de liste
    }
    
    li->length++;
    return li;
    }

//*************************************************************************************//
//cette fonction permet d'ajouter un element en milieu de la liste
ListeD liste_push_medium_liste(ListeD li,int x,int val){//ici l'element est ajouter apres la valeur val
    ListeNode *element; //ici on cree l'element a inserer dans la liste
    element=malloc(sizeof(*element));
    if (element==NULL)
    {
        fprintf(stderr,"Error :Allocation impossible\n");
        exit(EXIT_FAILURE);
    }
    element->value=x;
    element->next=NULL;  //ici les pointeur next ne pointe encore sur rien dont il est initialiser a NULL
    element->back=NULL;   //ici les pointeur back ne pointe encore sur rien dont il est initialiser a NULL
    if (listeD_isempty(li))
    {
        li=malloc(sizeof(*li));
        if (li==NULL)
        {
            fprintf(stderr,"Error :Allocation impossible\n");
            exit(EXIT_FAILURE);
        }
        li->length=0;
        li->begin=element;//ici l'element qu'on vient de creer est en meme temps premier et dernier element c'est pour cette raison que begin=element te end=element
        li->end=element;
    }
    else
    {   ListeNode *temp=li->begin;//cette variable temporaire vas nous permettre de parcourrie toute laliste et nous eviter de boujer le pointeru beging ou end***
        
        while (temp != NULL && temp->value != val) {
        temp = temp->next;
        }   
        if (temp == NULL) {
        // Aucun élément de valeur 6 trouvé dans la liste
        printf("Position non trouver\n");
        free(element); // Libérer la mémoire allouée à l'élément
        return li; // Ou retourner NULL ou une erreur
        }
        // Insérer l'élément après l'élément de valeur 6 trouvé
        element->next = temp->next;
        element->back = temp;
        if (temp->next != NULL) {
           temp->next->back = element;
        }
        temp->next = element;
    }
    
    li->length++;
    return li;
    }

//*************************************************************************************//
//cette fonction permet d'ajouter un element en milieu de la liste
ListeD liste_push_medium_liste1(ListeD li,int x1,int val1){//ici l'element est ajouter apres la valeur val
    ListeNode *element; //ici on cree l'element a inserer dans la liste
    element=malloc(sizeof(*element));
    if (element==NULL)
    {
        fprintf(stderr,"Error :Allocation impossible\n");
        exit(EXIT_FAILURE);
    }
    element->value=x1;
    element->next=NULL;  //ici les pointeur next ne pointe encore sur rien dont il est initialiser a NULL
    element->back=NULL;   //ici les pointeur back ne pointe encore sur rien dont il est initialiser a NULL
    if (listeD_isempty(li))
    {
        li=malloc(sizeof(*li));
        if (li==NULL)
        {
            fprintf(stderr,"Error :Allocation impossible\n");
            exit(EXIT_FAILURE);
        }
        li->length=0;
        li->begin=element;//ici l'element qu'on vient de creer est en meme temps premier et dernier element c'est pour cette raison que begin=element te end=element
        li->end=element;
    }
    else
    {   ListeNode *temp=li->begin;//cette variable temporaire vas nous permettre de parcourrie toute laliste et nous eviter de bouger le pointeru beging ou end
        
        while (temp != NULL && temp->value != val1) {
        temp = temp->next;
        }   
        if (temp == NULL) {
        // Aucun élément de valeur 6 trouvé dans la liste
        printf("Position non trouver\n");
        free(element); // Libérer la mémoire allouée à l'élément
        return li; // Ou retourner NULL ou une erreur
        }
        // Insérer l'élément avant l'élément de valeur val trouvé
        if (temp==li->begin)
        {    
            element->next=temp;
            temp->back=element;
            li->begin=element;
            element->back=NULL;//******
        }
        else
        {
            element->next=temp;
            element->back=temp->back;
            temp->back->next=element;
            temp->back=element;
            
        }
        
        
    }
    
    li->length++;
    return li;
    }


//*************************************************************************************//
//cette fonction permet de supprimer un element en milieu de la liste
ListeD liste_pop_medium_liste(ListeD li,int val){//ici l'element est supprimer apres la valeur val
    //si la iste est vide
    if (listeD_isempty(li))
    {   printf("Rien a suppreimer la liste est deja vide\n");
        return new_listeD();
    }
    //si la liste comporte un seul element
    if (li->begin==li->end)
    {
        free(li);
        li=NULL;
        return new_listeD();
    }
    //si la liste comporte plus d'un  element
      ListeNode *temp=li->begin;//cette variable temporaire vas nous permettre de parcourrie toute laliste et nous eviter de bouger le pointeru beging ou end***
        while (temp != NULL && temp->value != val) {
        temp = temp->next;
        //li=li->begin->next;
        }   
        if (temp == NULL) {
        // Aucun élément de valeur 6 trouvé dans la liste
        printf("Position non trouver\n");
        // Libérer la mémoire allouée à l'élément
        return li; // Ou retourner NULL ou une erreur
        }
        // suppression de  l'élément après l'élément de valeur val trouvé
        ListeNode *temp1=temp->next;//la varaiable temp1 permet de sauvegarder la valeur de temp->next en d'autre terme la valeur que l'on vas supprimer sera mtn dans temp1
        temp->next=temp1->next;
        if (temp->next != NULL) {
        temp->next->back = temp;//le predececeur du suivant de l'element temps est juste encore egale a temp
        }
        temp1->next=NULL;//ici on coupe le lien que cet element avais avec la liste
        temp1->back=NULL;
        free(temp1);
        temp1=NULL;
        li->length--;
        return li;
    }



    //*************************************************************************************//
//cette fonction permet de supprimer un element en milieu de la liste
ListeD liste_pop_medium_liste1(ListeD li,int val){//ici l'element est supprimer avant la valeur val
    //si la iste est vide
    if (listeD_isempty(li))
    {   printf("Rien a suppreimer la liste est deja vide\n");
        return new_listeD();
    }
    //si la liste comporte un seul element
    if (li->begin==li->end)
    {
        free(li);
        li=NULL;
        return new_listeD();
    }
    //si la liste comporte plus d'un  element
      ListeNode *temp=li->begin;//cette variable temporaire vas nous permettre de parcourrie toute laliste et nous eviter de bouger le pointeru beging ou end***

        // suppression de  l'élément après l'élément de valeur val trouvé
        //si le deuxieme element de la liste a la valeur specifier alors on vas juste supprimer le premier element de la liste
        if (temp->next != NULL && temp->next->value == val) {
        ListeNode *temp1 = temp;//la varaiable temp1 permet de sauvegarder la valeur de temp->next en d'autre terme la valeur que l'on vas supprimer sera mtn dans temp1
        li->begin = temp->next;
        temp->next->back = NULL;
        free(temp1);
        li->length--;
        return li;
        //li=liste_pop_front_liste(li);
        }  
        while (temp != NULL && temp->value != val) {
        temp = temp->next;
        }   
        if (temp == NULL) {
        // Aucun élément de valeur 6 trouvé dans la liste
        printf("Position non trouver\n");
        // Libérer la mémoire allouée à l'élément
        return li; // Ou retourner NULL ou une erreur
        }
        /*ListeNode *temp1=temp->next->back;temp est un pointeur vers le nœud actuel dans la liste. temp->next: C'est un pointeur vers le prochain nœud dans la liste après temp
        temp->next->back:C'est un pointeur vers le nœud précédent dans la liste par rapport au nœud temp->next
        Donc, lorsque nous utilisons temp->next->back, cela signifie que nous accédons au pointeur back du nœud suivant dans la liste par rapport au nœud temp.
        */
       //*****------*****
       /*
        ListeNode *temp1=temp->next->back;
        temp->next->back=temp1->back;     
        if (temp1->back != NULL) {
        temp1->back->next = temp->next;
        }*/
        //******-----******
        ListeNode *temp1=temp->back;
        temp=temp1->back->next;
        if (temp1->back != NULL) {
        temp1->back->next = temp->next;
        }
        temp1->next=NULL;//ici on coupe le lien que cet element avais avec la liste
        temp1->back=NULL;
        free(temp1);
        temp1=NULL;
        li->length--;
        return li;
    }

//*************************************************************************************//
//cette fonction permet de retirer un element en fin de la liste
ListeD liste_pop_back_liste(ListeD li){
    //si la iste est vide
    if (listeD_isempty(li))
    {   printf("Rien a suppreimer la liste est deja vide\n");
        return new_listeD();
    }
    //si la liste comporte un seul element
    if (li->begin==li->end)
    {
        free(li);
        li=NULL;
        return new_listeD();
    }
    //si la liste a plusieurs elements
    ListeNode *temp=li->end;//ce parametre vas nous permettre de recuperer le dernier element de la liste que l'on veut supprimer
    li->end=li->end->back;//ici ont a deplacer le pointeur end vers l'avant dernier element de la liste et ont a sauvegarder le dernier elemnet dans temp>
    li->end->next=NULL;//ici on remet a null la fin du pointeur pour boucler la liste
    temp->next=NULL;//ici on coupe le lien que cet element avais avec la liste
    temp->back=NULL;
    free(temp);
    temp=NULL;
    li->length--;
    return li;
}
//*************************************************************************************//
//cette fonction permet de retirer un element en debut de la liste
ListeD liste_pop_front_liste(ListeD li){
    //si la iste est vide
    if (listeD_isempty(li))
    {   printf("Rien a suppreimer la liste est deja vide\n");
        return new_listeD();
    }
    //si la liste comporte un seull element
    if (li->begin==li->end)
    {
        free(li);
        li=NULL;
        return new_listeD();
    }
    //si la liste a plusieurs elements
    ListeNode *temp=li->begin;//ce parametre vas nous permettre de recuperer le premier element de la liste que l'on veut supprimer
    li->begin=li->begin->next;//ici ont a deplacer le pointeur beguin vers le deuxieme element de la liste et ont a sauvegarder le premier elemnet dans temp
    li->begin->back=NULL;//ici on remet a null le debut du pointeur pour boucler la liste
    temp->next=NULL;//ici on coupe le lien que cet element avais avec la liste
    temp->back=NULL;
    free(temp);
    temp=NULL;
    li->length--;
    return li;
}
//*************************************************************************************//
//cette fonction permet de vider de la liste
ListeD clear_liste(ListeD li){
    if (listeD_isempty(li))
    {
        return new_listeD();
    }
    
    while (li!=NULL)
    {
       li=liste_pop_front_liste(li);
    }
}
int sum_elements(ListeD li){
    int sum=0;
    if (listeD_isempty(li))
    {
        return 0;
    }
    ListeNode *temp=li->begin;//cette variable temporaire vas nous permettre de parcourrie toute laliste et nous eviter de boujer le pointeru beging ou end
    while (temp!=NULL)
    {
        sum+=temp->value;
        temp=temp->next;
    }
    return sum;
}




//*************************************************************************************//
//fonction principale(main)
int main(){
    ListeD myliste=new_listeD();
 if(listeD_isempty(myliste))
    printf("La liste est bel et bien vide\n");
 else   
    printf("La liste n'est pas vide\n");
 printf("La liste compte %d elements\n",length_listeD(myliste));
 printf_listeD(myliste);
 myliste=liste_push_front_liste(myliste,14);
 printf("La liste compte %d elements\n",length_listeD(myliste));
 printf_listeD(myliste);
 myliste=liste_push_back_liste(myliste,6);
 myliste=liste_push_front_liste(myliste,23);
  myliste=liste_push_back_liste(myliste,20);
 printf("La liste compte %d elements\n",length_listeD(myliste));
 printf_listeD(myliste);
 myliste=liste_push_medium_liste(myliste,8,6);
 myliste=liste_push_medium_liste1(myliste,12,6);
 myliste=liste_push_medium_liste(myliste,10,23);
 printf_listeD(myliste);
 printf("La liste compte %d elements\n",length_listeD(myliste));
 printf("La somme des elements de la liste est de : %d \n",sum_elements(myliste));
 printf("Le premier element de la liste est de : %d \n",first_element_list(myliste));
 printf("Le dernier element de la liste est de : %d \n",last_element_list(myliste));
 myliste=liste_pop_medium_liste(myliste,12);
 //myliste=liste_pop_back_liste(myliste);
 printf("La liste compte %d elements\n",length_listeD(myliste));
 printf_listeD(myliste);
 myliste=liste_pop_medium_liste1(myliste,14);
 printf("La liste compte %d elements\n",length_listeD(myliste));
 printf_listeD(myliste);
 myliste=clear_liste(myliste);
 printf("La liste compte %d elements\n",length_listeD(myliste));
 printf_listeD(myliste);

    return 0;
}
