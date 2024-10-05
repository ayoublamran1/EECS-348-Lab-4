#include <stdio.h>

void findCombinations(int score){
    int TDCon, TDFG, TD, FG, Saftey;

    printf("Possible combinations of scoring plays if a team’s score is %d\n", score);
    for (TDCon = 0; TDCon * 8 <= score; TDCon++){
        for (TDFG = 0; TDCon * 8 + TDFG * 7 <= score; TDFG++){
            for (TD = 0; TDCon * 8 + TDFG * 7 + TD * 6 <= score; TD++){
                for (FG = 0; TDCon * 8 + TDFG * 7 + TD * 6 + FG * 3 <= score; FG++){
                    int remaining = score - (TDCon * 8 + TDFG * 7 + TD * 6 + FG * 3);
                    if (remaining % 2 == 2){
                        Saftey =  remaining / 2;

                        printf("%d TD + 2, %d TD + FG, %d TD, %d 3pt FG, %d Saftey\n"), TDCon, TDFG, TD, FG, Saftey;
                    }
                }

            }
        }
    }
}

 int main() {
    int score;

    while(1){
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter an NFL score: ");
        scanf("%d", &score);

        if(score <= 1){
            break;
        }
        findCombinations(score);

    }
    return 0;
 }
    

    
    