#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <SFML/Graphics.hpp>
//classes
#include "World.h"
#include "Snake.h"
//windows
#include "inputSettings.h"
#include "deathWindow.h"
#include "infoWindow.h"

using namespace sf;
using namespace std;

Font font;
Direction moveSite = None;
Clock moveClock;
float moveDelay = 0.3f; // швидкість переміщення

int main()
{
    Snake snake;
    World world;
    Color gray(187, 187, 187);
    font.loadFromFile("arial.ttf");

    int WindowW = 0, WindowH = 0;
    inputSettings(WindowW, WindowH);
    int weight = WindowW * 50, height = WindowH * 50;

    RenderWindow window(VideoMode(weight, height + 50), "Snake");

    // якщо відкрите вікно
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            // перевірка для закриття вікна
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    window.close();
                } }
            
            // контролювання руху змії
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Down) {
                    cout << "down";
                    moveSite = Down;
                } }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Up) {
                    cout << "up";
                    moveSite = Up;
                } }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Right) {
                    cout << "right";
                    moveSite = Right;
                } }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Left) {
                    cout << "left";
                    moveSite = Left;
                } }
        }
        // фон
        window.clear(Color::Black);

        // лінії
        int LineW = weight;
        do {
            RectangleShape line(Vector2f(2.f, height));
            line.setFillColor(Color::White);
            line.move(LineW, 0);
            window.draw(line);
            LineW -= 50;
        } while (LineW);

        int LineH = height;
        do {
            RectangleShape line(Vector2f(weight, 2.f));
            line.setFillColor(Color::White);
            line.move(0, LineH);
            window.draw(line);
            LineH -= 50;
        } while (LineH);


        // текст
        Text score("Score: " + to_string(snake.GetScore()), font, 40);
        score.setPosition(5, height);
        score.setFillColor(Color::White);
        window.draw(score);
        // info
        Text info("Info", font, 40);
        info.setPosition(weight - 130, height);
        info.setFillColor(Color::White);
        RectangleShape infoLogo(Vector2f(30, 30));
        infoLogo.setFillColor(gray);
        infoLogo.setPosition(weight - 40, height + 12);
        RectangleShape buttonInfo(Vector2f(140, 48));
        buttonInfo.setPosition(weight - 130, height + 2);
        buttonInfo.setFillColor(Color::Black);
        window.draw(buttonInfo);
        window.draw(infoLogo);
        window.draw(info);

        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == Mouse::Left) {
                Vector2i mousePos = Mouse::getPosition(window);

                // натискання на кнопку info
                FloatRect boundsWeight = buttonInfo.getGlobalBounds();
                if (boundsWeight.contains(static_cast<Vector2f>(mousePos))) {
                    cout << "info";
                    infoWindow(); } } }

        // Apple
        int AppleX = 0, AppleY = 0;
        if (world.GetBool() == false) {
            world.GenNumber(WindowW, WindowH);

        }
        else
        {
            RectangleShape apple(Vector2f(50, 50));
            apple.setFillColor(Color::Red);
            apple.setPosition(world.GetAppleX() * 50 + 1, world.GetAppleY() * 50 + 1);
            window.draw(apple);

            if (snake.HeadPosition().first == world.GetAppleX() * 50 &&
                snake.HeadPosition().second == world.GetAppleY() * 50) {
                snake.TakeApple();
                world.GenNumber(WindowW, WindowH);
            }
        }

        for (const auto& segment : snake.getSegments()) {
            RectangleShape body(Vector2f(50, 50));
            body.setFillColor(Color::Blue);
            body.setPosition(segment.first, segment.second);
            window.draw(body);
        }

        //move
        if (moveClock.getElapsedTime().asSeconds() > moveDelay) {
            if (moveSite != None) {
                snake.move(moveSite, weight, height, snake);
            }
            moveClock.restart();
        }

        // рендер вікна
        window.display();
    }
    return 0;
}