#include <string>
#include <iostream>
using namespace std;

class GameEntry{
  public:
  	GameEntry();
    GameEntry(const GameEntry& gf);
  	GameEntry(const string& n, int s = 0);
  	string Getname() const;
  	int Getscore() const;
  private:
  	string name;
  	int score;
};

GameEntry::GameEntry(){
	name = "none";
	score = 0;
}

GameEntry::GameEntry(const GameEntry& gf){
  name = gf.name;
  score = gf.score;
}

GameEntry::GameEntry(const string& n, int s)
  :name(n), score(s)
  {}

string GameEntry::Getname() const {return name;}

int GameEntry::Getscore() const { return score;}

class Scores{
  public:
  	Scores(int MaxEnt); //intializes a array of MaxEnt to store GameEntry datatype
  	~Scores();
    void add(const GameEntry& newGameEntry); //add the 'new' game entry and returns pointer to array
    GameEntry remove(int index); // remove the ith position entry
    void display();
  private:
  	int capacity;
  	int size;
  	GameEntry* array;
};

Scores::Scores(int MaxEnt){
   capacity = MaxEnt;
   size = 0;
   array = new GameEntry[capacity];
}

Scores::~Scores(){
  delete [] array;
}
void Scores::display(){
	for (int i = 0; i <= size; ++i)
	{
		cout << array[i].Getname() << endl;
		cout << array[i].Getscore() << endl;
	}
}

void Scores::add(const GameEntry& newGameEntry){
	int newScore = newGameEntry.Getscore();
	int i;
	if (capacity == size)
	{
		if(newScore <= array[size - 1].Getscore())
			return;
	}
	else
		size++;
    i = size - 2;

	while(i >= 0 && newScore > array[i].Getscore()){
		array[i+1] = array[i];
		i--;
	}
	array[i+1] = newGameEntry;
	return;
}
GameEntry Scores::remove(int index){
  GameEntry e = array[index];
  if(index > size-1){
  	cout << "out of bounds" << endl;
  }
  else{
  	for(int i=index; i <= size-2 ; i++){
  		array[i] = array[i+1];
  	}
  	array[size-1] = GameEntry();
  	size--;
  }
  return e;
}

int main(){
	GameEntry* K = new GameEntry("Prakash" , 11);
	GameEntry G ("Manish", 10);
	GameEntry J ("Rupank", 20);
	GameEntry L ("Bhavuk", 22);
	GameEntry M ("Aryan", 30);
  GameEntry P = L;
  GameEntry N(J);

	Scores book(10);
	book.display();
	cout << ' ' << endl;
    book.add(G);
    book.add(L);
    book.add(J);
    book.add(P);
    book.add(N);
    book.display();
    book.add(M);
    book.display();
    cout << ' ' << endl;
    book.remove(2);
    book.display();
}