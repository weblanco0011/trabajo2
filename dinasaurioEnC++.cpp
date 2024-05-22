#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

#define WIDTH 50
#define HEIGHT 10
#define JUMP_HEIGHT 6

using namespace std;

int gameOver;
int score;
int dinoX, dinoY;
int cactusX, cactusY;

void setup() {
    gameOver = 0;
    score = 0;
    dinoX = 5;
    dinoY = HEIGHT - 1;
    cactusX = WIDTH - 5;
    cactusY = HEIGHT - 1;
}

void draw() {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == dinoY && j == dinoX)
                cout << "O";
            else if (i == cactusY && j == cactusX)
                cout << "X";
            else if (i == HEIGHT - 1)
                cout << "_";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

void jump() {
    if (dinoY >= HEIGHT - JUMP_HEIGHT)
        dinoY -= JUMP_HEIGHT;
}


void input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == ' ')
         // Cambia ' ' por la tecla deseada, por ejemplo, 's' para la tecla 's'
            jump(); // Llama directamente a la función jump() cuando se detecte la tecla presionada
    }
}



void update() {
    if (dinoY < HEIGHT - 1)
        dinoY++;
    cactusX--;
    if (cactusX <= 0) {
        cactusX = WIDTH - 5;
        score++;
    }
    if ((cactusX == dinoX) && (cactusY == dinoY))
        gameOver = 1;
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        update();
        Sleep(100);
    }
    cout << "\nGame Over! Final Score: " << score << endl;
    return 0;
}
