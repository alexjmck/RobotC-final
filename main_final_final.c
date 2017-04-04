

/* Final project.
Authors: Nataniel, Alexander, Raymond.
APSC 142

This program runs a roller coaster simulation based off the colours on the ground.
Use walls to on 45 degree angles for the robot to bump off of to que it to do a 90 degree turn.

*/

// Predetermined Motor Speeds
#define TURN_SPEED 25					// Turn motor speed

//#pragma config(Sensor, S1,   soundSensor,         sensorSoundDB)

int speedIntitial = 31;
int speedReverse = -31;

// Predeterminged Wait Times

#define TURN_DURATION 1000

//Turn functions
void turnOnSpot (int bump);

//Face Functions
void happyFace();
void sadFace();

//Spiral Function
void spiral();

void forwardDrive(int speed);
void loopdeloop(int speed);
void stopMotor();

//Dizzy eyes declarations
float xAngle, yAngle;
int X,X1,Y1,Y;
float xRadius, yRadius;
bool work = true;

task main()
{
	int speedIntitial = 31;
	int speedReverse = -31;
	int count = 0;
	int colourCode;
	int soundLevel = 0;
	int touch = 0;
	int Leftbump = 0;			// bumper condition
	int Rightbump = 0;
	int touchStatusCode;
	int forwardSpeed = 40;			// speed for forward driving
	int driveTime = 2000;
	int waitTime = 100;
int soundspeed = 0;
bool highsound =false;

	// Set sensor type
	SensorType[S1] = sensorEV3_Color;
	SensorMode[S1] = modeEV3Color_Color;
	SensorType[S2] = sensorEV3_Touch;
	SensorType[S3] = sensorEV3_Touch;
	SensorType[S4] = sensorSoundDB;

	wait1Msec(1000);		//Gives time to initialize the sound sensor

   while(highsound == false)            // Infinite loop
   {
    sadFace();
    wait1Msec(10);
    soundspeed = SensorValue[S4];
    if (soundspeed > 20)
    {
     highsound = true;
    }
   }

	forwardDrive(forwardspeed);
	happyFace();

	for (int i = 0; i < 20; i++)
	{
		colourCode = getColorName(S1);
		Leftbump = getTouchValue(S2);
		Rightbump = getTouchValue(S3);
		touchStatusCode = Leftbump + (2 * Rightbump);
		wait1Msec(50);

		// Loopdeloop
		if (colourCode == colorBlue)
		{
			setLEDColor(ledGreenFlash);
			spiral();
			loopdeloop(forwardSpeed);
			wait1Msec(1000);
		}

		//Uphill
		else if (colourCode == colorGreen)
		{
			setLEDColor(ledGreen);
			happyFace();
			wait1Msec(driveTime);
		}

		//downhill
		else if (colourCode == colorRed)
		{
			setLEDColor(ledRed);
			spiral();
			wait1Msec(driveTime);
			forwardDrive(forwardspeed);
		}

		//move forward
		else if (colourCode == colorYellow)
		{
			setLEDColor(ledOrangeFlash);
			happyFace();
			wait1Msec(driveTime);
		}

		//stop
		else if (colourCode == colorBlack)
		{
			setLEDColor(ledOff);
			sadFace();
			stopMotor();
			setMotorSpeed(motorD,-100);
			 motor[motorA] = 50;
			wait1Msec(driveTime);
		}

		if (Leftbump == 1)
		{
			turnOnSpot(touchStatusCode);
			wait1Msec(waitTime);
		}
		else if (Rightbump == 1)
		{
			turnOnSpot(touchStatusCode);
			wait1Msec(waitTime);
		}
	}
}

// function definitions
void forwardDrive(int speed)
{
	setMotorSpeed(motorB,speed);
	setMotorSpeed(motorC,speed);
}

void loopdeloop (int speed)
{
	setMotorSpeed(motorB, speed);
	setMotorSpeed(motorC,(-speed);
	setMotorSpeed(motorB,(speed));
	setMotorSpeed(motorC,(-speed);
}

/* Turn Functions */
void turnOnSpot (int bump)
{
	if (bump == 1)
	{
		setMotorSpeed(motorB,(-1 * TURN_SPEED));
		setMotorSpeed(motorC,(TURN_SPEED));
		wait1Msec(3*1000/4);
	}
	else if (bump == 2)
	{
		setMotorSpeed(motorB,(TURN_SPEED));
		setMotorSpeed(motorC,(-1 * TURN_SPEED);
		wait1Msec(3*1000/4);
	}
}

void stopMotor()
{
	setMotorSpeed(motorB,0);
	setMotorSpeed(motorC,0);
}

/* Face Functions */
void happyFace() {
	drawBmpfile(0, 127, "Big smile");
	setMotorSpeed(motorD,100);
	sleep(2000);
}

void sadFace(){
	drawBmpfile(0, 127, "Black eye");
	sleep(2000);
}

/* Spiral eyes face */

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
