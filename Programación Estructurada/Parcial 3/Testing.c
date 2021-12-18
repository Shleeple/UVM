#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    FILE *input, *output;
    char ch;
    char name[30];
	
	// Store in the name and path, then append ".lis"
	strcpy(name,argv[2]);
    strcat(name, ".lis");
    
	// Open the input
    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("\nCannot open file %s for input\n", argv[1]);
        exit(1);
    }

	// Open the output
    output = fopen(name, "w");
    if (output == NULL) {
        printf("\nCannot open file %s for output\n", name);
        exit(1);
    }

	// Print the header with the filename
	fprintf(output,"***************** %s ***************\n",name);

	// Setup our read line buffer and counter
	char line[500];
	int counter = 1;

	// Read in a line up to 500 chars or until it hits a newline
	fgets(line,500,input);

	// While not at the end of a file
	while (!feof(input)) {
		// Read in a line up to 500 chars or until it hits a newline
		// Then print it with a counter for the line number
		fgets(line,500,input);
		fprintf(output,"%d: %s",counter, line);
		counter++;
	}
        
	// Cleanup the file pointers
    fclose(input);
    fclose(output);
    printf("\nCopied %s to %s\n", argv[1], name);
        
    return(0);
}

