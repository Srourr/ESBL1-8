#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Types.h"

#define Stack_Size 15
#define Stack_Initial_Rear -1
#define Offset 1
#define Left_Curly_bracket 123
#define Right_Curly_bracket 125
#define Left_Round_bracket 40
#define Right_Round_bracket 41
#define True 1
#define False 0


void Push(uint8_t u8_data);
uint8_t Pull();
void PrintStack();
uint8_t* balancedParentheses(uint8_t* expression);

uint8_t Stack[Stack_Size],Balanced[] = {'B','A','L','A','N','C','E','D',0},Not_Balanced[] = {'N','O','T','-','B','A','L','A','N','C','E','D',0};
int8_t Stack_Counter = -1;
int8_t Temp_variable = 0;



int main()
{
char Temporary_String[Stack_Size];
printf("\n\nPlease Enter The String :\n");
scanf("%s",&Temporary_String);
printf("\n\n%s\n\n",balancedParentheses(Temporary_String));

//PrintStack();
return 0;
}



/*Push Function is responsible of adding data into the stack first it checks if there's an empty space to add data in TRUE case 
it adds the data in the empty space and increases the stack rear variable which indicates the next space in stack.*/

void Push(uint8_t u8_data){
if (Stack_Counter == (Stack_Size-1) )
{
printf("\nStack Overflow !!!");
}
else 
{
Stack_Counter ++;
Stack[Stack_Counter] = u8_data;
}
}

/*Pull Function is responsible of pulling out the stack elements, First it checks if the stack is empty in TRUE case it shows an error message 
that there's nothing to be pulled else it will pull the last input to the stack and decreases the counter variable to indicate the next stack element.*/

uint8_t Pull()
{
uint8_t Stack_Pull;
if (Stack_Counter == Stack_Initial_Rear)
{
printf("\n Stack is Empty !!!");
}
else {
Stack_Pull = Stack[Stack_Counter];
Stack[Stack_Counter] = 0;
Stack_Counter --;
return (Stack_Pull);
}
}

/*PrintStack Function is only printing the stack elements but first it checks if there's any elements or not*/

void PrintStack()
{
int8_t Element_Number = Stack_Counter;
if (Stack_Counter == Stack_Initial_Rear)
{
printf("\n Stack is Empty !!!");
exit;
}

else 
{
for (int8_t Element_Number = Stack_Counter; Element_Number > Stack_Initial_Rear ; Element_Number-- )
{
printf("\nElement_Number %d is : %c", (Element_Number + Offset), Pull());
}
}
}

/* balancedParentheses DETERMINES if the expression is balanced or not by pushing them into the stack
and after each open bracket it checks if there's a closed bracket or not*/

uint8_t* balancedParentheses(uint8_t* expression)
{
uint8_t *Checking_pointer = expression;

for (uint8_t Exp_check = 0; Exp_check < Stack_Size ; Exp_check ++)
{
if (*Checking_pointer == 0)
{
break;
}
else
{
if ( ( (*Checking_pointer == '{' ) || (*Checking_pointer == '(' ) ) && (Stack_Counter != (Stack_Size -1)) )   Push(*Checking_pointer);

else if ( ( (*Checking_pointer == '}' ) || (*Checking_pointer == ')' ) ) && (Stack_Counter != (Stack_Size -1)) )
{
if ((*Checking_pointer == '}') && ( Stack[Stack_Counter] == '{' ) ) Pull();
else if ((*Checking_pointer == ')') && ( Stack[Stack_Counter] == '(' ) ) Pull();

}

else if (Stack_Counter == (Stack_Size -1)) break;

}
Checking_pointer ++;
}
if (Stack_Counter == Stack_Initial_Rear) return Balanced;
else if (Stack_Counter != Stack_Initial_Rear) return Not_Balanced;
else 
{}
}


