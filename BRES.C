   /*cg_3.c : write a program to draw a line from (x1,y1) to ( x2,y2)
     using Integer Generalised Bresenham line draw algorithm */

     #include<stdio.h>
     #include<conio.h>
     #include<graphics.h>
     #include<math.h>
     void line_draw(int x1,int y1,int x2,int y2);
     int bresenham(int x1, int y1, int x2, int y2, int x[], int y[]);
     int sign(int x);
     void draw_xy();
     void plot_line(int x[], int y[], int n, int c);

     void main()
     {
     int x1,y1,x2,y2;
     clrscr();
     printf("\nEnter x1=");
     scanf("%d",&x1);
     printf("\nEnter y1=");
     scanf("%d",&y1);
     printf("\nEnter x2=");
     scanf("%d",&x2);
     printf("\nEnter y2=");
     scanf("%d",&y2);
     line_draw(x1,y1,x2,y2);
     getch();
     closegraph();
     }
     /* void line_draw(int x1,int y1,int x2,int y2) : function to draw a line from
     (x1,y1) to (x2,y2) */
     void line_draw(int x1,int y1,int x2,int y2)
     {
     int x[700],y[700];
     int n,c;
     printf("\nEnter colour code of your line(1-14) : ");
     scanf("%d",&c);
     n=bresenham(x1,y1,x2,y2,x,y);
     draw_xy();
     plot_line(x,y,n,c);
     }

     /* int bresenham(int x1,int y1,int x2,int y2,int x[],int y[]): function to generate all
     points using integer generalised bresenham line draw algorithm */

     int bresenham(int x1,int y1,int x2,int y2,int x[],int y[])
     {
     int delx,dely,s1,s2;
     int interchange,temp;
     int xx,yy,e,i;
     delx=abs(x2-x1);
     dely=abs(y2-y1);
     s1=sign(x2-x1);
     s2=sign(y2-y1);
		 if(dely>delx)
		 {
		 temp=dely;
		 dely=delx;
		 delx=temp;
		 interchange=1;
		 }
		 else
		 interchange=0;
     xx=x1;
     yy=y1;
     e=2*dely-delx;
     /* to generate all points */
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

     printf("\nPress any key to display all points --->");
     getch();
     clrscr();
	      for(i=0;i<=delx;i++)
	      {
	      printf("x[%d]=%d y[%d]=%d\n",i,x[i],i,y[i]);
		     if(((i+1) % 20) == 0)
		     {
		     printf("\nPress any key to continue --->");
		     getch();
		     clrscr();
		     }
	      }
    printf("\nPress any key to continue --->");
    getch();
    return delx;
    }
    /* sign(int x): function to return sign of x */
    int sign(int x)
    {
       if(x<0)
       return -1;
       else if(x==0)
       return 0;
       else
       return 1;
    }

      void draw_xy()
      {
      int c,i,c1;
      int gd=DETECT, gm;
      initgraph(&gd,&gm,"c://turboc3//BGI");
      c=15;
       /* to draw x-axis */
	   for(i=0;i<=639;i++)
	   {
	   putpixel(i,240,c);
	   delay(10);
	   }
       /* to draw y-axis */
	   for(i=0;i<479;i++)
	   {
	   putpixel(320,i,c);
	   delay(10);
	   }
       c1=12;
       setbkcolor(c1);
       outtextxy(620,245,"+X");
       outtextxy(10,245,"-X");
       outtextxy(330,460,"+Y");
       outtextxy(330,460,"-Y");
       outtextxy(330,245,"0");
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