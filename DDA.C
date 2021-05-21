/* cg_1.c: write a program to draw a line from (x1,y1) to (x2,y2) using DDA algorithm */
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void line_draw(int x1,int y1,int x2,int y2);
int dda(int x1,int y1,int x2,int y2,int x[],int y[]);
int round1(float x);
void draw_xy();
void plot_line(int x[],int y[],int n,int c);
void main()
{
int x1,y1,x2,y2;
int x[700],y[700];
int n,c;
clrscr();
printf("\nEnter x1=");
scanf("%d",&x1);
printf("\nEnter y1=");
scanf("%d",&y1);
printf("\nEnter x2=");
scanf("%d",&x2);
printf("\nEnter y2=");
scanf("%d",&y2);
printf("\nEnter color code of your line(0-14):");
scanf("%d",&c);
line_draw(x1,y1,x2,y2);
getch();
}
void line_draw(int x1,int y1,int x2,int y2)
{
int x[700],y[700];
int n,c;
printf("\nEnter color code of your line:");
scanf("%d",&c);
n=dda(x1,y1,x2,y2,x,y);
draw_xy();
plot_line(x,y,n,c);
}
int dda(int x1,int y1,int x2,int y2,int x[],int y[])
{
int dx,dy;
float delx,dely,xx,yy;
int length,n;
dx=x2-x1;
dy=y2-y1;
	if(abs(dx)>abs(dy))
	length=abs(dx);
	else
	length=abs(dy);
delx=(float)dx/length;
dely=(float)dy/length;
xx=x1;
yy=y1;
x[0]=round1(xx);
y[0]=round1(yy);
	for(n=1;n<=length;n++)
	{
	xx=xx+delx;
	yy=yy+dely;
	x[n]=round1(xx);
	y[n]=round1(yy);
	}
printf("\nPress any key to display all points-->");
getch();
clrscr();
	for(n=0;n<=length;n++)
	{
	printf("x[%d]=%d  y[%d]=%d\n",n,x[n],n,y[n]);
		if(((n+1) % 20) == 0)
		{
		printf("\nPress any key to continue-->");
		getch();
		clrscr();
		}
	}
printf("\nPress any key to continue--->");
getch();
return length;
}
int round1(float x)
{
float x1;
int ix;
ix=(int)x;
x1=x-(float)ix;
x1=abs(x1);
	if(x1>=0.5)
	{
		if(x>=0)
		ix=ix+1;
		else
		ix=ix-1;
	}
return ix;
}
void draw_xy()
{
int i,c,c1;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c://turboc3//BGI");
c=15;
/*to draw x-axis*/
	for(i=0;i<=639;i++)
	{
	putpixel(i,240,c);
	delay(10);
	}
/*to draw y-axis*/
	for(i=0;i<=479;i++)
	{
	putpixel(320,i,c);
	delay(10);
	}
c1=6; /*c1=back ground color*/
setbkcolor(c1);
outtextxy(620,245,"+X");
outtextxy(10,245,"-X");
outtextxy(330,20,"+Y");
outtextxy(330,460,"-Y");
outtextxy(330,245,"O");
}
void plot_line(int x[],int y[],int n,int c)
{
	int i;
		for(i=0;i<=n;i++)
		{
		putpixel(320+x[i],240-y[i],c);
		delay(10);
		}
}

