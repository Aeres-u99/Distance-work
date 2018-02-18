/* haha couldnt even take some rest and my cruel head started throwing Ideas at me :p
 * so here we go with a newer Program
 * 		HAPPY NUMBERS 
 * yep you read that right.. Happy Numbers are strange types of numbers. what we do is take each digit of number 
 * square it then add them and replace the old number with the new one wherein this process is repeated until and unless
 * We get 1,after which it will stay there as such. Any number that follows this is called as Happy number :D
 * For this first of all I am going to write a function that will check the given numer for happiness :P
 * after that we will utilise that function to generate  first N happy numbers 
 *  So its tie to get into action and become happy :) 				*/
#include<stdio.h>
#define TRUE 1
#define FALSE 0
int SquareSum(int number){
	int sum = 0;
	while(number){
	sum += (number%10)*(number%10);
	number /= 10;
	}
	return sum;
}
int CheckHappyNumber(int number){ 			//Here came difficult part I literally struggled with thought of how to stop the check function
	int numberStepOne,numberStepTwo; 			//Then Floyd's Algorithm came to my rescue,Ofcourse I googled it up :D
	numberStepTwo = numberStepOne = number;
	do{
		numberStepOne = SquareSum(numberStepOne);
		numberStepTwo = SquareSum(SquareSum(numberStepTwo));
	}while(numberStepOne != numberStepTwo);
	if(numberStepOne == 1){
		return TRUE;
	}
	else{
		return FALSE;
	}
}
int main(){
	int number,temp,count = 1;
	printf("\t\t Enter the number of Happy Numbers you want to print: ");
	scanf("%d",&number);
	for(temp=1;count<=number;temp++){
		if(CheckHappyNumber(temp)){
			printf("\t %d \t\n",temp);
			count++;
		}
	}
		return 0;
}
/*
	A short introduction (again!!)
-----------------------HAPPY NUMBERS---------------------\n
A happy number is defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its
digits in base-ten, and repeat the process until the number either equals 1 (where it will stay), or it loops endlessly in a cycle that does not 
include 1. Those numbers for which this process ends in 1 are happy numbers, while those that do not end in 1 are unhappy numbers (or sad numbers).
<from wikipedia>
[Floyd's Cycle detection algorithm]
Well its kinda tricky for me to understand but still I will try my best to talk about it here
It goes like this, in a straight line race a fast bike will never encounter a slow bike , i.e once the race begins the faster bike will
see slower bike directly at the end of line.
The same is not the case in case of a circular track, rather the faster bike will complete 'cycle/s' before slower one just completes 
one revolution.So the thing is in case of a loop in a situation( or a loop in linked list as well) we take two pointers a slow paced one
and a fast paced one, eventually compare their values if they are equal it means there is a cycle and we can simply use that scenario 
to skip out of infinite loop :D
Thats what I have understood and tried to apply
*/
	
