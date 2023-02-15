#include <fstream>
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;

#include <math.h>
#include <stdlib.h>

//Declaration of Functions
//the *'s symbolise arrays (In this case a 2D Array)
void readArr(int, int, double **);
void multArrs(int, double **, int, double **, int, double **);

//Count the number of arguments passed
//2D array of real arguments provided through command line
int main(int argc, char *argv[])
{

    //
    //the row and column of first array
    int ar = atoi(argv[1]);
    int ac = atoi(argv[2]);

    //the row and column of second array
    int br = atoi(argv[3]);
    int bc = atoi(argv[4]);


    //if the coulumns of the first is not equal to the rows of the second
    if (ac != br)
    {
        //displays a error
        cerr<< "Matrix dimensions mismatch; exiting.\n";
        //error occoured
        exit(-1);
    }

    // reserve space for the three arrays
    double **A = new double*[ar];	// each el. of this points to a row of A
    for (int i = 0; i < ar; i++)
        A[i] = new double[ac];	// a row of 'ac' floats

    double **B = new double*[br];
    for (int i = 0; i < br; i++)
        B[i] = new double[bc];	// a row of 'bc' floats

    double **C = new double*[ar];	// each el. of this points to a row of C
    //fill in code here to allocate C
    for (int i = 0; i < ar; i++)
        C[i] = new double[bc];
    // C has 'ar' rows and 'bc' columns

    //second line to fill in

    // a row of 'bc' floats

    // now that sufficient storage is allocated, start reading from kbd

    readArr(ar, ac, A);
    readArr(br, bc, B);

    multArrs(ar, A, bc, B, ac, C);


    for(int i = 0; i < ar; i++){
        for (int j = 0; j < bc; j++){
            cout << C[i][j] << ' ';
        }
        cout << endl;
    }
    // now print out answer, nice and plainly

}

// read from kbd into this array, row by row
//  for a total of r x c entries;
//  WARNING: space for array must have been reserved beforehand
void readArr(int r, int c, double **arr)
{
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin>> arr[i][j];
    // code for reading in r rows of c elements each goes here

}

void multArrs(int ar, double **A, int bc, double **B, int br, double **C)
{
    // multiplication here
    for(int i = 0; i < ar; ++i)
        for(int j = 0; j <  bc; ++j)
            for(int k = 0; k <  br; ++k)
            {

                C[i][j] += A[i][k] * B[k][j];

            }
}