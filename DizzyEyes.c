
/* Spiral eyes
   This code will be eventually incorperated into the main_final.c 
   once we confirm that this works on it's own.
*/

float xAngle, yAngle;
int X,X1,Y1,Y;
float xRadius, yRadius;
bool work = true;

task main()
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
			SetPixel(X + 40, Y + 72);
			SetPixel(X1 + 120, Y1 + 72);
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
			ClearPixel(X + 40, Y + 72);
			ClearPixel(X1 + 120, Y1 + 72);
			wait1Msec(1);
			xRadius += .02;
			yRadius += .02;
			--xAngle;
			--yAngle;
			work = false;
		}

	}
}
