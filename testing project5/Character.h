#ifndef CHARACTER_FILE
#define CHARACTER_FILE

#include "SFML/Graphics.hpp"
#include <iostream>

class Character{
    private:
    int* characterPosition;
    sf::Sprite characterIcon;
    sf::Texture TextureIcon;
    public:
    Character(){

        this->characterPosition = new int[2];

    }
    
    Character(const std::string &filename, float xScale, float yScale, int xAxis, int yAxis){

        this->TextureIcon.loadFromFile(filename);
        this->characterIcon.setTexture(this->TextureIcon);
        this->characterIcon.setScale(xScale, yScale);
        this->characterIcon.setPosition( xAxis/2, yAxis/2);
        this->characterPosition = new int[2];
        this->characterPosition[0] = xAxis/2;
        this->characterPosition[1] = yAxis/2;

    }

    void move(int xAxis, int yAxis, int xBound, int yBound){

        if (this->characterPosition[0] + xAxis + 100 <= xBound && this->characterPosition[0] + xAxis >= 0 ){
            
            this->characterPosition[0] += xAxis;

        }
        if (this->characterPosition[1] + yAxis + 100 <= yBound && this->characterPosition[1] + yAxis >= 0){

            this->characterPosition[1] += yAxis;

        }

        this->characterIcon.setPosition( this->characterPosition[0], this->characterPosition[1]);

    }

    int * getPosition(){

        return this->characterPosition;

    }

    void setPosition(int xAxis, int yAxis){

        this->characterPosition[0] = xAxis;
        this->characterPosition[1] = yAxis;
        this->characterIcon.setPosition( this->characterPosition[0], this->characterPosition[1]);

    }

    sf::Sprite getIcon (){

        return this->characterIcon;

    }

    ~Character(){

        delete []this->characterPosition;

    }
};

#endif