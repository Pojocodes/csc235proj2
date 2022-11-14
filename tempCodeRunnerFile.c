#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
        }
    }
    return step;
}

int main() {
    FILE *fh_output;
    fh_output = fopen("new.txt","w");// open the file for writing
    fputs("i created a file\n",fh_output);
    fputs("this is an output\n",fh_output);
    fputs("i am getting tired\n",fh_output);
    fprintf(fh_output,"this are %d oranges",10)
    fclose(fh_output);
    return 0;
}