#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    // Mobile number
    unsigned long long mobile;
    // Random number & error check count
    int r_num, r_num_v, count = 0, v_num;
    // File variable
    FILE *fptr;

    // Get Mobile Number
    printf("Enter a 11 digit mobile number: ");
    scanf("%llu",&mobile);

    // Check if the Mobile Number is 11 Digits
    do { count++; mobile /= 10; }
    while(mobile != 0);

    // Generate 4 digit random number
    r_num = (rand()%9000) + 1000;

    // Saving the random number in the file in write mode
    fptr = fopen("r_num.txt", "w");

    if(fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fptr = fopen("r_num.txt", "w");
    fprintf(fptr, "%d\n", r_num);

    printf("Verification code saved\n",r_num);
    fclose(fptr);

    // Loading the random number from the file
    if ((fptr = fopen("r_num.txt","r")) == NULL){
        printf("Error! Cannot Open file");
        exit(1);
    }

    fscanf(fptr, "%d", &r_num_v);

    printf("Enter Verification Code: ");
    scanf("%d",&v_num);
    if (v_num==r_num_v){
        printf("Verified!!");
    }
    else{
        printf("Error!! Try Again.");
    }
    fclose(fptr);

    return 0;
}
