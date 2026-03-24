/* ouk 2026.03
interest income calculator

to do
DONE parse arguments and assign to variables
× calculate basic interest.
*/

/* argument format
    ./<program> capital interestRate_Yearly period cycle 
    ./intr 10000 40.5 32 6
    
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    
    // define variables
    float capitalBefore, capital;
    float interestRate_Yearly;
    int periodDays;
    int cycle;
    
    float interestBeforeCuts;
    
    // assign command line arg to variables
    capitalBefore = atof(argv[1]);
    interestRate_Yearly = atof(argv[2]);
    periodDays = atoi(argv[3]);
    cycle = atoi(argv[4]);

    /* DEBUG */
    printf("\n\tcapital\t: %.2f", capitalBefore);
    printf("\n\tinterestRate_Yearly\t: %.2f", interestRate_Yearly);
    printf("\n\tperiodDays\t: %d", periodDays);
    printf("\n\tcycle\t: %d", cycle);
    printf("\n");
    
    // calculate basic interest
    // f = (ant)/36000    
    interestBeforeCuts = (capitalBefore * interestRate_Yearly * periodDays) / 36000;
    capital = capitalBefore + interestBeforeCuts;
    
    /* DEBUG */
    printf("\n\tinterestBeforeCuts : %.2f", interestBeforeCuts);
    printf("\n\tNew Capital\t: %.2f", capital);
    printf("\n");
    
    return 0;
}