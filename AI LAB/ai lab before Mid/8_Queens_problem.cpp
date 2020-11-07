#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;


#define MAX 100


int numberOfQueen=8;
int N_Queens[MAX];


void initialize_N_Queens()    //Random Initialization state.
{
    int i;

    for( i = 0; i < numberOfQueen; i++ )
	{
		N_Queens[i] = (rand() % numberOfQueen);
	}
}

void print_N_Queens()         //Print 8_Queens.
{
    int i;
    int j;

    printf("\n");

    for( i = 0; i < numberOfQueen; i++ )
    {
        for( j = 0; j < numberOfQueen; j++ )
        {
            if( N_Queens[j] == i )
			{
			    printf("Q  ");
			}
			else
            {
                printf(".  ");
            }
		}
		 printf("\n\n");
	}
}

int Conflict(int *N_Queens)      //Finding Number Of Conflict
{
    int i;
    int j;
	int counter = 0;

	for( i = 0; i < (numberOfQueen - 1); i++ )
	{
	    for( j = (i + 1); j < numberOfQueen; j++ )
		{
			if( N_Queens[i] == N_Queens[j] )
			{
				counter++;
			}
			else if( (N_Queens[i] - N_Queens[j]) == (i - j) )
			{
				counter++;
			}
			else if( (N_Queens[i] - N_Queens[j]) == (j - i) )
			{
				counter++;
			}
		}
	}

	return counter;
}

int* generateSuccessor()     //Generating Successor of initial state.
{
	int i;
	int j;

	int numberOfConflict;
	int currentNumberOfConflict;
	int successorRowNumber;

	int temp_N_Queens[numberOfQueen];


	numberOfConflict =Conflict(N_Queens);

	for( i = 0; i < numberOfQueen; i++ )
	{
		temp_N_Queens[i] = N_Queens[i];
	}

	for( i = 0; i < numberOfQueen; i++ )
	{
		successorRowNumber = temp_N_Queens[i];

		for( j = 0; j < numberOfQueen; j++ )
		{
			temp_N_Queens[i] = j;

			currentNumberOfConflict = Conflict(temp_N_Queens);

			if( currentNumberOfConflict < numberOfConflict )
			{
				successorRowNumber = j;
			    numberOfConflict = currentNumberOfConflict;
			}
		}

		temp_N_Queens[i] = successorRowNumber;
	}

	return temp_N_Queens;
}

void HillClimbing()       //Start hill climbing.
{
    int i;
    int j;
    int *temp_N_Queens;

	for( i = 1; Conflict(N_Queens) != 0; i++ )
	{
		temp_N_Queens = generateSuccessor();

		if(Conflict(temp_N_Queens) < Conflict(N_Queens) )
		{
			for( j = 0; j < numberOfQueen; j++ )
			{
				N_Queens[j] = temp_N_Queens[j];
			}
		}
		else
		{
			initialize_N_Queens();
		}

	}
}


int main()
{

    srand(time(NULL));
    printf("Random inital state of  8_Queens problem : \n");
	initialize_N_Queens();
	print_N_Queens();
    printf("Number of conflict : %d\n\n",Conflict(N_Queens));


	HillClimbing();


	printf("Solution After Hill climbing search : \n");
	print_N_Queens();

	printf("Number of conflict : %d\n\n",Conflict(N_Queens));
	return 0;
}
