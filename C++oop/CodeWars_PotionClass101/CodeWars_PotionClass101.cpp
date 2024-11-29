#include <array>
#include <cmath>
#include <iostream>
using namespace std;

class Potion {
public:
    array<unsigned char, 3> color;
    unsigned int volume;

    Potion(const array<unsigned char, 3>& color, unsigned int volume) {
        this->color = color;
        this->volume = volume;
    }

    Potion mix(const Potion& other) {
        Potion newPotion({ 0, 0, 0 }, 1);

        // Calculate each color component with correct casting and order of operations
        newPotion.color[0] = static_cast<unsigned char>(std::ceil(
            (this->volume * static_cast<double>(this->color[0]) +
                other.volume * static_cast<double>(other.color[0])) /
            (this->volume + other.volume)));

        newPotion.color[1] = static_cast<unsigned char>(std::ceil(
            (this->volume * static_cast<double>(this->color[1]) +
                other.volume * static_cast<double>(other.color[1])) /
            (this->volume + other.volume)));

        newPotion.color[2] = static_cast<unsigned char>(std::ceil(
            (this->volume * static_cast<double>(this->color[2]) +
                other.volume * static_cast<double>(other.color[2])) /
            (this->volume + other.volume)));

        // Set the total volume for the new potion
        newPotion.volume = this->volume + other.volume;

        return newPotion;
    }
};
