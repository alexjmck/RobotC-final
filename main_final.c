

/* Final project.
   Authors: Nataniel, Alexander, Raymond.
   APSC 142

   This program runs a roller coaster simulation based off the colours on the ground.
   Use walls to on 45 degree angles for the robot to bump off of to que it to do a 90 degree turn.

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
	int count = 0;
	int colourCode;
  int soundLevel = 0;
  int touch = 0;

 	colourCode = getColorName(S1); 		//Retrieves the colour name from sensor

  // Set sensor type
  SensorType[S1] = sensorEV3_Color;
  SensorType[S2] = sensorEV3_Touch;
  SensorType[S3] = sensorEV3_Touch;
  SensorType[S4] = sensorSoundDB;

  wait1Msec(1000);									//Initialize the sound sensor

  soundLevel = SensorValue[sensorSoundDB];		//Set sound level

  while(soundLevel <= 90){       //Wait for loud clap
  		readyFace();
  		wait1Msec(30);
}
  happyFace();

	wait1Msec(5000);

  while(soundLevel >= 50){       //Wait for loud clap to stop. Contains main function

	}

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

	spiral();

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
