#include <raylib.h>
#include <string>
#include <random>

const int width = 1200;
const int height = 900;

const int centerX = 600;
const int centerY = 450;

int scoreL = 0;
int scoreR = 0;

struct Circle {
    float x;
    float y;

    double Yvelocity;
    double Xvelocity;
    double radius;

    Color color;
};

int main() {
    InitWindow(width, height, "Pong!");
    SetTargetFPS(60);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> velGenX(0,1);

    int valX = velGenX(gen);
    Circle circle;
    circle.x = centerX;
    circle.y = centerY;
    circle.Yvelocity = 1;
    if (valX == 0) {
        circle.Xvelocity = 5;
    } else {
        circle.Xvelocity = -5;
    }
    circle.radius = 10;
    circle.color = WHITE;

    Rectangle left;
    left.x = 50;
    left.y = centerY;
    left.width = 10;
    left.height = 100;
    
    Rectangle right;
    right.x = width - 50 - 10;
    right.y = centerY;
    right.width = 10;
    right.height = 100;

    double paddleSpeed = 5;

    while (!WindowShouldClose()) {
        BeginDrawing();
        
        ClearBackground(BLACK);
        circle.y += circle.Yvelocity;
        circle.x += circle.Xvelocity;

        // TOP
        if (CheckCollisionCircleLine({circle.x, circle.y}, circle.radius, {0, 0}, {width, 0})) {
            circle.Yvelocity = -1 * circle.Yvelocity;
        } 
        // BOTTOM
        else if (CheckCollisionCircleLine({circle.x, circle.y}, circle.radius, {0, height}, {width, height})) {
            circle.Yvelocity = -1 * circle.Yvelocity;
        }
        // LEFT
        else if (CheckCollisionCircleLine({circle.x, circle.y}, circle.radius, {0, 0}, {0, height})) {
            int valX = velGenX(gen);
            if (valX == 0) {
                circle.Xvelocity = 5;
            } else {
                circle.Xvelocity = -5;
            }
            circle.Xvelocity = -1 * circle.Xvelocity;
            circle.x = centerX;
            circle.y = centerY;
            scoreR++;
        }
        // RIGHT
        else if (CheckCollisionCircleLine({circle.x, circle.y}, circle.radius, {width, 0}, {width, height})) {
            int valX = velGenX(gen);
            if (valX == 0) {
                circle.Xvelocity = 5;
            } else {
                circle.Xvelocity = -5;
            }
            circle.Xvelocity = -1 * circle.Xvelocity;
            circle.x = centerX;
            circle.y = centerY;
            scoreL++;
        }

        if(CheckCollisionCircleRec({circle.x, circle.y}, circle.radius, left)) {
            if (circle.Xvelocity < 0) {
                circle.Xvelocity -= 0.5;
            } else {
                circle.Xvelocity += 0.5;
            }
            circle.Xvelocity = -1 * circle.Xvelocity;
            // TOP of left paddle
            if (circle.y >= left.y - circle.radius && circle.y < left.y + 20) {
                circle.Yvelocity = -3;
            // HALF WAY UP of left paddle
            } else if (circle.y >= left.y + 20 && circle.y < left.y + 40) {
                circle.Yvelocity = -1;
            // CENTER of left paddle
            } else if (circle.y >= left.y + 40 && circle.y < left.y + 60) {
                circle.Yvelocity = 0;
            // HALF WAY DOWN of left paddle
            } else if (circle.y >= left.y + 60 && circle.y < left.y + 80) {
                circle.Yvelocity = 1;
            // BOTTOM of left paddle
            } else if (circle.y >= left.y + 80 && circle.y <= left.y + left.height + circle.radius) {
                circle.Yvelocity = 3;
            }
        }

        if (CheckCollisionCircleRec({circle.x, circle.y}, circle.radius, right)) {
            if (circle.Xvelocity < 0) {
                circle.Xvelocity -= 0.5;
            } else {
                circle.Xvelocity += 0.5;
            }
            circle.Xvelocity = -1 * circle.Xvelocity;
            // TOP of right paddle
            if (circle.y >= right.y - circle.radius && circle.y < right.y + 20) {
                circle.Yvelocity = -3;
            // HALF WAY UP of right paddle
            } else if (circle.y >= right.y + 20 && circle.y < right.y + 40) {
                circle.Yvelocity = -1;
            // CENTER of right paddle
            } else if (circle.y >= right.y + 40 && circle.y < right.y + 60) {
                circle.Yvelocity = 0;
            // HALF WAY DOWN of right paddle
            } else if (circle.y >= right.y + 60 && circle.y < right.y + 80) {
                circle.Yvelocity = 1;
            // BOTTOM of right paddle
            } else if (circle.y >= right.y + 80 && circle.y <= right.y + right.height - circle.radius) {
                circle.Yvelocity = 3;
            }
        }

        if (IsKeyDown(KEY_W) && left.y != 0) left.y -= paddleSpeed;
        if (IsKeyDown(KEY_S) && left.y != height - left.height) left.y += paddleSpeed;
        if (IsKeyDown(KEY_UP) && right.y != 0) right.y -= paddleSpeed;
        if (IsKeyDown(KEY_DOWN) && right.y != height - right.height) right.y += paddleSpeed;


        std::string scoreLStr = "Score: " + std::to_string(scoreL);
        std::string scoreRStr = "Score: " + std::to_string(scoreR);

        DrawCircle(circle.x, circle.y, circle.radius, circle.color);
        DrawRectangle(left.x, left.y, left.width, left.height, WHITE);
        DrawRectangle(right.x, right.y, right.width, right.height, WHITE);
        DrawText(scoreLStr.c_str(), 50, 0, 25, WHITE);
        DrawText(scoreRStr.c_str(), width - 150, 0, 25, WHITE);

        EndDrawing();
    }
    return 0;
}
