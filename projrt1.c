#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define Max 200
typedef struct
{
   int jour ;
   char mois [10] ;
   int annee ;
}Date1;

typedef struct
{
    int no_rue ;
    char rue [100] ;
    int code_postal ; 
    char ville [30] ; 
    char pays [30] ;
}Adress;

typedef struct 
{
    long CNE;
    char nom [30] ;
    char prenom [30] ;
    Date1 date_naiss;
    Adress ads ;
   char email [30] ;
   char phone [14] ;
   char site_web [30] ;
}Etudiant;
void lecture_etudiant(Etudiant etudiant1[], int n){
    int i;
    for (i=0;i<n;i++)
    {
       printf("Veillez s'il vous plait entrer les coordonnes de l'etudiant No%d\n",i+1);
       printf("Entrer le numero de CNE:");
       scanf("%ld",&etudiant1[i].CNE);
       printf("Entrer le numero le nom:");
       scanf("%s",etudiant1[i].nom);
       printf("Entrer le numero prenom:");
       scanf("%s",etudiant1[i].prenom);
       printf("Entrer la date de naissance:\n");
       printf("Jour de naissance:");
       scanf("%d",&etudiant1[i].date_naiss.jour);
       printf("Mois de naissance:");
       scanf("%s",etudiant1[i].date_naiss.mois);
       printf("Anne de naissance:");
       scanf("%d",&etudiant1[i].date_naiss.annee);
       printf("Veillez entrer les donnes en rapporet avec votre adress:\n");
       printf("N_o de rue:");
       scanf("%d",&etudiant1[i].ads.no_rue);
       printf("Rue:");
       scanf("%s",etudiant1[i].ads.rue);
       printf("Code postal:");
       scanf("%d",&etudiant1[i].ads.code_postal);
       printf("Pays:");
       scanf("%s",etudiant1[i].ads.pays);
       printf("Ville:");
       scanf("%s",etudiant1[i].ads.ville);
       printf("Entrer votre adress mail:");
       scanf("%s",etudiant1[i].email);
       printf("Entrer votre numero de tel:");
       scanf("%s",etudiant1[i].phone);
       printf("Entrer votre site web:");
       scanf("%s",etudiant1[i].site_web);
    }
}
void affichage_etudiant(Etudiant etudiant1[],int n){
    //ici nous allons affichez les etudiants
    int i;
    FILE *f;
    f=fopen("Annuaire.txt", "w");
    if (f==NULL)
    {
        exit(1);
    }
    
    for (i=0;i<n;i++)
    {
        printf("Les coordonnes de l'etudiant No%d\n",i+1);
        fprintf(f,"Les coordonnes de l'etudiant No%d\n",i+1);
        printf("CNE:%ld\n",&etudiant1[i].CNE);
        fprintf(f,"CNE:%ld\n",&etudiant1[i].CNE);
        printf("Nom:%s\n",etudiant1[i].nom);
        fprintf(f,"Nom:%s\n",etudiant1[i].nom);
        printf("Prenom:%s\n",etudiant1[i].prenom);
        fprintf(f,"Prenom:%s\n",etudiant1[i].prenom);
        printf("Date de naissance:%d-%s-%d\n",etudiant1[i].date_naiss.jour,etudiant1[i].date_naiss.mois,etudiant1[i].date_naiss.annee);
        fprintf(f,"Date de naissance:%d-%s-%d\n",etudiant1[i].date_naiss.jour,etudiant1[i].date_naiss.mois,etudiant1[i].date_naiss.annee);
        printf("Adress:Rue No:%d, Nom de la Rue:%s, Code postal:%d, Pays:%s, Ville:%s\n",etudiant1[i].ads.no_rue,etudiant1[i].ads.rue,etudiant1[i].ads.code_postal,etudiant1[i].ads.pays,etudiant1[i].ads.ville);
        fprintf(f,"Adress:Rue No:%d, Nom de la Rue:%s, Code postal:%d, Pays:%s, Ville:%s\n",etudiant1[i].ads.no_rue,etudiant1[i].ads.rue,etudiant1[i].ads.code_postal,etudiant1[i].ads.pays,etudiant1[i].ads.ville);
        printf("Adress mail:%s\n",etudiant1[i].email);
        fprintf(f,"Adress mail:%s\n",etudiant1[i].email);
        printf("Telephone:%s\n",etudiant1[i].phone);
        fprintf(f,"Telephone:%s\n",etudiant1[i].phone);
        printf("Site web:%s\n",etudiant1[i].site_web);
        fprintf(f,"Site web:%s\n",etudiant1[i].site_web);
        printf("\n");
        fprintf(f,"\n");
}
fclose(f);
}
void recuperer_unetudiant(Etudiant etudiant1[],int n){
     FILE *f;
     FILE *fic;
     int i;
     char choix[20];
     char cne[10];
     char texte[255];
    f=fopen("Annuaire.txt", "r");
    fic=fopen("Etudiant_recupere.txt","w");
    if (f==NULL)
    {
        exit(1);
    }
    if (fic==NULL)
    {
        exit(1);
    }
    printf("ici ont vas recuperer un etudiant dans le fichier\n");
    printf("Voulez vous recuperer un etudiant dans le fichier?");
    scanf("%s",choix);
    if (strcmp(choix,"oui")==0)
    {
        printf("Veillez entrer le CNE de l'etudiant recherche:");
        scanf("%s",cne);
         while (fgets(texte,255,f)!=NULL){
            if (strstr(texte,cne)!=NULL)
            {    
                printf("Les coordonnes relatives a l'etudiant dont le CNE est %s sont les suivant:\n",cne);
                fprintf(fic,"Les coordonnes relatives a l'etudiant dont le CNE est %s sont les suivant:\n",cne);
                 printf("%s",texte);
                 fprintf(fic,"%s",texte);
                 while (fgets(texte, 255, f) != NULL && strcmp(texte, "\n") != 0) {
                 printf("%s", texte);
                 fprintf(fic,"%s",texte);
                   }
            }
                 }    
                  }

fclose(f);
fclose(fic);


}

void Modifie_etudiant1(Etudiant etudinat1[],int n){
     FILE *f;
     FILE *fic;
     FILE *fic1;
     char variable[50];
     char choix[20];
     char cne[20];
     int choix1;
     char texte[255];
     int longueur;
    f=fopen("Annuaire.txt", "r");
    fic=fopen("etudiant_modif.txt","w");
    fic1=fopen("Annuaire1.txt","w");
    if (f==NULL)
    {
        exit(1);
    }
    if (fic==NULL)
    {
        exit(1);
    }
    if (fic1==NULL)
    {
        exit(1);
    }
    while (fgets(texte,255,f)!=NULL){
        fprintf(fic1,"%s",texte);
    }
    rewind(f);
    printf("ici ont vas modifier un etudiant dans le fichier\n");
    printf("Voulez vous modifier un etudiant dans le fichier?");
    scanf("%s",choix);
    if (strcmp(choix,"oui")==0)
    {
        printf("Veillez entrer le CNE de l'etudiant recherche:");
        scanf("%s",cne);
        printf("1=nom,2=prenom,3=jour de naissance,4=mois de naissance,5=annee de naissance,6=numero de rue,7=nom de la rue,8=code postal,9=pays,10=ville,11=adress mail,12=telephone,13=site web\n");
        printf("Que voulez vous modifiez?:");
        scanf("%d",&choix1);

        if (choix1==1)
        {
            printf("Veillez entrer le nouveau nom:");
            scanf("%s",variable);
            while (fgets(texte,255,f)!=NULL){
                if (strstr(texte,cne)==NULL)//tant que l'on n'a pas encore atteind le cne recherche on recopie tous les elements dans un autre fichier 
                {
                    fprintf(fic,"%s",texte); 
                }
            else{
                if(strstr(texte,cne)!=NULL)
             {
                fprintf(fic,"%s",texte); 
                fprintf(fic,"Nom:%s",variable);
                //fgets(texte,255,f);
                //longueur=strlen(texte);
                //fseek(f,(longueur-1),SEEK_CUR);
                fgets(texte,255,f);
                fseek(f,-1,SEEK_CUR);
                while (fgets(texte, 255, f) != NULL) {
                fprintf(fic,"%s",texte);
                   }
            }
                 }  
                 }  
         }  

        /*
        if (choix1==3)
        {
            char variable2[20],variable2[20];
            printf("Veillez entrer le nouveau jour de naissance:");
            scanf("%s",variable);
            while (fgets(texte,255,f)!=NULL){
            if (strstr(texte,"Les coordonnes de l'etudiant")!=NULL)
            {
                fprintf(fic,"%s",texte); 
            }
            
            else {
                if(strstr(texte,cne)!=NULL)
             {
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 

                


                fprintf(fic,"Prenom:%s",variable);
                fseek(f,12,SEEK_CUR);
                while (fgets(texte, 255, f) != NULL) {
                fprintf(fic,"%s",texte);
                   }
            }
                 }  
                 }  
        }*/


        if (choix1==2)
        {
            printf("Veillez entrer le nouveau prenom:");
            scanf("%s",variable);
            while (fgets(texte,255,f)!=NULL){
            if (strstr(texte,cne)==NULL)
            {
                fprintf(fic,"%s",texte); 
            }
            
            else {
                if(strstr(texte,cne)!=NULL)
             {
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fprintf(fic,"Prenom:%s",variable);
                //fgets(texte,255,f);    //ici je recupere la ligne de la variable dont on veut modifier dans le texte 
                //longueur=strlen(texte);  // je determine la longueuer de la ligne dont ont veut modifier dans le texte
                //fseek(f,(longueur-1),SEEK_CUR);  //je deplace mon curceur en fonction de la longueur de ma ligne
                fgets(texte,255,f);
                fseek(f,-2,SEEK_CUR);
                while (fgets(texte, 255, f) != NULL) {
                fprintf(fic,"%s",texte);
                   }
            }
                 }  
                 }  
        }

        if (choix1==11)
        {
            printf("Veillez entrer la nouvelle adress mail:");
            scanf("%s",variable);
            while (fgets(texte,255,f)!=NULL){
            if (strstr(texte,cne)==NULL)
            {
                fprintf(fic,"%s",texte); 
            }
            
            else {
                if(strstr(texte,cne)!=NULL)
             {
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fprintf(fic,"Adress mail:%s",variable);
                //fgets(texte,255,f);    //ici je recupere la ligne de la variable dont on veut modifier dans le texte 
                //fseek(f,(longueur-1),SEEK_CUR);  // je determine la longueuer de la ligne dont ont veut modifier dans le texte
                //fseek(f,longueur,SEEK_CUR);  //je deplace mon curceur en fonction de la longueur de ma ligne
                fgets(texte,255,f);
                fseek(f,-1,SEEK_CUR);
                while (fgets(texte, 255, f) != NULL) {
                fprintf(fic,"%s",texte);
                   }
            }
                 }  
                 }  
        }


      if (choix1==12)
        {
            printf("Veillez entrer le nouveau numero de telephone:");
            scanf("%s",variable);
            while (fgets(texte,255,f)!=NULL){
            if (strstr(texte,cne)==NULL)
            {
                fprintf(fic,"%s",texte); 
            }
            
            else {
                if(strstr(texte,cne)!=NULL)
             {
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fprintf(fic,"Telephone:%s",variable);
                //fgets(texte,255,f);    //ici je recupere la ligne de la variable dont on veut modifier dans le texte 
                //fseek(f,(longueur-1),SEEK_CUR);  // je determine la longueuer de la ligne dont ont veut modifier dans le texte
                //fseek(f,longueur,SEEK_CUR);  //je deplace mon curceur en fonction de la longueur de ma ligne
                fgets(texte,255,f);
                fseek(f,-1,SEEK_CUR);
                while (fgets(texte, 255, f) != NULL) {
                fprintf(fic,"%s",texte);
                   }
            }
                 }  
                 }  
        }
       

       if (choix1==13)
        {
            printf("Veillez entrer le nouveau site web:");
            scanf("%s",variable);
            while (fgets(texte,255,f)!=NULL){
            if (strstr(texte,cne)==NULL)
            {
                fprintf(fic,"%s",texte); 
            }
            
            else {
                if(strstr(texte,cne)!=NULL)
             {
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fgets(texte,255,f);
                fprintf(fic,"%s",texte);
                fgets(texte,255,f);
                fprintf(fic,"%s",texte); 
                fprintf(fic,"Site web:%s",variable);
                fgets(texte,255,f);
                fseek(f,-1,SEEK_CUR);
                while (fgets(texte, 255, f) != NULL) {
                fprintf(fic,"%s",texte);
                   }
            }
                 }  
                 }  
        }


        /*
        printf("Veillez entrer le nouveau nom:");
        scanf("%s",nom);
        while (fgets(texte,255,f)!=NULL){
            if (strstr(texte,"Les coordonnes de l'etudiant")!=NULL)
            {
                fprintf(fic,"%s",texte); 
            }
            
            else {
                if(strstr(texte,cne)!=NULL)
             {
                fprintf(fic,"%s",texte); 
                fprintf(fic,"Nom:%s",nom);
                fseek(f,8,SEEK_CUR);
                while (fgets(texte, 255, f) != NULL) {
                fprintf(fic,"%s",texte);
                   }
            }
                 }  
                 }  

 */



 }
 
 fclose(f);
 fclose(fic);
 remove("Annuaire.txt");
 rename("etudiant_modif.txt" , "Annuaire.txt");

}
void supprimer_etudiant1(Etudiant etudinat1[],int n){
     FILE *f;
     FILE *fic;
     FILE *fic1;
     FILE *fic2;
     char variable[50];
     char choix[20];
     char cne[20];
     int choix1;
     char texte[255];
     int longueur;
    f=fopen("Annuaire.txt", "r");
    fic=fopen("Annuaire1.txt","r");
    fic1=fopen("etudiant_supp.txt","w");
    fic2=fopen("etudiant_supp1.txt","w");
   
    if (f==NULL)
    {
        exit(1);
    }
    if (fic==NULL)
    {
        exit(1);
    }
    if (fic1==NULL)
    {
        exit(1);
    }
    if (fic2==NULL)
    {
        exit(1);
    }
    printf("ici ont vas supprimer un etudiant dans le fichier\n");
    printf("Voulez vous supprimer un etudiant dans le fichier?");
    scanf("%s",choix);
    if (strcmp(choix,"oui")==0)
    {
        printf("Veillez entrer le CNE de l'etudiant a supprimer:");
        scanf("%s",cne);
        while (fgets(texte,255,f)!=NULL){
                if (strstr(texte,cne)!=NULL)
                {
                    while (fgets(texte, 255, f) != NULL && strcmp(texte, "\n") != 0) {
                        //cette boucle me permet de deplacer le curceur et de la mettre a la prochaine ligne apres le sut a la ligne
                        }
                        while (fgets(texte,255,f)!=NULL){
                            fprintf(fic1,"%s",texte);

                        }
                }
                else
                {
                   fprintf(fic1,"%s",texte);

                }
                
                
        }


        while (fgets(texte,255,fic)!=NULL){
                if (strstr(texte,cne)!=NULL)
                {
                    while (fgets(texte, 255, fic) != NULL && strcmp(texte, "\n") != 0) {
                        //cette boucle me permet de deplacer le curceur et de la mettre a la prochaine ligne apres le sut a la ligne
                    }
                        while (fgets(texte,255,fic)!=NULL){
                            fprintf(fic2,"%s",texte);

                        }
                }
                else
                {
                   fprintf(fic2,"%s",texte);

                }    
        }
        
        
    }
 fclose(f);
 fclose(fic);
 fclose(fic1);
 fclose(fic2);
 remove("Annuaire.txt");//je supprime les anciens fichiers 
 remove("Annuaire1.txt");
 rename("etudiant_supp.txt" , "Annuaire.txt");//je renome les fichier avec les noms des anciens fichier pour avoir l'impression de n'avoir rien changer
 rename("etudiant_supp1.txt" , "Annuaire1.txt");
}









int main (){
    //Nous allons ecrire un programme qui permet d'enreigister les etudiants :
    Etudiant *etudiant;
    int i,n;
    etudiant=(Etudiant*)malloc(sizeof(Etudiant)*Max);
    if (etudiant==NULL)
    {
        exit(1);
    }
    //printf("combien d'etudinat voulez vous enreigistre:");
    //scanf("%d",&n);
    //lecture_etudiant(etudiant,n);
    //affichage_etudiant(etudiant,n);
    recuperer_unetudiant(etudiant,n);
    //Modifie_etudiant1(etudiant,n);
    supprimer_etudiant1(etudiant ,n);
    
    free(etudiant);
    return 0;
    }


