// Javisth Chabria
// jc4377

#include <stdio.h>
#include <errno.h>

int 
main(int argc, char *argv[])
{
	#define BUF_SIZE 1024
	int nl;
	int c;
	int row;
	int col;
	int i;
	int j;
	int max;
	FILE *fp;
	// Initializing all elements of the array to ~
	char arr[BUF_SIZE][BUF_SIZE] = { '~' };

	nl = 0;
	row = 0;
	col = 0;
	i = 0;
	j = 0;
	max = 0;
	
	// checking for missing argument

	if(argc < 2){
		while((c = getchar()) != EOF) {
                	// storing lines in the array
                	if(c != '\n'){
                        	arr[row][col++] = c;
                	}
                	else {
                        	// count lines, move to next row, reset columns
                        	nl++;
                        	row++;
                        	// finding the longest line
                        	if(col>=max)
                                	max = col;
                        	col = 0;
                	}
        	}
		// printing lines in reverse order

        	for(int i=nl-1;i>=0;i--){
                	for(int j=0;j<max;j++){
                        	if(arr[i][j] == '~')
                                	break;
                        	printf("%c",arr[i][j]);
                	}
                	printf("\n");
        	}

		return 0;
	}

	// opening file
	fp = fopen(argv[1], "r");

	while((c = fgetc(fp)) != EOF) {
		// storing lines in the array
		if(c != '\n'){
			arr[row][col++] = c;
		}
		else {
			// count lines, move to next row, reset columns
			nl++;
			row++;
			// finding the longest line
			if(col>=max)
				max = col;
			col = 0;
		}
	}
	
	// printing lines in reverse order
	
	for(int i=nl-1;i>=0;i--){
		for(int j=0;j<max;j++){
			if(arr[i][j] == '~')
				break;
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}	
	fclose(fp);
	return 0;
}
