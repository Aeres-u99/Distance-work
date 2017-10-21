 /*------------------------------------------------------------------------------------*/ 
/* Hello this program is Meant to calculate Distance between two cities */ /* It works on 
input of Angles in degrees ,Though it Requires angle in Radians. Dont worry it will 
be easy as we will be converting the inputted angle in rads                           */ 
/*------------------------------------------------------------------------------------*/
#include<stdio.h>		//For basic Oprations of inputting and Printing
#include<math.h>		//This one is for Mathematical operation
#define pi 3.1415962
#define R 6366.707
#define minutes 0.01666666666666667
#define seconds 0.00027777777777778
int main()
{
	struct details						//I felt it will come in Really handy to use Structure
{
	float lat_deg,lat_min,lat_sec;
	float lon_deg,lon_min,lon_sec;
	char name[25];
	float lat_angle_deg,lat_angle_rad;//this is where we Store
	float lon_angle_deg,lon_angle_rad;//the Angle in RAdians Also Note in
							//decimal form
}city_1,city_2;
	float lon_diff,lat_diff;
	double theta;		//Alone as it is Important
	float distance,a_factor;
	float	numerator,dr;
	float x1,x2,y1,y2,z1,z2;			//In the End i think i have to 
								//rely on dev logic
	printf("Hello \n THis program will calculate distance between Two cities\n\n ");
	printf("\t YOu will need cities lattitude and longitude in Degrees\n");
/*-------------------------------------------------------------------------------*/
	printf("\t\t Input the Details:\n");
	printf("City 1:\n");				//CIty 1 details
	printf("\t\t Input Name: ");
	scanf("%s",&city_1.name);
		printf("\n");
	printf("\t\t Input the Further details: \n");
	printf("\t\t  lattitude degrees: ");
	scanf("%f",&city_1.lat_deg);
	printf("\n\t\t  lattitude Minutes: ");
	scanf("%f",&city_1.lat_min);
	printf("\n\t\t  lattitude seconds: ");
	scanf("%f",&city_1.lat_sec);
	printf("\n\t\t Input the Further details: \n");
	printf("\n\t\t  longitude degrees: ");
	scanf("%f",&city_1.lon_deg);
	printf("\n\t\t  longitude Min: ");
	scanf("%f",&city_1.lon_min);
	printf("\n\t\t  longitude seconds: ");
	scanf("%f",&city_1.lon_sec);
	 	printf("City 2:\n");				//CIty 2 details
		printf("\t\t Input Name: ");
		scanf("%s",&city_2.name);
		printf("\n");
		printf("\t\t Input the Further details: \n");
		printf("\t\t  lattitude degrees: ");
		scanf("%f",&city_2.lat_deg);
		printf("\n\t\t  lattitude Minutes: ");
		scanf("%f",&city_2.lat_min);
		printf("\n\t\t  lattitude seconds: ");
		scanf("%f",&city_2.lat_sec);
		printf("\n\t\t Input the Further details: \n");
		printf("\n\t\t  longitude degrees: ");
		scanf("%f",&city_2.lon_deg);
		printf("\n\t\t  longitude Min: ");
		scanf("%f",&city_2.lon_min);
		printf("\n\t\t  longitude seconds: ");
		scanf("%f",&city_2.lon_sec);
printf("\nCalculating...\n");
/*------------------------------------------------------------------------------*/
/*------------------------Here Starts MAthematical Stuff------------------------*/
/*------------------------------------------------------------------------------*/
city_1.lat_min *= minutes;
city_1.lat_sec *= seconds;
city_1.lon_min *= minutes;
city_1.lon_sec *= seconds;
city_2.lat_min *= minutes;
city_2.lat_sec *= seconds;
city_2.lon_min *= minutes;
city_2.lon_sec *= seconds;
/*-------------------This part is for proper ddegree to RAdian conversion-----------------------*/
city_1.lat_angle_deg = city_1.lat_deg + city_1.lat_min + city_1.lat_sec ;
city_1.lon_angle_deg = city_1.lon_deg + city_1.lon_min + city_1.lon_sec ;
city_2.lat_angle_deg = city_2.lat_deg + city_2.lat_min + city_2.lat_sec ;
city_2.lon_angle_deg = city_2.lon_deg + city_2.lon_min + city_2.lon_sec ;
city_1.lat_angle_rad = city_1.lat_angle_deg*(pi/180);
city_1.lon_angle_rad = city_1.lat_angle_deg*(pi/180);
city_2.lat_angle_rad = city_2.lat_angle_deg*(pi/180);
city_2.lon_angle_rad = city_2.lon_angle_deg*(pi/180);
/*_--------------------------Printing Stuffs----------------------------------------------------*/
	printf("\n\t\t\t %f: City 1-lattitude angle in degree",city_1.lat_angle_deg);
	printf("\n\t\t\t %f: City 1-longitude angle in degree",city_1.lon_angle_deg);
	printf("\n\t\t\t %f: City 2-lattitude angle in degree",city_2.lat_angle_deg);
	printf("\n\t\t\t %f: City 2-longitude angle in degree",city_2.lon_angle_deg);
	printf("\n\t\t\t %f: City 1-lattitude angle in radians",city_1.lat_angle_rad);
	printf("\n\t\t\t %f: City 1-longitude angle in radians",city_1.lon_angle_rad);
	printf("\n\t\t\t %f: City 2-lattitude angle in radians",city_2.lat_angle_rad);
	printf("\n\t\t\t %f: City 2-longitude angle in radians",city_2.lon_angle_rad);
/*-----------------------------------------------------------------------------*/
/*---------------------MAthematical Conversion Finished------------------------*/
/*-----------------------------------------------------------------------------*/
/*---------------------------Now Comes formula Part----------------------------*/
/*-----------------------------------------------------------------------------*/
/*Formula Name: Vincenty Formula: TL;DW */
lat_diff = (city_1.lat_angle_rad)-(city_2.lat_angle_rad);
lat_diff = fabs(lat_diff);
	printf("\n\t\t\t Lattitude difference between Cities : %f",lat_diff);
lon_diff = (city_1.lon_angle_rad)-(city_2.lon_angle_rad);
lon_diff = fabs(lon_diff);

		printf("\n\t\t\t Longitude difference between cities : %f ",lon_diff);
	
 	x1 = R*(cos(city_1.lon_angle_rad)*sin(city_1.lat_angle_rad));
 y1 = R*(sin(city_1.lon_angle_rad)*sin(city_1.lat_angle_rad));
 z1 = R*cos(city_1.lat_angle_rad);


	x2 = R*(cos(city_2.lon_angle_rad)*sin(city_2.lat_angle_rad));
	y2 = R*(sin(city_2.lon_angle_rad)*sin(city_2.lat_angle_rad));
	z2 = R*cos(city_2.lat_angle_rad);


a_factor = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
		printf("\n\t\t a_factor : %f",a_factor);
		numerator = (R*R)+(R*R)-(a_factor)*(a_factor);
		printf("\n\t\t Print the a_factor: %f",a_factor);
		dr = (numerator)/(2*R*R);
		printf("\n\t\t\t\t\t This is trial Print dr : %f");
		theta = acos(dr);
		printf("\n\t\t theta : %f ",theta);
		distance = R*theta;


/*-------------------------------------------------------------------------------*/
/*------------------------------- Finishing Touch--------------------------------*/
/*-------------------------------------------------------------------------------*/
printf("\n________________________________________________________________________\n");
printf("\t\tDistance between two cities is %f km",distance);
printf("\n------------------------------------------------------------------------\n");
return 0;
}
