

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
void sadFace();
void readyFace();

//Spiral Function
void spiral();


task main()
{
	int count=0;
	int colourCode;
	
	while(clap<50)
	{
		readyface();
		
	}
	
	while(count<2000)
	{
		count = count + 1;
		wait1Msec(2);
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
	
	
	
}
void readyFace(){
	drawBmpfile(0, 127, "Black eye");
	sleep(2000);	
	
	
}

/* Spiral */

void spiral(){
	
}
