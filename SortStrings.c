//-----------------------------------------------------------------------------
// Jacob McCLure
//
// SortStrings.c
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>

void printArray(FILE* out, char** A, int n){
   int i;
   for(i=0; i<n; i++){
      fprintf(out, "%s\n", A[i]);
   }
}

void swap(char** A, int i, int j){
   char* temp;
   temp = A[i];
   A[i] = A[j];
   A[j] = temp;
}

int Partition(char** A, int p, int r){
   int i, j;
   char* x = A[r];
   i = p-1;
   for(j=p; j<r; j++){
      if( strcmp(A[j], x)<=0){
         i++;
         swap(A, i, j);
      }
   }
   swap(A, i+1, r);
   return(i+1);
}

void QuickSort(char** A, int p, int r){
   int q;
   if( p<r ){
      q = Partition(A, p, r);
      QuickSort(A, p, q-1);
      QuickSort(A, q+1, r);
   }
}

int main(int argc, char* argv[]){
   FILE* in = fopen(argv[1], "r");            // handle for input file           
   FILE* out = fopen(argv[2], "w");           // handle for output file      
   int n;

   // check command line for correct number of arguments 
   if( argc != 3 ){
      printf("Usage: %s input-file output-file\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   // open input file for reading
   if( in==NULL ){
      printf("Unable to read from file %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   // open output file for writing 
   if( out==NULL ){
      printf("Unable to write to file %s\n", argv[2]);
      exit(EXIT_FAILURE);
   }

   // store contents of first line, first character in "n"
   fscanf(in, "%d", &n);

   // parse through line 2 of infile to populate char array
   char** A = calloc(n, sizeof(char*));
   for (int i=0; i<n; i++){
      A[i] = (char*)calloc(n, sizeof(char)); // 200 is the max length
      fscanf(in, "%s", A[i]);
   }  
   
   QuickSort(A, 0, n-1);
   printArray(out, A, n);
   
   // free heap memory
   for (int k=0; k<n; k++){ 
     free(A[k]);
   }
   free(A);

   // close files
   fclose(in);
   fclose(out);

   return(EXIT_SUCCESS);
}
