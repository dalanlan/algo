#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;

// only available windows 
// WA

enum Direction {UP, DOWN, LEFT, RIGHT};
//Frame of the game
class Frame {
public:
    friend class snakeNode;
    friend class movement;
    unsigned width, height;
    Frame(): width(30), height(30) {}
    void setHeight(unsigned hgt) {
        height = hgt;
    }
    void setWidth(unsigned wid) {
        width = wid;
    }
    void initializeFrame();
    void displayFrame();
private:
    vector< vector<char> > window;
}frame;

void Frame::initializeFrame() {
    if (width <= 0 || height <= 0) {
        cerr << "WRONG FRAME DIMENSION!" << endl;
        exit(0);
    }
    window = vector<vector<char> >(height, vector<char>(width, ' '));
    for (int i = 0; i != height; ++i) {
        window[i][0] = window[i][width-1] = '#';
    }
    for (int j = 0; j != width; ++j) {
        window[0][j] = window[height-1][j] = '#';
    }
}

void Frame::displayFrame() {
    for (int i = 0; i != height; ++i) {
        for (int j = 0;j < width; j++) {
                //char ch : window[i])
            cout << window[i][j] << ' ';
        }
        cout << endl;
    }
}
//snakeNode
class snakeNode {
public:
    friend class movement;
    snakeNode(int ix, int iy): x(ix), y(iy), next(NULL), prior(NULL) {}
    void addHead(int, int);
    void delTail();
private:
    int x, y;
    snakeNode *next, *prior;
}*head, *tail;

void snakeNode::addHead(int ix, int iy) {
    snakeNode *newSnake = new snakeNode(ix, iy);
    newSnake->next = head;
    if (head)
        head->prior = newSnake;
    else
        tail = newSnake;
    head = newSnake;
    frame.window[ix][iy] = '~';
}

void snakeNode::delTail() {
    snakeNode *snakeTail = tail;
    frame.window[snakeTail->x][snakeTail->y] = ' ';
    tail = snakeTail->prior;
    if (tail)
        tail->next = NULL;
    else
        head = NULL;
    delete snakeTail;
}

//movement
class movement {
public:
    movement(): dir(LEFT) {randomFood();}
    void randomFood();
    void move();
    void changeDirection(char);
private:
    enum Direction dir;
    int fx, fy;
    bool outOfFrame(int h, int w) {
        return h < frame.height - 1 && h > 0 && w < frame.width - 1 && w > 0 ? false : true;
    }
    bool block(int h, int w) {
        for (snakeNode *snake = head; snake; snake = snake->next) {
            if (snake->x == h && snake->y == w)
                return true;
        }
        return false;
    }
};

void movement::randomFood() {
    srand((unsigned)time(0));
    bool onSnake = true;
    while (onSnake) {
        onSnake = false;
        fx = rand() % (frame.height - 2) + 1;
        fy = rand() % (frame.width - 2) + 1;
        for (snakeNode *snake = head; snake; snake = snake->next) {
            if (fx == snake->x && fy == snake->y) {
                onSnake = true; break;
            }
        }
    }
    frame.window[fx][fy] = 'x';
}

void movement::move() {
    int h = head->x, w = head->y;
    switch(dir) {
        case UP: --h; break;
        case DOWN: ++h; break;
        case LEFT: --w; break;
        case RIGHT: ++w; break;
    }
    if (outOfFrame(h, w) || block(h, w)) {
        cout << "Game Over!" << endl;
        exit(0);
    }
    if (h == fx && w == fy) {
        head->addHead(fx, fy);
        randomFood();
    }
    else {
        head->addHead(h, w);
        head->delTail();
    }
}

void movement::changeDirection(char key) {
    switch(key) {
        case 'w': {
            if (dir != DOWN) dir = UP;
            break;
        }
        case 's': {
            if (dir != UP) dir = DOWN;
            break;
        }
        case 'a': {
            if (dir != RIGHT) dir = LEFT;
            break;
        }
        case 'd': {
            if (dir != LEFT) dir = RIGHT;
            break;
        }
    }
}

int main() {
    unsigned speed, h, w;
    char key;
    cout << "Please input height and width!(10~39)" << endl;
    cout << "height = ";
    cin >> h;
    cout << "width = ";
    cin >> w;
    cout << "Please input speed!(1~500)" <<endl;
    cout << "speed = ";
    cin >> speed;
    frame.setHeight(h); frame.setWidth(w);
    frame.initializeFrame();
    head->addHead(frame.height / 2, frame.width / 2);
    movement myMove;
    while (true) {
        while (!kbhit()) {
            system("cls");
            myMove.move();
            frame.displayFrame();
            Sleep(speed);
        }
        key = getch();
        myMove.changeDirection(key);
    }
    return 0;
}
