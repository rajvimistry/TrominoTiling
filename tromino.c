#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=-10;
int count1=0;

static void trominoTile(int size,int hole_row,int hole_col,int board[size][size],int total_row);
void main(int argc, char *argv[])
{
	int k = atoi(argv[1]);
	int r = atoi(argv[2]);
	int c = atoi(argv[3]);
	int total_row = 1,total_column,i,j;

	for(i=0;i<k;i++)
	{total_row = total_row*2;}
	total_column = total_row;
	srand(time(NULL));
	//generate board

	int board[total_row][total_column];

	for(i=0;i<total_row;i++)
	{
		for(j=0;j<total_column;j++)
		{
			board[i][j]=-5;
		}
	}

	//Set the hole in a board
	for(i=0;i<total_row;i++)
	{
		for(j=0;j<total_column;j++)
		{
			if(i==(r-1) && j==(c-1)){board[i][j]=-1;}
		}
	}
	trominoTile(total_row,r,c,board,total_row);
}

void trominoTile(int size,int hole_row,int hole_col,int board[size][size],int total_row)
{
	//Base Condition
	int random = rand() % 10;
	if(size == 2)
	{
		int i,j;//count++;			
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				if(board[i][j]!=-1 && board[i][j] == -5){board[i][j]=random;}
			}
		}return;
	}
	//count++;
	int board1[size/2][size/2], board2[size/2][size/2], board3[size/2][size/2], board4[size/2][size/2],i,j;

	//Deviding the board into 4 subboards
	for(i=0;i<size/2;i++)
	{
		for(j=0;j<size/2;j++)
		{
			board1[i][j] = -5;
			board2[i][j] = -5;
			board3[i][j] = -5;
			board4[i][j] = -5;
		}
	}
	int h1_r=0,h1_c=0,h2_r=0,h2_c=0,h3_r=0,h3_c=0,h4_r=0,h4_c=0;

	//Set the holes in remaining quadrants
	if((hole_row-1)<(size/2))
	{
		if((hole_col-1)<(size/2))
		{
			board2[(size/2)-1][0] = random;h2_r=(size/2);h2_c=1;
			board3[0][(size/2)-1] = random;h3_r=1;h3_c=(size/2);
			board4[0][0] = random;h4_r=1;h4_c=1;
			//int m1,m2,n1,n2;
			for(i=0;i<size/2;i++)
			{
				for(j=0;j<size/2;j++)
				{
					board1[i][j]=board[i][j];
					if(board1[i][j]==-1 || board1[i][j] > -1){h1_r=i+1;h1_c=j+1;}
					else{board1[i][j] = -5;}
				}
			}
		}
		else
		{
			board1[(size/2)-1][(size/2)-1] = random; h1_r=(size/2);h1_c=(size/2);
			board3[0][(size/2)-1] = random; h3_r=1;h3_c=(size/2);
			board4[0][0] = random; h4_r=1;h4_c=1;
			int m1,n1,m2,n2;
			for(m1=0,m2=0;m1<size/2,m2<size/2;m1++,m2++)
			{
				for(n1=size/2,n2=0;n1<size,n2<size/2;n2++,n1++)
				{
					board2[m2][n2]=board[m1][n1];
					if(board2[m2][n2]==-1 || board2[m2][n2] >-1){board2[m2][n2]=board[m1][n1];h2_r=m2+1;h2_c=n2+1;}
					else{board2[i][j] = -5;}
				}
			}
		}
	}
	else
	{
		if((hole_col-1)<(size/2))
		{
			board2[(size/2)-1][0] = random;h2_r=(size/2);h2_c=1;
			board1[(size/2)-1][(size/2)-1] =random;h1_r=(size/2);h1_c=(size/2);
			board4[0][0] = random;h4_r=1;h4_c=1;
			int m1,n1,n2,m2;
			for(m1=size/2,m2=0;m1<size,m2<size/2;m1++,m2++)
			{
				for(n1=0,n2=0;n1<size/2,n2<size/2;n2++,n1++)
				{
					board3[m2][n2]=board[m1][n1];
					if(board3[m2][n2]==-1 || board3[m2][n2] >-1){board3[m2][n2]=board[m1][n1];h3_r=m2+1;h3_c=n2+1;}
					else{board3[i][j] = -5;}
				}
			}
		}
		else
		{
			board1[(size/2)-1][(size/2)-1] = random;h1_r=(size/2);h1_c=(size/2);
			board3[0][(size/2)-1] = random;h3_r=1;h3_c=(size/2);
			board2[(size/2)-1][0] = random;h2_r=(size/2);h2_c=1;
			int m1,n1,m2,n2;
			for(m1=size/2,m2=0;m1<size,m2<size/2;m1++,m2++)
			{
				for(n1=size/2,n2=0;n1<size,n2<size/2;n2++,n1++)
				{
					board4[m2][n2]=board[m1][n1];
					if(board4[m2][n2]==-1 || board4[m2][n2]>-1){board4[m2][n2]=board[m1][n1];h4_r=m2+1;h4_c=n2+1;}
					else{board4[i][j] = -5;}
				}
			}
		}
	}

	//Recursive Calls

	trominoTile(size/2,h1_r,h1_c,board1,total_row);
	trominoTile(size/2,h2_r,h2_c,board2,total_row);
	trominoTile(size/2,h3_r,h3_c,board3,total_row);
	trominoTile(size/2,h4_r,h4_c,board4,total_row);


		//combine into a single Board
		int i1,i2,j1,j2;
		for(i1=0,i2=0;i1<size/2,i2<size/2;i1++,i2++)
		{
			for(j1=0,j2=0;j1<size/2,j2<size/2;j1++,j2++)
			{board[i1][j1]=board1[i2][j2];}
		}
		for(i1=0,i2=0;i1<size,i2<(size/2);i1++,i2++)
		{
			for(j1=(size/2),j2=0;j1<size/2,j2<size/2;j1++,j2++)
			{board[i1][j1]=board2[i2][j2];}
		}
		for(i1=(size/2),i2=0;i1<size,i2<size/2;i1++,i2++)
		{
			for(j1=0,j2=0;j1<size/2,j2<size/2;j1++,j2++)
			{board[i1][j1]=board3[i2][j2];}
		}
		for(i1=(size/2),i2=0;i1<size/2,i2<size/2;i1++,i2++)
		{
			for(j1=(size/2),j2=0;j1<size,j2<size/2;j1++,j2++)
			{board[i1][j1]=board4[i2][j2];}
		}


		if(size==total_row)
		{
		printf("\nTromino Tile: \n");

		for(i1=0;i1<size;i1++)
		{
			for(j1=0;j1<size;j1++)
			{
				if(board[i1][j1]==-1){printf("X ");}
				else{printf("%d ",board[i1][j1]);}
			}printf("\n");
		}}
		
}
