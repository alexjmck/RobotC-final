

/* Final project.
   Authors: Nataniel, Alexander, Raymond.
   APSC 142

*/

//Colour detections
void greenDownhill();
void blueUphill();
void redLoop();

//Turn functions
void turnLeft();
void turnRight();

//Face Functions
void happyFace();
void dizzyFace();
void readyFace();

//Spiral Function
void spiral();

//Dizzy eyes declarations
float xAngle, yAngle;
int X,X1,Y1,Y;
float xRadius, yRadius;
bool work = true;


task main()
{
	//	int count=0;
	//	int colourCode;
	
	spiral();
	wait1Msec(100);
	
/*	while(clap<50)
	{
		readyface();
		
	}
	
	while(count<2000)
	{
		count = count + 1;
		wait1Msec(2);
	}
*/	
}



/* Colour Functions */

void greenDownhill(){
	
}

void blueUphill(){
	
}

void redLoop(){
	
}


/* Turn Functions */

void turnLeft(){
	
}

void turnRight(){
	
}


/* Face Functions */
void happyFace() {
		drawBmpfile(0, 127, "Big smile");
		sleep(2000);
	
	
}
void dizzyFace(){
	
	
	
}
void readyFace(){
		drawBmpfile(0, 127, "Black eye");
		sleep(2000);	
	
	
}

/* Spiral */

void spiral()
{	
	eraseDisplay();
	while (work)
	{
		// Draw the spiral
		xRadius = 32;
		yRadius = 32;
		xAngle = 0;
		yAngle = 0;
		while(xRadius > 0)
		{
			float xSin1,x1Sin1;
			float yCos1,y1Cos1;
			float xSin2,x1Sin2;
			float yCos2,y1Cos2;
			float fRadians,f1Radians;
			
			fRadians = xAngle * PI /(float) 180.0;
			f1Radians = yAngle * PI /(float) 180.0;
			xSin1 = sin(f1Radians);
			x1Sin1 = sin(fRadians);
			yCos1 = cos(fRadians);
			y1Cos1 = cos(f1Radians);
			xSin2 = sinDegrees(xAngle);
			x1Sin2 = sinDegrees(yAngle);
			yCos2 = cosDegrees(xAngle);
			y1Cos2 = cosDegrees(yAngle);
			X = sinDegrees(xAngle) * xRadius;
			X1 = sinDegrees(yAngle) * yRadius;
			Y = cosDegrees(xAngle) * xRadius;
			Y1 = cosDegrees(yAngle) * yRadius;
			setPixel(X + 40, Y + 72);
			setPixel(X1 + 120, Y1 + 72);
			wait1Msec(1);
			xRadius -=.02;
			yRadius -=.02;
			++xAngle;
			++yAngle;
		}
		
		// Erase the spiral
		while(xRadius <= 32)
		{
			X = sinDegrees(xAngle)  * xRadius;
			X1 = sinDegrees(yAngle)  * yRadius;
			Y = cosDegrees(xAngle) * xRadius;
			Y1 = cosDegrees(yAngle) * yRadius;
			clearPixel(X + 40, Y + 72);
			clearPixel(X1 + 120, Y1 + 72);
			wait1Msec(1);
			xRadius += .02;
			yRadius += .02;
			--xAngle;
			--yAngle;
			work = false;
		}
		
	}
	
}
