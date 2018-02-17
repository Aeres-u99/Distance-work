# Distance-Calculator Using Haversine Formula
      HAVERSINE FORMULA
The haversine formula determines the great-circle distance between two points on a sphere given their longitudes and latitudes. Important in navigation, it is a special case of a more general formula in spherical trigonometry, the law of haversines, that relates the sides and angles of spherical triangles.

The first table of haversines in English was published by James Andrew in 1805,but Florian Cajori credits an earlier use by José de Mendoza y Ríos in 1801.The term haversine was coined in 1835 by James Inman.
[Wikipedia :p]


Haversine
formula: 	a = sin²(Δφ/2) + cos φ1 ⋅ cos φ2 ⋅ sin²(Δλ/2)
c = 2 ⋅ atan2( √a, √(1−a) )
d = R ⋅ c
where 	φ is latitude, λ is longitude, R is earth’s radius (mean radius = 6,371km);
note that angles need to be in radians to pass to trig functions!

now here in my code I have mostly tried to use obvious names for variables and thanx to my bad choice of using structures, the variable names are very long but descriptive.

I have used various functions to achieve the tasks and yeah the next stage will be to include commandline arguments for it [as per ladyElusive's Suggestion she is here :https://github.com/cruelthesis :p]
But before that I am planning to implement the same in Python mostly py3 as that is latest :p as per amigojapan_bnc's suggestion.
[dont forget to check his website:  http://amigojapan.github.io/ ]
And also thanx for advice KaffeeJunky123 :)
