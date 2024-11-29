#include <vector>

class Automaton
{
private:
    int currentState;
public:

    Automaton() {
        currentState = 1;
    }
    bool read_commands(const std::vector<char>& commands) {
        for (char command : commands) {
            if (currentState == 1) {
                if (command == '1') {
                    currentState = 2;
                }
            }
            else if (currentState == 2) {
                if (command == '0') {
                    currentState = 3;
                }
            }
            else if (currentState == 3) {

                if (command == '1' || command == '0') {
                    currentState = 2;
                }
            }
        }

        return currentState == 2;
    }
};