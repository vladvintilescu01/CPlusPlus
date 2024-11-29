#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string generateName()
{
	string allcharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string name;
	bool isUnique = false;

	srand(time(nullptr));

	while (!isUnique) {
		name.clear();
		for(int i = 0 ;i < 6; i++){
			name += allcharacters[rand() % allcharacters.length()];
		}
		if (!photoManager.nameExists(name)) {//in order to use you need to put in codewars website
			isUnique = true;
		}
	}
	return name;
}