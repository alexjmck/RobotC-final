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
//Duration
int Dwhole = 200;
int Whole = 100;
int Half = 50;
int Quarter = 25;
int Eighth = 13;
int Sixteenth = 6;

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

task main()
{
	for (int i=0; i<48; i++) //change the "49" to the new number of notes in the piece
	{
		playTone(Notes[i][0], Notes[i][1]);
		while(bSoundActive);
		wait1Msec(20);
	}
}
