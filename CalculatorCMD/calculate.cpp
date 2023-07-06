#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//Addition
float Add(float a, float b){
	return a + b;
}

//Substraction
float Substract(float a, float b){
	return a - b;
}

//Multiplication
float Multiplication(float a, float b){
	return a * b;
}

//Division
float Division(float a, float b){
	return a / b;
}

//Power
float Power(float a, float b){
	return pow(a,b);
}

//Root
float Root(float a, float b){
	return pow(a, 1/ b);
}

//Division
int Div(float a, float b){
	return a / b;
}

//Mod
int Mod(int a, int b){
	return a % b;
}

//Convertiong Degree to Radius
float degToRad(float deg){
	return (deg * M_PI / 180);
}

//Sin
float Sin(float a){
	return sin(degToRad(a));
}

//Cos
float Cos(float a){
	return cos(degToRad(a));
}

//Tan
float Tan(float a){
	return tan(degToRad(a));
}

//Log
float Log(float a){
	return log10(a);
}

//Ln
float Ln(float a){
	return log(a);
}

//Factorial
int Factorial(int a){
	if (a == 0 || a == 1){
		return 1;
	}
	else{
		return a * Factorial(a - 1);
	}
}


int main(int argc, char **argv){
	
	float a, b;
	
	//Checking if the argc is 4 arguments or 3 arguments
	if (argc == 4){
		a = atof(argv[1]);
		b = atof(argv[3]);
		
		//Addition
		if (strcmp(argv[2], "+") == 0){
			printf("%0.2f + %0.2f = %0.2f",a,b,Add(a,b));
		}
		
		//Substraction
		else if (strcmp(argv[2], "-") == 0){
			printf("%0.2f - %0.2f = %0.2f",a,b,Substract(a,b));
		}
		
		//Multiplication
		else if (strcmp(argv[2], "x") == 0){
			printf("%0.2f x %0.2f = %0.2f",a,b,Multiplication(a,b));
		}
		
		//Division
		else if (strcmp(argv[2], "/") == 0){
			printf("%0.2f / %0.2f = %0.2f",a,b,Division(a,b));	
		}
		
		//Power
		else if (strcmp(argv[2], "power") == 0){
			printf("%0.2f power %0.2f = %0.2f",a,b,Power(a,b));
		}
		
		//Root
		else if (strcmp(argv[2], "root") == 0){
			printf("%0.2f root %0.2f = %0.2f",a,b,Root(a,b));
		}
		
		//Div
		else if (strcmp(argv[2], "div") == 0){
			printf("%0.2f div %0.2f = %i",a,b,Div(a,b));
		}
		
		//Mod
		else if (strcmp(argv[2], "mod") == 0){
			printf("%0.2f mod %0.2f = %i",a,b,Mod(a,b));
		}
		
		//If the variable is wrong
		else{
			printf("--Invalid input--\n");
			printf("These are the command for 4 variables ! ! \n");
			printf("- A + B \n");
			printf("- A - B \n");
			printf("- A x B \n");
			printf("- A / B \n");
			printf("- A power B \n");
			printf("- A root B \n");
			printf("- A div B \n");
			printf("- A mod B \n");

		}
	}
	
	//Checking if the argc is 4 arguments or 3 arugments
	if (argc == 3){
		a = atof(argv[2]);
		
		//Sin
		if (strcmp(argv[1], "sin") == 0){
			printf("%s %.1f = %.2f", argv[1], a, Sin(a));
		}
		
		//Cos
		else if (strcmp(argv[1], "cos") == 0){
			printf("%s %.1f = %.2f", argv[1], a, Cos(a));
		}
		
		//Tan
		else if (strcmp(argv[1], "tan") == 0){
			printf("%s %.1f = %.2f", argv[1], a, Tan(a));
		}
		
		//Mod
		else if (strcmp(argv[1], "log") == 0){
			printf("%s %.1f = %.2f", argv[1], a, Log(a));
		}
		
		//Ln
		else if (strcmp(argv[1], "ln") == 0){
			printf("%s %.1f = %.2f", argv[1], a, Ln(a));
		}
		
		//Factorial
		else if (strcmp(argv[1], "factorial") == 0){
			printf("%s %.f = %i", argv[1], a, Factorial(a));
		}
		
		//If the variable is wrong
		else {
			printf("--Invalid input--\n");
			printf("These are the command for 3 variables ! ! \n");
			printf("- sin X \n");
			printf("- cos X \n");
			printf("- tan X \n");
			printf("- log X \n");
			printf("- ln X \n");
			printf("- factorial X \n");
		}
	}
	

	//If the users forgot the arithmatic or not using CMD
    if (argc == 1) {
    
        printf("Please run this code in cmd !!.\n");
        printf("If you already in cmd you must have forgot the arithmetic calculation!");

	//If the users input more than 4 arguments
    } else if (argc > 4 || argc < 3) {
			printf("--Invalid input--\n");
			printf("These are the command for 4 variables ! ! \n");
			printf("- A + B \n");
			printf("- A - B \n");
			printf("- A x B \n");
			printf("- A / B \n");
			printf("- A power B \n");
			printf("- A root B \n");
			printf("- A div B \n");
			printf("- A mod B \n");

			printf("These are the command for 3 variables ! ! \n");
			printf("- sin X \n");
			printf("- cos X \n");
			printf("- tan X \n");
			printf("- log X \n");
			printf("- ln X \n");
			printf("- factorial X \n");
        return 1;
    }

	return 0;
}