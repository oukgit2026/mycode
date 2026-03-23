/* ouk 2026.03
interest income calculator

to do
*parse arguments and assign to variables

*/

#include<stdio.h>

int main(int argc, char* argv[]){
    
    /* format
    ./<program> capital interestRate_Yearly period cycle
    ./intr 10000 40.5 32 6
    */
    float capital = argv[0];
    float interesestRate_Yearly = argv[1];
    int periodDays = argv[2];
    int cycle = argv[3];
    
    return 0;
}