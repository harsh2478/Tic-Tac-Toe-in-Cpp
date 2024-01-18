#include "iostream"
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char value = 'X';
string p1;
string p2;
bool tie = false;

// creating the space for the structure of the game and giving inout for names;
void structure(){

// creating the structure of the game;
cout << "    |      |    \n";
cout << " "<<space[0][0]<<  "  |  " <<space[0][1]<< "   | "<< space[0][2]<< "\n"; 
cout << "____|______|____\n";
cout << "    |      |    \n";
cout << " "<<space[1][0]<<  "  |  " <<space[1][1]<< "   | "<< space[1][2]<< "\n";
cout << "____|______|____\n";
cout << "    |      |    \n";
cout << " "<<space[2][0]<<  "  |  " <<space[2][1]<< "   | "<< space[2][2]<< "\n";
cout << "    |      |    \n";
}


void placingValue(){
	// This will enter the value as per the positions clarify by digit variable
	int digit;
	
	if(value=='X')
	{
	cout<<p1<<", Please enter: ";
	cin>>digit;	
	
	}
	else if(value == 'O')
	{
	cout<<p2<<", Please enter: ";
	cin>>digit;	
	}
	
	
	if(digit==1)
	{
	row=0;
	column=0;	
	}	

	else if(digit==2)
	{
	row=0;
	column=1;	
	}

	else if(digit==3)
	{
	row=0;
	column=2;	
	}
	
	else if(digit==4)
	{
	row=1;
	column=0;	
	}

	else if(digit==5)
	{
	row=1;
	column=1;	
	}

	else if(digit==6)
	{
	row=1;
	column=2;	
	}
	
	else if(digit==7)
	{
	row=2;
	column=0;	
	}
	
	else if(digit==8)
	{
	row=2;
	column=1;	
	}
	
	else if(digit==9)
	{
	row=2;
	column=2;	
	}

	else if(digit<1 || digit>9)
	{
	cout << "INVALID PLACE !!" << endl;	
	return;
	}
	
	if(value=='X' && space[row][column] != 'X'&& space[row][column] != 'O')
	{
		space[row][column] = 'X';
		value = 'O';
	}
	else if(value=='O' && space[row][column] != 'X'&& space[row][column] != 'O')
	{
		space[row][column]='O';
		value = 'X';
	}
	
	else{
		cout << "There is no empty places now" << endl;
		placingValue();
	}
	structure();
}


bool CheckWin(){
	
	for(int i=0;i<3;i++)
	{
		if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i] )
		{
		return true;	
		}
	}
	if(space[0][0]==space[1][1] && space[0][0]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
	{
		return true;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(space[i][j] != 'X' && space[i][j] != 'O')
			{
				return false;
			}
		}
	}
	tie=true;
	return false;
}

int main()
{
	cout << "  WELCOME TO MY TIC-TAC-TOE GAME PORTAL "<< endl;
	cout << "-----------------------------------------"<< endl;
	cout << "INSTRUCTIONS: "<< endl;
	cout << "      1. The game is played on a grid thats 3x3"<<endl;
	structure();
	cout << "      2. You are X and your friend is O "<< endl;
	cout << "      3. The player takes turn putting their marks in empty squares"<< endl;
	cout << "      4. The first player to get 3 of her marks in a row(up, down, diagonally, or across) is the winner"<< endl;
	cout << endl;
	cout << "Enter the name of Player 1 : ";
	getline(cin, p1);
	cout << "Enter the name of the Player 2 : ";
	getline(cin, p2);
	cout << endl;
	cout << " Player 1 is, " << p1 << ", so he will play first "<<endl;
	cout << endl;
	
	while(!CheckWin())
	{
		placingValue();
		CheckWin();
	}
	// this condition means that last turn is of player 2 and the game was not tie
	if(value == 'X' && tie == false)
	{
		cout<<"Congrats "<<p2<<", You Win!!"<<endl; 
	}
	// this condition means that last turn is of player one and the game was not tie
	else if(value == 'O' && tie == false)
	{
		cout<<"Congrats "<<p1<<", You Win!!"<<endl;
	}
	else{
		cout << "It's a DRAW "<<endl;
	}
}
