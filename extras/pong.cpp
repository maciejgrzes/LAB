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
    Vector2 vel;

    double radius;

    Color color;
};


void resetBall(Circle &circle) {
    circle.pos = { centerX, centerY };

    float angle = GetRandomValue(-45, 45) * DEG2RAD;
    float speed = 6;
    int dir = (GetRandomValue(0, 1) == 0) ? -1 : 1;

    circle.vel.x = cos(angle) * speed * dir;
    circle.vel.y = sin(angle) * speed;
}


int main() {
    InitWindow(width, height, "Pong!");
    SetTargetFPS(60);

    Circle circle;
    circle.pos.x = centerX;
    circle.pos.y = centerY;
    circle.vel = {5, 1};
    circle.radius = 10;
    circle.color = WHITE;

    Rectangle left;
    left.width = 10;
    left.height = 100;
    left.x = 50;
    left.y = centerY - left.height / 2;
    
    Rectangle right;
    right.width = 10;
    right.height = 100;
    right.x = width - 50 - 10;
    right.y = centerY - right.height / 2;

    double paddleSpeed = 5;

    while (!WindowShouldClose()) {
        BeginDrawing();
        
        ClearBackground(BLACK);
        circle.pos.y += circle.vel.y;
        circle.pos.x += circle.vel.x;

        if (circle.pos.y - circle.radius <= 0 || circle.pos.y + circle.radius >= height)
            circle.vel.y *= -1;

        if (circle.pos.x < 0) { scoreR++; resetBall(circle); }
        if (circle.pos.x > width) { scoreL++; resetBall(circle); }

        if(CheckCollisionCircleRec(circle.pos, circle.radius, left)) {
            if (circle.vel.x < 0) {
                circle.vel.x -= 0.5;
            } else {
                circle.vel.x += 0.5;
            }
            circle.vel.x *= -1;
            circle.pos.x = left.x + left.width + circle.radius;
        
            float relative = (circle.pos.y - (left.y + left.height/2)) / (left.height/2);
            float maxAngle = 60 * DEG2RAD;
            float angle = relative * maxAngle;

            float speed = sqrt(circle.vel.x * circle.vel.x + circle.vel.y * circle.vel.y);

            circle.vel.x = cos(angle) * speed;
            circle.vel.y = sin(angle) * speed;
        }

        if (CheckCollisionCircleRec(circle.pos, circle.radius, right)) {
            if (circle.vel.x < 0) {
                circle.vel.x -= 0.5;
            } else {
                circle.vel.x += 0.5;
            }
            circle.vel.x *= -1;
            circle.pos.x = right.x - circle.radius;
        
            float relative = (circle.pos.y - (right.y + right.height/2)) / (right.height/2);
            float maxAngle = 60 * DEG2RAD;
            float angle = relative * maxAngle;

            float speed = sqrt(circle.vel.x * circle.vel.x + circle.vel.y * circle.vel.y);

            circle.vel.x = -cos(angle) * speed;
            circle.vel.y = sin(angle) * speed;
        }

        if (IsKeyDown(KEY_W) && left.y > 0) left.y -= paddleSpeed;
        if (IsKeyDown(KEY_S) && left.y + left.height < height) left.y += paddleSpeed;

        if (IsKeyDown(KEY_UP) && right.y > 0) right.y -= paddleSpeed;
        if (IsKeyDown(KEY_DOWN) && right.y + right.height < height) right.y += paddleSpeed;


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
