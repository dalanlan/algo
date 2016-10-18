// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.


#include<iostream>
// #include<stdlib.h>

using namespace std;

struct msg_definition { 
    unsigned int x; long unsigned int y; char text[4]; 
    
};

// __attribute__((packed)) ; 
char data[] = {0x0F, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x42, 0x43, 0x44}; 
int main(int argc, char** argv) { 
    msg_definition *msg = (msg_definition*)data; 
    //printf("x = %u, y = %lu, text = %s\n", msg->x, msg->y, msg->text); 
    cout<<msg->x<<" "<<msg->y <<" "<<msg->text;

    char tex[] = {0x41, 0x42, 0x43, 0x44};
    for(int i=0; i<4; i++) {
    	cout<< tex[i]<<" ";
    }
    return 0; }