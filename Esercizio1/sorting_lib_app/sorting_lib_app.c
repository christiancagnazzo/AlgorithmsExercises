#include <stdio.h>
#include <string.h>
#include "sorting_lib.h"
#include <stdlib.h>

#define ERROR_EXIT_CODE 1
#define SIZE 20000000

typedef struct {
    int id;
    char * field_one;
    int field_two;
    float field_three;
 } Record;

 typedef struct {
    char const * file_name;
    SortingLibCmp comparison_fun;
    int algorithm;
 } Options;

void print_usage() {
    printf("Usage: sorting_lib_app < -1 | -2 > < -A -B -C > <filename>\n");
    printf("    -1: sort through the insertion sort algorithm\n");
    printf("    -2: sort through the quick sort algorithm\n");
    printf("    -A: sort according to the first field ascending order\n");
    printf("    -B: sort according to the second field ascending order\n");
    printf("    -C: sort according to the third field ascending order\n");
}

int compare_first_field(Record * rec1, Record * rec2){
    return strcmp(rec1->field_one,rec2->field_one);
}

int compare_second_field(Record * rec1, Record * rec2){
    return rec1->field_two - rec2->field_two;
}

int compare_third_field(Record * rec1, Record * rec2){
    return rec1->field_three - rec2->field_three;
}


Options parse_options(int argc, char const *argv[]){
    if (argc != 4){
        printf("Parameters error\n");
        print_usage();
        exit(ERROR_EXIT_CODE);
    }

    Options options;
    
    if (!strcmp(argv[2],"-A"))
        options.comparison_fun = (SortingLibCmp) compare_first_field;
    else if (!strcmp(argv[2],"-B"))
        options.comparison_fun = (SortingLibCmp) compare_second_field;
        else if (!strcmp(argv[2],"-C"))
            options.comparison_fun = (SortingLibCmp) compare_third_field;
        else {
            printf("Parameters error\n");
            print_usage();
            exit(ERROR_EXIT_CODE);
        }
    
    if (!strcmp(argv[1], "-1"))
        options.algorithm = 1;
    else if (!strcmp(argv[1], "-2"))
        options.algorithm = 2;
        else {
            printf("Parameters error\n");
            print_usage();
            exit(ERROR_EXIT_CODE);
        }
    
    options.file_name = argv[3];

    return options;
}

void load_data(Record ** array, const char * file_name){
    FILE * file = fopen(file_name,"r");

    #define MAX_BUF_LEN 1024
    int id;
    char field_one[MAX_BUF_LEN];
    int field_two;
    float field_three;
    int i = 0;

    while (!feof(file)){
        Record * record = malloc(sizeof(Record));
        
        int n = fscanf(file, "%d,%1024[^,],%d,%f\n", &id, field_one, &field_two, &field_three);

        if(n != 4) {
            if(feof(file)) {
                continue;
            }
            printf("Error while reading file");
            exit(ERROR_EXIT_CODE);
        }

        record->id = id;
        record->field_one = strndup(field_one, MAX_BUF_LEN);
        record->field_two = field_two;
        record->field_three = field_three;

        array[i] = record;
        i++;
    }

    fclose(file);
}

void free_data(Record ** array){
    for (int i = 0; i < SIZE; i++)
        free(array[i]);
    free(array);
}

int main(int argc, char const *argv[]){

    Options options = parse_options(argc, argv);
    Record ** array = malloc(sizeof(Record *)*SIZE); 
    load_data(array, options.file_name);
    if (options.algorithm == 1) insertion_sort((void **) array,options.comparison_fun,SIZE);
    else if (options.algorithm == 2) quick_sort((void **) array,options.comparison_fun,0,SIZE-1);

    /*STAMPA PROVA*/
    for (int i = 0; i < 10; i++){
        Record * rec = array[i];
        printf("ID: %d\t FIELD_ONE: %s\t\t FIELD_TWO: %d\t FIELD_THREE: %f\n",rec->id,rec->field_one,rec->field_two,rec->field_three);
    }
    /**/

    free_data(array);

}




