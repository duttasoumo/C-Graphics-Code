/*circle_c.c: Write a program to take
 reflection of a triangle along some standard axis*/
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int c,bgcolor;
void draw_xy();
void plot_xy(int x[],int y[],int xc,int yc,int n);
void line_draw(int x1,int y1,int x2,int y2);
int bresenham(int x1,int y1,int x2,int y2,int x[],int y[]);
int sign(int x);
int round1(float x);
void plot_line(int x[],int y[],int n);//n=no of points , c=color code
void draw_triangle(int x1,int y1,int x2,int y2,int x3,int y3);
void reflection(int x1,int y1,int x2,int y2,int x3,int y3,int choice);
void rotation(int x1,int y1,int x2,int y2,int x3,int y3,float theta);
void translation(int x1,int y1,int x2,int y2,int x3,int y3,int a,int b);
void main()
{
int x1,y1,x2,y2,x3,y3,choice;
int a,b;
float theta;
clrscr();
printf("\nEnter x co-ordinate of Vertex A:");
scanf("%d",&x1);
printf("\nEnter y co-ordinate of Vertex A:");
scanf("%d",&y1);
printf("\nEnter x co-ordinate of Vertex B:");
scanf("%d",&x2);
printf("\nEnter y co-ordinate of Vertex B:");
scanf("%d",&y2);
printf("\nEnter x co-ordinate of Vertex C:");
scanf("%d",&x3);
printf("\nEnter y co-ordinate of Vertex C:");
scanf("%d",&y3);
printf("Enter choice(x-axis:1.y-axis:2,y=x axis:3,y=-x axis:4=");
scanf("%d",&choice);
printf("Enter rotation in degree:");
scanf("%f",&theta);
printf("\nEnter translation factor along x-axis:");
scanf("%d",&a);
printf("\nEnter translation factor along y-axis:");
scanf("%d",&b);
printf("Enter background color code=");
scanf("%d",&bgcolor);
printf("\nEnter color code of lines(1-14):");
scanf("%d",&c);
draw_xy();
translation(x1,y1,x2,y2,x3,y3,a,b);
rotation(x1,y1,x2,y2,x3,y3,theta);
reflection(x1,y1,x2,y2,x3,y3,choice);
rotation(x1,y1,x2,y2,x3,y3,theta);
translation(x1,y1,x2,y2,x3,y3,a,b);
getch();
closegraph();
}
void draw_triangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
line_draw(x1,y1,x2,y2);
line_draw(x2,y2,x3,y3);
line_draw(x3,y3,x1,y1);
}
void reflection(int x1,int y1,int x2,int y2,int x3,int y3,int choice)
{
int ref[3][3],obj[3][3],obj1[3][3];
int xm1,ym1,xm2,ym2,xm3,ym3;
int i,j,k;
char a[80];
/*to construct reflection matrix*/
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		ref[i][j]=0;
	if(choice==1)
	{
	ref[0][0]=1;
	ref[1][1]=-1;
	ref[2][2]=1;
	}
	else if(choice==2)
	{
	ref[0][0]=-1;
	ref[1][1]=1;
	ref[2][2]=1;
	}
	else if(choice==3)
	{
	ref[0][1]=1;
	ref[1][0]=1;
	ref[2][2]=1;
	}
	else if(choice==4)
	{
	ref[0][1]=-1;
	ref[1][0]=-1;
	ref[2][2]=1;
	}
	/*to construct object matrix*/
	obj[0][0]=x1;
	obj[0][1]=x2;
	obj[0][2]=x3;
	obj[1][0]=y1;
	obj[1][1]=y2;
	obj[1][2]=y3;
	obj[2][0]=1;
	obj[2][1]=1;
	obj[2][2]=1;
	/*to get co-ordinate of transformed triangle*/
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
			{
			obj1[i][j]=0;
				for(k=0;k<3;k++)
				obj1[i][j]=obj1[i][j]+ref[i][k]*obj[k][j];
			}
	xm1=obj1[0][0];
	xm2=obj1[0][1];
	xm3=obj1[0][2];
	ym1=obj1[1][0];
	ym2=obj1[1][1];
	ym3=obj1[1][2];
	/*to draw initial object*/
	draw_triangle(x1,y1,x2,y2,x3,y3);
	sprintf(a,"A(%d %d)",x1,y1);
	outtextxy(325+x1,245-y1,a);
	sprintf(a,"B(%d %d)",x2,y2);
	outtextxy(325+x2,245-y2,a);
	sprintf(a,"C(%d %d)",x3,y3);
	outtextxy(325+x3,245-y3,a);
	outtextxy(360+x3,260-y3,"Before Reflection");
	/*to draw modified object*/
	draw_triangle(xm1,ym1,xm2,ym2,xm3,ym3);
	sprintf(a,"A(%d %d)",xm1,ym1);
	outtextxy(325+xm1,245-ym1,a);
	sprintf(a,"B(%d %d)",xm2,ym2);
	outtextxy(325+xm2,245-ym2,a);
	sprintf(a,"C(%d %d)",xm3,ym3);
	outtextxy(325+xm3,245-ym3,a);
	outtextxy(360+xm3,260-ym3,"After Reflection");
	}
void rotation(int x1,int y1,int x2,int y2,int x3,int y3,float theta)
{
int obj[3][3],obj1[3][3];
float rot[3][3];
float xrad;
int xm1,ym1,xm2,ym2,xm3,ym3;
int i,j,k;
char m[80];
/*to construct rotation matrix*/
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		rot[i][j]=0;
	xrad=theta*3.141593/180;
	rot[0][0]=cos(xrad);
	rot[0][1]=-sin(xrad);
	rot[0][2]=0;
	rot[1][0]=sin(xrad);
	rot[1][1]=cos(xrad);
	rot[1][2]=0;
	rot[2][0]=0;
	rot[2][1]=0;
	rot[2][2]=1;
	/*to construct object matrix*/
	obj[0][0]=x1;
	obj[0][1]=x2;
	obj[0][2]=x3;
	obj[1][0]=y1;
	obj[1][1]=y2;
	obj[1][2]=y3;
	obj[2][0]=1;
	obj[2][1]=1;
	obj[2][2]=1;
	/*to get co-ordinate of transformed triangle*/
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
			{
			obj1[i][j]=0;
				for(k=0;k<3;k++)
				obj1[i][j]=obj1[i][j]+rot[i][k]*obj[k][j];
			}
	xm1=obj1[0][0];
	xm2=obj1[0][1];
	xm3=obj1[0][2];
	ym1=obj1[1][0];
	ym2=obj1[1][1];
	ym3=obj1[1][2];
	/*to draw initial object*/
	draw_triangle(x1,y1,x2,y2,x3,y3);
	sprintf(m,"A(%d %d)",x1,y1);
	outtextxy(325+x1,245-y1,m);
	sprintf(m,"B(%d %d)",x2,y2);
	outtextxy(325+x2,245-y2,m);
	sprintf(m,"C(%d %d)",x3,y3);
	outtextxy(325+x3,245-y3,m);
	outtextxy(360+x3,260-y3,"Before rotation");
	/*to draw modified object*/
	draw_triangle(xm1,ym1,xm2,ym2,xm3,ym3);
	sprintf(m,"A'(%d %d)",xm1,ym1);
	outtextxy(325+xm1,245-ym1,m);
	sprintf(m,"B'(%d %d)",xm2,ym2);
	outtextxy(325+xm2,245-ym2,m);
	sprintf(m,"C'(%d %d)",xm3,ym3);
	outtextxy(325+xm3,245-ym3,m);
	outtextxy(360+xm3,260-ym3,"After rotation");
	}
void translation(int x1,int y1,int x2,int y2,int x3,int y3,int a,int b)
{
int obj[3][3],obj1[3][3];
int tra[3][3];
int xm1,ym1,xm2,ym2,xm3,ym3;
int i,j,k;
char m[80];
/*to construct scaling matrix*/
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		tra[i][j]=0;
	tra[0][2]=a;
	tra[1][2]=b;
	tra[2][2]=1;
	tra[0][0]=1;
	tra[1][1]=1;
	/*to construct object matrix*/
	obj[0][0]=x1;
	obj[0][1]=x2;
	obj[0][2]=x3;
	obj[1][0]=y1;
	obj[1][1]=y2;
	obj[1][2]=y3;
	obj[2][0]=1;
	obj[2][1]=1;
	obj[2][2]=1;
	/*to get co-ordinate of transformed triangle*/
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
			{
			obj1[i][j]=0;
				for(k=0;k<3;k++)
				obj1[i][j]=obj1[i][j]+tra[i][k]*obj[k][j];
			}
	xm1=obj1[0][0];
	xm2=obj1[0][1];
	xm3=obj1[0][2];
	ym1=obj1[1][0];
	ym2=obj1[1][1];
	ym3=obj1[1][2];
	/*to draw initial object*/
	draw_triangle(x1,y1,x2,y2,x3,y3);
	sprintf(m,"A(%d %d)",x1,y1);
	outtextxy(325+x1,245-y1,m);
	sprintf(m,"B(%d %d)",x2,y2);
	outtextxy(325+x2,245-y2,m);
	sprintf(m,"C(%d %d)",x3,y3);
	outtextxy(325+x3,245-y3,m);
	outtextxy(360+x3,260-y3,"Before translation");
	/*to draw modified object*/
	draw_triangle(xm1,ym1,xm2,ym2,xm3,ym3);
	sprintf(m,"A'(%d %d)",xm1,ym1);
	outtextxy(325+xm1,245-ym1,m);
	sprintf(m,"B'(%d %d)",xm2,ym2);
	outtextxy(325+xm2,245-ym2,m);
	sprintf(m,"C'(%d %d)",xm3,ym3);
	outtextxy(325+xm3,245-ym3,m);
	outtextxy(360+xm3,260-ym3,"After translation");
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
