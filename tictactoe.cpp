#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char tic[3][3]={{'#','#','#'},{'#','#','#'},{'#','#','#'}};




void printboard()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%c ",tic[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}




int checkcomplete(int count)
{
	char c;
	if(count%2==0)
	c='O';
	else
	c='X';
	for(int i=0;i<3;i++)
	{
		if(tic[i][0]==c && tic[i][1]==c && tic[i][2]==c)
		{
			return 0;
		}
	}
	for(int i=0;i<3;i++)
	{
		if(tic[0][i]==c && tic[1][i]==c && tic[2][i]==c)
		{
			return 0;
		}
	}
	if(tic[0][0]==c && tic[1][1]==c && tic[2][2]==c)
	{
		return 0;
	}	
	if(tic[0][2]==c && tic[1][1]==c && tic[2][0]==c)
	{
		return 0;
	}
	return 1;
}





int taccheckcomplete(char tac[3][3],int count)
{
	char c;
	if(count%2==0)
	c='X';
	else
	c='O';
	for(int i=0;i<3;i++)
	{
		if(tac[i][0]==c && tac[i][1]==c && tac[i][2]==c)
		{
			return 1;
		}
	}
	for(int i=0;i<3;i++)
	{
		if(tac[0][i]==c && tac[1][i]==c && tac[2][i]==c)
		{
			return 1;
		}
	}
	if(tac[0][0]==c && tac[1][1]==c && tac[2][2]==c)
	{
		return 1;
	}	
	if(tac[0][2]==c && tac[1][1]==c && tac[2][0]==c)
	{
		return 1;
	}
	return 0;
}



int finalcompmove(char tac[3][3],int count)
{
	int min=100,max=-100,sp=0,rr;
	char temp[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			temp[i][j]=tac[i][j];
		}
	}
	if(count%2==0)
	{
		count++;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(temp[i][j]=='#')
				{
					sp++;
					temp[i][j]='O';
					if(taccheckcomplete(temp,count))
					{
						//printf("Bye\n");
					    return 1;
				}
					rr=finalcompmove(temp,count);
					if(rr>max)
					{
						max=rr;
					}
					//	tac[i][j]='#';
						for(int i=0;i<3;i++)
	                   {
		                  for(int j=0;j<3;j++)
		                      {
			                     temp[i][j]=tac[i][j];
		                      }
	                   } 
				}
			}
		}
			if(sp==0)
			{
				//printf("HIBYE\n");
	        return 0;
			}
			//printf("max=%d\n\n\n",max);
		    return max;
	}
	else
	{
		count++;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(temp[i][j]=='#')
				{
					sp++;
					temp[i][j]='X';
					if(taccheckcomplete(temp,count))
					{
						//printf("Hi\n");
					return -1;
				}
				//printf("HELLO\n\n");
					rr=finalcompmove(temp,count);
					if(rr<min)
					{
						min=rr;
					}
					//tac[i][j]='#';
						for(int i=0;i<3;i++)
	                    {
	 	                    for(int j=0;j<3;j++)
		                    {
		                    	temp[i][j]=tac[i][j];
	                      	}
                    	}
				}
			}
		}
		if(sp==0)
		{
			//printf("HIBYE\n\n\n");
		return 0;
		}
		//printf("min=%d\n\n",min);
		return min;
	}
}



void playermove()
{
	int a,b;
	printf("Enter the position of X (in the form a and b) ::::  ");
	scanf("%d%d",&a,&b);
	printf("\n");
	printf("\n");
	if(a>0 && a<=3 && b>0 && b<=3 )
	{	
	printf("Players Turn\n\n\n");
	tic[a-1][b-1]='X';
    }
   else
   {
   	printf("----------Position should be between [1,3]----------");
	   printf("\n\n");
	   playermove();	 
   }

}




void computermove()
{
	printf("Computers turn\n\n\n");
	int max=-100,m1=0,m2=0,rr,temp=0;
	char tac[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			tac[i][j]=tic[i][j];
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(tac[i][j]=='#')
			{
			tac[i][j]='O';
			if(taccheckcomplete(tac,3))
			{
				temp++;
				m1=i;
				m2=j;
				break;
			}
			else
			{
			
			rr=finalcompmove(tac,1);
			if(rr>max)
			{
				max=rr;
				m1=i;
				m2=j;
			}
		}
			//tac[i][j]='#';
	    	for(int i=0;i<3;i++)
	        {
		    for(int j=0;j<3;j++)
		    {
			tac[i][j]=tic[i][j];
		    }
	        }
		}
		}
		if(temp!=0)
		break;
	}
	tic[m1][m2]='O';
	
/*	int temp=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(tic[i][j]=='#')
			{
				tic[i][j]='O';
				temp++;
				break;
			}
		}
			if(temp==1)
			break;
	}*/
}





void rungame()
{
	int count=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			tic[i][j]='#';
		}
	}
	do
	{
		count++;	
		printboard();
		if(count%2!=0)
		playermove();
		else
		computermove();
			if(count==9)
			{
				printboard();
				printf("----------Draw----------\n\n\n");
				break;
		}
	}while(checkcomplete(count));
	 if(count%2==0 &&count !=9)
	 {
		printboard();	 
	printf("----------Computer Wins----------\n\n\n");
}
	else if(count%2!=0 && count!=9)
	{
		printboard();
	printf("----------Player Wins----------\n\n\n");
}
}




int main()
{
	
	rungame();
	printf("if u want to play again press 1 else 0 ::::");
	int y;
	scanf("%d",&y);
	printf("\n\n");
	while(y)
	{
			rungame();
			printf("if u want to play again press 1 else 0 ::::");
	        scanf("%d",&y);
	        printf("\n\n");
	}
}
