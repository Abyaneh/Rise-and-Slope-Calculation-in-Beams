#include<iostream>
#include <conio.h>
#include <math.h>
#include <limits.h>
#include <iomanip>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <cstring>
using namespace std;

// Name: Mohammad Maleki Abyaneh
// Student number : 9930723


int main()
{
	int n;
	int za;
	int q,qa,qb,qc;
	double a,p,l,b,x,t,y,h,r,u,e,E,I,m,D;
	double s1,s2,s3,s4;
	double w,w1,w2,wx,wm,wd;
	double Ra,Rb;
	double ta,tb;
	double l1,lb,lw;
	double Ma,Mb;
    double sa,sb;
    double x1,x2,xa,xp,xd;                                                     
    double g1,h1;


    cout<<"ASSUMPSTIONS: *Down is assumed to be positive and counterclockwise is assumed to be positive.*"<<endl<<endl<<endl;


	//Young's Modulus
	cout<<"Enter the value of Young's Modulus: "<<endl;
	cin>>e;
	E=e;
	
	
    //Moment of inertia
	cout<<"Enter Moment of inertia:(Rectangle=1, Rectangular tube=2, Circle=3, Semicircle=4, Quarter circle=5, Circular tube=6, Right Triangle=7, another area=8)"<<endl;  
	cin>>za;
	
	if(za==1)                                             // Rectangle
	{
		cout<<"Enter the value of width:(b) "<<endl;
		cin>>b;
		cout<<"Enter the value of length:(h) "<<endl;
		cin>>h;
		I=(1.0/12)*b*pow(h,3); 
		cout<<"Your moment of inertia = "<<I<<endl;
	}
	
	else if(za==2)                                      // Rectangular tube
	{
		cout<<"Enter the value of width:(b) "<<endl;
		cin>>b;
		cout<<"Enter the value of length:(h) "<<endl;
		cin>>h;	
		cout<<"Enter the value of thickness(t): "<<endl;
    	cin>>t; 
    	while(D<(2*t))
    	{
    		cout<<"error: 2*t shoud be less than D"<<endl;
			cout<<"Enter the value of thickness(t): "<<endl;                
		    cin>>t;
     	}
    	I=(b*pow(h,3)-(b-(2*t))*pow(h-(2*t),3)/(12));
    	cout<<"Your moment of inertia = "<<I<<endl;
	}
	
	else if(za==3)                                        // Circle
	{
		cout<<"Enter the value of radius: "<<endl;
		cin>>r;
		I=(1.0/4)*(M_PI)*pow(r,4);
		cout<<"Your moment of inertia = "<<I<<endl;   
	}
    
    else if(za==4)                                       // Semicircle
    {
    	cout<<"Enter the value of radius: "<<endl;
		cin>>r;
		I=((9*pow(M_PI,2)-64)/(72*M_PI))*(pow(r,4));
		cout<<"Your moment of inertia = "<<I<<endl; 
	}

    else if(za==5)                                      // Quarter circle
    {
       	cout<<"Enter the value of radius: "<<endl;
		cin>>r;
		I=((9*pow(M_PI,2)-64)/(144*(M_PI)))*(pow(r,4));
		cout<<"Your moment of inertia= "<<I<<endl;
	}

    else if(za==6)                                      // Circular tube
    {
    	cout<<"Enter the value of external diameter(D): "<<endl;
    	cin>>D;
    	cout<<"Enter the value of thickness(t): "<<endl;
    	cin>>t;                                                                     
    	while(D<(2*t))
    	{
    		cout<<"error: 2*t shoud be less than D"<<endl;
			cout<<"Enter the value of thickness(t): "<<endl;                
		    cin>>t;
     	}
    	I=((M_PI)*(pow(D,4)-pow(D-(2*t),4)/64));
    	cout<<"Your moment of inertia = "<<I<<endl;
	}
  
    else if(za==7)                                      // Right Triangle
    {
    	cout<<"Enter the value of base of a triangle:(b)"<<endl;
    	cin>>b;
    	cout<<"Enter the value of height of a tiangle:(h)"<<endl;
    	cin>>h;
    	I=(b*pow(h,3)/36);
    	cout<<"Your moment of inertia = "<<I<<endl;
	}

	else if(za==8)                                       // another area
	{
		cout<<"Enter the value of moment of inertia:(I)"<<endl;
		cin>>I;
		while(I<=0)
		{
			cout<<"error: (I) shoud be postive"<<endl;
			cin>>I;
		}
		cout<<"Your moment of inertia = "<<I<<endl;
	}	

	cout<<"Enter border conditions:(Simply-Supported-Beam=1 or Cantilever-Beam=2 or Fixed-Beam=3 or Fixed-Pinned-Beam=4)"<<endl;  // SHARTE TAVAGHOF
	cin>>n;
	
	if(n==1)                             //Simply Supported Beam
	{
		    cout<<"   _______________________________________________ "<<endl;
            cout<<"  |_______________________________________________|"<<endl;
            cout<<"  /\\                                              O"<<endl<<endl;
            
		    cout<<"Enter your load:(Point-load=1 or Point-moment=2 or Trapezoidal-load(partially distributed linearly varying load)=3 or  Trapezoidal load distribution=4 or Two equal loads at equal distances from supports=5 or Equal moment at each support=6)"<<endl;  
		    cin>>q;
		
		if(q==1)                                        //Point load in Simply Supported Beam
		{
			cout<<"                 p                                  "<<endl;
            cout<<"                 |                                  "<<endl;
            cout<<"                 V                                  "<<endl;
            cout<<"   _______________________________________________  "<<endl;
            cout<<"  |_______________________________________________| "<<endl;
            cout<<"  /\\             :                                O"<<endl;
            cout<<"  :              :                                : "<<endl;
            cout<<"  |------(a)-----|--------------------------------- "<<endl<<endl;
            
			cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;                                                                          // SHARTE TAVAGHOF
			 
			while(a>l)
			{
				cout<<"error: a shoud be less than l"<<endl;
				cout<<"Enter a:(distance from the start of the beam)"<<endl;                // BARAYE HAME BENEVISAM
			    cin>>a;
			} 
			
			b=(l-a);
			
			cout<<"Enter the value of point load: "<<endl;
			cin>>p;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;                                                                         // SHARTE TAVAGHOF
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;                // BARAYE HAME BENEVISAM
			    cin>>x;
			} 
			
			xp=l-x;
			Ra=(p*b)/l;
			Rb=(p*a)/l;
			ta=(-p*b*(pow(l,2)-pow(b,2))/(6*E*I*l));
			tb=(p*a*(pow(l,2)-pow(a,2))/(6*E*I*l));
			
			if(x<=a)                                         
			{
				t=(ta)+(Ra*pow(x,2)/(2*E*I));
				y=(-ta*x)-(Ra*pow(x,3)/(6*E*I));
			}
			else
			{
				t=tb-(Rb*pow(xp,2)/(2*E*I));
				y=(-ta*x)-(Ra*pow(x,3)/(6*E*I))+(p*pow(x-a,3)/(6*E*I));
			}
			
				cout<<"Slope= "<<t<<endl;
				cout<<"Deflection= "<<y<<endl;
			
		}
        else if(q==2)                                 //Point-moment in Simply Supported Beam
        {
        	cout<<"            point moment                            "<<endl;
            cout<<"   _______________________________________________  "<<endl;
            cout<<"  |_______________________________________________| "<<endl;
            cout<<"  /\\             :                                O"<<endl;
            cout<<"  :              :                                  "<<endl;                 
            cout<<"  |-----(a)------:                                  "<<endl<<endl;
            
        	cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;                                                           
			
			while(a>l)
			{
				cout<<"error: a shoud be less than l"<<endl;
				cout<<"Enter a:(distance from the start of the beam)"<<endl;                
			    cin>>a;
			} 
			
			b=(l-a);
			
			cout<<"Enter the value of point moment: "<<endl;
			cin>>m;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;                                                           
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;                
			    cin>>x;
			} 
			
			xp=l-x;
			Ra=(m/l);
			Rb=(-m/l);
			ta=(m*(3*pow(b,2)-pow(l,2))/(6*E*I*l));
			tb=(m*(3*pow(a,2)-pow(l,2))/(6*E*I*l));
			
			if(x<=a)
			{
				t=ta+(Ra*pow(x,2)/(2*E*I));
				y=(-ta*x)-(Ra*pow(x,3)/(6*E*I));
			}
			else
			{
				t=tb-(Rb*pow(xp,2)/(2*E*I));
				y=(-ta*x)-(Ra*pow(x,3)/(6*E*I))+(m*pow(x-a,2)/(2*E*I));
			}
				cout<<"Slope= "<<t<<endl;
				cout<<"Deflection= "<<y<<endl;
		}
        
        else if(q==3)                                        //Trapezoidal load in Simply Supported Beam
        {
        	cout<<"                         w2                        "<<endl;
            cout<<"                         .                         "<<endl;
            cout<<"                       . |                         "<<endl;
            cout<<"                     . | |                         "<<endl;
            cout<<"                   . | | |                         "<<endl;
            cout<<"              w1 . | | | |                         "<<endl;
            cout<<"               . | | | | |                         "<<endl;
            cout<<"               | | | | | |                         "<<endl;
            cout<<"               | | | | | |                         "<<endl;
            cout<<"               V V V V V V                         "<<endl;
            cout<<"   _______________________________________         "<<endl;
            cout<<"  |_______________________________________|        "<<endl;
            cout<<"  /\\          :         :                O        "<<endl;
            cout<<"              :         :                :         "<<endl;
            cout<<"  |----(a)----|         |-------(b)------|         "<<endl<<endl;
            
           	cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;                                                                          
			
			cout<<"Enter b:(distance between the end of the load and the end of the beam)"<<endl;
			cin>>b;                                                                        
			  
			while((a+b)>l)
			{
				cout<<"error: a+b shoud be less than l"<<endl;
				cout<<"Enter a:(distance from the start of the beam)"<<endl;                
			    cin>>a;
			  	cout<<"Enter b:(distance between the end of the load and the end of the beam)"<<endl;
			    cin>>b;
			} 
			  
			cout<<"Enter w1:(value of the load at the start) "<<endl;
			cin>>w1; 
			
			cout<<"Enter w2:(value of the load at the end) "<<endl;
			cin>>w2;
			
			cout<<"Enter where you want the values of slope and deflection:"<<endl;
			cin>>x;                                                                          
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;               
			    cin>>x;
			} 
			
			wm=(w1+w2)/2;
			lw=l-a-b;
			wx=w1+((w2-w1)*(x-a))/(lw);
			
			Ra=(lw*(6*wm*b+(2*w1+w2))*lw)/(6*l);
			Rb=(lw*(6*wm*(l-b)-(2*w1+w2)))*lw/(6*l);
			xa=x-a;
			xp=l-x;
			
			
			s1=(20*pow(a,2))*(a-(3*l))+(20*lw*a*(a-2*l))+10*pow(lw,2)*(a-l)+2*pow(lw,3);
			s2=(10*lw*a*(a-2*l))+10*pow(lw,2)*(a-l)+3*pow(lw,3);
			s3=20*pow(a,3)+20*lw*pow(a,2)+10*pow(lw,2)*a+2*pow(lw,3);
			s4=10*lw*pow(a,2)+10*pow(lw,2)*a+3*pow(lw,3);
			
			ta=(-Rb*pow(l,2)/(3*E*I))-((lw*(s1*wm+s2*w2)))/(120*E*I*l);
			tb=(Rb*pow(l,2)/(6*E*I))-((lw*(s3*wm+s4*w2)))/(120*E*I*l);
			
			if(x<=a)
			{
				t=(ta)+(Ra*pow(x,2))/(2*E*I);
				y=(-ta)*x-(Ra*pow(x,3))/(6*E*I);
			}
			
			else if(a<x<(l-b))
			{
				t=(ta)+((Ra*pow(x,2))/(2*E*I))-((3*w1+wx)*pow(xa,3))/(24*E*I);
				y=(-ta*x)-(Ra*pow(x,3)/6*E*I)+((4*w1+wx)*pow(xa,3))/(120*E*I);
			}
			
			else
			{
				t=(tb)-(Rb*pow(xp,2))/(2*E*I);
				y=tb*xp-(Rb*pow(xp,3))/(6*E*I);
			}
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
        
        else if(q==4)                                            // Trapezoidal load distribution
        {
        	cout<<"                . . . . . .                 "<<endl;
            cout<<"              . | | | | | | .               "<<endl;
            cout<<"            . | | | | | | | | .             "<<endl;
            cout<<"          . | | | | | | | | | | .           "<<endl;
            cout<<"        . | | | | | | | | | | | | .         "<<endl;
            cout<<"      . | | | | | | | | | | | | | | .       "<<endl;
            cout<<"    . | | | | | | | | | | | | | | | | .     "<<endl;
            cout<<"  . V V V V V V V V V V V V V V V V V V .   "<<endl;
            cout<<"   _______________________________________  "<<endl;
            cout<<"  |_______________________________________| "<<endl;
            cout<<"  /\\            :         :              O "<<endl;
            cout<<"                :         :              :  "<<endl;
            cout<<" |------(a)-----|         |------(b)-----|  "<<endl<<endl;
              
         	cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(Length of the triangle load at the start)"<<endl;
			cin>>a;                                                                          
			
			cout<<"Enter b:(Length of the triangle load at the end)"<<endl;
			cin>>b; 
			
			while((a+b)>l)
			{
				cout<<"error: a+b shoud be less than l"<<endl;
				cout<<"Enter a:(Length of the triangle load at the start)"<<endl;                
			    cin>>a;
			  	cout<<"Enter b:(Length of the triangle load at end)"<<endl;
			    cin>>b;
			} 
			
			cout<<"Enter w:(value of wide load)"<<endl;
			cin>>w;
			
			cout<<"Enter where you want the values of slope and deflection:"<<endl;
			cin>>x;
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(Distance from the start of the beam)"<<endl;                
			    cin>>x;
			} 
			
			xp=l-x;
			s1=x*pow(a,3)+2*a*pow(x,3)-2*pow(a,2)*pow(x,2)-pow(x,4)-pow(a,5)/5;
			s2=pow(a,3)+6*a*pow(x,2)-4*pow(a,2)*x-pow(x,3);
			Ra=(w/(6*l))*(3*pow(l,2)-3*l*a+pow(a,2)-pow(b,2));
			Rb=(w/(6*l))*(3*pow(l,2)-3*l*b-pow(a,2)+pow(b,2));
			ta=-(w*(15*pow(l,4)-20*pow(l,2)*pow(a,2)-10*pow(l,2)*pow(b,2)+15*l*pow(a,3)-3*pow(a,4)+3*pow(b,4)))/(360*E*I*l);
        	tb=(w*(15*pow(l,4)-10*pow(l,2)*pow(a,2)-20*pow(l,2)*pow(b,2)+15*l*pow(b,3)+3*pow(a,4)-3*pow(b,4)))/(360*E*I*l);
        	
        	if(x<=a)
        	{
        		t=ta+((Ra*pow(x,2))/(2*E*I))-((w*pow(x,4)))/(24*E*I*a);
        		y=(-ta)*x-((Ra*pow(x,3))/(6*E*I))+((w*pow(x,5))/(120*E*I*a));
			}
			
			else if(a<x<(l-b))
			{
				t=ta+((Ra*pow(x,2))/(2*E*I))+((w*s2))/(24*E*I);
				y=(-ta)*x-((Ra*pow(x,3))/(6*E*I))-((w*s1)/(24*E*I));
			}
			
			else if(x>=(l-b))
			{
				t=tb-((Rb*pow(xp,2))/(2*E*I))+((w*pow(xp,4)))/(24*E*I*b);
				y=(tb)*xp-((Rb*pow(xp,3))/(6*E*I))+((w*pow(xp,5))/(120*E*I*b));
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
        
        else if(q==5)                                       // Two equal loads at equal distances from supports
        {
        	cout<<"               p                       p            "<<endl;
            cout<<"               |                       |            "<<endl;
            cout<<"               V                       V            "<<endl;
            cout<<"   _______________________________________________  "<<endl;
            cout<<"  |_______________________________________________| "<<endl;
            cout<<"  /\\           :                      :           O"<<endl;
            cout<<"  :            :                      :           : "<<endl;
            cout<<"  |----(a)-----|                      |----(a)----| "<<endl<<endl;
    
           	cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(Distance from both supports)"<<endl;
			cin>>a;                                                          
			
			while((2*a)>l)
			{
				cout<<"error: 2*a shoud be less than l"<<endl;
				cout<<"Enter a:(distance from the start of the beam)"<<endl;              
			    cin>>a;
			} 
			
			cout<<"Enter the value of point load: "<<endl;
			cin>>p;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;           
			    cin>>x;
			} 
			
			
			if(x<=a)
			{
				t=(p*(pow(a,2)-(l*a)+pow(x,2)))/(2*E*I);
				y=((-p*x)*(3*pow(a,2)-(3*l*a)+pow(x,2)))/(6*E*I);
			}
			
			else if(a<x<=l-a)
			{
				t=((-a*p*(l-(2*x))))/(2*E*I);
				y=((-a*p)*(pow(a,2)+3*pow(x,2)-3*l*x))/(6*E*I);
			}
			
			else if((l-a)<x<=l)
			{
				t=(-p*(pow(a,2)-(l*a)+pow((l-x),2)))/(2*E*I);
				y=(-p*(l-x)*(3*pow(a,2)-3*l*a+pow(l,2)+pow(x,2)-2*l*x))/(6*E*I);
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
        
        else if(q==6)                                           // Equal moment at each support
        {
            cout<<"  (point moment)(Clockwise)       (point moment)(Counterclockwise)"<<endl;
            cout<<"   ______________________________________________________________ "<<endl;
            cout<<"  |______________________________________________________________|"<<endl;
            cout<<"  /\\                                                            O"<<endl<<endl;
            
        	cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter the value of the point moment: "<<endl;
			cin>>m;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;                
			    cin>>x;
			} 
			
			t=((-m)*(l-(2*x)))/(2*E*I);
			y=((m*x)*(l-x))/(2*E*I);
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
        
        
        
        
	}



    else if(n==2)                                           //Cantilever Beam
    {
    	    cout<<"  ////|                                          "<<endl;
            cout<<"  ////|                                          "<<endl;
            cout<<"  ////|                                          "<<endl;
            cout<<"  ////|_____________________________________     "<<endl;
            cout<<"  ////|_____________________________________|    "<<endl;
            cout<<"  ////|                                          "<<endl;
            cout<<"  ////|                                          "<<endl;
            cout<<"  ////|                                          "<<endl<<endl;
    	    cout<<"Enter your load:(Point-load=1 or Point-moment=2 or Trapezoidal-load(partially distributed linearly varying load)=3 or  Trapezoidal load distribution (from a slab)=4 )"<<endl;
    	    cin>>qa;
    	
    	if(qa==1)                                   //Point load in Cantilever Beam       
    	{
    		cout<<"  ////|             p                            "<<endl;
            cout<<"  ////|             |                            "<<endl;
            cout<<"  ////|             V                            "<<endl;
            cout<<"  ////|_____________________________________     "<<endl;
            cout<<"  ////|_____________________________________|    "<<endl;
            cout<<"  ////|             :                            "<<endl;
            cout<<"  ////|             :                            "<<endl;
            cout<<"  ////|-----(a)-----|                            "<<endl<<endl;
            
   			cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;                                                                            
			
			while(a>l)
			{
				cout<<"error: a shoud be less than l"<<endl;
				cout<<"Enter a:(distance from the start of the beam)"<<endl;                
			    cin>>a;
			} 
			
			
			cout<<"Enter the value of point load: "<<endl;
			cin>>p;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;                                                                             
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;                
			    cin>>x;
			} 
			
			tb=(-p*pow(a,2))/(2*E*I);
			
			if(x<=a)
			{
				t=(-p*x*(2*a-x))/(2*E*I);
				y=(p*pow(x,2)*(3*a-x)/(6*E*I));
			}
			
			else
			{
				t=tb;
				y=(p*pow(a,2)*(3*x-a)/(6*E*I));
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
		
		
		else if(qa==2)                                    //Point moment in Cantilever Beam
		{
            cout<<"  ////|                                          "<<endl;
            cout<<"  ////|                                          "<<endl;
            cout<<"  ////|        point moment                      "<<endl;
            cout<<"  ////|_____________________________________     "<<endl;
            cout<<"  ////|_____________________________________|    "<<endl;
            cout<<"  ////|             :                            "<<endl;
            cout<<"  ////|             :                            "<<endl;
            cout<<"  ////|-----(a)-----|                            "<<endl<<endl;
            
        	cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;															
			
			while(a>l)
			{
				cout<<"error: a shoud be less than l"<<endl;
				cout<<"Enter a:(distance from the start of the beam)"<<endl;                
			    cin>>a;
			} 
			
			cout<<"Enter the value of point moment: "<<endl;
			cin>>m;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;																
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;               
			    cin>>x;
			} 
			
			tb=(m*a/(E*I));
			
			if(x<=a)
			{
				t=(m*x)/(E*I);
				y=(-m*pow(x,2))/(2*E*I);
			}
			
			else
			{
				t=tb;
				y=(-tb*(x-(a/2)));
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
		
		else if(qa==3)                                         //Trapezoidal-load in Cantilever Beam
		{
			cout<<"                             w2                        "<<endl;
            cout<<"                             .                         "<<endl;
            cout<<"                           . |                         "<<endl;
            cout<<"                         . | |                         "<<endl;
            cout<<"                       . | | |                         "<<endl;
            cout<<"                  w1 . | | | |                         "<<endl;
            cout<<"                   . | | | | |                         "<<endl;
            cout<<"                   | | | | | |                         "<<endl;
            cout<<"  ////|            | | | | | |                         "<<endl;
            cout<<"  ////|            V V V V V V                         "<<endl;
            cout<<"  ////|_______________________________________         "<<endl;
            cout<<"  ////|_______________________________________|        "<<endl;
            cout<<"  ////|            :         :                :        "<<endl;
            cout<<"  ////|            :         :                :        "<<endl;
            cout<<"  ////|----(a)-----|         |-------(b)------|        "<<endl<<endl;
            
		  	cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;                                                        
			
			cout<<"Enter b:(distance between the end of the load and the end of the beam)"<<endl;
			cin>>b;															
			
			while((a+b)>l)
			{
				cout<<"error: a+b shoud be less than l"<<endl;
		        cout<<"Enter a:(distance from the start of the beam)"<<endl;
			    cin>>a;                                                         
			    cout<<"Enter b:(Distance between the end of the load and the end of beam)"<<endl;
			    cin>>b;
			} 
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;																
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;                
			    cin>>x;
			} 
			
			cout<<"Enter w1:(value of load at the start) "<<endl;
			cin>>w1;
			
			cout<<"Enter w2:(value of load at the end) "<<endl;
			cin>>w2;
			
			xa=x-a;
			lw=l-a-b;
			l1=l+a-b;
			lb=l-b;
			wm=(w1+w2)/2;
			wx=w1+((w2-w1)*(x-a))/lw;
			Ra=lw*wm;
			Ma=-(((3*a)+lw)*lw*wm)/3-((pow(lw,2))*w2)/6;
			tb=(-lw)*(((2*pow(a,2)+pow(l1,2))*wm+(l1*lw*w2))/(12*E*I));
			
			
			if(x<=a)
			{
				t=(Ra*pow(x,2)/2*E*I)+((Ma*x)/(E*I));
				y=(-Ra*pow(x,3)/(6*E*I))-((Ma*pow(x,2))/(2*E*I));
			}
			
			else if(a<x<(l-b))
			{
				t=(Ra*pow(x,2)/2*E*I)+(Ma*x/(E*I));
				y=(-Ra*pow(x,3)/(6*E*I))-((Ma*pow(x,2))/(2*E*I))+((4*w1+wx)*pow(xa,4)/(120*E*I));
			}
			
			else
			{
				t=tb;
				y=(-Ra*pow(lb,3)/(6*E*I))-(Ma*pow(lb,2)/(2*E*I))+((4*w1+w2)*pow(lw,4)/(120*E*I))-(tb*(x-lb));
			}
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
			
		}
		
		else if(qa==4)                                     // Trapezoidal load distribution (from a slab)
		{
			cout<<"                     . . . . . . . . . . . . .   "<<endl;
            cout<<"                   . | | | | | | | | | | | | |   "<<endl;
            cout<<"                 . | | | | | | | | | | | | | |   "<<endl;
            cout<<"               . | | | | | | | | | | | | | | |   "<<endl;
            cout<<"             . | | | | | | | | | | | | | | | |   "<<endl;
            cout<<"  \\\\|    . | | | | | | | | | | | | | | | | |   "<<endl;
            cout<<"  \\\\|  . | | | | | | | | | | | | | | | | | |   "<<endl;
            cout<<"  \\\\|. V V V V V V V V V V V V V V V V V V V   "<<endl;
            cout<<"  \\\\|_______________________________________   "<<endl;
            cout<<"  \\\\|_______________________________________|  "<<endl;
            cout<<"  \\\\|                :                         "<<endl;
            cout<<"  \\\\|                :                         "<<endl;
            cout<<"  \\\\|------(a)-------|                         "<<endl<<endl;
            
         	cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(length of the triangle load at the start)"<<endl;
			cin>>a;
			
			while(a>l)
			{
				cout<<"error: a shoud be less than l"<<endl;
				cout<<"Enter a:(distance from the start of the beam)"<<endl;                
			    cin>>a;
			}
			
			cout<<"Enter w:(value of wide load)"<<endl;
			cin>>w;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;                
			    cin>>x;
			} 
			
			Ra=(w*(l-(a/2)));
			Ma=(-w/6)*(3*pow(l,2)-pow(a,2));
			tb=-(w*(4*pow(l,3)-pow(a,3)))/(24*E*I);
			
			if (x<=a)
			{
				t=(Ra*pow(x,2))/(2*E*I)+((Ma*x)/(E*I))-(w*pow(x,4))/(24*E*I*a);
				y=(-Ra*pow(x,3))/(6*E*I)-(Ma*pow(x,2))/(2*E*I)+(w*pow(x,5))/(120*E*I*a);
			}
			
			else if(x>a)
			{
				t=tb+(w*pow(l-x,3))/(6*E*I);
				y=(-tb*x)+(w*pow(l-x,4))/(24*E*I)-(w*(5*pow(l,4)-pow(a,4)))/(120*E*I);
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
		
	}
	
	
	else if(n==3)                              //Fixed Beam
	{
		cout<<"  ////|                                     |////"<<endl;
        cout<<"  ////|                                     |////"<<endl;
        cout<<"  ////|                                     |////"<<endl;
        cout<<"  ////|_____________________________________|////"<<endl;
        cout<<"  ////|_____________________________________|////"<<endl;
        cout<<"  ////|                                     |////"<<endl;
        cout<<"  ////|                                     |////"<<endl;
        cout<<"  ////|                                     |////"<<endl<<endl;
            
		cout<<"Enter your load:(Point-load=1 or Point-moment=2 or Trapezoidal-load(partially distributed linearly varying load)=3 or Trapezoidal load distribution=4)"<<endl;
		cin>>qb;
		
		if(qb==1)                         //Point load in Fixed Beam
		{
			cout<<"  ////|               p                     |////"<<endl;
            cout<<"  ////|               |                     |////"<<endl;
            cout<<"  ////|               V                     |////"<<endl;
            cout<<"  ////|_____________________________________|////"<<endl;
            cout<<"  ////|_____________________________________|////"<<endl;
            cout<<"  ////|               :                     |////"<<endl;
            cout<<"  ////|               :                     |////"<<endl;
            cout<<"  ////|-----(a)-------|---------(b)-------- |////"<<endl<<endl;
            
			cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;														    
			
			while(a>l)
			{
				cout<<"error: a shoud be less than l"<<endl;
				cout<<"Enter a:(distance from the start of the beam)"<<endl;                
			    cin>>a;
			} 
			
			b=(l-a);
			
			cout<<"Enter value of point load: "<<endl;
			cin>>p;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;															
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;                
			    cin>>x;
			} 
			
			sa=l+(2*a);
			sb=l+(2*b);
			Ra=(p*pow(b,2)*sa/pow(l,3));
			Rb=(p*pow(a,2)*sb/pow(l,3));
			Ma=(-p*a*pow(b,2))/(pow(l,2));
			Mb=(-p*pow(a,2)*b/(pow(l,2)));
			
			if(x<=a)
			{
				t=(Ra*pow(x,2)/(2*E*I))+((Ma*x)/(E*I));
				y=(-Ra*pow(x,3)/(6*E*I))-((Ma*pow(x,2))/2*E*I);
			}
			
			else
			{
				t=(Ra*pow(x,2)/(2*E*I))+((Ma*x)/(E*I))-((p*pow(x-a,2))/(2*E*I));
				y=(-Ra*pow(x,3)/(6*E*I))-(Ma*pow(x,2)/(2*E*I))+(p*pow(x-a,3)/(6*E*I));
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
		
		if(qb==2)                               //Point moment in Fixed Beam
		{
			cout<<"  ////|                                     |////"<<endl;
            cout<<"  ////|                                     |////"<<endl;
            cout<<"  ////|      point moment                   |////"<<endl;
            cout<<"  ////|_____________________________________|////"<<endl;
            cout<<"  ////|_____________________________________|////"<<endl;
            cout<<"  ////|           :                         |////"<<endl;
            cout<<"  ////|           :                         |////"<<endl;
            cout<<"  ////|----(a)----|                         |////"<<endl<<endl;
            
			cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;														
			
			while(a>l)
			{
				cout<<"error: a shoud be less than l"<<endl;
				cout<<"Enter a:(distance from the start of the beam)"<<endl;                
			    cin>>a;
			} 
			
			b=(l-a);
			
			cout<<"Enter the value of point moment: "<<endl;
			cin>>m;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;															
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;                
			    cin>>x;
			} 
			
			x1=l*((0.5)-(sqrt(3)/6));
			x2=l*((0.5)+(sqrt(3)/6));
			ta=l-(3*a);
			tb=l-(3*b);
			Ra=(6*m*a*b/pow(l,3));
			Rb=(-Ra);
			Ma=(m*b*ta)/(pow(l,2));
			Mb=(-m*a*tb)/(pow(l,2));
			
			if(x<=a)
			{
				t=(Ra*pow(x,2)/(2*E*I))+(Ma*x/(E*I));
				y=(-Ra*pow(x,3)/(6*E*I))-(Ma*pow(x,2)/(2*E*I));
			}
			
			else
			{
				t=(Ra*pow(x,2)/(2*E*I))+(Ma*x/(E*I))-(m*(x-a)/(E*I));
				y=(-Ra*pow(x,3)/(6*E*I))-(Ma*pow(x,2)/(2*E*I))+(m*pow(x-a,2)/(2*E*I));
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
		 
		if(qb==3)                                       //Trapezoidal load in Fixed Beam
		{
			cout<<"                             w2                    "<<endl;
            cout<<"                             .                     "<<endl;
            cout<<"                           . |                     "<<endl;
            cout<<"                         . | |                     "<<endl;
            cout<<"                       . | | |                     "<<endl;
            cout<<"                  w1 . | | | |                     "<<endl;
            cout<<"                   . | | | | |                     "<<endl;
            cout<<"                   | | | | | |                     "<<endl;
            cout<<"  ////|            | | | | | |                |////"<<endl;
            cout<<"  ////|            V V V V V V                |////"<<endl;
            cout<<"  ////|_______________________________________|////"<<endl;
            cout<<"  ////|_______________________________________|////"<<endl;
            cout<<"  ////|            :         :                |////"<<endl;
            cout<<"  ////|            :         :                |////"<<endl;
            cout<<"  ////|----(a)-----|         |-------(b)------|////"<<endl<<endl;
            
		  	cout<<"Enter the length of the beam:"<<endl;
			cin>>l;	
			
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;														
			
			cout<<"Enter b:(Distance between the end of the load and the end of the beam)"<<endl;
			cin>>b;																
			
			while((a+b)>l)
			{
				cout<<"error: a+b shoud be less than l"<<endl;
			    cout<<"Enter a:(distance from the start of the beam)"<<endl;
			    cin>>a;														
			    cout<<"Enter b:(Distance between the end of the load and the end of the beam)"<<endl;
			    cin>>b;
			} 
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;																	
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;                
			    cin>>x;
			} 
			
			cout<<"Enter w1:(value of the load at the start) "<<endl;
			cin>>w1;
			
			cout<<"Enter w2:(value of the load at the end) "<<endl;
			cin>>w2;
			
			xp=l-x;
			xa=x-a;
			lw=l-a-b;
			wm=(w1+w2)/2;
			wd=w2-w1;
			wx=w1+((w2-w1)*(x-a)/lw);
			s1=10*((pow(l,2)+pow(a,2))*(l+a)-(pow(a,2)+pow(b,2))*(a-b)-(l*b)*(l+b)-pow(a,3));
			s2=lw*(l*(2*l+a+b)-3*pow(a-b,2)-2*a*b);
			s3=120*a*b*(a+lw)+10*lw*(6*pow(a,2)+4*l*lw-3*pow(lw,2));
			s4=10*l*pow(lw,2)-10*lw*a*(l-3*b)-9*pow(lw,3);
			Rb=(lw*(s1*wm+s2*wd))/(20*pow(l,3));
			Ra=(lw*wm)-Rb;
			Mb=(-(lw*(s3*wm+s4*wd)))/(120*pow(l,2));
			Ma=Mb+Rb*l-a*lw*wm-((pow(lw,2)*(2*w2+w1)))/(6);
			
			
			if(x<=a)
			{
				t=(Ra*pow(x,2)/(2*E*I))+(Ma*x/(E*I));
				y=(-Ra*pow(x,3)/(6*E*I))-(Ma*pow(x,2)/(2*E*I));
			}
			
			else if(a<x<l-b)
			{
				t=(Ra*pow(x,2)/(2*E*I))+((Ma*x)/(E*I))-((3*w1+wx)*pow(xa,3)/(24*E*I));
				y=(-Ra*pow(x,3)/(6*E*I))-(Ma*pow(x,2)/(2*E*I))+((4*w1+wx)*pow(xa,4)/(120*E*I));
			}
			
			else
			{
				t=(-Rb*pow(xp,2)/(2*E*I))-(Mb*xp/(E*I));
				y=(-Rb*pow(xp,3)/(6*E*I))-(Mb*pow(xp,2)/(2*E*I));
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
		
		if(qb==4)                                                    // Trapezoidal load distribution
		{
			cout<<"                     . . . . . .                   "<<endl;
            cout<<"                   . | | | | | | .                 "<<endl;
            cout<<"                 . | | | | | | | | .               "<<endl;
            cout<<"               . | | | | | | | | | | .             "<<endl;
            cout<<"             . | | | | | | | | | | | | .           "<<endl;
            cout<<"  \\\\|    . | | | | | | | | | | | | | | .    |\\\\"<<endl;
            cout<<"  \\\\|  . | | | | | | | | | | | | | | | | .  |\\\\"<<endl;
            cout<<"  \\\\|. V V V V V V V V V V V V V V V V V V .|\\\\"<<endl;
            cout<<"  \\\\|_______________________________________|\\\\"<<endl;
            cout<<"  \\\\|_______________________________________|\\\\"<<endl;
            cout<<"  \\\\|              :         :              |\\\\"<<endl;
            cout<<"  \\\\|              :         :              |\\\\"<<endl;
            cout<<"  \\\\|------(a)-----|         |------(b)-----|\\\\"<<endl<<endl;
            
         	cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(length of the triangle load at the start)"<<endl;
			cin>>a;                                                                          
			
			cout<<"Enter b:(length of the triangle load at the end)"<<endl;
			cin>>b; 
			
			while((a+b)>l)
			{
				cout<<"error: a+b shoud be less than l"<<endl;
				cout<<"Enter a:(length of the triangle load at the start)"<<endl;                
			    cin>>a;
			  	cout<<"Enter b:(length of the triangle load at the end)"<<endl;
			    cin>>b;
			} 
			
			cout<<"Enter w:(value of wide load)"<<endl;
			cin>>w;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;                
			    cin>>x;
			} 
			
			xp=l-x;
			s1=10*pow(l,3)*(l-b)-5*l*(pow(a,3)-pow(b,3))+2*(pow(a,4)-pow(b,4));
			s2=5*pow(l,2)*(pow(l,2)-2*pow(b,2))-5*l*(pow(a,3)-2*pow(b,3))+3*(pow(a,4)-pow(b,4));
			g1=((-pow(a,4))/5)+pow(a,3)*x-2*pow(a,2)*pow(x,2)+2*a*pow(x,3)-pow(x,4);
			h1=pow(a,3)-4*pow(a,2)*x+6*a*pow(x,2)-4*pow(x,3);
			Rb=(w*s1)/(20*pow(l,3));
			Ra=w*(l-(a/2)-(b/2))-Rb;
			Mb=(-w*s2)/(60*pow(l,2));
			Ma=Mb+Rb*l-w*(pow(l,2)/2-(b*l)/2+pow(b,2)/(6)-pow(a,2)/6);
			
			if(x<=a)
			{
				t=(Ra*pow(x,2))/(2*E*I)+((Ma*x)/(E*I))-(w*pow(x,4))/(24*E*I*a);
				y=(-(Ra*pow(x,3)))/(6*E*I)-((Ma*pow(x,2))/(2*E*I))+(w*pow(x,5))/(120*E*I*a);
			}
			
			else if(a<x<(l-b))
			{
				t=(Ra*pow(x,2))/(2*E*I)+(Ma*x)/(E*I)+(w*h1)/(24*E*I);
				y=(-(Ra*pow(x,3)))/(6*E*I)-(Ma*pow(x,2))/(2*E*I)-(w*g1)/(24*E*I);
			}
			
			else if(x>=(l-b))
			{
				t=((-Rb*pow(xp,2))/(2*E*I))-(Mb*xp)/(E*I)+(w*pow(xp,4))/(24*E*I*b);
				y=(-(Rb*pow(xp,3)))/(6*E*I)-((Mb*pow(xp,2))/(2*E*I))+(w*pow(xp,5))/(120*E*I*b);
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
	}
	
	else if(n==4)                                        //Fixed Pinned Beam
	{
		cout<<"  ////|                                          "<<endl;
        cout<<"  ////|                                          "<<endl;
        cout<<"  ////|                                          "<<endl;
        cout<<"  ////|_____________________________________     "<<endl;
        cout<<"  ////|_____________________________________|    "<<endl;
        cout<<"  ////|                                     O    "<<endl;
        cout<<"  ////|                                          "<<endl;
        cout<<"  ////|                                          "<<endl<<endl;
        
		cout<<"Enter your load:(Point-load=1 or Point-moment=2 or Trapezoidal-load(partially distributed linearly varying load)=3 or Trapezoidal load distribution=4)"<<endl;
		cin>>qc;
		
		if(qc==1)                                    //Point load in Fixed Pinned Beam
		{
			cout<<"  ////|            p                             "<<endl;
            cout<<"  ////|            |                             "<<endl;
            cout<<"  ////|            V                             "<<endl;
            cout<<"  ////|_____________________________________     "<<endl;
            cout<<"  ////|_____________________________________|    "<<endl;
            cout<<"  ////|            :                        O    "<<endl;
            cout<<"  ////|            :                             "<<endl;
            cout<<"  ////|-----(a)----|                             "<<endl<<endl;
            
			cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;													        
			
			while(a>l)
			{
				cout<<"error: a shoud be less than l"<<endl;
				cout<<"Enter a:(distance from the start of the beam)"<<endl;                
			    cin>>a;
			} 
			
			b=(l-a);
			
			cout<<"Enter the value of point load: "<<endl;
			cin>>p;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;																
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;              
			    cin>>x;
			} 
			
			x1=(2-sqrt(2))*l;
			x2=0.65270*l;                                 //(root of: pow(x,3)-3*l*pow(x,2)+pow(l,3)=0)
			Ra=(p*b*(3*pow(l,2)-pow(b,2))/2*pow(l,3));
			Rb=(p*pow(a,2)*(2*l+b)/2*pow(l,3));
			Ma=(-p*a*b*(l+b)/(2*pow(l,2)));
			
			if(x<=a)
			{
				t=(Ra*pow(x,2)/(2*E*I))+(Ma*x/(E*I));
				y=(-Ra*pow(x,3)/(6*E*I))-(Ma*pow(x,2)/(2*E*I));
			}
			
			else
			{
				t=(Ra*pow(x,2)/(2*E*I))+(Ma*x/(E*I))-(p*pow(x-a,2)/(2*E*I));
				y=(-Ra*pow(x,3)/(6*E*I))-(Ma*pow(x,2)/(2*E*I))+(p*pow(x-a,3)/(6*E*I));
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
		
		if(qc==2)                                  //Point moment in Fixed Pinned Beam
		{
			cout<<"  ////|                                          "<<endl;
            cout<<"  ////|                                          "<<endl;
            cout<<"  ////|       point moment                       "<<endl;
            cout<<"  ////|_____________________________________     "<<endl;
            cout<<"  ////|_____________________________________|    "<<endl;
            cout<<"  ////|            :                        O    "<<endl;
            cout<<"  ////|            :                             "<<endl;
            cout<<"  ////|-----(a)----|                             "<<endl<<endl;
            
			cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;														    	
			
			while(a>l)
			{
				cout<<"error: a shoud be less than l"<<endl;
				cout<<"Enter a:(distance from the start of the beam)"<<endl;                
			    cin>>a;
			} 
			
			b=(l-a);
			
			cout<<"Enter the value of point moment: "<<endl;
			cin>>m;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;                                  							
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;                
			    cin>>x;
			} 
			
			x1=0.257773*l;               //(x1,x2 are roots of:3x^2-9*l*x^2+6*l^2*x-l^3=0)
			x2=0.605069*l;               //(x1,x2 are roots of:3x^2-9*l*x^2+6*l^2*x-l^3=0)
			xd=0.582925*l;               //(xd is a root of: 3*sqrt(3)*x^3[(2*l-3*x)(2*l-x)]^(3/2)-2*[l^2-3*(l-x)^2]^3=0)
			ta=3*pow(b,2)-pow(l,2);
			tb=(2*l-a)*(3*b-l);
			Ra=(3*m*a*(l+b)/(2*pow(l,3)));
			Rb=(-Ra);
			Ma=Rb*l+m;
			
			if(x<=a)
			{
				t=(Ra*pow(x,2)/(2*E*I))+(Ma*x/(E*I));
				y=(-Ra*pow(x,3)/(6*E*I))-(Ma*pow(x,2)/(2*E*I));
			}
			
			else
			{
				t=(Ra*pow(x,2)/(2*E*I))+(Ma*x/(E*I))-(m*(x-a)/(E*I));
				y=(-Ra*pow(x,3)/(6*E*I))-(Ma*pow(x,2)/(2*E*I))+(m*pow(x-a,2)/(2*E*I));
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
			
		}
		 
		if(qc==3)                                          //Trapezoidal load in Fixed Pinned Beam
		{
			cout<<"                             w2                        "<<endl;
            cout<<"                             .                         "<<endl;
            cout<<"                           . |                         "<<endl;
            cout<<"                         . | |                         "<<endl;
            cout<<"                       . | | |                         "<<endl;
            cout<<"                  w1 . | | | |                         "<<endl;
            cout<<"                   . | | | | |                         "<<endl;
            cout<<"                   | | | | | |                         "<<endl;
            cout<<"  ////|            | | | | | |                         "<<endl;
            cout<<"  ////|            V V V V V V                         "<<endl;
            cout<<"  ////|_______________________________________         "<<endl;
            cout<<"  ////|_______________________________________|        "<<endl;
            cout<<"  ////|            :         :                O        "<<endl;
            cout<<"  ////|            :         :                :        "<<endl;
            cout<<"  ////|----(a)-----|         |-------(b)------|        "<<endl<<endl;
            
		  	cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;													            		
			
			cout<<"Enter b:(Distance between the end of the load and the end of the beam)"<<endl;
			cin>>b;																		
			
			while((a+b)>l)
			{
			cout<<"error: a+b shoud be less than l"<<endl;
			cout<<"Enter a:(distance from the start of the beam)"<<endl;
			cin>>a;													            		
			
			cout<<"Enter b:(Distance between the end of the load and the end of the beam)"<<endl;
			cin>>b;
			} 
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;																		
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;                
			    cin>>x;
			} 
			
			cout<<"Enter w1:(value of load at the start) "<<endl;
			cin>>w1;
			
			cout<<"Enter w2:(value of load at the end) "<<endl;
			cin>>w2;
			
			xp=l-x;
			xa=x-a;
			lw=l-a-b;
			wm=(w1+w2)/2;
			wd=(w2-w1);
			wx=w1+((w2-w1)*(x-a)/lw);
			s1=40*l*(2*pow(l,2)-(lw,2))+10*lw*(pow(lw,2)-2*pow(a,2))-40*a*(l-b)*(2*l+b);
			s2=lw*(3*pow(lw,2)-10*l*(lw+2*a)+10*a*(a+lw));
			s3=(-60*a)*(a+lw)*(a+(2*b))+(10*pow(lw,2)*(3*lw-4*l))+(60*pow(a,3));
			s4=(10*lw)*(lw*(l+lw)-(a+lw)*(2*l-3*a))-pow(lw,3);
			Ra=(lw*(s1*wm+s2*wd)/80*pow(l,3));
			Rb=lw*wm-Ra;
			Ma=Rb*l-a*lw*wm-(pow(lw,2)*(2*w2+w1)/6);
			tb=(-lw*(s3*wm+s4*wd)/(480*E*I*l));
			
			if(x<=a)
			{
				t=(Ra*pow(x,2)/(2*E*I))+(Ma*x/(E*I));
				y=(-Ra*pow(x,3)/6*E*I)-(Ma*pow(x,2)/(2*E*I));
			}
			
			else if(a<x<l-b)
			{
				t=(Ra*pow(x,2)/(2*E*I))+(Ma*x/(E*I))-((3*w1+wx)*pow(xa,3)/(24*E*I));
				y=(-Ra*pow(x,3)/6*E*I)-(Ma*pow(x,2)/(2*E*I))+((4*w1+wx)*pow(xa,4)/(120*E*I));
			}
			
			else
			{
				t=tb-((Rb*pow(xp,2)/(2*E*I)));
				y=tb*(xp)-((Rb*pow(xp,3)/(6*E*I)));
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
		
		if(qc==4)                                                     // Trapezoidal load distribution
		{
			cout<<"                     . . . . . .                "<<endl;
            cout<<"                   . | | | | | | .              "<<endl;
            cout<<"                 . | | | | | | | | .            "<<endl;
            cout<<"               . | | | | | | | | | | .          "<<endl;
            cout<<"             . | | | | | | | | | | | | .        "<<endl;
            cout<<"  \\\\|    . | | | | | | | | | | | | | | .      "<<endl;
            cout<<"  \\\\|  . | | | | | | | | | | | | | | | | .    "<<endl;
            cout<<"  \\\\|. V V V V V V V V V V V V V V V V V V .  "<<endl;
            cout<<"  \\\\|_______________________________________  "<<endl;
            cout<<"  \\\\|_______________________________________| "<<endl;
            cout<<"  \\\\|              :         :              O "<<endl;
            cout<<"  \\\\|              :         :              : "<<endl;
            cout<<"  \\\\|------(a)-----|         |------(b)-----| "<<endl<<endl;
            
         	cout<<"Enter the length of the beam:"<<endl;
			cin>>l;
			
			cout<<"Enter a:(length of the triangle load at the start)"<<endl;
			cin>>a;                                                                          
			
			cout<<"Enter b:(length of the triangle load at the end)"<<endl;
			cin>>b; 
			
			while((a+b)>l)
			{
				cout<<"error: a+b shoud be less than l"<<endl;
				cout<<"Enter a:(length of the triangle load at the start)"<<endl;                
			    cin>>a;
			  	cout<<"Enter b:(length of the triangle load at the end)"<<endl;
			    cin>>b;
			} 
			
			cout<<"Enter w:(value of wide load)"<<endl;
			cin>>w;
			
			cout<<"Enter where you want the values of slope and deflection: "<<endl;
			cin>>x;
			
			while(x>l)
			{
				cout<<"error: x shoud be less than l"<<endl;
				cout<<"Enter x:(distance from the start of the beam)"<<endl;               
			    cin>>x;
			} 
			
			xp=l-x;
			s1=pow(5*pow(l,2)-pow(b,2),2)-5*l*a*(4*pow(l,2)-pow(a,2))-pow(a,4);
			s2=(-10*pow(l,3)*pow(b,2)*(l-b))-pow(l,2)*pow(a,3)*(5*l-3*a)+pow(l,2)*(5*pow(l,4)-3*pow(b,4));
			g1=(-pow(a,4))/5+pow(a,3)*x-2*pow(a,2)*pow(x,2)+2*a*pow(x,3)-pow(x,4);
			h1=pow(a,3)-4*pow(a,2)*x+6*a*pow(x,2)-4*pow(x,3);
			Ra=(w*s1)/(40*pow(l,3));
			Rb=w*(l-(a/2)-(b/2))-Ra;
			Ma=Rb*l-w*((pow(l,2)/2)-(b*l)/2+(pow(b,2))/6-(pow(a,2))/6);
			tb=(w*s2)/(240*E*I*pow(l,3));
			
			if(x<=a)
			{
				t=((Ra*pow(x,2))/(2*E*I))+((Ma*x)/(E*I))-((w*pow(x,4))/(24*E*I*a));
				y=((-Ra*pow(x,3)))/(6*E*I)-((Ma*pow(x,2)))/(2*E*I)+((w*pow(x,5)))/(120*E*I*a);
			}
			
			else if(a<x<(l-b))
			{
				t=((Ra*pow(x,2))/(2*E*I))+((Ma*x)/(E*I))+((w*h1)/(24*E*I));
				y=((-Ra*pow(x,3)))/(6*E*I)-((Ma*pow(x,2)))/(2*E*I)-((w*g1))/(24*E*I);
			}
			
			else if(x>=(l-b))
			{
				t=tb-((Rb*pow(xp,2)))/(2*E*I)+(w*pow(xp,4))/(24*E*I*b);
				y=tb*xp-(Rb*pow(xp,3)/(6*E*I))+(w*pow(xp,5)/(120*E*I*b));
			}
			
			cout<<"Slope= "<<t<<endl;
			cout<<"Deflection= "<<y<<endl;
		}
		
	}
			
	getch();
	
}
