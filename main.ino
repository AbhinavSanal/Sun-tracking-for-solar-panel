#include <Servo.h>

#define ldr1 2
#define ldr2 3
#define ldr3 4
#define ldr4 5

Servo yaxis;
Servo xaxis;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  pinMode(ldr4, INPUT);
  yaxis.attach(10);
  xaxis.attach(11);
}

void setServos(int xdestination, int ydestination, int xcurrent, int ycurrent) {
  // Move the X servo smoothly
  if (xcurrent < xdestination) {
    for (int pos = xcurrent; pos <= xdestination; pos++) {
      xaxis.write(pos);
      delay(15);  // Adjust delay for smoothness
    }
  } else {
    for (int pos = xcurrent; pos >= xdestination; pos--) {
      xaxis.write(pos);
      delay(15);  // Adjust delay for smoothness
    }
  }

  // Move the Y servo smoothly
  if (ycurrent < ydestination) {
    for (int pos = ycurrent; pos <= ydestination; pos++) {
      yaxis.write(pos);
      delay(15);  // Adjust delay for smoothness
    }
  } else {
    for (int pos = ycurrent; pos >= ydestination; pos--) {
      yaxis.write(pos);
        delay(15);  // Adjust delay for smoothness
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int val[4] = { digitalRead(ldr1),
                 digitalRead(ldr2),
                 digitalRead(ldr3),
                 digitalRead(ldr4) };

  int xangle = xaxis.read();
  int yangle = yaxis.read();
  
  Serial.print("LDRs: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(val[i]);
    Serial.print(" ");
  }
  Serial.println();

  // Debugging: print current servo angles
  Serial.print("Current Angles -> X: ");
  Serial.print(xangle);
  Serial.print(", Y: ");
  Serial.println(yangle);

  if(val[0] == 0 && val[1] == 0 && val[2] == 0 && val[3] == 0)
  setServos(-1, yangle, xangle, yangle);
  if(val[0] == 1 && val[1] == 1 && val[2] == 1 && val[3] == 1)
  setServos(-1, yangle, xangle, yangle);
  else if(val[0] == 1 && val[1] == 1 && val[2] == 0 && val[3] == 1)
  setServos(31, 178, xangle, yangle);
  else if(val[0] == 1 && val[1] == 0 && val[2] == 0 && val[3] == 0)
  setServos(31, 178, xangle, yangle);
  else if(val[0] == 1 && val[1] == 0 && val[2] == 0 && val[3] == 1)
  setServos(31, 140, xangle, yangle); 
  else if(val[0] == 1 && val[1] == 0 && val[2] == 1 && val[3] == 1)
  setServos(31, 90, xangle, yangle);
  else if(val[0] == 0 && val[1] == 0 && val[2] == 0 && val[3] == 1)
  setServos(31, 90, xangle, yangle);
  else if(val[0] == 0 && val[1] == 1 && val[2] == 1 && val[3] == 1)
  setServos(31, 0, xangle, yangle);
  else if(val[0] == 0 && val[1] == 0 && val[2] == 1 && val[3] == 0)
  setServos(31, 0, xangle, yangle);    
  else if(val[0] == 0 && val[1] == 0 && val[2] == 1 && val[3] == 1)
  setServos(31,45, xangle, yangle);
}
