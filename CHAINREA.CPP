#include<iostream.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>

struct position
{
	int arr;
	char col;
};

void main()
{
	position pos[10][6];
	int i,j,x,y,chance=0;
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	setbkcolor(0);
	setcolor(2);
	for(i=0;i<10;i++)
		for(j=0;j<6;j++)
			pos[i][j].arr=0;
	for(i=185;i<=455;i+=45)
		line(i,15,i,465);
	for(j=15;j<=465;j+=45)
		line(185,j,455,j);
	pos[0][0].arr=2;
	while(chance!=1)
	{
		cout<<"\nEnter the position(x,y):\n";
		cin>>x>>y;x--;y--;
		pos[y][x].arr++;

		cleardevice();
		setbkcolor(0);
		setcolor(2);
		for(i=185;i<=455;i+=45)
			line(i,15,i,465);
		for(j=15;j<=465;j+=45)
			line(185,j,455,j);
		setcolor(4);
		setfillstyle(1,RED);
		for(i=0;i<10;i++)
		{
			for(j=0;j<6;j++)
			{
				if(pos[y][x].arr<=3)
				{
					if(pos[y][x].arr>0)
					{
						circle(185+45*(x)+22.5,15+45*(y)+22.5,7.5);
						floodfill(185+45*(x)+22.5,15+45*(y)+22.5,RED);
					}
					if(pos[y][x].arr>1)
					{
						circle(185+45*(x)+13,15+45*(y)+20,6.5);
						floodfill(185+45*(x)+13,15+45*(y)+20,RED);
					}
					if(pos[y][x].arr>2)
					{
						circle(185+45*(x)+30,15+45*(y)+20,6.5);
						floodfill(185+45*(x)+30,15+45*(y)+20,RED);
					}

				}
			}
		}
		chance=1;
	}
	getch();


	closegraph();
}