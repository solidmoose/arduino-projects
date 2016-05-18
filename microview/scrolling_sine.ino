// a scrolling sinewave animation
#include <MicroView.h>

const float pi = 3.141592654;


bool firstpass = true;
int offset = 0;
int stepsize = 5;
int ydist[64];

void setup() {
  // put your setup code here, to run once:
  uView.begin();
  uView.clear(PAGE);

  float x, y;
  for(int angle = 0; angle < 360; angle++){
    x = angle * (pi / 180);


    y = -1*sin(x);
    y = y * 24; //amplitude
    y += 24; //center on screen
    x = angle * 64/360;

    ydist[(int)x] = (int)y;

    printf("%d\n", x);
    //uView.pixel(x, y);
  }

  //Serial.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float x, y;

  if(firstpass){
    //draw our first wave
    for(int i = 0; i < 64; i++){
      uView.pixel(i, ydist[i]);
      uView.display();
    }

    firstpass = false;

  } else {
    //scroll
    offset = (offset + stepsize) % 64;
    //draw the main section of wave
    for(int i = 0; i < 60; i++){
      uView.pixel(i, ydist[(i + offset) % 64]);

    }
    uView.display();
    for(int i = 60; i < 63; i++){
      uView.pixel(i, ydist[(i + offset) % 64]);
      uView.display(); //display these as they are drawn
    }
  }
  // for(int angle = 0; angle <= 360; angle++){
  //  x = angle * (pi / 180);


  //  y = -1*sin(x);
  //  y = y * 24; //amplitude
  //  //y += 24; //center on screen

  //  x = angle * 64/360;
  //  printf("%d\n", x);
  //  uView.pixel(x, y);
  //  uView.display();
  // }

  delay(75);
  uView.clear(PAGE);
}
