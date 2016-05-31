#include <iostream>
#include <string>
#include <Windows.h>
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"





using namespace std;

enum Place{
	MOUNTAIN = 0,
	WEST,
	NORTH,
	SOUTH,
	EAST,
	DINNING_ROOM,
	KITCHEN,
	LIVING_ROOM,
	GARAGE,
	PARK_1,
	PARK_2,
	NONE
};

//Player
class Player{
	string name;

public:
	int current_room;

	Player(int _current_room, string _name);

	Player();

	void SetPlayer(string _name, int current_room);
	string get_name()const;
};

Player::Player(int _current_room, string _name) : current_room(_current_room), name(_name){};

void Player::SetPlayer(string _name, int _current_room){
	name = _name;
	current_room = _current_room;
}

Player::Player(){
	name = "player name here";
	current_room = MOUNTAIN;
};

string Player::get_name()const{ return name; };

//Room

class Room{
	string name;
	string description;
	bool goNorth;
	bool goSouth;
	bool goEast;
	bool goWest;


public:
	Room(string _name, string d, bool n, bool s, bool e, bool w);

	Room();

	string get_name()const;
	string get_desc()const;

	bool get_gonorth()const;
	bool get_gosouth()const;
	bool get_goeast()const;
	bool get_gowest()const;

	void CreateRoom(string _name, string _description, bool _goNorth, bool _goSouth, bool _goEast, bool _goWest);
};


Room::Room(string _name, string d, bool n, bool s, bool e, bool w){
	name = _name;
	description = d;
	goNorth = n;
	goSouth = s;
	goEast = e;
	goWest = w;
}

Room::Room(){
	name = "room name here";
	description = "description here";
	goNorth = true;
	goSouth = true;
	goEast = true;
	goWest = true;
}

string Room::get_name()const { return name; };
string Room::get_desc()const { return description; };

bool Room::get_gonorth()const { return goNorth; };
bool Room::get_gosouth()const { return goSouth; };
bool Room::get_goeast()const { return goEast; };
bool Room::get_gowest()const { return goWest; };

void Room::CreateRoom(string _name, string _description, bool _goNorth, bool _goSouth, bool _goEast, bool _goWest){
	name = _name;
	description = _description;
	goNorth = _goNorth;
	goSouth = _goSouth;
	goEast = _goEast;
	goWest = _goWest;
}



//Exit


class Exit{
	int RoomAtNorth;
	int RoomAtSouth;
	int RoomAtEast;
	int RoomAtWest;
public:
	Exit(int rn, int rs, int re, int rw);
	Exit();

	void SetExit(int _RoomAtNorth, int _RoomAtSouth, int _RoomAtEast, int _RoomAtWest);

	int get_rn()const;
	int get_rs()const;
	int get_re()const;
	int get_rw()const;

};


Exit::Exit(int rn, int rs, int re, int rw){
	RoomAtNorth = rn;
	RoomAtSouth = rs;
	RoomAtEast = re;
	RoomAtWest = rw;
}

Exit::Exit(){
	RoomAtNorth = MOUNTAIN;
	RoomAtSouth = WEST;
	RoomAtEast = DINNING_ROOM;
	RoomAtWest = LIVING_ROOM;
}


void Exit::SetExit(int _RoomAtNorth, int _RoomAtSouth, int _RoomAtEast, int _RoomAtWest){
	RoomAtNorth = _RoomAtNorth;
	RoomAtSouth = _RoomAtSouth;
	RoomAtEast = _RoomAtEast;
	RoomAtWest = _RoomAtWest;
}

int Exit::get_rn()const { return RoomAtNorth; };
int Exit::get_rs()const { return RoomAtSouth; };
int Exit::get_re()const { return RoomAtEast; };
int Exit::get_rw()const { return RoomAtWest; };


//globals

Player* dad = new Player;
Room* Rooms = new Room[11];
Exit* Exits = new Exit[11];

//out fcn

void move(int dest, bool isPossible){

	if (isPossible){
		dad->current_room = dest;
	}
};


//main

int main(){
	bool exit = false;

	dad->SetPlayer("dad", MOUNTAIN);

	Rooms[MOUNTAIN].CreateRoom("Mountain", "You are in the Mountain, where the Troll was born :)", false, true, false, false);
	Rooms[WEST].CreateRoom("West of the House", "You are in the West of the House. Here you can find the front door of the house", true, true, true, true);
	Rooms[NORTH].CreateRoom("North of the House", "You are in the North of the House. Here you can find the entrance of the Garage, but it is locked", false, true, true, true);
	Rooms[SOUTH].CreateRoom("South of the House", "You are in the South of the House. Here you can only find a big and ugly wall.", false, false, true, true);
	Rooms[EAST].CreateRoom("East of the House", "You are in the East of the House. There is nothing here, but the Park is near :P", true, true, true, false);
	Rooms[DINNING_ROOM].CreateRoom("Dinning room", "You are in the Dining Room.", true, false, true, true);
	Rooms[KITCHEN].CreateRoom("Kitchen", "You are in the Kitchen. Be careful with knives!", false, false, false, true);
	Rooms[LIVING_ROOM].CreateRoom("Living room", "You are in the Living Room.", false, true, true, false);
	Rooms[GARAGE].CreateRoom("Garage", "You are in the Garage. You cannot open the door to go to the North of the House.", true, false, false, true);
	Rooms[PARK_1].CreateRoom("Park 1", "You are in the Park 1.", false, true, false, false);
	Rooms[PARK_2].CreateRoom("Park 2", "You are in the Park 2.", true, false, false, true);

	Exits[MOUNTAIN].SetExit(NONE, WEST, NONE, NONE);
	Exits[WEST].SetExit(NORTH, SOUTH, DINNING_ROOM, MOUNTAIN);
	Exits[NORTH].SetExit(NONE, GARAGE, EAST, WEST);
	Exits[SOUTH].SetExit(NONE, NONE, EAST, WEST);
	Exits[EAST].SetExit(NORTH, SOUTH, PARK_2, NONE);
	Exits[DINNING_ROOM].SetExit(LIVING_ROOM, NONE, KITCHEN, WEST);
	Exits[KITCHEN].SetExit(NONE, NONE, NONE, DINNING_ROOM);
	Exits[LIVING_ROOM].SetExit(NONE, DINNING_ROOM, GARAGE, NONE);
	Exits[GARAGE].SetExit(NORTH, NONE, NONE, LIVING_ROOM);
	Exits[PARK_1].SetExit(NONE, PARK_2, NONE, NONE);
	Exits[PARK_2].SetExit(PARK_1, NONE, NONE, EAST);

	cout << "----------------------------------------------------------------------------" << endl;
	cout << "This Zork has been created by Carlos Martinez Segarra. The instructions are" << endl;
	cout << "very simple:" << endl;
	cout << "-You can move in the map with the commands north/south/east/west and n/s/e/w" << endl;
	cout << "-To exit the program you have to write the command 'exit' when the game asks" << endl;
	cout << "which direction do you want to go." << endl;
	cout << "-If you are lost check the map that I have in my Github :)" << endl;
	cout << "-To open a door just answer yes or y when the question 'do you want to open" << endl;
	cout << "the door' appears on the screen." << endl;
	cout << "I hope that you enjoy playing the game!!! :))" << endl;
	cout << "----------------------------------------------------------------------------" << endl;

	int x = MOUNTAIN;

	while (exit != true){

		x = dad->current_room;

		cout << Rooms[x].get_desc() << endl;

		cout << "Which direction do you want to go ?" << endl;
		string answer;
		getline(cin, answer);

		if (answer == "north" || answer == "n" || answer == "go north"){
			move(Exits[x].get_rn(), Rooms[x].get_gonorth());
		}
		else if (answer == "south" || answer == "s" || answer == "go south"){
			move(Exits[x].get_rs(), Rooms[x].get_gosouth());
		}
		else if (answer == "east" || answer == "e" || answer == "go east"){
			move(Exits[x].get_re(), Rooms[x].get_goeast());
		}
		else if (answer == "west" || answer == "w" || answer == "go west"){
			move(Exits[x].get_rw(), Rooms[x].get_gowest());
		}
		else if (answer == "quit" || answer == "exit"){
			exit = true;
		}

	}

	delete dad;
	delete[] Exits;
	delete[] Rooms;


	return 0;

}