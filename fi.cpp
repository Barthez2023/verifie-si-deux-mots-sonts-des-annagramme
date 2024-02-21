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
	
	//printf("%d \n",fibonacci(40));
	printf("%d",fibonacci1(11));
	
	
	
	return 0;
}

