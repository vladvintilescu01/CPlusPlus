#include <string>
using namespace std;
class Pong {
    int turn = 0;
    int p1_win = 0;
    int p2_win = 0;
    int game_over = 0;
public:
    int max_score;
    Pong(int _max_score) : max_score(_max_score) {};

    std::string play(int ball_pos, int player_pos) {
        int lower_bound = player_pos - 3; //lower bound where player can hit
        int upper_bound = player_pos + 3; //upper bound where player can hit

        turn++;
        if (turn % 2 == 1 && game_over == 0) {
            //it means is turn of player 1
            int hit = 0;
            for (int i = lower_bound; i <= upper_bound; i++) {
                if (i == ball_pos) {
                    return "Player 1 has hit the ball!";
                    hit = 1;
                    break;
                }
            }
            if (hit == 0) {
                //means that the player doesn't hit the ball
                p2_win++;
                if(p2_win < this->max_score){
                    return "Player 1 has missed the ball!";
                }
                else if (p2_win == this->max_score) {
                    game_over = 1;
                    return "Player 2 has won the game!";
                    
                }
            }
        }
        else if (turn % 2 == 0 && game_over == 0) {
            //it means is turn of player 2
            int hit = 0;
            for (int i = lower_bound; i <= upper_bound; i++) {
                if (i == ball_pos) {
                    return "Player 2 has hit the ball!";
                    hit = 1;
                    break;
                }
            }
            if (hit == 0) {
                p1_win++;
                if (p1_win < this->max_score) {
                    return "Player 2 has missed the ball!";
                }
                else if (p1_win == this->max_score) {
                    game_over = 1;
                    return "Player 1 has won the game!";
                    
                }
            }
        }
        else if (game_over == 1) {
            return "Game Over!";
        }

    };
};