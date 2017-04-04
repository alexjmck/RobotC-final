

/* Final project - Legend of Zelda Roller Coaster
Authors: Nataniel, Alexander, Raymond.
APSC 142

This program will begin waiting for a clap. Then it will play A shortened Legend of Zelda Theme song.

This program runs a roller coaster simulation based off the colours on the ground.

Use walls to on 45 degree angles for the robot to bump off of to que it to do a 90 degree turn.

Musical Note dictionary primarily sourced from Tinkernology.blogspot.com and various other sources.

*/

// Predetermined Motor Speeds
#define TURN_SPEED 25					// Turn motor speed

//#pragma config(Sensor, S1,   soundSensor,         sensorSoundDB)

int speedIntitial = 31;
int speedReverse = -31;

// Musical note dictionary. Each note mapped to a frequency
// Frequency (note)
// Example: A_3 is A in the third octave
// Ash_3 is A# in the third octave
int C_3 = 261;
int Csh_3 = 275;
int D_3 = 293;
int Dsh_3 = 310;
int E_3 = 329;
int F_3 = 348;
int Fsh_3 = 370;
int G_3 = 392;
int Gsh_3 = 412;
int A_3 = 440;
int Ash_3 = 466;
int B_3 = 496;
int C_4 = 524;
int Csh_4 = 555;
int D_4 = 590;
int Dsh_4 = 621;
int E_4 = 656;
int F_4 = 695;
int Fsh_4 = 738;
int G_4 = 788;
int Gsh_4 = 830;
int A_4 = 877;
int Ash_4 = 929;
int B_4 = 987;
int C_5 = 1054;
int Csh_5 = 1104;
int D_5 = 1188;
int Dsh_5 = 1251;
int E_5 = 1322;
int F_5 = 1401;
int Fsh_5 = 1488;
int G_5 = 1590;
int Gsh_5 = 1646;
int A_5 = 1770;
int Ash_5 = 1841;
int B_5 = 1995;

// Note Length Reference
int Dwhole = 200;
int Whole = 100;
int Half = 50;
int Quarter = 25;
int Eighth = 13;
int Sixteenth = 6;

// Legend of Zelda Theme song array
int Notes[][]= //currently "Legend of Zelda", Change these notes for a new song
{
	{	Ash_3, Quarter},
	{	F_3, Half},
	{	Ash_3, Sixteenth},
	{	Ash_3, Sixteenth},
	{	C_4, Sixteenth},
	{	D_4, Sixteenth},
	{	Dsh_4, Sixteenth},
	{	F_4, Half},
	{	F_4, Eighth},
	{	F_4, Eighth},
	{	Fsh_4, Eighth},
	{	Gsh_4, Eighth},
	{	Ash_4, Half},
	{	Ash_4, Eighth},
	{	Ash_4, Eighth},
	{	Ash_4, Eighth},
	{	Gsh_4, Eighth},
	{	Fsh_4, Eighth},
	{	Gsh_4, Eighth},
	{	Fsh_4, Eighth},
	{	F_4, Half},
	{	F_4, Quarter},
	{	Dsh_4, Eighth},
	{	Dsh_4, Sixteenth},
	{	F_4, Sixteenth},
	{	Fsh_4, Half},
	{	F_4, Eighth},
	{	Dsh_4, Eighth},
	{	Csh_4, Eighth},
	{	Csh_4, Sixteenth},
	{	Dsh_4, Sixteenth},
	{	F_4, Half},
	{	Dsh_4, Eighth},
	{	Csh_4, Eighth},
	{	C_4, Eighth},
	{	C_4, Sixteenth},
	{	D_4, Sixteenth},
	{	E_4, Half},
	{	G_4, Quarter},
	{	F_4, Eighth},
	{	F_3, Sixteenth},
	{	F_3, Sixteenth},
	{	F_3, Eighth},
	{	F_3, Sixteenth},
	{	F_3, Sixteenth},
	{	F_3, Eighth},
	{	F_3, Sixteenth},
	{	F_3, Sixteenth},
	{	F_3, Quarter},
};


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
	//	int speedIntitial = 31;
	//	int speedReverse = -31;
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
	// Music Program playing Legend of Zelda theme.
	
	for (int i=0; i<49; i++) //Number is number of notes in song.
	{
		playTone(Notes[i][0], Notes[i][1]);
		while(bSoundActive)
			wait1Msec(20);
	}
	
	forwardDrive(forwardSpeed);
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
			forwardDrive(forwardSpeed);
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
	setMotorSpeed(motorC,(-speed));
	setMotorSpeed(motorB,(speed));
	setMotorSpeed(motorC,(-speed));
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
		setMotorSpeed(motorC,(-1 * TURN_SPEED));
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
