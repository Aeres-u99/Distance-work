/*This is a Program to calculate distance between two cities using Haversine formula, yep Haversine formula is not very much accurate 
 * as It takes earth to be more spherical in shape than spheroid nevertheless it is accurate upto 0.3% which should mostly suffice for testing purpose
 * I wont be documenting it as Such because ugh thats booring adn plus variable names are kinda obvious nevertheless We dont know when we might end up getting time; So yes there is a slight  * chance that I might end up Documenting it hehe but dont expect it to happen anytime Sooner...
 */
#include<stdio.h>
#include<math.h> 	//We will be using a lot from this guy hehe
#define PI  3.14159265
#define RadiusOfEarth 6371000 		//meter Silly!
struct coordinates{
	float degrees;
	float minutes;
	float seconds;
	float radians;
	float DecimalFormat; 		//This will store the result in Decimal format
	char direction;
};
struct city{
	char name[25];
	struct coordinates lattitude;
	struct coordinates longitude;
}city_1,city_2;
//This part is an input fnction wherein we will be passsing the structures which will be updated 
//Lets see whether its working or not	
void InputDetails(struct city *cityX){
	printf("\tInput City details: \n");
	printf("\ti\t\n Name:[] ");
	scanf("%s",cityX->name);
	printf("\t\t Coordinates:[] \n");
	printf("\t\t Lattitude--> \n"); 		//Lattitude
	printf("\t\t\t Degrees:[] ");
	scanf("%f",&cityX->lattitude.degrees);
	printf("\t\t\t Minutes:[] ");
	scanf("%f",&cityX->lattitude.minutes);
	printf("\t\t\t Seconds:[] ");
	scanf("%f",&cityX->lattitude.seconds);
	printf("\t\t\t Direction:[N/S] ");
	scanf(" %c", &cityX->lattitude.direction);
	printf("\t\t Longitude--> \n"); 		//Longitude
	printf("\t\t\t Degrees:[] ");
	scanf("%f",&cityX->longitude.degrees);
	printf("\t\t\t Minutes:[] ");
	scanf("%f",&cityX->longitude.minutes);
	printf("\t\t\t Seconds:[] ");
	scanf("%f",&cityX->longitude.seconds);
	printf("\t\t\t Direction:[E/W] ");
	scanf(" %c", &cityX->longitude.direction);
	return ;
}
void DisplayData(struct city *cityX){
	printf("\n\t\t\t Name:[] %s",city_1.name);
	printf("\t\t\t Lattitude:[] \n");
	printf("\t\t Degrees:[] %f\n",cityX->lattitude.degrees);
	printf("\t\t Minutes:[] %f\n",cityX->lattitude.minutes);
	printf("\t\t Seconds:[] %f\n",cityX->lattitude.seconds);
	printf("\t\t Direction:[] %c\n",cityX->lattitude.direction);
	printf("\t\t\t Longitude:[] \n");
	printf("\t\t Degrees:[] %f\n",cityX->longitude.degrees);
	printf("\t\t Minutes:[] %f\n",cityX->longitude.minutes);
	printf("\t\t Seconds:[] %f\n",cityX->longitude.seconds);
	printf("\t\t Direction:[] %c\n",cityX->longitude.direction);;
	return ;
}
float ConvertToRadians(float degrees){ 			//This is a function to convert things to radian
	return (degrees*(PI/180));
}
void ConvertIntoRadians(struct city *cityX){ 		//This function will simply convert the values so far stored in degrees to their Radians value depending upon req
	cityX->lattitude.DecimalFormat = cityX->lattitude.degrees+(cityX->lattitude.minutes/60)+(cityX->lattitude.seconds/3600);
	cityX->longitude.DecimalFormat = cityX->longitude.degrees+(cityX->longitude.minutes/60)+(cityX->longitude.seconds/3600);
	cityX->lattitude.radians = ConvertToRadians(cityX->lattitude.DecimalFormat);
	cityX->longitude.radians = ConvertToRadians(cityX->longitude.DecimalFormat);
	if ((cityX->lattitude.direction == 'S')||(cityX->lattitude.direction == 's')){
		printf("\t\tDirections are inverted... \n");
		cityX->lattitude.radians *= -1;
	}
	if ((cityX->longitude.direction == 'W')||(cityX->longitude.direction == 'w')){
		printf("\t\tDirections are inverted... \n");
			cityX->longitude.radians *= -1;
	}
}
float HaversineA(struct city *cityX,struct city *cityY){
	float DeltaLattitude,DeltaLongitude,Distance,a,b,d,c; 			//I couldnt come up with better name
	DeltaLattitude = cityY->lattitude.radians-cityX->lattitude.radians;    //Simple difference
	DeltaLongitude = cityY->longitude.radians-cityX->longitude.radians;
	a = sin(DeltaLattitude/2.0)*sin(DeltaLattitude/2.0);
	b = cos(cityX->lattitude.radians)*cos(cityY->lattitude.radians)*sin(DeltaLongitude/2.0)*sin(DeltaLongitude/2.0);
	d = a+b;
	c = 2*atan2(sqrt(d),sqrt(1-d));
	Distance = RadiusOfEarth*c;
	return Distance;
}
int main(){
	float Distance;
	printf("Input details for First city: \n");
	InputDetails(&city_1);
	printf("Input details for second city: \n");
	InputDetails(&city_2);
/**********************************************************
//================DISPLAYING RESULTS HERE===================
***********************************************************/
	printf("\t\tFor testing purpose We are simply printing the details:-\n");
	printf("\t-------------City 1: []------------- \n");
	DisplayData(&city_1);
	printf("\t-------------City 2: []------------- \n");
	DisplayData(&city_2);
	ConvertIntoRadians(&city_1);
	ConvertIntoRadians(&city_2);
	printf("Okay! time to see whether the radian functions are working properly or not....\n");
	printf("Now we will do calculation part");
	Distance = HaversineA(&city_1,&city_2);
	printf("\t\t-----------------------------------------------------------\t\n");
	printf("\t\t|                                                         |\t\n");
	printf("\t\t Distance between %s and %s is %f",city_1.name,city_2.name,Distance);
	return 0;
}
