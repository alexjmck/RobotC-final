/* Remote control NXT
Authors: Alexander McKinnon, Nataniel Canisius, Raymond Chan

The goal of this program is to send the slave robot its
stopping function that ends the main function.


*/
int wait = 1;
int number = 40;

task main()
{

	while(wait == 1)
	{
		displayTextLine(1, "Press button to stop the robot");
	}

	displayTextLine(1, "Stopping the robot");

	sendMessage(number);

	wait1Msec(5000);


}
