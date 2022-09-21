
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// argc: counter for number of arguments passed on command line
// argv: array of pointers pointing at command line arguments
//       size of this array is equal to value of argc
//       note: argv[0] holds name of program itself
//             argv[1] is pointer to first command line argument
// note: command line arguments are separated by space
//       if argument itself has a space, use double/single quotes around it
int main(int argc, char *argv[]) {

    int 
        ii,
        opt_ret;

    char
        filename[PATH_MAX];

    printf( "argument count: %d\n", argc );

    for (ii=0; ii<=argc; ++ii) {
        printf( "%d at %p: %s\n", ii, argv[ii], argv[ii] );
    }

    // using getopt to loop through arguments until it return -1, 
    // meaning there is no argument to parse
    // if current argument matches an option, option character is returned
    // handle parsed arguments then with a switch block
    //
    // getopt( argument count, array of arguments, optstring)
    //   possible options are provided via "optstring" (single character options)
    //   options prededed with a colon (e.g. "u:") require an argument
    //   optarg then points to the substring at the end of the argument
    //     (thus having its value)
    //   if optstring starts with a ":", getopt will return ":" in case of missing value
    //     and not "?", meaning you have to make your own error-handling
    while ( (opt_ret = getopt(argc, argv, ":f:")) != -1 ) {
        switch (opt_ret) {
            case 'f':
                printf( "parameter 'f', given filename: %s\n", optarg );
                sprintf( filename, "%s", optarg);
                break;
        }
    }

    printf( "filename provided via parameters '-f': %s\n", filename );

    return EXIT_SUCCESS;
}
