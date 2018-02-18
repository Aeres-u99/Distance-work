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
	
