//ce code donne tout les element d(une suite de Fibonnaci jusau'au terme entrer
#include<stdio.h>
#include<stdlib.h>
int fibonacci(int n){
	if(n<2)
        return 1;
    return  fibonacci(n-1)+fibonacci(n-2);
	
}
int fibonacci1(int n){
	int terme0=1,terme1=1,temp=0,i=1;
	if(n<2)
        return 1;
    while(n>i){
    	temp=terme0+terme1;
    	terme0=terme1;
    	terme1=temp;
    	i++;
	}
	return terme1;
}

int main (){
	int *T,n,i=0,m=0;
	printf("entrer le dernier indice de la suite de fibonnaci:");
	scanf("%d",&n);
	T=(int*)malloc(sizeof(int) * n);   
	if(T==NULL)
	    printf("allocation echoue\n");
	T[0]=1;
	T[1]=1;
	i=2;
	m=2;
	while(m!=n){
		T[i]=fibonacci1(m);
		i++;
	    m++;
	}
	for(i=0;i<n;i++){
		printf("%d ",T[i]);
	}
	
	
	//printf("%d \n",fibonacci(40));
	//printf("%d",fibonacci1(11));
	
	
	
	return 0;
}

