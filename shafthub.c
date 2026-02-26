/*
shafthub.c
ouk 202602
format: dShaftDia +tol -tol DHubDia +tol -tol
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	float shaftDia, hubDia;
	float shaftUpperTol, shaftLowerTol;
	float hubUpperTol, hubLowerTol;
	
	if  (argc != 7){
		printf("\ninvaid input");
		printf("Correct format: dShaftDia +tol -tol DHubDia +tol -tol");
		return 0;
	}
	
	sscanf(argv[1], "%f", &shaftDia);
	sscanf(argv[4], "%f", &hubDia);
	
	printf("\n\tSaft Dia [mm]\t: %0.4f", shaftDia );
	printf("\n\tHub Dia [mm]\t: %0.4f", hubDia );
	
	return 0;	
}