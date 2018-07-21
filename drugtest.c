// Zachary Keeley drugtest.c program // 21 october 2016

#include <stdio.h>
#include <stdlib.h>

void tallyResults(int numbers[], int numElements){ // function to count the amount of times each percentage appears in the array
    int i, n, tally, count[100];

    for (i=0; i<numElements;i++ ){ // loop to be executed 200 time
        count[numbers[i]]++; // adds the amount of times each number appears to the 'count' array
    }
    for (i=0; i<101;i++){ // this loop prints the amount of times each number appears
        printf("%d%% appears %d times.\n", i, count[i]);
    }
}

void displayResults(int numbers[], int numElements){ // takes the array and the length of the array as parameters, prints the vales stored in the array
    int i, j, n, count[101]={};
    for (i=0; i<numElements;i++ ){ // loop to be executed 200 time
        count[numbers[i]]++; // adds the amount of times each number appears to the 'count' array
    }
    printf("Results\n"); // header for the results
    printf("\n");
    printf("%%    Number of Cases\n");
    printf("----------------------\n"); // end header
    for (i=0; i<101;i++){ // this loop prints the amount of times that each percent appears
        printf("%d%%  %d\n", i, count[i]);
    }
}

void getMaxLeft(int numbers[], int numElements){ // array and size as parameters, returns the mode of the set of numbers
    int i, max=0, count[100]={};

    for (i=0; i<numElements;i++ ){ // loop to be executed 200 time
        count[numbers[i]]++;// adds the amount of times each number appears to the 'count' array
    }
    for(i=0; i<101; i++){
        if(count[i]>max){ // sets the greatest value found in the count array as max
            max = count[i];
        }
    }
    printf("The maximum number of cases - %d had %d%% left\n",max,numbers[count[max]]);
}


int getAverageLeft(int numbers [], int numElements){ // averaging the array
    int average, total, i;
    for(i=0; i<numElements; i++){
        total = numbers[i] + total;
    }
    average = (total/numElements); // sum of all the values divided by the number of values
    return average; // returns the average
}

void getNumSamples(int numbers[], int numElements, int p){ //returns the number of times that a called upon value appears in the array
    int i, max=0, count[100]={};

    for (i=0; i<numElements;i++ ){ // loop to be executed 200 time
        count[numbers[i]]++; // adds the amount of times each number appears to the 'count' array
    }
    printf("There were %d cases with %d%% of the cells left.", count[p], p);
}

int main(void){

    int numElements = 200, p, max;
    FILE *results; // this is the file pointer that points to the file name
    int i=0;

    results = fopen("results.txt", "r"); // opening our file
    int numbers[numElements];
    int num;
    while(fscanf(results, "%d", &num) > 0){  //reading the file and adding the numbers to an array
        numbers[i] = num;
        i++;
    }

    fclose(results); // closing our file
    displayResults(numbers, numElements); // prints the values stored in the file as a table

    float av = getAverageLeft(numbers, numElements); // function call to get average of all the percents
    printf("the average %% of cells left is %.2f\n", av);

    getMaxLeft(numbers, numElements); // displays which percent had the maximum number of appearances

    printf("For what percent would you like to find the number of cases?\n");
    scanf("%d", &p);
    getNumSamples(numbers, numElements,p); // function call to allow the user to know the amount of cells left for an entered percentage
return 0;
}
