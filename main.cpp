/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <otmallah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:26:34 by otmallah          #+#    #+#             */
/*   Updated: 2022/10/25 04:53:06 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class Game{
    public :
        bool GameOver;
        const int height;
        const int width;
        int x;
        int y;
        int fx;
        int fy;
        int score;
        int enemyX;
        int enemyY;
        Game();
};

Game::Game():height(20),width(20){}

Game game;

enum edirection {STOP = 0, UP, DOWN, LEFT, RIGHT};
edirection dir;

void    setup()
{
    game.GameOver = false; 
    dir = STOP;
    game.x = game.width / 2;
    game.y = game.width / 2;
    game.fx = std::rand() % game.width;
    game.fy = std::rand() % game.height;
    game.score = 0;
}

void    draw()
{
    std::system("clear");
    for (int i = 0; i < game.width; i++)
        std::cout << "*";
    std::cout << std::endl;
    for (int i = 0; i < game.height; i++)
    {
        for (int j = 0; j < game.width; j++)
        {
            if (j == 0)
                std::cout << "-";
            if ( j == 5 && i == 5)
            {
                game.enemyX = i;
                game.enemyY = j;
                std::cout << "/*\\";
            }
            if (i == game.x && j == game.y)
                std::cout << "O";
            else if (i == game.fx && j == game.fy)
                std::cout << "F";
            if (j == game.width - 1)
                std::cout << "-";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < game.width; i++)
        std::cout << "*";
    std::cout << std::endl;
    std::cout << " Your Score = " << game.score << std::endl;
}

void    input()
{
    int a;
    std::cin >> a;
    if (a)
    {
        switch (a)
        {
            case 1:
                dir = LEFT;
                break;
            case 2:
                dir = DOWN;
                break;
            case 3:
                dir = RIGHT;
                break;
            case 5:
                dir = UP;
                break;
            case 8:
                game.GameOver = true;
                break;
        }
    }
}

void    logic()
{
    switch (dir)
    {
    case STOP:
        break;
    case UP:
        game.x--;
        break;
    case DOWN:
        game.x++;
        break;
    case RIGHT:
        game.y++;
        break;
    case LEFT:
        game.y--;
        break;
    default:
        break;
    }
    if ((game.x > game.width || game.y > game.height) || (game.x == game.enemyX && game.y == game.enemyY))
    {
        std::cout << "Game Over!" << std::endl;
        game.GameOver = true;
    }
    if (game.x == game.fx && game.y == game.fy)
    {
        game.score += 5;
        game.fx = std::rand() % game.width;
        game.fy = std::rand() % game.height;
    }
}

int main()
{
    setup();
    while (!game.GameOver)
    {
        draw();
        input();
        logic();
    }
}