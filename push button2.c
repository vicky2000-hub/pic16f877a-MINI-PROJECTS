#include<pic.H>
void main()
{
	TRISB0=0;
    TRISB1=1;

	if(RB1==1)
	{
		RB0=1;
    }
    else
    {
      RB0=0;
    }
}