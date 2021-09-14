#include<stdio.h>
#include"Types.h"

#define Array_Size 20
#define Maximum_Array_Size 255
#define Offset 1
#define Not_Found -1

uint32_t Sorted_Array[Array_Size] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
uint32_t NonSorted_Array[Array_Size] = {12,5,67,8,97,59,4,34,22,1,72,11,6,76,48,90,87,55,100,122};
int8_t Array_Type,Index,Search_Value;
int32_t Binary_Search(uint32_t *Array, uint32_t Start, uint32_t End,uint32_t Element);

void Print_Array(uint32_t *Array);
void Bubble_Sort(uint32_t *Array);
void Swap(uint32_t *Swap1, int *Swap2);

/* in main function the user is asked to choose from sorted and non-sorted arrays to search in for some value it can be modified later to make the user
enter his desired array, then the user is asked to enter the value he wants to search for in array then the index of this value is returned to be printed
to user */

int main()
{
printf("\nTo Search in Sorted Array Enter 'S' \t To Search in Non-Sorted Array Enter 'N' :");
scanf("%c",&Array_Type);

if (Array_Type == 'S' || Array_Type == 's') 
{
Print_Array(Sorted_Array);

printf("\n\nPlease Enter a value to search for :\n");
scanf("%d",&Search_Value);
Index = Binary_Search(Sorted_Array,0,(Array_Size-Offset),Search_Value);

}


else if (Array_Type == 'N' || Array_Type == 'n') 
{
Bubble_Sort(NonSorted_Array);
Print_Array(NonSorted_Array);

printf("\n\nPlease Enter a value to search for :\n");
scanf("%d",&Search_Value);
Index = Binary_Search(NonSorted_Array,0,(Array_Size- Offset),Search_Value);
}

if (Index == -1) printf("\n\nThis Value was not found !!");
else printf("Element found at index : %d",Index);

return 0;
}

/* Swap function is used in the Bubble_Sort function to swap the lower and bigger values inside the array and 
it takes two pointers these to pointers are pointing to the two swapped values */

void Swap(uint32_t *Swap1, int *Swap2)
{
     uint32_t Temp = *Swap1;
    *Swap1 = *Swap2;
    *Swap2 = Temp;
}

/* Bubble_Sort function is taking a pointer to first element in the non-sorted array and inside the function the 
less and bigger values are swapped one by one till the array is full sorted*/

void Bubble_Sort(uint32_t *Array)
{
   uint8_t Sort1,Sort2;
   for (Sort1 = 0; Sort1 < (Array_Size -Offset); Sort1++)      
     for (Sort2 = 0; Sort2 < Array_Size-Sort1-1; Sort2++) 
           if (Array[Sort2] > Array[Sort2+1])
              Swap(&Array[Sort2], &Array[Sort2+1]);
}
  
/*Print_Array functions only prints the elements of array it is used after sorting the non-sorted arrays
and to print the sorted array before searching*/

void Print_Array(uint32_t *Array)
{
    uint8_t print;
    for (print=0; print < Array_Size; print++)
        printf("Element %d : %d\n",print, Array[print]);
}

/*Binary Search Function is responsible to return the searched element index in case of value exisistance inside the searched array
if the value doesn't exist the function returns Not_Found (-1) value*/

int32_t Binary_Search(uint32_t *Array, uint32_t Start, uint32_t End,uint32_t Element){
   if (End >= Start){
      int Middle = Start + (End - Start )/2;
      if (Array[Middle] == Element)
         return Middle;
      if (Array[Middle] > Element)
         return Binary_Search(Array, Start, (Middle-Offset), Element);
      return Binary_Search(Array, (Middle + Offset), End, Element);
   }
  else return Not_Found;
}
  
