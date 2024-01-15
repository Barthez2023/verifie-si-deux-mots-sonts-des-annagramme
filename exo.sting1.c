#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
bool polindrome_number(int n){
   int i,a,k=0,b;
    b=n;
    while(n!=0){
        a=n;
        n=n/10;
        i=a-(n*10);
        k=k*10+i;
    }
    if(b==k)
        return true;
    else 
        return false;
    /*
    int i,a,k=0,b;
    b=n;
    while(n!=0){
        a=n;
        n=n/10;
        i=a-(n*10);
        k=k*10+i;
    }
    return k==b;*/
}

char* reverse(char word[]){
    
    char *word1;
    int i,j=0,n;
    n=strlen(word);
    word1=malloc(sizeof(char)*(n+1));
    for(i=n-1;i>=0;i--){
        word1[j]=word[i];
        j++;
    }
    word1[j]='\0';
    return word1;
}
bool annagrame(char word[],char word2[]){
    int n,i,j=0;
    n=strlen(word);
    if(strlen(word)!=strlen(word2))
        return false;
    else{
        for(i=0;word[i]!='\0';i++){
            if(strchr(word2,word[i])!=NULL)
                j=1;
            else{
                j=0;
                break;
            }
                
        }
        if(j==1)
            return true;
        else
            return false;

    }

}
/*void reverse(char word[]){
    
    char word1[50];
    int i,j=0,n;
    n=strlen(word);
    for(i=n-1;i>=0;i--){
        word1[j]=word[i];
        j++;
    }
    word1[j]='\0';
     printf("%s",word1);

}*/

int main(){
    int n;
    char word[50];
    char word1[50];
    char word2[50];
    //printf("enter the number: ");
    //scanf("%d",&n);
    //if(polindrome_number(n))
   //     printf("%d is a polindrome number\n",n);
    //else
    //    printf("%d is not a polindrome number\n",n);
    printf("enter the word: ");
    gets(word);
    //reverse(word);
    printf("%s\n",reverse(word));
    
    printf("Entrez le premier mot : ");
    scanf("%s", word1);

    printf("Entrez le deuxieme mot : ");
    scanf("%s", word2);

    if (annagrame(word1, word2)) {
        printf("%s et %s sont des anagrammes.\n", word1, word2);
    } else {
        printf("%s et %s ne sont pas des anagrammes.\n", word1, word2);
    }
    return 0;
}