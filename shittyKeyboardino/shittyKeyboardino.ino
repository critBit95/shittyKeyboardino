/*
  shittyPianoKeyboard

  Reads I/O matrix and does nothing because it's shitty
*/

int pushButton = 0;

//int xRowPins[] = {2,4,16,17,5,18,19,21};
//int yRowPins[] = {13,12,14,27,26,25,33};

int xRowPins[] = {2,4,16,17,5,18,19,21};
int yRowPins[] = {13,12,14,27,26,25,33};

int xRowLen = sizeof(xRowPins)/sizeof(xRowPins[0]);
int yRowLen = sizeof(yRowPins)/sizeof(yRowPins[0]);

void setup() {
  Serial.begin(115200);
  
  for (int i=0;i<xRowLen;i++){
    pinMode(xRowPins[i],OUTPUT);
  }

  for (int i=0;i<yRowLen;i++){
    pinMode(yRowPins[i], INPUT_PULLDOWN);
  }
}

void setSinglePin(int *pinArray,int pinArraySize,int pinNo){
  for (int i=0;i<pinArraySize; i++){
    if (i == pinNo)
      digitalWrite(pinArray[i], HIGH);
    else
      digitalWrite(pinArray[i], LOW);
  }
}

void printPinArray(int *pinArray, int pinArraySize){
  for (int i=0;i<pinArraySize; i++){
    int state = digitalRead(pinArray[i]);
    Serial.printf("%d",state);
  }
  Serial.println("|");
}

// the loop routine runs over and over again forever:
void loop() {
  for (int x = 0;x<xRowLen;x++){
    //set X pin
    setSinglePin(xRowPins,xRowLen,x);
    //get Y pins
    printPinArray(yRowPins,yRowLen);
    delay(10);
  }
  Serial.println("================");
  delay(333);
}
