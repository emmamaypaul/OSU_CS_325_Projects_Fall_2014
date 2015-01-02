/*
Project:	CS325 - Project 2
Section:	Algorithm 4
File:		Alg4Input.c
Authors: 	Ian Paul, Emma Paul, Abdulhalim Bambang
*/
// ------------------------------------------------



#include <stdio.h>//
#include <stdlib.h>//
#include <string.h>//
#include <time.h>//
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>


//variables for timing
time_t startTime;
time_t endTime;
double totalTime = 0;
double startTimer;
double endTimer;

int i, j, k, z, sum, subsetSize, arraySize, position, tempSize;

int sum1, sum2;
int arraySize1, arraySize2, fullArraySize;
int subArraySize1, subArraySize2;
int startPos1, startPos2;
int y;

int array1FinalStartPos, array2FinalStartPos;
int array1FinalSize, array2FinalSize;


int absSum;
int lowestSum = NULL; //variable to store lowest Sum when found while iterating through 
int startPos, endPos; //variables to store the beginning and end index positions in the array for the sub array 

int zeroPosStart, zeroPosEnd;
int zeroFlag = 0;


static int testArray1[100];
static int testArray2[100];
static int testArray3[100];
static int testArray4[100];
static int testArray5[100];
static int testArray6[100];
static int testArray7[100];
static int testArray8[100];
static int testArray9[100];
static int testArray10[100];

int junk;

//CHANGE THIS FOR TIMING TESTING
#define sizeToTest 100
#define halfSizeToTest 50 //must always be half of sizeToTest



static int fullArray1[sizeToTest];

int sizeOfRandArray = sizeToTest;


int fullArraySize = sizeToTest;

arraySize1 = halfSizeToTest;
arraySize2 = halfSizeToTest;

int temp;
int tempPos;

static int array1Sums[halfSizeToTest];
static int array1SumsPos[halfSizeToTest];
static int array2Sums[halfSizeToTest];
static int array2SumsPos[halfSizeToTest];
static int array1[halfSizeToTest];
static int array2[halfSizeToTest];

static int sum1Array[halfSizeToTest];
static int sum2Array[halfSizeToTest];
static int array1SumsPos[halfSizeToTest];
static int array2SumsPos[halfSizeToTest];

int sumArray1, sumArray2;





int main(int argc, char *argv[])
{
    FILE *myFile, *outputFile;

	char outputFileName[] = "input_results_Alg4.txt";
    myFile = fopen(argv[1], "r");

    //read file into array
    if (myFile == NULL)
    {
        printf("Error Reading File\n");
        exit (0);
    }
	

//Scans first line for first array
	fscanf(myFile, "[", &junk);
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray1[i]);
	}
	fscanf(myFile, "]\n", &junk);
		
	
//Scans second line for second array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray2[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans third line for third array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray3[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans fourth line for fourth array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray4[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans fifth line for fifth array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray5[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans sixth line for sixth array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray6[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans seventh line for seventh array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray7[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans eighth line for eighth array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray8[i]);
	}
	fscanf(myFile, "]\n", &junk);

//Scans ninth line for ninth array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray9[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans tenth line for tenth array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray10[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//close file	
	fclose(myFile);	
	
//opens output file
	outputFile = fopen(outputFileName, "w");
	
	if(outputFile == NULL)
	{
		fprintf(stderr, "Can't open output file %s!\n", outputFileName);
		exit(1);
	}
	
	
//Start of Array 1
	
//Populating fullArray1	

for (i = 0; i < fullArraySize; i++)
	{
		fullArray1[i] = testArray1[i];
	}
	
arraySize1 = (sizeof(array1) / sizeof(array1[0]));	
arraySize2 = (sizeof(array2) / sizeof(array2[0]));	
//populating array 1 from fullArray1
for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
//populating array 2 from fullArray1	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+arraySize2];
	}
	

subArraySize1 = arraySize1;

subArraySize2 = arraySize2;


//loops for alg

//finding sums of array 1
for(i = 0; i < arraySize1; i++)
{
	sumArray1 += array1[i];

}
//populating sum1Array
	
	sum1Array[0] = sumArray1;
	
for(i = 1; i < arraySize1; i++)
{
	sum1Array[i] = sum1Array[i-1] - array1[i-1];
}



//Populate sum2Array
for(i = 0; i < arraySize2; i++)
{
	sumArray2 += array2[i];
	sum2Array[i] = sumArray2;
}


//populating array sums positions
	for (i = 0; i < arraySize1; i++)
	{
		array1SumsPos[i] = i;
	}	
	for (i = 0; i < arraySize2; i++)
	{
		array2SumsPos[i] = i;
	}
	

	

//Sorting sum1Array and array1SumsPos
     for (i = 0; i < (arraySize1 - 1); i++)
     {
          for (j = 0; j < arraySize1 - 1 - i; j++ )
          {
               if (sum1Array[j] > sum1Array[j+1])
               {
					//for sorting array elements
                    temp = sum1Array[j+1];
                    sum1Array[j+1] = sum1Array[j];
                    sum1Array[j] = temp;
					
					//for sorting array position
					tempPos = array1SumsPos[j+1];
                    array1SumsPos[j+1] = array1SumsPos[j];
                    array1SumsPos[j] = tempPos;
					
               }
          }
     }

	 


	

//Sorting sum2Array and array2SumsPos
     for (i = 0; i < (arraySize2 - 1); i++)
     {
          for (j = 0; j < arraySize2 - 1 - i; j++)
          {
               if (sum2Array[j] > sum2Array[j+1])
               {
					//for sorting array elements
                    temp = sum2Array[j+1];
                    sum2Array[j+1] = sum2Array[j];
                    sum2Array[j] = temp;
					
					//for sorting array position
					tempPos = array2SumsPos[j+1];
                    array2SumsPos[j+1] = array2SumsPos[j];
                    array2SumsPos[j] = tempPos;
					
               }
          }
     }
	 
  

//pitting to find lowest
for(i = 0; i < arraySize1; i++)
{
	sum1 = sum1Array[i];
	
	for(j = 0; j < arraySize2; j++)
	{
	
		
		sum2 = sum2Array[j];
		
		sum = sum1 + sum2;
		
		//printf("%d + %d = %d\n", sum1, sum2, sum);
		
		if (abs(sum) < lowestSum || lowestSum == NULL)
		{
			lowestSum = abs(sum);
			//printf("Struck Gold!! ");
			//printf("%d\n", lowestSum);
			//array1FinalStartPos
			//array1FinalSize
			//array2FinalStartPos
			//array2FinalSize
			//printf("array2SumsPos: %d\n",array2SumsPos[j]);
			//printf("sum2Array Value: %d\n",sum2Array[j]);
			array1FinalStartPos = array1SumsPos[i];
			array1FinalSize = arraySize1 - array1FinalStartPos;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = array2SumsPos[j];
					   
		}
	}
}




fprintf(outputFile,"[");
for (i = 0; i < arraySize1; i++)
{
	fprintf(outputFile,"%d", array1[i]);
		if (i < arraySize1-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

fprintf(outputFile,"[");
for (i = 0; i < arraySize2; i++)
{
	fprintf(outputFile,"%d", array2[i]);
		if (i < arraySize2-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

//printf("\n");
sum1 = 0;
sum2 = 0;
		//printf("(");
		fprintf(outputFile,"[");
		for (z = array1FinalStartPos; z < arraySize1; z++)
		{
			fprintf(outputFile,"%d", array1[z]);
			sum1 += array1[z];
			if (z < arraySize1-1)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum1);

		fprintf(outputFile,"[");
		for (z = 0; z <= array2FinalSize; z++)
		{
			fprintf(outputFile,"%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum2);
		
		lowestSum = sum1+sum2;
		sum1 = 0;
		sum2 = 0;
		startPos1 = 0;
		startPos2 = 0;
		fprintf(outputFile,"%d\n", lowestSum);
		
		lowestSum = NULL;
		array1FinalStartPos = 0;
		array1FinalSize = 0;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = 0;
			sumArray1 = 0;
			sumArray2 = 0;

	
/////////////////////////////////////////////////////////////////End of Array 1
//Start of Array 2
	
//Populating fullArray1	

for (i = 0; i < fullArraySize; i++)
	{
		fullArray1[i] = testArray2[i];
	}
	
arraySize1 = (sizeof(array1) / sizeof(array1[0]));	
arraySize2 = (sizeof(array2) / sizeof(array2[0]));	
//populating array 1 from fullArray1
for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
//populating array 2 from fullArray1	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+arraySize2];
	}
	

subArraySize1 = arraySize1;

subArraySize2 = arraySize2;


//loops for alg

//finding sums of array 1
for(i = 0; i < arraySize1; i++)
{
	sumArray1 += array1[i];

}
//populating sum1Array
	
	sum1Array[0] = sumArray1;
	
for(i = 1; i < arraySize1; i++)
{
	sum1Array[i] = sum1Array[i-1] - array1[i-1];
}



//Populate sum2Array
for(i = 0; i < arraySize2; i++)
{
	sumArray2 += array2[i];
	sum2Array[i] = sumArray2;
}


//populating array sums positions
	for (i = 0; i < arraySize1; i++)
	{
		array1SumsPos[i] = i;
	}	
	for (i = 0; i < arraySize2; i++)
	{
		array2SumsPos[i] = i;
	}
	

	

//Sorting sum1Array and array1SumsPos
     for (i = 0; i < (arraySize1 - 1); i++)
     {
          for (j = 0; j < arraySize1 - 1 - i; j++ )
          {
               if (sum1Array[j] > sum1Array[j+1])
               {
					//for sorting array elements
                    temp = sum1Array[j+1];
                    sum1Array[j+1] = sum1Array[j];
                    sum1Array[j] = temp;
					
					//for sorting array position
					tempPos = array1SumsPos[j+1];
                    array1SumsPos[j+1] = array1SumsPos[j];
                    array1SumsPos[j] = tempPos;
					
               }
          }
     }

	 


	

//Sorting sum2Array and array2SumsPos
     for (i = 0; i < (arraySize2 - 1); i++)
     {
          for (j = 0; j < arraySize2 - 1 - i; j++)
          {
               if (sum2Array[j] > sum2Array[j+1])
               {
					//for sorting array elements
                    temp = sum2Array[j+1];
                    sum2Array[j+1] = sum2Array[j];
                    sum2Array[j] = temp;
					
					//for sorting array position
					tempPos = array2SumsPos[j+1];
                    array2SumsPos[j+1] = array2SumsPos[j];
                    array2SumsPos[j] = tempPos;
					
               }
          }
     }
	 
  

//pitting to find lowest
for(i = 0; i < arraySize1; i++)
{
	sum1 = sum1Array[i];
	
	for(j = 0; j < arraySize2; j++)
	{
	
		
		sum2 = sum2Array[j];
		
		sum = sum1 + sum2;
		
		//printf("%d + %d = %d\n", sum1, sum2, sum);
		
		if (abs(sum) < lowestSum || lowestSum == NULL)
		{
			lowestSum = abs(sum);
			//printf("Struck Gold!! ");
			//printf("%d\n", lowestSum);
			//array1FinalStartPos
			//array1FinalSize
			//array2FinalStartPos
			//array2FinalSize
			//printf("array2SumsPos: %d\n",array2SumsPos[j]);
			//printf("sum2Array Value: %d\n",sum2Array[j]);
			array1FinalStartPos = array1SumsPos[i];
			array1FinalSize = arraySize1 - array1FinalStartPos;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = array2SumsPos[j];
					   
		}
	}
}




fprintf(outputFile,"[");
for (i = 0; i < arraySize1; i++)
{
	fprintf(outputFile,"%d", array1[i]);
		if (i < arraySize1-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

fprintf(outputFile,"[");
for (i = 0; i < arraySize2; i++)
{
	fprintf(outputFile,"%d", array2[i]);
		if (i < arraySize2-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

//printf("\n");
sum1 = 0;
sum2 = 0;
		//printf("(");
		fprintf(outputFile,"[");
		for (z = array1FinalStartPos; z < arraySize1; z++)
		{
			fprintf(outputFile,"%d", array1[z]);
			sum1 += array1[z];
			if (z < arraySize1-1)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum1);

		fprintf(outputFile,"[");
		for (z = 0; z <= array2FinalSize; z++)
		{
			fprintf(outputFile,"%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum2);
		
		lowestSum = sum1+sum2;
		sum1 = 0;
		sum2 = 0;
		startPos1 = 0;
		startPos2 = 0;
		fprintf(outputFile,"%d\n", lowestSum);
		
		lowestSum = NULL;
		array1FinalStartPos = 0;
		array1FinalSize = 0;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = 0;
			sumArray1 = 0;
			sumArray2 = 0;


	
/////////////////////////////////////////////////////////////////End of Array 2
//Start of Array 3
	
//Populating fullArray1	

for (i = 0; i < fullArraySize; i++)
	{
		fullArray1[i] = testArray3[i];
	}
	
arraySize1 = (sizeof(array1) / sizeof(array1[0]));	
arraySize2 = (sizeof(array2) / sizeof(array2[0]));	
//populating array 1 from fullArray1
for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
//populating array 2 from fullArray1	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+arraySize2];
	}
	

subArraySize1 = arraySize1;

subArraySize2 = arraySize2;


//loops for alg

//finding sums of array 1
for(i = 0; i < arraySize1; i++)
{
	sumArray1 += array1[i];

}
//populating sum1Array
	
	sum1Array[0] = sumArray1;
	
for(i = 1; i < arraySize1; i++)
{
	sum1Array[i] = sum1Array[i-1] - array1[i-1];
}



//Populate sum2Array
for(i = 0; i < arraySize2; i++)
{
	sumArray2 += array2[i];
	sum2Array[i] = sumArray2;
}


//populating array sums positions
	for (i = 0; i < arraySize1; i++)
	{
		array1SumsPos[i] = i;
	}	
	for (i = 0; i < arraySize2; i++)
	{
		array2SumsPos[i] = i;
	}
	

	

//Sorting sum1Array and array1SumsPos
     for (i = 0; i < (arraySize1 - 1); i++)
     {
          for (j = 0; j < arraySize1 - 1 - i; j++ )
          {
               if (sum1Array[j] > sum1Array[j+1])
               {
					//for sorting array elements
                    temp = sum1Array[j+1];
                    sum1Array[j+1] = sum1Array[j];
                    sum1Array[j] = temp;
					
					//for sorting array position
					tempPos = array1SumsPos[j+1];
                    array1SumsPos[j+1] = array1SumsPos[j];
                    array1SumsPos[j] = tempPos;
					
               }
          }
     }

	 


	

//Sorting sum2Array and array2SumsPos
     for (i = 0; i < (arraySize2 - 1); i++)
     {
          for (j = 0; j < arraySize2 - 1 - i; j++)
          {
               if (sum2Array[j] > sum2Array[j+1])
               {
					//for sorting array elements
                    temp = sum2Array[j+1];
                    sum2Array[j+1] = sum2Array[j];
                    sum2Array[j] = temp;
					
					//for sorting array position
					tempPos = array2SumsPos[j+1];
                    array2SumsPos[j+1] = array2SumsPos[j];
                    array2SumsPos[j] = tempPos;
					
               }
          }
     }
	 
  

//pitting to find lowest
for(i = 0; i < arraySize1; i++)
{
	sum1 = sum1Array[i];
	
	for(j = 0; j < arraySize2; j++)
	{
	
		
		sum2 = sum2Array[j];
		
		sum = sum1 + sum2;
		
		//printf("%d + %d = %d\n", sum1, sum2, sum);
		
		if (abs(sum) < lowestSum || lowestSum == NULL)
		{
			lowestSum = abs(sum);
			//printf("Struck Gold!! ");
			//printf("%d\n", lowestSum);
			//array1FinalStartPos
			//array1FinalSize
			//array2FinalStartPos
			//array2FinalSize
			//printf("array2SumsPos: %d\n",array2SumsPos[j]);
			//printf("sum2Array Value: %d\n",sum2Array[j]);
			array1FinalStartPos = array1SumsPos[i];
			array1FinalSize = arraySize1 - array1FinalStartPos;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = array2SumsPos[j];
					   
		}
	}
}




fprintf(outputFile,"[");
for (i = 0; i < arraySize1; i++)
{
	fprintf(outputFile,"%d", array1[i]);
		if (i < arraySize1-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

fprintf(outputFile,"[");
for (i = 0; i < arraySize2; i++)
{
	fprintf(outputFile,"%d", array2[i]);
		if (i < arraySize2-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

//printf("\n");
sum1 = 0;
sum2 = 0;
		//printf("(");
		fprintf(outputFile,"[");
		for (z = array1FinalStartPos; z < arraySize1; z++)
		{
			fprintf(outputFile,"%d", array1[z]);
			sum1 += array1[z];
			if (z < arraySize1-1)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum1);

		fprintf(outputFile,"[");
		for (z = 0; z <= array2FinalSize; z++)
		{
			fprintf(outputFile,"%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum2);
		
		lowestSum = sum1+sum2;
		sum1 = 0;
		sum2 = 0;
		startPos1 = 0;
		startPos2 = 0;
		fprintf(outputFile,"%d\n", lowestSum);
		
		lowestSum = NULL;
		array1FinalStartPos = 0;
		array1FinalSize = 0;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = 0;
			sumArray1 = 0;
			sumArray2 = 0;


	
/////////////////////////////////////////////////////////////////End of Array 3
//Start of Array 4
	
//Populating fullArray1	

for (i = 0; i < fullArraySize; i++)
	{
		fullArray1[i] = testArray4[i];
	}
	
arraySize1 = (sizeof(array1) / sizeof(array1[0]));	
arraySize2 = (sizeof(array2) / sizeof(array2[0]));	
//populating array 1 from fullArray1
for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
//populating array 2 from fullArray1	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+arraySize2];
	}
	

subArraySize1 = arraySize1;

subArraySize2 = arraySize2;


//loops for alg

//finding sums of array 1
for(i = 0; i < arraySize1; i++)
{
	sumArray1 += array1[i];

}
//populating sum1Array
	
	sum1Array[0] = sumArray1;
	
for(i = 1; i < arraySize1; i++)
{
	sum1Array[i] = sum1Array[i-1] - array1[i-1];
}



//Populate sum2Array
for(i = 0; i < arraySize2; i++)
{
	sumArray2 += array2[i];
	sum2Array[i] = sumArray2;
}


//populating array sums positions
	for (i = 0; i < arraySize1; i++)
	{
		array1SumsPos[i] = i;
	}	
	for (i = 0; i < arraySize2; i++)
	{
		array2SumsPos[i] = i;
	}
	

	

//Sorting sum1Array and array1SumsPos
     for (i = 0; i < (arraySize1 - 1); i++)
     {
          for (j = 0; j < arraySize1 - 1 - i; j++ )
          {
               if (sum1Array[j] > sum1Array[j+1])
               {
					//for sorting array elements
                    temp = sum1Array[j+1];
                    sum1Array[j+1] = sum1Array[j];
                    sum1Array[j] = temp;
					
					//for sorting array position
					tempPos = array1SumsPos[j+1];
                    array1SumsPos[j+1] = array1SumsPos[j];
                    array1SumsPos[j] = tempPos;
					
               }
          }
     }

	 


	

//Sorting sum2Array and array2SumsPos
     for (i = 0; i < (arraySize2 - 1); i++)
     {
          for (j = 0; j < arraySize2 - 1 - i; j++)
          {
               if (sum2Array[j] > sum2Array[j+1])
               {
					//for sorting array elements
                    temp = sum2Array[j+1];
                    sum2Array[j+1] = sum2Array[j];
                    sum2Array[j] = temp;
					
					//for sorting array position
					tempPos = array2SumsPos[j+1];
                    array2SumsPos[j+1] = array2SumsPos[j];
                    array2SumsPos[j] = tempPos;
					
               }
          }
     }
	 
  

//pitting to find lowest
for(i = 0; i < arraySize1; i++)
{
	sum1 = sum1Array[i];
	
	for(j = 0; j < arraySize2; j++)
	{
	
		
		sum2 = sum2Array[j];
		
		sum = sum1 + sum2;
		
		//printf("%d + %d = %d\n", sum1, sum2, sum);
		
		if (abs(sum) < lowestSum || lowestSum == NULL)
		{
			lowestSum = abs(sum);
			//printf("Struck Gold!! ");
			//printf("%d\n", lowestSum);
			//array1FinalStartPos
			//array1FinalSize
			//array2FinalStartPos
			//array2FinalSize
			//printf("array2SumsPos: %d\n",array2SumsPos[j]);
			//printf("sum2Array Value: %d\n",sum2Array[j]);
			array1FinalStartPos = array1SumsPos[i];
			array1FinalSize = arraySize1 - array1FinalStartPos;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = array2SumsPos[j];
					   
		}
	}
}




fprintf(outputFile,"[");
for (i = 0; i < arraySize1; i++)
{
	fprintf(outputFile,"%d", array1[i]);
		if (i < arraySize1-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

fprintf(outputFile,"[");
for (i = 0; i < arraySize2; i++)
{
	fprintf(outputFile,"%d", array2[i]);
		if (i < arraySize2-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

//printf("\n");
sum1 = 0;
sum2 = 0;
		//printf("(");
		fprintf(outputFile,"[");
		for (z = array1FinalStartPos; z < arraySize1; z++)
		{
			fprintf(outputFile,"%d", array1[z]);
			sum1 += array1[z];
			if (z < arraySize1-1)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum1);

		fprintf(outputFile,"[");
		for (z = 0; z <= array2FinalSize; z++)
		{
			fprintf(outputFile,"%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum2);
		
		lowestSum = sum1+sum2;
		sum1 = 0;
		sum2 = 0;
		startPos1 = 0;
		startPos2 = 0;
		fprintf(outputFile,"%d\n", lowestSum);
		
		lowestSum = NULL;
		array1FinalStartPos = 0;
		array1FinalSize = 0;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = 0;
			sumArray1 = 0;
			sumArray2 = 0;


	
/////////////////////////////////////////////////////////////////End of Array 4
//Start of Array 5
	
//Populating fullArray1	

for (i = 0; i < fullArraySize; i++)
	{
		fullArray1[i] = testArray5[i];
	}
	
arraySize1 = (sizeof(array1) / sizeof(array1[0]));	
arraySize2 = (sizeof(array2) / sizeof(array2[0]));	
//populating array 1 from fullArray1
for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
//populating array 2 from fullArray1	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+arraySize2];
	}
	

subArraySize1 = arraySize1;

subArraySize2 = arraySize2;


//loops for alg

//finding sums of array 1
for(i = 0; i < arraySize1; i++)
{
	sumArray1 += array1[i];

}
//populating sum1Array
	
	sum1Array[0] = sumArray1;
	
for(i = 1; i < arraySize1; i++)
{
	sum1Array[i] = sum1Array[i-1] - array1[i-1];
}



//Populate sum2Array
for(i = 0; i < arraySize2; i++)
{
	sumArray2 += array2[i];
	sum2Array[i] = sumArray2;
}


//populating array sums positions
	for (i = 0; i < arraySize1; i++)
	{
		array1SumsPos[i] = i;
	}	
	for (i = 0; i < arraySize2; i++)
	{
		array2SumsPos[i] = i;
	}
	

	

//Sorting sum1Array and array1SumsPos
     for (i = 0; i < (arraySize1 - 1); i++)
     {
          for (j = 0; j < arraySize1 - 1 - i; j++ )
          {
               if (sum1Array[j] > sum1Array[j+1])
               {
					//for sorting array elements
                    temp = sum1Array[j+1];
                    sum1Array[j+1] = sum1Array[j];
                    sum1Array[j] = temp;
					
					//for sorting array position
					tempPos = array1SumsPos[j+1];
                    array1SumsPos[j+1] = array1SumsPos[j];
                    array1SumsPos[j] = tempPos;
					
               }
          }
     }

	 


	

//Sorting sum2Array and array2SumsPos
     for (i = 0; i < (arraySize2 - 1); i++)
     {
          for (j = 0; j < arraySize2 - 1 - i; j++)
          {
               if (sum2Array[j] > sum2Array[j+1])
               {
					//for sorting array elements
                    temp = sum2Array[j+1];
                    sum2Array[j+1] = sum2Array[j];
                    sum2Array[j] = temp;
					
					//for sorting array position
					tempPos = array2SumsPos[j+1];
                    array2SumsPos[j+1] = array2SumsPos[j];
                    array2SumsPos[j] = tempPos;
					
               }
          }
     }
	 
  

//pitting to find lowest
for(i = 0; i < arraySize1; i++)
{
	sum1 = sum1Array[i];
	
	for(j = 0; j < arraySize2; j++)
	{
	
		
		sum2 = sum2Array[j];
		
		sum = sum1 + sum2;
		
		//printf("%d + %d = %d\n", sum1, sum2, sum);
		
		if (abs(sum) < lowestSum || lowestSum == NULL)
		{
			lowestSum = abs(sum);
			//printf("Struck Gold!! ");
			//printf("%d\n", lowestSum);
			//array1FinalStartPos
			//array1FinalSize
			//array2FinalStartPos
			//array2FinalSize
			//printf("array2SumsPos: %d\n",array2SumsPos[j]);
			//printf("sum2Array Value: %d\n",sum2Array[j]);
			array1FinalStartPos = array1SumsPos[i];
			array1FinalSize = arraySize1 - array1FinalStartPos;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = array2SumsPos[j];
					   
		}
	}
}




fprintf(outputFile,"[");
for (i = 0; i < arraySize1; i++)
{
	fprintf(outputFile,"%d", array1[i]);
		if (i < arraySize1-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

fprintf(outputFile,"[");
for (i = 0; i < arraySize2; i++)
{
	fprintf(outputFile,"%d", array2[i]);
		if (i < arraySize2-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

//printf("\n");
sum1 = 0;
sum2 = 0;
		//printf("(");
		fprintf(outputFile,"[");
		for (z = array1FinalStartPos; z < arraySize1; z++)
		{
			fprintf(outputFile,"%d", array1[z]);
			sum1 += array1[z];
			if (z < arraySize1-1)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum1);

		fprintf(outputFile,"[");
		for (z = 0; z <= array2FinalSize; z++)
		{
			fprintf(outputFile,"%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum2);
		
		lowestSum = sum1+sum2;
		sum1 = 0;
		sum2 = 0;
		startPos1 = 0;
		startPos2 = 0;
		fprintf(outputFile,"%d\n", lowestSum);
		
		lowestSum = NULL;
		array1FinalStartPos = 0;
		array1FinalSize = 0;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = 0;
			sumArray1 = 0;
			sumArray2 = 0;


	
/////////////////////////////////////////////////////////////////End of Array 5
//Start of Array 6
	
//Populating fullArray1	

for (i = 0; i < fullArraySize; i++)
	{
		fullArray1[i] = testArray6[i];
	}
	
arraySize1 = (sizeof(array1) / sizeof(array1[0]));	
arraySize2 = (sizeof(array2) / sizeof(array2[0]));	
//populating array 1 from fullArray1
for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
//populating array 2 from fullArray1	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+arraySize2];
	}
	

subArraySize1 = arraySize1;

subArraySize2 = arraySize2;


//loops for alg

//finding sums of array 1
for(i = 0; i < arraySize1; i++)
{
	sumArray1 += array1[i];

}
//populating sum1Array
	
	sum1Array[0] = sumArray1;
	
for(i = 1; i < arraySize1; i++)
{
	sum1Array[i] = sum1Array[i-1] - array1[i-1];
}



//Populate sum2Array
for(i = 0; i < arraySize2; i++)
{
	sumArray2 += array2[i];
	sum2Array[i] = sumArray2;
}


//populating array sums positions
	for (i = 0; i < arraySize1; i++)
	{
		array1SumsPos[i] = i;
	}	
	for (i = 0; i < arraySize2; i++)
	{
		array2SumsPos[i] = i;
	}
	

	

//Sorting sum1Array and array1SumsPos
     for (i = 0; i < (arraySize1 - 1); i++)
     {
          for (j = 0; j < arraySize1 - 1 - i; j++ )
          {
               if (sum1Array[j] > sum1Array[j+1])
               {
					//for sorting array elements
                    temp = sum1Array[j+1];
                    sum1Array[j+1] = sum1Array[j];
                    sum1Array[j] = temp;
					
					//for sorting array position
					tempPos = array1SumsPos[j+1];
                    array1SumsPos[j+1] = array1SumsPos[j];
                    array1SumsPos[j] = tempPos;
					
               }
          }
     }

	 


	

//Sorting sum2Array and array2SumsPos
     for (i = 0; i < (arraySize2 - 1); i++)
     {
          for (j = 0; j < arraySize2 - 1 - i; j++)
          {
               if (sum2Array[j] > sum2Array[j+1])
               {
					//for sorting array elements
                    temp = sum2Array[j+1];
                    sum2Array[j+1] = sum2Array[j];
                    sum2Array[j] = temp;
					
					//for sorting array position
					tempPos = array2SumsPos[j+1];
                    array2SumsPos[j+1] = array2SumsPos[j];
                    array2SumsPos[j] = tempPos;
					
               }
          }
     }
	 
  

//pitting to find lowest
for(i = 0; i < arraySize1; i++)
{
	sum1 = sum1Array[i];
	
	for(j = 0; j < arraySize2; j++)
	{
	
		
		sum2 = sum2Array[j];
		
		sum = sum1 + sum2;
		
		//printf("%d + %d = %d\n", sum1, sum2, sum);
		
		if (abs(sum) < lowestSum || lowestSum == NULL)
		{
			lowestSum = abs(sum);
			//printf("Struck Gold!! ");
			//printf("%d\n", lowestSum);
			//array1FinalStartPos
			//array1FinalSize
			//array2FinalStartPos
			//array2FinalSize
			//printf("array2SumsPos: %d\n",array2SumsPos[j]);
			//printf("sum2Array Value: %d\n",sum2Array[j]);
			array1FinalStartPos = array1SumsPos[i];
			array1FinalSize = arraySize1 - array1FinalStartPos;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = array2SumsPos[j];
					   
		}
	}
}




fprintf(outputFile,"[");
for (i = 0; i < arraySize1; i++)
{
	fprintf(outputFile,"%d", array1[i]);
		if (i < arraySize1-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

fprintf(outputFile,"[");
for (i = 0; i < arraySize2; i++)
{
	fprintf(outputFile,"%d", array2[i]);
		if (i < arraySize2-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

//printf("\n");
sum1 = 0;
sum2 = 0;
		//printf("(");
		fprintf(outputFile,"[");
		for (z = array1FinalStartPos; z < arraySize1; z++)
		{
			fprintf(outputFile,"%d", array1[z]);
			sum1 += array1[z];
			if (z < arraySize1-1)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum1);

		fprintf(outputFile,"[");
		for (z = 0; z <= array2FinalSize; z++)
		{
			fprintf(outputFile,"%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum2);
		
		lowestSum = sum1+sum2;
		sum1 = 0;
		sum2 = 0;
		startPos1 = 0;
		startPos2 = 0;
		fprintf(outputFile,"%d\n", lowestSum);
		
		lowestSum = NULL;
		array1FinalStartPos = 0;
		array1FinalSize = 0;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = 0;
			sumArray1 = 0;
			sumArray2 = 0;


	
/////////////////////////////////////////////////////////////////End of Array 6
//Start of Array 7
	
//Populating fullArray1	

for (i = 0; i < fullArraySize; i++)
	{
		fullArray1[i] = testArray7[i];
	}
	
arraySize1 = (sizeof(array1) / sizeof(array1[0]));	
arraySize2 = (sizeof(array2) / sizeof(array2[0]));	
//populating array 1 from fullArray1
for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
//populating array 2 from fullArray1	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+arraySize2];
	}
	

subArraySize1 = arraySize1;

subArraySize2 = arraySize2;


//loops for alg

//finding sums of array 1
for(i = 0; i < arraySize1; i++)
{
	sumArray1 += array1[i];

}
//populating sum1Array
	
	sum1Array[0] = sumArray1;
	
for(i = 1; i < arraySize1; i++)
{
	sum1Array[i] = sum1Array[i-1] - array1[i-1];
}



//Populate sum2Array
for(i = 0; i < arraySize2; i++)
{
	sumArray2 += array2[i];
	sum2Array[i] = sumArray2;
}


//populating array sums positions
	for (i = 0; i < arraySize1; i++)
	{
		array1SumsPos[i] = i;
	}	
	for (i = 0; i < arraySize2; i++)
	{
		array2SumsPos[i] = i;
	}
	

	

//Sorting sum1Array and array1SumsPos
     for (i = 0; i < (arraySize1 - 1); i++)
     {
          for (j = 0; j < arraySize1 - 1 - i; j++ )
          {
               if (sum1Array[j] > sum1Array[j+1])
               {
					//for sorting array elements
                    temp = sum1Array[j+1];
                    sum1Array[j+1] = sum1Array[j];
                    sum1Array[j] = temp;
					
					//for sorting array position
					tempPos = array1SumsPos[j+1];
                    array1SumsPos[j+1] = array1SumsPos[j];
                    array1SumsPos[j] = tempPos;
					
               }
          }
     }

	 


	

//Sorting sum2Array and array2SumsPos
     for (i = 0; i < (arraySize2 - 1); i++)
     {
          for (j = 0; j < arraySize2 - 1 - i; j++)
          {
               if (sum2Array[j] > sum2Array[j+1])
               {
					//for sorting array elements
                    temp = sum2Array[j+1];
                    sum2Array[j+1] = sum2Array[j];
                    sum2Array[j] = temp;
					
					//for sorting array position
					tempPos = array2SumsPos[j+1];
                    array2SumsPos[j+1] = array2SumsPos[j];
                    array2SumsPos[j] = tempPos;
					
               }
          }
     }
	 
  

//pitting to find lowest
for(i = 0; i < arraySize1; i++)
{
	sum1 = sum1Array[i];
	
	for(j = 0; j < arraySize2; j++)
	{
	
		
		sum2 = sum2Array[j];
		
		sum = sum1 + sum2;
		
		//printf("%d + %d = %d\n", sum1, sum2, sum);
		
		if (abs(sum) < lowestSum || lowestSum == NULL)
		{
			lowestSum = abs(sum);
			//printf("Struck Gold!! ");
			//printf("%d\n", lowestSum);
			//array1FinalStartPos
			//array1FinalSize
			//array2FinalStartPos
			//array2FinalSize
			//printf("array2SumsPos: %d\n",array2SumsPos[j]);
			//printf("sum2Array Value: %d\n",sum2Array[j]);
			array1FinalStartPos = array1SumsPos[i];
			array1FinalSize = arraySize1 - array1FinalStartPos;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = array2SumsPos[j];
					   
		}
	}
}




fprintf(outputFile,"[");
for (i = 0; i < arraySize1; i++)
{
	fprintf(outputFile,"%d", array1[i]);
		if (i < arraySize1-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

fprintf(outputFile,"[");
for (i = 0; i < arraySize2; i++)
{
	fprintf(outputFile,"%d", array2[i]);
		if (i < arraySize2-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

//printf("\n");
sum1 = 0;
sum2 = 0;
		//printf("(");
		fprintf(outputFile,"[");
		for (z = array1FinalStartPos; z < arraySize1; z++)
		{
			fprintf(outputFile,"%d", array1[z]);
			sum1 += array1[z];
			if (z < arraySize1-1)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum1);

		fprintf(outputFile,"[");
		for (z = 0; z <= array2FinalSize; z++)
		{
			fprintf(outputFile,"%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum2);
		
		lowestSum = sum1+sum2;
		sum1 = 0;
		sum2 = 0;
		startPos1 = 0;
		startPos2 = 0;
		fprintf(outputFile,"%d\n", lowestSum);
		
		lowestSum = NULL;
		array1FinalStartPos = 0;
		array1FinalSize = 0;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = 0;
			sumArray1 = 0;
			sumArray2 = 0;


	
/////////////////////////////////////////////////////////////////End of Array 7
//Start of Array 8
	
//Populating fullArray1	

for (i = 0; i < fullArraySize; i++)
	{
		fullArray1[i] = testArray8[i];
	}
	
arraySize1 = (sizeof(array1) / sizeof(array1[0]));	
arraySize2 = (sizeof(array2) / sizeof(array2[0]));	
//populating array 1 from fullArray1
for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
//populating array 2 from fullArray1	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+arraySize2];
	}
	

subArraySize1 = arraySize1;

subArraySize2 = arraySize2;


//loops for alg

//finding sums of array 1
for(i = 0; i < arraySize1; i++)
{
	sumArray1 += array1[i];

}
//populating sum1Array
	
	sum1Array[0] = sumArray1;
	
for(i = 1; i < arraySize1; i++)
{
	sum1Array[i] = sum1Array[i-1] - array1[i-1];
}



//Populate sum2Array
for(i = 0; i < arraySize2; i++)
{
	sumArray2 += array2[i];
	sum2Array[i] = sumArray2;
}


//populating array sums positions
	for (i = 0; i < arraySize1; i++)
	{
		array1SumsPos[i] = i;
	}	
	for (i = 0; i < arraySize2; i++)
	{
		array2SumsPos[i] = i;
	}
	

	

//Sorting sum1Array and array1SumsPos
     for (i = 0; i < (arraySize1 - 1); i++)
     {
          for (j = 0; j < arraySize1 - 1 - i; j++ )
          {
               if (sum1Array[j] > sum1Array[j+1])
               {
					//for sorting array elements
                    temp = sum1Array[j+1];
                    sum1Array[j+1] = sum1Array[j];
                    sum1Array[j] = temp;
					
					//for sorting array position
					tempPos = array1SumsPos[j+1];
                    array1SumsPos[j+1] = array1SumsPos[j];
                    array1SumsPos[j] = tempPos;
					
               }
          }
     }

	 


	

//Sorting sum2Array and array2SumsPos
     for (i = 0; i < (arraySize2 - 1); i++)
     {
          for (j = 0; j < arraySize2 - 1 - i; j++)
          {
               if (sum2Array[j] > sum2Array[j+1])
               {
					//for sorting array elements
                    temp = sum2Array[j+1];
                    sum2Array[j+1] = sum2Array[j];
                    sum2Array[j] = temp;
					
					//for sorting array position
					tempPos = array2SumsPos[j+1];
                    array2SumsPos[j+1] = array2SumsPos[j];
                    array2SumsPos[j] = tempPos;
					
               }
          }
     }
	 
  

//pitting to find lowest
for(i = 0; i < arraySize1; i++)
{
	sum1 = sum1Array[i];
	
	for(j = 0; j < arraySize2; j++)
	{
	
		
		sum2 = sum2Array[j];
		
		sum = sum1 + sum2;
		
		//printf("%d + %d = %d\n", sum1, sum2, sum);
		
		if (abs(sum) < lowestSum || lowestSum == NULL)
		{
			lowestSum = abs(sum);
			//printf("Struck Gold!! ");
			//printf("%d\n", lowestSum);
			//array1FinalStartPos
			//array1FinalSize
			//array2FinalStartPos
			//array2FinalSize
			//printf("array2SumsPos: %d\n",array2SumsPos[j]);
			//printf("sum2Array Value: %d\n",sum2Array[j]);
			array1FinalStartPos = array1SumsPos[i];
			array1FinalSize = arraySize1 - array1FinalStartPos;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = array2SumsPos[j];
					   
		}
	}
}




fprintf(outputFile,"[");
for (i = 0; i < arraySize1; i++)
{
	fprintf(outputFile,"%d", array1[i]);
		if (i < arraySize1-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

fprintf(outputFile,"[");
for (i = 0; i < arraySize2; i++)
{
	fprintf(outputFile,"%d", array2[i]);
		if (i < arraySize2-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

//printf("\n");
sum1 = 0;
sum2 = 0;
		//printf("(");
		fprintf(outputFile,"[");
		for (z = array1FinalStartPos; z < arraySize1; z++)
		{
			fprintf(outputFile,"%d", array1[z]);
			sum1 += array1[z];
			if (z < arraySize1-1)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum1);

		fprintf(outputFile,"[");
		for (z = 0; z <= array2FinalSize; z++)
		{
			fprintf(outputFile,"%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum2);
		
		lowestSum = sum1+sum2;
		sum1 = 0;
		sum2 = 0;
		startPos1 = 0;
		startPos2 = 0;
		fprintf(outputFile,"%d\n", lowestSum);
		
		lowestSum = NULL;
		array1FinalStartPos = 0;
		array1FinalSize = 0;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = 0;
			sumArray1 = 0;
			sumArray2 = 0;


	
/////////////////////////////////////////////////////////////////End of Array 8
//Start of Array 9
	
//Populating fullArray1	

for (i = 0; i < fullArraySize; i++)
	{
		fullArray1[i] = testArray9[i];
	}
	
arraySize1 = (sizeof(array1) / sizeof(array1[0]));	
arraySize2 = (sizeof(array2) / sizeof(array2[0]));	
//populating array 1 from fullArray1
for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
//populating array 2 from fullArray1	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+arraySize2];
	}
	

subArraySize1 = arraySize1;

subArraySize2 = arraySize2;


//loops for alg

//finding sums of array 1
for(i = 0; i < arraySize1; i++)
{
	sumArray1 += array1[i];

}
//populating sum1Array
	
	sum1Array[0] = sumArray1;
	
for(i = 1; i < arraySize1; i++)
{
	sum1Array[i] = sum1Array[i-1] - array1[i-1];
}



//Populate sum2Array
for(i = 0; i < arraySize2; i++)
{
	sumArray2 += array2[i];
	sum2Array[i] = sumArray2;
}


//populating array sums positions
	for (i = 0; i < arraySize1; i++)
	{
		array1SumsPos[i] = i;
	}	
	for (i = 0; i < arraySize2; i++)
	{
		array2SumsPos[i] = i;
	}
	

	

//Sorting sum1Array and array1SumsPos
     for (i = 0; i < (arraySize1 - 1); i++)
     {
          for (j = 0; j < arraySize1 - 1 - i; j++ )
          {
               if (sum1Array[j] > sum1Array[j+1])
               {
					//for sorting array elements
                    temp = sum1Array[j+1];
                    sum1Array[j+1] = sum1Array[j];
                    sum1Array[j] = temp;
					
					//for sorting array position
					tempPos = array1SumsPos[j+1];
                    array1SumsPos[j+1] = array1SumsPos[j];
                    array1SumsPos[j] = tempPos;
					
               }
          }
     }

	 


	

//Sorting sum2Array and array2SumsPos
     for (i = 0; i < (arraySize2 - 1); i++)
     {
          for (j = 0; j < arraySize2 - 1 - i; j++)
          {
               if (sum2Array[j] > sum2Array[j+1])
               {
					//for sorting array elements
                    temp = sum2Array[j+1];
                    sum2Array[j+1] = sum2Array[j];
                    sum2Array[j] = temp;
					
					//for sorting array position
					tempPos = array2SumsPos[j+1];
                    array2SumsPos[j+1] = array2SumsPos[j];
                    array2SumsPos[j] = tempPos;
					
               }
          }
     }
	 
  

//pitting to find lowest
for(i = 0; i < arraySize1; i++)
{
	sum1 = sum1Array[i];
	
	for(j = 0; j < arraySize2; j++)
	{
	
		
		sum2 = sum2Array[j];
		
		sum = sum1 + sum2;
		
		//printf("%d + %d = %d\n", sum1, sum2, sum);
		
		if (abs(sum) < lowestSum || lowestSum == NULL)
		{
			lowestSum = abs(sum);
			//printf("Struck Gold!! ");
			//printf("%d\n", lowestSum);
			//array1FinalStartPos
			//array1FinalSize
			//array2FinalStartPos
			//array2FinalSize
			//printf("array2SumsPos: %d\n",array2SumsPos[j]);
			//printf("sum2Array Value: %d\n",sum2Array[j]);
			array1FinalStartPos = array1SumsPos[i];
			array1FinalSize = arraySize1 - array1FinalStartPos;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = array2SumsPos[j];
					   
		}
	}
}




fprintf(outputFile,"[");
for (i = 0; i < arraySize1; i++)
{
	fprintf(outputFile,"%d", array1[i]);
		if (i < arraySize1-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

fprintf(outputFile,"[");
for (i = 0; i < arraySize2; i++)
{
	fprintf(outputFile,"%d", array2[i]);
		if (i < arraySize2-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

//printf("\n");
sum1 = 0;
sum2 = 0;
		//printf("(");
		fprintf(outputFile,"[");
		for (z = array1FinalStartPos; z < arraySize1; z++)
		{
			fprintf(outputFile,"%d", array1[z]);
			sum1 += array1[z];
			if (z < arraySize1-1)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum1);

		fprintf(outputFile,"[");
		for (z = 0; z <= array2FinalSize; z++)
		{
			fprintf(outputFile,"%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum2);
		
		lowestSum = sum1+sum2;
		sum1 = 0;
		sum2 = 0;
		startPos1 = 0;
		startPos2 = 0;
		fprintf(outputFile,"%d\n", lowestSum);
		
		lowestSum = NULL;
		array1FinalStartPos = 0;
		array1FinalSize = 0;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = 0;
			sumArray1 = 0;
			sumArray2 = 0;


	
/////////////////////////////////////////////////////////////////End of Array 9
//Start of Array 10
	
//Populating fullArray1	

for (i = 0; i < fullArraySize; i++)
	{
		fullArray1[i] = testArray10[i];
	}
	
arraySize1 = (sizeof(array1) / sizeof(array1[0]));	
arraySize2 = (sizeof(array2) / sizeof(array2[0]));	
//populating array 1 from fullArray1
for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
//populating array 2 from fullArray1	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+arraySize2];
	}
	

subArraySize1 = arraySize1;

subArraySize2 = arraySize2;


//loops for alg

//finding sums of array 1
for(i = 0; i < arraySize1; i++)
{
	sumArray1 += array1[i];

}
//populating sum1Array
	
	sum1Array[0] = sumArray1;
	
for(i = 1; i < arraySize1; i++)
{
	sum1Array[i] = sum1Array[i-1] - array1[i-1];
}



//Populate sum2Array
for(i = 0; i < arraySize2; i++)
{
	sumArray2 += array2[i];
	sum2Array[i] = sumArray2;
}


//populating array sums positions
	for (i = 0; i < arraySize1; i++)
	{
		array1SumsPos[i] = i;
	}	
	for (i = 0; i < arraySize2; i++)
	{
		array2SumsPos[i] = i;
	}
	

	

//Sorting sum1Array and array1SumsPos
     for (i = 0; i < (arraySize1 - 1); i++)
     {
          for (j = 0; j < arraySize1 - 1 - i; j++ )
          {
               if (sum1Array[j] > sum1Array[j+1])
               {
					//for sorting array elements
                    temp = sum1Array[j+1];
                    sum1Array[j+1] = sum1Array[j];
                    sum1Array[j] = temp;
					
					//for sorting array position
					tempPos = array1SumsPos[j+1];
                    array1SumsPos[j+1] = array1SumsPos[j];
                    array1SumsPos[j] = tempPos;
					
               }
          }
     }

	 


	

//Sorting sum2Array and array2SumsPos
     for (i = 0; i < (arraySize2 - 1); i++)
     {
          for (j = 0; j < arraySize2 - 1 - i; j++)
          {
               if (sum2Array[j] > sum2Array[j+1])
               {
					//for sorting array elements
                    temp = sum2Array[j+1];
                    sum2Array[j+1] = sum2Array[j];
                    sum2Array[j] = temp;
					
					//for sorting array position
					tempPos = array2SumsPos[j+1];
                    array2SumsPos[j+1] = array2SumsPos[j];
                    array2SumsPos[j] = tempPos;
					
               }
          }
     }
	 
  

//pitting to find lowest
for(i = 0; i < arraySize1; i++)
{
	sum1 = sum1Array[i];
	
	for(j = 0; j < arraySize2; j++)
	{
	
		
		sum2 = sum2Array[j];
		
		sum = sum1 + sum2;
		
		//printf("%d + %d = %d\n", sum1, sum2, sum);
		
		if (abs(sum) < lowestSum || lowestSum == NULL)
		{
			lowestSum = abs(sum);
			//printf("Struck Gold!! ");
			//printf("%d\n", lowestSum);
			//array1FinalStartPos
			//array1FinalSize
			//array2FinalStartPos
			//array2FinalSize
			//printf("array2SumsPos: %d\n",array2SumsPos[j]);
			//printf("sum2Array Value: %d\n",sum2Array[j]);
			array1FinalStartPos = array1SumsPos[i];
			array1FinalSize = arraySize1 - array1FinalStartPos;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = array2SumsPos[j];
					   
		}
	}
}




fprintf(outputFile,"[");
for (i = 0; i < arraySize1; i++)
{
	fprintf(outputFile,"%d", array1[i]);
		if (i < arraySize1-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

fprintf(outputFile,"[");
for (i = 0; i < arraySize2; i++)
{
	fprintf(outputFile,"%d", array2[i]);
		if (i < arraySize2-1)
		{
			fprintf(outputFile,", ");
		}
}
fprintf(outputFile,"], ");

//printf("\n");
sum1 = 0;
sum2 = 0;
		//printf("(");
		fprintf(outputFile,"[");
		for (z = array1FinalStartPos; z < arraySize1; z++)
		{
			fprintf(outputFile,"%d", array1[z]);
			sum1 += array1[z];
			if (z < arraySize1-1)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum1);

		fprintf(outputFile,"[");
		for (z = 0; z <= array2FinalSize; z++)
		{
			fprintf(outputFile,"%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize)
			{
				fprintf(outputFile,", ");
			}
		}
		fprintf(outputFile,"], ");
		//printf("%d\n", sum2);
		
		lowestSum = sum1+sum2;
		sum1 = 0;
		sum2 = 0;
		startPos1 = 0;
		startPos2 = 0;
		fprintf(outputFile,"%d\n", lowestSum);
		
		lowestSum = NULL;
		array1FinalStartPos = 0;
		array1FinalSize = 0;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = 0;
			sumArray1 = 0;
			sumArray2 = 0;


	
/////////////////////////////////////////////////////////////////End of Array 10
//fprintf(outputFile,", ");
//close file	
	fclose(outputFile);	

return 0;
}