#include <iostream>
#include <string>

class Position{
public:
	int pos;
};

class Room {
public:
	std::string room_name;

};

int main(){

	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << "This Zork has been created by Carlos Martinez Segarra. The instructions are" << std::endl;
	std::cout << "very simple:" << std::endl;
	std::cout << "-You can move in the map with the commands north/south/east/west and n/s/e/w" << std::endl;
	std::cout << "-To exit the program you have to write the command 'exit' when the game asks" << std::endl;
	std::cout << "which direction do you want to go." << std::endl;
	std::cout << "-If you are lost check the map that I have in my Github :)" << std::endl;
	std::cout << "-To open a door just answer yes or y when the question 'do you want to open" << std::endl;
	std::cout << "the door' appears on the screen." << std::endl;
	std::cout << "I hope that you enjoy playing the game!!! :))" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	Position Player = { 2 };

	bool IsADoor = false;
	bool OpenDoor = false;
	bool exit = false;
	
	int next_room = 0;
	int& next_room_after_door = next_room;

	while (exit != true){

		if (IsADoor == true){
			std::cout << "Do you want to open the door?" << std::endl;
			std::string door_answer;
			getline(std::cin, door_answer);

			if (door_answer == "yes" || door_answer == "y"){
				OpenDoor = true;
			}
			
			if (OpenDoor == true){
				Player.pos = next_room_after_door;
			}
			std::cout << "Do you want to close the door?" << std::endl;
			std::string door2_answer;
			getline(std::cin, door2_answer);
			
			if (door_answer == "yes" || door_answer == "y"){
				OpenDoor = true;
			}
			IsADoor = false;
			next_room_after_door = 0;
		}

		switch (Player.pos){
		case 1:
			std::cout << "You are in the Mountain, where the Troll was born :)" << std::endl;
			break;
		case 2:
			std::cout << "You are in the West of the House. Here you can find the front door of the house" << std::endl;
			break;
		case 3:
			std::cout << "You are in the North of the House. Here you can find the entrance of the Garage, but is locked" << std::endl;
			break;
		case 4:
			std::cout << "You are in the South of the House. Here you can only find a big and ugly wall." << std::endl;
			break;
		case 5:
			std::cout << "You are in the East of the House. There is nothing here, but the Park is near :P" << std::endl;
			break;
		case 6:
			std::cout << "You are in the Dining Room." << std::endl;
			break;
		case 7:
			std::cout << "You are in the Kitchen. Be careful with knives!" << std::endl;
			break;
		case 8:
			std::cout << "You are in the Living Room." << std::endl;
			break;
		case 9:
			std::cout << "You are in the Garage. You cannot open the door to go to the Nort of the House." << std::endl;
			break;
		case 10:
			std::cout << "You are in the Park 1." << std::endl;
			break;
		case 11:
			std::cout << "You are in the Park 2." << std::endl;
			break;
		}		

		std::cout << std::endl << "Which direction do you want to go?  ";

		std::string direction;
		getline(std::cin, direction);

		if (direction == "exit"){
			exit = true;
		} else if (Player.pos == 1){
			if (direction == "south" || direction == "s"){
				Player.pos = 2;
			}
			else{
				std::cout << "You can not go in that direction" << std::endl;
			}
		}
		else if (Player.pos == 2){
			if (direction == "west" || direction == "w"){
				Player.pos = 1;
			}
			else if (direction == "north" || direction == "n"){
				Player.pos = 3;
			}
			else if (direction == "south" || direction == "s"){
				Player.pos = 4;
			}
			else if (direction == "east" || direction == "e"){
				next_room_after_door = 6;
				IsADoor = true;
			}
			else{
				std::cout << "You can not go in that direction" << std::endl;
			}
		}
		else if (Player.pos == 3){
			if (direction == "west" || direction == "w"){
				Player.pos = 2;
			}
			else if (direction == "east" || direction == "e"){
				Player.pos = 5;
			}
			else{
				std::cout << "You can not go in that direction" << std::endl;
			}
		}
		else if (Player.pos == 4){
			if (direction == "west" || direction == "w"){
				Player.pos = 2;
			}
			else if (direction == "east" || direction == "e"){
				Player.pos = 5;
			}
			else{
				std::cout << "You can not go in that direction" << std::endl;
			}
		}
		else if (Player.pos == 5){
			if (direction == "north" || direction == "n"){
				Player.pos = 3;
			}
			else if (direction == "south" || direction == "s"){
				Player.pos = 4;
			}
			else if (direction == "east" || direction == "e"){
				Player.pos = 11;
			}
			else{
				std::cout << "You can not go in that direction" << std::endl;
			}
		}
		else if (Player.pos == 6){
			if (direction == "north" || direction == "n"){
				Player.pos = 8;
			}
			else if (direction == "west" || direction == "w"){
				next_room_after_door = 2;
				IsADoor = true;
			}
			else if (direction == "east" || direction == "e"){
				Player.pos = 7;
			}
			else{
				std::cout << "You can not go in that direction" << std::endl;
			}
		}
		else if (Player.pos == 7){
			 if (direction == "west" || direction == "w"){
				 Player.pos = 6;
			}
			else{
				std::cout << "You can not go in that direction" << std::endl;
			}
		}
		else if (Player.pos == 8){
			if (direction == "south" || direction == "s"){
				Player.pos = 6;
			}
			else if (direction == "east" || direction == "e"){
				Player.pos = 9;
			}
			else{
				std::cout << "You can not go in that direction" << std::endl;
			}
		}
		else if (Player.pos == 9){
			if (direction == "west" || direction == "w"){
				Player.pos = 8;
			}
			else{
				std::cout << "You can not go in that direction" << std::endl;
			}
		}
		else if (Player.pos == 10){
			if (direction == "south" || direction == "s"){
				Player.pos = 11;
			}
			else{
				std::cout << "You can not go in that direction" << std::endl;
			}
		}
		else if (Player.pos == 11){
			if (direction == "west" || direction == "w"){
				Player.pos = 5;
			}
			else if (direction == "north" || direction == "n"){
				Player.pos = 10;
			}
			else{
				std::cout << "You can not go in that direction" << std::endl;
			}
		}

		printf("\n");
	}
	return 0;
}