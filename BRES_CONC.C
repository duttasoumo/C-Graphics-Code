/*bresenham circle draw algorithm to draw two concentric circles*/
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
int c,bgcolor;
void circle_draw(int xc,int yc,int r);
void draw_xy();
void plot_xy(int x[],int y[],int xc,int yc,int n);
/*c=color code of the circle,bgcolor=background color,xc,yc=co-ordinate of centre,r=radius,n=total no of points,x[],y[]=co-ordinate of all n points*/
void main()
{
int xc,yc,r;
clrscr();
printf("\nEnter x-co-ordinate of centre:");
scanf("%d",&xc);
printf("\nEnter y co-ordinate of centre:");
scanf("%d",&yc);
printf("Enter radius of the circle=");
scanf("%d",&r);
printf("\nEnter background color:");
scanf("%d",&bgcolor);
printf("\nEnter color of Circle=");
scanf("%d",&c);
draw_xy();
circle_draw(xc,yc,r);
circle_draw(xc,yc,r+20);
getch();
closegraph();
}
void circle_draw(int xc,int yc,int r)
{
int xk,yk,n,d;
float pk;
int x[1200],y[1200];
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
	/*to take reflection of all points along x-axis*/
	n1=2*n-1;
	j=n-1;
		for(i=n+1;i<=n1;i++)
		{
		x[i]=x[j];
		y[i]=-y[j];
		j=j-1;
		}
		/*To take reflection along y-axis*/
		n2=4*n-4;
		j=n1-1;
			for(i=n1+1;i<=n2;i++)
			{
			x[i]=-x[j];
			y[i]=y[j];
			j=j-1;
			}
       /*	printf("\n n1=%d n2=%d\n",n1,n2);
	getch();
	/*to generate all points in 1st,2nd,3rd&4th quadrant*/
	       /*	for(i=1;i<=n2;i++)
		{
		printf("x[%d]=%d y[%d]=%d\n",i,x[i],i,y[i]);
			if(i%20==0)
			{
			printf("\nPress any key to continue-->");
			getch();
			clrscr();
			}
		}*/
	n=n2;
	plot_xy(x,y,xc,yc,n);
	}
	void draw_xy()
	{
	int gd=DETECT,gm;
	int i,c1;
	c1=15;
	initgraph(&gd,&gm,"c://turboc3//BGI");
	setbkcolor(bgcolor);
		for(i=0;i<640;i++)
		{
		putpixel(i,240,c1);
		delay(5);
		}
		for(i=0;i<480;i++)
		{
		putpixel(320,i,c1);
		delay(5);
		}
	outtextxy(10,245,"-X");
	outtextxy(610,245,"+X");
	outtextxy(325,20,"+Y");
	outtextxy(325,460,"-Y");
	outtextxy(325,245,"O(0,0)");
	}
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
