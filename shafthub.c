/*
shafthub.c
./shafthub 18.45 0 -0.05 18.40 0.01 -0
ouk 202602
format: dShaftDia +tol -tol DHubDia +tol -tol
*/

//./shafthub 18.45 0 -0.05 18.40 0.01 -0

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	    // check command line arguments format
        if  (argc != 7){
                printf("\ninvaid input");
                printf("Correct format: dShaftDia +tol -tol DHubDia +tol -tol");
                return 0;
        }
	
	    // variables
        float shaftDia, hubDia;
        float shaftUpperTol, shaftLowerTol;
        float hubUpperTol, hubLowerTol;
        
        float shaftDiaMax, shaftDiaMin;
        float hubDiaMax, hubDiaMin;
        
        float interfererenceMax, interferenceMin;
        float clearenceMax, clearenceMin;
        
        bool interferenceFit, clearenceFit, transitionalFit; 
        
                
        // assign argumenta to variables
        sscanf(argv[1], "%f", &shaftDia);
        sscanf(argv[4], "%f", &hubDia);
        sscanf(argv[2], "%f", &shaftUpperTol);
        sscanf(argv[3], "%f", &shaftLowerTol);
        sscanf(argv[5], "%f", &hubUpperTol);
        sscanf(argv[6], "%f", &hubLowerTol);
        
        // shaft diameter min & max value
        shaftDiaMax = shaftDia + shaftUpperTol;
        shaftDiaMin = shaftDia + shaftLowerTol;
        
        // hub diameter min & max value
        hubDiaMax = hubDia + hubUpperTol;
        hubDiaMin = hubDia + hubLowerTol;
        
        // check fit type
        if(shaftDiaMin >= hubDiaMax){
        	interferenceFit = true;
        }
        else if(hubDiaMin >= shaftDiaMax){
        	clearenceFit = true;
        }
        else{
        	transitionalFit = true;
        }
        
        // print calculations in pretty format
        printf("\nShaft Dia [mm]\t: %0.4f (%0.4f / %0.4f)", shaftDia, shaftUpperTol, shaftLowerTol );
        printf("\nHub Dia [mm]\t: %0.4f (%0.4f / %0.4f)", hubDia, hubUpperTol, hubLowerTol );
        printf("\n");

        return 0;        
}