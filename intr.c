/* ouk 2026.03
interest income calculator

to do
*parse arguments and assign to variables

*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    /* format
    ./<program> capital interestRate_Yearly period cycle
    ./intr 10000 40.5 32 6
    */
    
    // define variables
    float capital;
    float interesestRate_Yearly;
    int periodDays;
    int cycle;
    
    // assign command line arg to variables
    capital = atof(argv[1]);
    interesestRate_Yearly = atof(argv[2]);
    periodDays = atoi(argv[3]);
    cycle = atoi(argv[4]);

    /* debug */
    printf("\n\tcapital\t: %f", capital);
    printf("\n");
    return 0;
}