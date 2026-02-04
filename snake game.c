#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20
#define SNAKE_MAX_LENGTH 100

// Structure to represent a point on the board.
typedef struct {
    int x;
    int y;
} Point;

// Structure to represent the snake.
typedef struct {
    Point body[SNAKE_MAX_LENGTH];
    int length;
    int dx;  // Movement in x-direction
    int dy;  // Movement in y-direction
} Snake;

// Structure to represent the food.
typedef struct {
    int x;
    int y;
} Food;

// Function to initialize the game state.
void initGame(Snake *snake, Food *food) {
    snake->length = 3; // Starting length
    snake->body[0].x = WIDTH / 2;
    snake->body[0].y = HEIGHT / 2;
    snake->body[1].x = WIDTH / 2 - 1;
    snake->body[1].y = HEIGHT / 2;
    snake->body[2].x = WIDTH / 2 - 2;
    snake->body[2].y = HEIGHT / 2;
    snake->dx = 1;  // Initially moving right
    snake->dy = 0;

    food->x = rand() % (WIDTH - 2) + 1;
    food->y = rand() % (HEIGHT - 2) + 1;
}

// Function to draw the game state.
void drawGame(Snake snake, Food food) {
    system("cls");  // Clear the console

    // Draw top border.
    for (int i = 0; i < WIDTH; i++) {
        printf("#");
    }
    printf("\n");

    // Draw the game board.
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0 || j == WIDTH - 1) {
                printf("#");  // side borders
            } else if (i == food.y && j == food.x) {
                printf("F");  // food
            } else {
                int printed = 0;
                for (int k = 0; k < snake.length; k++) {
                    if (snake.body[k].x == j && snake.body[k].y == i) {
                        if (k == 0)
                            printf("O");  // snake head
                        else
                            printf("o");  // snake body
                        printed = 1;
                        break;
                    }
                }
                if (!printed)
                    printf(" ");
            }
        }
        printf("\n");
    }

    // Draw bottom border.
    for (int i = 0; i < WIDTH; i++) {
        printf("#");
    }
    printf("\n");
}

// Function to check for collisions with walls or self.
int checkCollision(Snake snake) {
    // Collision with walls.
    if (snake.body[0].x <= 0 || snake.body[0].x >= WIDTH - 1 ||
        snake.body[0].y <= 0 || snake.body[0].y >= HEIGHT - 1)
        return 1;

    // Collision with the snake's own body.
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x &&
            snake.body[0].y == snake.body[i].y)
            return 1;
    }
    return 0;
}

// Function to update the snake's position.
void updateSnake(Snake *snake) {
    // Move the snake body by shifting each segment.
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
    // Move the head.
    snake->body[0].x += snake->dx;
    snake->body[0].y += snake->dy;
}

// Function to generate a new food position ensuring it doesn't appear on the snake.
void generateFood(Food *food, Snake snake) {
    int valid = 0;
    while (!valid) {
        valid = 1;
        food->x = rand() % (WIDTH - 2) + 1;
        food->y = rand() % (HEIGHT - 2) + 1;
        for (int i = 0; i < snake.length; i++) {
            if (snake.body[i].x == food->x && snake.body[i].y == food->y) {
                valid = 0;
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Snake snake;
    Food food;
    initGame(&snake, &food);

    while (1) {
        // Check for keyboard input.
        if (_kbhit()) {
            int ch = _getch();
            // Arrow keys return two codes; ignore the first.
            if (ch == 0 || ch == 224)
                ch = _getch();
            switch(ch) {
                case 72: // Up arrow
                    if (snake.dy != 1) {
                        snake.dx = 0;
                        snake.dy = -1;
                    }
                    break;
                case 80: // Down arrow
                    if (snake.dy != -1) {
                        snake.dx = 0;
                        snake.dy = 1;
                    }
                    break;
                case 75: // Left arrow
                    if (snake.dx != 1) {
                        snake.dx = -1;
                        snake.dy = 0;
                    }
                    break;
                case 77: // Right arrow
                    if (snake.dx != -1) {
                        snake.dx = 1;
                        snake.dy = 0;
                    }
                    break;
            }
        }

        updateSnake(&snake);

        // Check if the snake eats the food.
        if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
            if (snake.length < SNAKE_MAX_LENGTH) {
                snake.body[snake.length] = snake.body[snake.length - 1];
                snake.length++;
            }
            generateFood(&food, snake);
        }

        // Check for collisions.
        if (checkCollision(snake))
            break;

        drawGame(snake, food);
        Sleep(100);  // Delay (in milliseconds) to control game speed.
    }

    printf("Game Over! Your score: %d\n", snake.length - 3);
    return 0;
}
