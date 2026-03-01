/*
shafthub.c
./shafthub 18.45 0 -0.05 18.40 0.01 -0
ouk 202602
format: dShaftDia +tol -tol DHubDia +tol -tol
*/

/* default cmd line arguments for test:

./shafthub 18.65 0 -0.05 18.40 0.01 -0
  
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	// Display Info
	printf("\n======================="
	       "\nShaft & Hub Fit Calculator v0.1"
	       "\n=======================\n");
	
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
        
        float interferenceMax, interferenceMin;
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
        
        // check fit type,calculate interference and/clearence
        
        interferenceFit = false;
        clearenceFit = false;
        transitionalFit = false;
        
        if(shaftDiaMin > hubDiaMax){
        	interferenceFit = true;
        	interferenceMax = shaftDiaMax - hubDiaMin;
        	interferenceMin = shaftDiaMin - hubDiaMax;
        } else if (hubDiaMin > shaftDiaMax) {
        	clearenceFit = true;
        	clearenceMax = hubDiaMax - shaftDiaMin;
        	clearenceMin = hubDiaMin - shaftDiaMax;
        } else {
        	transitionalFit = true;
        	interferenceMax = shaftDiaMax - hubDiaMin;
        	clearenceMax = hubDiaMax - shaftDiaMin;
        	interferenceMin = 0;
        	clearenceMin = 0;
        }
        
        // print calculations
        printf("\nShaft Dia [mm]\t: %0.4f (%0.4f / %0.4f)", shaftDia, shaftUpperTol, shaftLowerTol );
        printf("\n\tMax\t: %0.4f"
               "\n\tMin\t: %0.4f"
               , shaftDiaMax, shaftDiaMin);
        
        printf("\nHub Dia [mm]\t: %0.4f (%0.4f / %0.4f)", hubDia, hubUpperTol, hubLowerTol );
        printf("\n\tMax\t: %0.4f"
               "\n\tMin\t: %0.4f"
               , hubDiaMax, hubDiaMin);
        
        printf("\nFit Type\t:  ");
        if(interferenceFit){
        	printf("Interference fit"
        	       "\n\tInterference Max\t: %0.4f"
        	       "\n\tInterference Min\t: %0.4f"
        	       , interferenceMax, interferenceMin);
        }
        
        if(clearenceFit){
        	printf("Clearence fit"
        	       "\n\tClearence [mm]"
        	       "\n\tMax\t: %0.4f"
        	       "\n\tMin\t: %0.4f"
        	       , clearenceMax,clearenceMin);
        }
        
        if(transitionalFit){
        	printf("Clearence fit"
        	       "\n\tInterference Max [mm]\t:\t%0.4f"
        	       "\n\tClearence Max [mm]\t: %0.4f"
        	       , interferenceMax,clearenceMax);
        }

        return 0;        
}