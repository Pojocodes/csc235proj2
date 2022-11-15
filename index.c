#include <stdio.h>
#include <string.h>
#include <ctype.h>

//  a function to make all the case upper i.e("UUUDDD")
const char *changeCase(char *word ){
    int length = strlen(word);
    for(int i = 0; i<length; i++){
        word[i] = toupper(word[i]);   // this makes it upper case
    }
    
}

// A function to check how many times adam goes up
int countSteps(char *steps){
    int step = 0;
    int length = strlen(steps);   // find the length of the array
    for(int i = 0; i < length; i++){  // a loop to count how many times adam goes up before he comes down
        if(steps[i] == 'U'){
            step+=1;
        }
        else if (steps[i] =='D'){
            break;
        }
        else {
            printf("There must be an error in the input\n");
            break;
        }
    }
    return step;
}



int main() {
    FILE *fh_input;   //create the input file
    fh_input = fopen("adam.txt","r");// open the file for writing
    char finput[100];
    char buf[100];
    if (fh_input != NULL) {        // if the file path is correct
        fgets(buf, 100, fh_input);
        while(fscanf(fh_input, "%s", finput) != EOF){
            changeCase(finput);
            printf("%s = %d trials\n", finput,countSteps(finput));
        }
    }
    
    else {  //  else the program would collect input from the console
        int length;
        printf("put the maximum no:\n");
        scanf("%d", &length);
        for(int i = 0; i<length; i++){
            char user_input[100];
            printf("Enter the user input:\n");
            scanf(" %[^\n]%*c", user_input);
            printf("\n");
            changeCase(user_input);
            printf("%s = %d trials\n", user_input, countSteps(user_input));
        }
    }
    return 0;
}