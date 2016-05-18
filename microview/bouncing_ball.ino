// animates a bouncing ball which will be redirected upon
// colliding with the box in the center
#include <MicroView.h>
#include <Time.h>

class Vec2D {
  public:
    int x = 0, y = 0;
  public:
    void add(Vec2D other){
      x += other.x;
      y += other.y;
    }
};

class Box {
  public:
    Vec2D pos;
    int width, height;

    Box(){
      width = 7;
      height = 7;

      pos.x = 32;
      pos.y = 24;
    }

    void draw(){
      uView.rect(pos.x, pos.y, width, width);
    }

    
} the_box;

bool checkCollision(Vec2D obj1, int rad1, Vec2D obj2, int rad2, Vec2D *velo){  
  if((obj1.x < obj2.x + rad2) && (obj1.x + rad1 > obj2.x) && (obj1.y < obj2.y + rad2) && (obj1.y + rad1 > obj2.y)){
        //int xpos = (velo->x > 0) ? 1 : -1;
        //int ypos = (velo->y > 0) ? 1 : -1;
        velo->x = (rand() % 6); // * xpos;
        velo->y = (rand() % 6); // * ypos;
        //delay(5000);
      }
}

class Ball {
  public:
    Vec2D pos, velocity;
    int radius = 3;

    Ball(){
      pos.x = 15;
      pos.y = 15;

      velocity.x = 1;
      velocity.y = 1;
    }

    void draw(){
      
      uView.circle(pos.x, pos.y, radius);
      
    }

    void update(){
      pos.add(velocity);
      checkCollision(pos, radius, the_box.pos, the_box.width, &velocity);
      if(pos.x + radius > 64 || pos.x - radius < 0){
        velocity.x *= -1;
      }
      
      if(pos.y + radius > 48 || pos.y - radius < 0){
        velocity.y *= -1;
      }
    }
} the_ball;





void setup() {
  // put your setup code here, to run once:
  uView.begin();
  uView.clear(PAGE);
  srand(now());
}

void loop() {
  // put your main code here, to run repeatedly:
  the_ball.update();
  
  uView.clear(PAGE);
  the_ball.draw();
  the_box.draw();
  uView.display();
  delay(10);
}
