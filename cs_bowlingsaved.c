
// Assignment 0
// cs_bowling.c
// This program was written by Kara Mckinney (z5418203)
// on 28/2/22
// This program simulates bowling

#include <stdio.h>
#define LOOP 10

int main (void){
    printf("Welcome to CS Bowling!\n");
    
    int bowl_one;
    int bowl_two;
    int count = 0;
    int frame_number = 1;
    int total_score = 0;
    int spare_flag = 0;
    int strike_flag = 0;

    while (count < LOOP) {
        int final_score = 0;

        printf("Frame %d, Bowl 1: ", frame_number);
        scanf("%d", &bowl_one);

        if (bowl_one == 10) {
            printf("Score for Frame: 10\n");
            printf("Strike! Bonus for this frame is next two rolls.\n");
            final_score += 10; 
            strike_flag = 1;
            if (spare_flag == 1) {
                total_score += bowl_one;
                spare_flag = 0;
            }

        } else {
        
            if (bowl_one < 0 || bowl_one > 10) {
                printf("Bowl 1 invalid!\n");
                bowl_one = 0;
            }
        
            printf("Frame %d, Bowl 2: ", frame_number);
            scanf("%d", &bowl_two); 

            int score = bowl_one + bowl_two;
            if (score < 0 || score > 10) {
                printf("Bowl 2 invalid!\n");
                bowl_two = 0;
            }

            final_score = bowl_one + bowl_two;
        
            if (spare_flag == 1) {
                total_score += bowl_one;
                spare_flag = 0;
            }

            if (strike_flag == 1) {
                total_score += (bowl_one + bowl_two);
                strike_flag = 0;
            } 

            printf("Score for Frame: %d\n", final_score);
            if (final_score == 10) {
                printf("Spare! Bonus for this frame is next roll.\n");
                spare_flag = 1;
            }

        }

        total_score = total_score + final_score;
        count += 1; 
        frame_number += 1;
       
    }
   
    int final_score = bowl_one + bowl_two;

    if (bowl_one == 10 || final_score == 10) {
        int bonus_bowl = 0;
        printf("Bonus Bowl 1: ");
        scanf("%d", &bonus_bowl);
    
        if (bonus_bowl < 0 || bonus_bowl > 10) {
            printf("Bonus Bowl Invalid!\n");

        } else {
            total_score += 2 * bonus_bowl;
        }
     
    }

    printf("Total Score: %d\n", total_score);

    return 0;

}