#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE_LEN 256
#define STATS_FORMAT_STR "Number of lines: %d\nLongest field: %d characters\n"
#define USAGE_FORMAT_STR "ERR: expected usage is %s -c <in_cols> [-d delimiter] [-s] col1 ...\n"

int main(int argc, char **argv) {

    int in_cols = 0;  /* number of columns in input */
    int out_cols = 0; /* number of columns to output */

    int c_flag = 0; /* keep track of whether or not we received the required c flag */

    char delim = ','; /* keep track of the delimiter, by default it is a comma */

    /* local variables to store the statistics */
    int stats_flag = 0; /* keep track of whether -s flag is passed in or not */
    unsigned int linecnt = 0;   /* number of lines in input */
    unsigned int lngst_fld = 0; /* longest field in input */

    /* TODO: process named command line options using getopt and store the information
        in the appropriate local variables */
    int c;
    /* TODO: fill out this skeleton code calling getopt */
    while ((c = getopt(argc, argv, "s" /* TODO: fix argument to getopt */)) != -1) {
        switch (c) {
        case 's':
            stats_flag = 1;
            break;
        /* 
        TODO: fill in remaining cases (c flag, d flag)
        - You will want to use the optarg variable set by getopt, to access option args
        - You will want to use atoi to convert strings to integer types
        */
        default:
            fprintf(stderr, USAGE_FORMAT_STR, *argv);
            return EXIT_FAILURE;
        }
    }

    /* TODO: uncomment following block & check to make sure c argument was provided */
    /* 
    if ( -FILL IN- ) {
        // we did not receive the required c option, print usage and terminate
        fprintf(stderr, USAGE_FORMAT_STR, *argv);
        return EXIT_FAILURE;

    }
    */

    /* pointers to arrays which will be allocated dynamically by you */
    char **colptrs = NULL; /* pointer to array of pointers to the start of
                             each field in input buffer */
    int *target_cols = NULL;  /* pointer to array of output indices */

    // allocate arrays dynamically
    /* TODO: uncomment the block below & fill in mallocs */
    /*
    colptrs = malloc( (-FILL IN-) * sizeof(*buf) ); // should be based on in_cols
    if (colptrs == NULL) { // always check if malloc failed
        return EXIT_FAILURE;
    }
    out_cols = (-FILL IN-); // should be based on argc, optind
    target_cols = malloc( (out_cols) * sizeof(*target_cols) );
    if (target_cols == NULL) { // always check if malloc failed
        free(buf);
        return EXIT_FAILURE;
    }
    */

    /* 
    TODO: process other command line arguments (list of output columns) 
    - Fill these into target_cols!
    */

    char line[MAX_LINE_LEN]; /* read buffer for processing lines in input */
    char *line_ptr;
    /* TODO: using fgets, loop over input from stdin
    steps:  read a line, 
            parse the line as described in writeup, 
            print target columns for this line
            repeat for next line
        repeat until no more lines 
    */

    /* TODO: use this line to print out the statistics if -s flag is set */
    printf(STATS_FORMAT_STR, linecnt, lngst_fld);

    // free the memory for arrays allocated with malloc 
    /* TODO: uncomment these lines when you uncomment the mallocs above */
    // free(colpts); 
    // free(target_cols);
    return EXIT_SUCCESS;
}
