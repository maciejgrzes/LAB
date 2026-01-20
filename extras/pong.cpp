#include <raylib.h>
#include <string>
#include <cmath>

const int width = 1200;
const int height = 900;

const int centerX = 600;
const int centerY = 450;

int scoreL = 0;
int scoreR = 0;

struct Circle {
    Vector2 pos;
    Vector2 spd;
    Vector2 dir;

    double radius;

    Color color;
};

int main() {
    InitWindow(width, height, "Pong!");
    SetTargetFPS(60);

    Circle circle;
    circle.pos.x = centerX;
    circle.pos.y = centerY;
    circle.spd = {5, 1};
    circle.dir = {1, 1};
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
        circle.pos.y += circle.dir.y * circle.spd.y;
        circle.pos.x += circle.dir.x * circle.spd.x;

        // TOP
        if (CheckCollisionCircleLine(circle.pos, circle.radius, {0, 0}, {width, 0})) {
            circle.dir.y = -1 * circle.dir.y;
        } 
        // BOTTOM
        else if (CheckCollisionCircleLine(circle.pos, circle.radius, {0, height}, {width, height})) {
            circle.dir.y = -1 * circle.dir.y;
        }
        // LEFT
        else if (CheckCollisionCircleLine(circle.pos, circle.radius, {0, 0}, {0, height})) {
            circle.dir.x = -1 * circle.dir.x;
            circle.pos.x = centerX;
            circle.pos.y = centerY;
            scoreR++;
        }
        // RIGHT
        else if (CheckCollisionCircleLine(circle.pos, circle.radius, {width, 0}, {width, height})) {
            circle.dir.x = -1 * circle.dir.x;
            circle.pos.x = centerX;
            circle.pos.y = centerY;
            scoreL++;
        }

        if(CheckCollisionCircleRec(circle.pos, circle.radius, left)) {
            if (circle.dir.x < 0) {
                circle.dir.x -= 0.5;
            } else {
                circle.dir.x += 0.5;
            }
            circle.dir.x = -1 * circle.dir.x;
        
            float angle = ( circle.pos.y - ( left.y + (left.height/2) ) ) / (left.height/2);

            circle.dir.x = cos(angle) * circle.spd.x;
            circle.dir.y = sin(angle) * circle.spd.y;
        }

        if (CheckCollisionCircleRec(circle.pos, circle.radius, right)) {
            if (circle.dir.x < 0) {
                circle.dir.x -= 0.5;
            } else {
                circle.dir.x += 0.5;
            }
            circle.dir.x = -1 * circle.dir.x;
            
            float angle = ( circle.pos.y - ( right.y + (right.height/2) ) ) / (right.height/2);
        
            circle.dir.x = cos(angle) * circle.spd.x;
            circle.dir.y = sin(angle) * circle.spd.y;
        }

        if (IsKeyDown(KEY_W) && left.y != 0) left.y -= paddleSpeed;
        if (IsKeyDown(KEY_S) && left.y != height - left.height) left.y += paddleSpeed;
        if (IsKeyDown(KEY_UP) && right.y != 0) right.y -= paddleSpeed;
        if (IsKeyDown(KEY_DOWN) && right.y != height - right.height) right.y += paddleSpeed;


        std::string scoreLStr = "Score: " + std::to_string(scoreL);
        std::string scoreRStr = "Score: " + std::to_string(scoreR);

        DrawCircle(circle.pos.x, circle.pos.y, circle.radius, circle.color);
        DrawRectangle(left.x, left.y, left.width, left.height, WHITE);
        DrawRectangle(right.x, right.y, right.width, right.height, WHITE);
        DrawText(scoreLStr.c_str(), 50, 0, 25, WHITE);
        DrawText(scoreRStr.c_str(), width - 150, 0, 25, WHITE);

        EndDrawing();
    }
    return 0;
}
