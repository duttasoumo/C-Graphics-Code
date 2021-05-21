/*circle_c.c: Write a program to connect the centres of  four circles*/
#include<stdio.h>
#include<graphics.h>
int c,bgcolor;
void circle_draw(int xc,int yc,int r);
void draw_xy();
void plot_xy(int x[],int y[],int xc,int yc,int n);
void line_draw(int x1,int y1,int x2,int y2);
int bresenham(int x1,int y1,int x2,int y2,int x[],int y[]);
int sign(int x);
int round1(float x);
void plot_line(int x[],int y[],int n);//n=no of points , c=color code


void main()
{
int xc1,yc1,xc2,yc2,xc3,yc3,xc4,yc4,r1,r2,r3,r4;
clrscr();
printf("\nEnter x-coordinate of circle1:");
scanf("%d",&xc1);
printf("\nEnter y-coordinate of circle1:");
scanf("%d",&yc1);
printf("\nEnter x-coordinate of circle2:");
scanf("%d",&xc2);
printf("\nEnter y-coordinate of circle2:");
scanf("%d",&yc2);
printf("\nEnter x-coordinate of circle3:");
scanf("%d",&xc3);
printf("\nEnter y-coordinate of circle3:");
scanf("%d",&yc3);
printf("\nEnter x-coordinate of circle4:");
scanf("%d",&xc4);
printf("\nEnter y-coordinate of circle4:");
scanf("%d",&yc4);
printf("\nEnter radius of circle1:");
scanf("%d",&r1);
printf("\nEnter radius of circle2:");
scanf("%d",&r2);
printf("\nEnter radius of circle3:");
scanf("%d",&r3);
printf("\nEnter radius of circle4:");
scanf("%d",&r4);
printf("\nEnter background colour code:");
scanf("%d",&bgcolor);
printf("\nEnter colour code of the circles:");
scanf("%d",&c);
draw_xy();
circle_draw(xc1,yc1,r1);
circle_draw(xc2,yc2,r2);
circle_draw(xc3,yc3,r3);
circle_draw(xc4,yc4,r4);
line_draw(xc1,yc1,xc2,yc2);
line_draw(xc2,yc2,xc3,yc3);
line_draw(xc3,yc3,xc4,yc4);
line_draw(xc4,yc4,xc1,yc1);
getch();
closegraph();
}
/*void circle_draw(int xc,int yc,int r) : Function to draw
a circle using Bresenham algorithm*/
void circle_draw(int xc,int yc,int r)
{
int xk,yk,n,d;
float pk;
int x[1200],y[1200];//320*4=1280 points in total. 320 points on the first quadrant
int i,j,n1,n2;
xk=0;
yk=r;
n=0;
	while(yk>=0)
	{
	n++;
	x[n]=xk;
	y[n]=yk;
	d=(xk+1)*(xk+1)+(yk-1)*(yk-1)-r*r;
		if(d<0)
		{
		pk=(xk+1)*(xk+1)+(yk-.5)*(yk-.5)-r*r;
			if(pk<=0)
			xk=xk+1;
			else
			{
			xk=xk+1;
			yk=yk-1;
			}
		}
		else if(d>0)
		{
		pk=(xk+.5)*(xk+.5)+(yk-1)*(yk-1)-r*r;
			if(pk<=0)
			{
			xk=xk+1;
			yk=yk-1;
			}
			else
			yk=yk-1;
		}
		else
		{
		xk=xk+1;
		yk=yk-1;
		}
	}
	/*To take reflection of all points along x-axis*/
n1=2*n-1;
j=n-1;
	for(i=n+1;i<=n1;i++)
	{
	x[i]=x[j];
	y[i]=-y[j];
	j=j-1;
	}
	/*To take reflection of all points along y-axis*/
n2=4*n-4;
j=n1-1;
	for(i=n1+1;i<=n2;i++)
	{
	x[i]=-x[j];
	y[i]=y[j];
	j=j-1;
	}
plot_xy(x,y,xc,yc,n2);
}

/* void draw_xy() : Function to display x-axis, y-axis */
void draw_xy()
{
int i,c,c1;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C://turboc3//BGI");
c=15;
/* To draw x-axis */
	for(i=0;i<=639;i++)
	{
	putpixel(i,240,c);
	delay(2);
	}
/* To draw y-axis */
	for(i=0;i<=479;i++)
	{
	putpixel(320,i,c);
	delay(2);
	}
setbkcolor(bgcolor);
outtextxy(620,245,"+X");
outtextxy(10,245,"-X");
outtextxy(330,20,"+Y");
outtextxy(330,460,"-Y");
outtextxy(330,245,"O");
outtextxy(350,25,"Name:Anwesha Chakraborty Roll:581");
}

/* void plot_xy(int x[],int y[],int xc,int yc,int n): Function to draw circle*/
void plot_xy(int x[],int y[],int xc,int yc,int n)
{
int i;
char a[80];
	for(i=1;i<=n;i++)
	{
	putpixel(x[i]+320+xc,240-y[i]-yc,c);
	delay(10);
	}
sprintf(a,"C(%d,%d)",xc,yc);
outtextxy(xc+320,240-yc,a);
}

	/*void line_draw(int x1,int y1,int x2,int y2) : Function to draw
	aline from (x1,y1) to (x2,y2)*/
	void line_draw(int x1,int y1,int x2,int y2)
	{
	int x[700],y[700];
	int n;
	n=bresenham(x1,y1,x2,y2,x,y);
	plot_line(x,y,n);
	}


       //int bresenham(int x1,int y1,int x2,int y2,int x[],int y[]):
       //Function to generate all points using Generalized Bresenham algorithm

	int bresenham(int x1,int y1,int x2,int y2,int x[],int y[])
	{
	int delx,dely,s1,s2;
	int interchange,temp;
	int xx,yy;
	int e,i;
	delx=abs(x2-x1);
	dely=abs(y2-y1);
	s1=sign(x2-x1);
	s2=sign(y2-y1);
	/*To Calculate value of interchange*/
		if(dely>delx)
		{temp=dely;
		dely=delx;
		delx=temp;
		interchange=1;
		}
		else
		interchange=0;
	xx=x1;
	yy=y1;
	e=2*dely-delx;
	//To generate all points
		for(i=0;i<=delx;i++)
		{
		x[i]=xx;
		y[i]=yy;
			while(e>=0)
			{
				if(interchange==1)
				xx=xx+s1;
				else
				yy=yy+s2;
			e=e-2*delx;
			}
			if(interchange==1)
			yy=yy+s2;
			else
			xx=xx+s1;
		e=e+2*dely;
		}
	return delx;
	}

	void plot_line(int x[],int y[],int n)
	{
	int i;
	for(i=0;i<=n;i++)
	{
	putpixel(320+x[i],240-y[i],c);
	delay(10);
	}
	}

	//int sign(int x) : Function to return sign of x
	int sign(int x)
	{
		if(x>0)
		return 1;
		else if(x==0)
		return 0;
		else
		return -1;
	}
