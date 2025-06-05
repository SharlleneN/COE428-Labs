#include <stdlib.h>
#include <stdio.h>
#include "towers.h"


int main(int argc, char **argv)
{
    int n = 3;//default num of disks
    int from = 1;//default from tower
    int dest = 2;//default destination tower
	//handling command-line arguments
    if (argc == 2) {
        n = atoi(argv[1]);
    }else if(argc >= 3){
		n = atoi(argv[1]);
		from = atoi(argv[2]);
		dest = atoi(argv[3]);
		if(from < 1 || from > 3 || (dest < 1 || dest > 3) || (from == dest)){
			fprintf(stderr, "Error: Invalid tower IDs. Towers must be 1, 2, or 3, and must be different.\n");
		exit(1);
			}
	}

	
	//Call the towers function
    towers(n, from, dest);
	//Exit (with success)
    exit(0);
}//end main

