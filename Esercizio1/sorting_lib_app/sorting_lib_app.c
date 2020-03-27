#include <stdio.h>
#include <string.h>
#include "sorting_lib.h"

#define ERROR_EXIT_CODE 1

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

Options parse_options(int argc, char const *argv[]){
    if (argc != 4){
        printf("Parameters erro\n");
        print_usage();
        exit(ERROR_EXIT_CODE);
    }

    Options options;
    
    if (!strcmp(argv[2],"-A"))
        options.comparison_fun = (SortingLibCmp) compare_first_field();
    else if (!strcmp(argv[2],"-B"))
        options.comparison_fun = (SortingLibCmp) compare_second_field();
        else if (!strcmp(argv[2],"-C"))
            options.comparison_fun = (SortingLibCmp) compare_third_field();
        else {
            printf("Parameters erro\n");
            print_usage();
            exit(ERROR_EXIT_CODE);
        }
    
    if (!strcmp(argv[1], "-1"))
        options.algorithm = 1;
    else if (!strcmp(argv[1], "-1"))
        options.algorithm = 2;
        else {
            printf("Parameters erro\n");
            print_usage();
            exit(ERROR_EXIT_CODE);
        }
    
    options.file_name = argv[3];

    return options;
}


 /*
    comparison function
 */


int main(int argc, char const *argv[])
{
    Options options = parse_options(argc, argv);
    /*
    load_data
    sort_array
    free_data
    */
    return 0;
}



