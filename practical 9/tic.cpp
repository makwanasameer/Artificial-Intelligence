#include<iostream.h>
#include<conio.h>
#include<process.h>

enum whoplays { human, machine };
enum cell { empty, full };
enum boolean { false, true };
int deep=0;

  int totalscore = 0;
  int highscore = 0;
  int avgscore;
  int score2;
  boolean waswin = false;
  boolean wasother = false;



class Position            		     
  {                                          
  private:                                   
    cell mcell[9];
cell hcell[9];                           
    whoplays player;                         
  public:
    Position();
    boolean IsWin();


boolean IsLegal(int);
    void MakeMove(int);
    void SetPlayer(whoplays);
    static void InitDisplay();
    void Display();
    int Evaluate(int&);
  };


void Position::SetPlayer(whoplays p)
  {
  player = p;
  }


Position::Position()
  {
  for (int j=0; j<9; j++ )
    mcell[j] = hcell[j] = empty;
  }

boolean Position::IsLegal(int move)
  {
  if( move>=0 && move<=8 && mcell[move]==empty && hcell[move]==empty )
    return(true);
  else
    return(false);
  }



boolean Position::IsWin()
  {
  cell *ptr;
  if( player==human )
    ptr = hcell;
  else
    ptr = mcell;


//20
if( (ptr[0] && ptr[1] && ptr [2]) ||
      (ptr[3] && ptr[4] && ptr [5]) ||
      (ptr[6] && ptr[7] && ptr [8]) ||
      (ptr[0] && ptr[3] && ptr [6]) ||
      (ptr[1] && ptr[4] && ptr [7]) ||
      (ptr[2] && ptr[5] && ptr [8]) ||
      (ptr[0] && ptr[4] && ptr [8]) ||
      (ptr[2] && ptr[4] && ptr [6]) )
	return(true);
      else
	return(false);
  }


void Position::Display()
  {
  void Insert(unsigned char, int, int);
  int row, col;

  for(int j=0; j<9; j++)
    {
    if( hcell[j] )
      Insert('X', (j%3)*6+2, (j/3)*4+1);
    else if( mcell[j] )
      Insert('0', (j%3)*6+2, (j/3)*4+1);

else
      Insert(' ', (j%3)*6+2, (j/3)*4+1);
    }
  gotoxy(1,23);
  }

//baki





void Position::InitDisplay()
  {
  const unsigned char block = '\xB2';
  void Insert(unsigned char, int, int);
  int row,col;
clrscr();
  for(row=0; row<11; row++)
    {
    Insert(block, 5, row);
    Insert(block, 11, row);

    }
  for(col=0; col<17; col++)
    {
    Insert(block, col, 3);
    Insert(block, col, 7);
    }
  for(int j=0; j<9; j++)
    Insert( (char)(j+'0'), (j%3)*6+4, (j/3)*4 );
  }

void Insert(unsigned char ch, int col, int row)
  {
  gotoxy(col+50+1, row+5+1);
  putch(ch);
  }


int Position::Evaluate( int& score)
  {
  int const winscore = 100;
  int const drawscore = 50;
  int returnmove;
  Position *posptr;
  int legalmoves = 0;


if(score2==winscore)
	  waswin = true;
	else
	  wasother = true;
	totalscore += score2;
	if( score2 > highscore )
	  {
	  highscore = score2;
	  returnmove = move;
	  }
	}


      delete posptr;
      }
    }
  if( legalmoves==0 )
    {
    score = drawscore;
    --deep;
    return(99);
    }




//baki


void Position::MakeMove(int move)
  {
  if( player==human )
    hcell[move] = full;
  else
    mcell[move] = full;
  }


void main(void)
  {
  int move;
  int sc;
  int movecount = 0;
  Position current;
  int cursrow =  0;
Position::InitDisplay();
  while(1)
    {
    current.SetPlayer(human);
    current.Display();
    gotoxy(1, ++cursrow);
    cout << "Make your move (0 to 8): ";


    cin >> move;
    if( ! current.IsLegal(move) )
      {
      gotoxy(1, ++cursrow);
      cout << "Illegal move.";
      continue;
      }
    current.MakeMove(move);
    current.Display();


if( current.IsWin() )
      {
      gotoxy(1, ++cursrow);
      cout << "Computer win!";
      getch();
      exit(0);
      }
    }
  }

//baki

