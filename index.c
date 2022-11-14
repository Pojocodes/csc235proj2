#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

const char *changeCase(char *word ){
    int length = strlen(word);
    for(int i = 0; i<length; i++){
        word[i] = toupper(word[i]);
    }
    
}

int countSteps(char *steps){
    int step = 0;
    int length = strlen(steps);
    for(int i = 0; i < length; i++){
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
    FILE *fh_input;
    fh_input = fopen("ada.txt","r");// open the file for writing
    char finput[100];
    bool x = false;
    char buf[100];
    if(fh_input != NULL){
        fgets(buf, 100, fh_input);
        while(fscanf(fh_input, "%s", finput) != EOF){
            changeCase(finput);
            printf("%s = %d trials\n", finput,countSteps(finput));
            x = true;
        }
    }
    
    else {
        
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