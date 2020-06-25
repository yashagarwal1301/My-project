#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000
int c=0;                                  //Total number of vehicles entered in a day

int Matrix[MAXSIZE][MAXSIZE];              /*Blueprint of Parking Lot */
                                           //position is empty(denoted by 0) and if occupied(denoted by token number)
int current=0;

void view(int n , int m);
void sparsematrix(int n , int m);
void entry(int n , int m);
void exits(int n , int m);


void exits(int n , int m)                  /*EXIT Parkink Lot*/
{
    if(current==0)
     cout<<'\n'<<"No vehicle in parking lot"<<'\n';
    else
    {
        int a=0;
        cout<<'\n'<<"##**##**##**##**##**##**##**##"<<'\n';
        int token,xecord,yecord;
        cout<<"Enter token number:";
        cin>>token;
        
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          if(token == Matrix[i][j])
          {
              a=1;
              current--;
              Matrix[i][j]=0;
              
              xecord=n-i;
              yecord=m-j;
              
              cout<<"Total units to exit =  "<<xecord+yecord+n+1;
              cout<<"To exit: go "<<xecord<<" units right, then move "<<yecord<<" units left, and again move "<<n+1<<" units left";
              cout<<'\n'<<"The Exit is at your left";
              cout<<'\n'<<"  THANK YOU"<<'\n'<<"PLEASE VISIT AGAIN"<<'\n';
              
              break;
          }
          if(a==0)
           cout<<'\n'<<"!!!Wrong token number!!!"<<'\n';
    }       
}

void view(int n, int m)
{
    cout<<'\n'<<'\t'<<"PARKING LOT"<<'\n';
    cout<<" [0 denotes empty slot]"<<endl;
    for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
          cout<<Matrix[i][j]<<'\t';
          cout<<'\n';
     }      
}

void entry(int n, int m)                      //Entered Parking Lot
{
    
    if((n*m)==current)
     cout<<'\n'<<"Parking Lot is full!!!";
    
    else
    {
        c++;
        current++;
        
        cout<<'\n'<<"##**##**##**##**##**##**##**##"<<'\n';
        int s=9999,total,xcord,ycord;
        
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
           {
               if(Matrix[i][j]==0)
               {
                   total = i+j;
                   if(total<=s) 
                    {
                        s=total;
                        xcord=i;
                        ycord=j;
                    }   
                   
                }
            }        
                
        cout<<"Your TOKEN NUMBER is:"<<c<<'\n';    
        cout<<"Total units to your slot = "<<ycord+xcord+1<<endl;
        cout<<"Your Parking slot cordinates is: go "<<ycord<<" units straight, and"<<" go "<<xcord+1<<" units right";
        
        Matrix[xcord][ycord]=c;
        
    }
}

void sparsematrix(int n,int m)
{
    cout<<'\n'<<'\t'<<"Empty positions in Parking lot"<<'\n'<<endl;
    int size=0;
    for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (Matrix[i][j] == 0)
			 size++; 

	int sMatrix[3][size]; 
    
	int k = 0; 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (Matrix[i][j] == 0) 
			{ 
				sMatrix[0][k] = i; 
				sMatrix[1][k] = j; 
				sMatrix[2][k] = Matrix[i][j]; 
				k++; 
			} 

	for (int i=0; i<3; i++) 
	{ 
	    if(i==0)
	     cout<<"ROW    :";
	    else if(i==1)
	     cout<<"COLUMN :";
	    else if(i==2)
	     cout<<"        ";
		for (int j=0; j<k; j++) 
			cout<<sMatrix[i][j]<<" "; 

		cout<<'\n';
	} 
	
	cout<<endl<<"Total number of empty slots:"<<(n*m)-current<<'\n';
 
}


int main() 
{
  int n,m,ch;
  bool p=true;
  
  cout<<"Enter size of your parking space:";
  cin>>n>>m;                                         /*n = number of rows
                                                       m = number of columns*/ 
  
  memset(Matrix, 0, sizeof(Matrix));                 //slot position is empty(denoted by 0) and if occupied(denoted by token number)
  
  while(p)
  {
      cout<<'\n'<<'\n'<<'\t'<<"****####**MENU**####****"<<'\n';
      cout<<" 1. IN"<<'\n';
      cout<<" 2. OUT"<<'\n';
      cout<<" 3. View Parking Lot"<<'\n';
      cout<<" 4. Empty Slots"<<'\n';
      cout<<" 5. EXIT"<<'\n';
      cout<<"Enter your choice:";
      cin>>ch;
      
      switch(ch)
      {
          case 1: entry(n,m);
                  break;
          case 2: exits(n,m);
                  break;
          case 3: view(n,m);
                  break;
          case 4: sparsematrix(n,m);
                  break;
          case 5: p=false;
                  break;
          default: cout<<"Wrong Input"<<'\n';
          
      }
  }

	return 0; 
} 




