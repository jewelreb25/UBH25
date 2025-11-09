const int G = 8; //g4
const int C = 7; //c4
const int A = 6; //a4
const int E = 5; //e4
const int trigPinG = 40;
const int echoPinG = 38;
const int trigPinC=  42;
const int echoPinC = 44;
const int trigPinA = 46;
const int echoPinA = 48;
const int trigPinE = 50;
const int echoPinE = 52;
const int endSense = 13;
float echoTimeG, echoTimeC, echoTimeA, echoTimeE ;
int distanceG, distanceC, distanceA, distanceE;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(G, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(trigPinG, OUTPUT);
  pinMode(echoPinG, INPUT);
  pinMode(trigPinC, OUTPUT);
  pinMode(echoPinC, INPUT);
  pinMode(trigPinA, OUTPUT);
  pinMode(echoPinA, INPUT);
  pinMode(trigPinE, OUTPUT);
  pinMode(echoPinE, INPUT);
  pinMode(endSense, INPUT);
}

    // int audioByte = 0; // Read a byte from serial
void loop() {
  // put your main code here, to run repeatedly:
  //tone(speaker, 329.63, 500); //E note
  /*delay(500);
  //tone(speaker, 392, 500);    //G note
  delay(500);
 // tone(speaker, 261.63, 500); //C note
  delay(500);
 // tone(speaker, 440, 500);    /g/A note
  delay(500);*/

  // while (Serial.available()>0){
  //     int audioByte = Serial.read(); // Read a byte from serial
  //         // Map the 8-bit audio value to a frequency range suitable for the buzzer
  //         // Example: Map 0-255 to 200-2000 Hz
  //         // audioByte=random(0, 256);
  //     int frequency = map(audioByte, 0, 255, 200, 440); 
  //         //Serial.println(frequency);
  //     tone(G, frequency);
  //     //analogWrite(G, audioByte);
  //   }
    //SENSOR FOR G STRING
    digitalWrite(trigPinG, LOW); //set the trigger to be off for a few micros
    delayMicroseconds(2);
    digitalWrite(trigPinG, HIGH); //send out a trigger and wait 
    delayMicroseconds(10);
    digitalWrite(trigPinG, LOW);
    echoTimeG= pulseIn(echoPinG, HIGH);   //MUST BE CALLED A FWE DOZEN MICROS BEFORE

    //SENSOR FOR C STRING
    digitalWrite(trigPinC, LOW); //set the trigger to be off for a few micros
    delayMicroseconds(2);
    digitalWrite(trigPinC, HIGH); //send out a trigger and wait 
    delayMicroseconds(10);
    digitalWrite(trigPinC, LOW);
    echoTimeC= pulseIn(echoPinC, HIGH);
    //SENSOR FOR A STRING
    digitalWrite(trigPinA, LOW); //set the trigger to be off for a few micros
    delayMicroseconds(2);
    digitalWrite(trigPinA, HIGH); //send out a trigger and wait 
    delayMicroseconds(10);
    digitalWrite(trigPinA, LOW);
    echoTimeA= pulseIn(echoPinA, HIGH);

    //SENSOR FOR E STRING
    digitalWrite(trigPinE, LOW); //set the trigger to be off for a few micros
    delayMicroseconds(2);
    digitalWrite(trigPinE, HIGH); //send out a trigger and wait 
    delayMicroseconds(10);
    digitalWrite(trigPinE, LOW);
    echoTimeE= pulseIn(echoPinE, HIGH);

    distanceG= (echoTimeG*0.0343)/2;  //time x speed of sound in cm/micros
    if(distanceG>2 && distanceG < 90){
      switch(distanceG){
        case 4:
        case 5 :
          tone(G, 392);    //G note
          break;
        case 7:
        case 8 :
          tone(G, 440); //A note
          break;
        case 10:
        case 11:
          tone(G, 493.88); //B note
          break;
        case 13:
        case 14:
          tone(G, 523.25);   //C5 note
          break;
        default:
          break;
      }
    }
    else {
        noTone(G);
    }

    distanceC= (echoTimeC*0.0343)/2;  //time x speed of sound in cm/micros
    if (distanceG > 3 && distanceG < 90) { 
      switch(distanceC){
        case 4:
        case 5 :
          tone(C, 261.63);    //C note
          break;
        case 7:
        case 8 :
          tone(C, 293.66); //D4 note
          break;
        case 10:
        case 11:
          tone(C, 329.63); //E note
          break;
        case 13:
        case 14:
          tone(C, 349.23);    //F4 note
          break;
        default:
          break;
      }
    }
    else {
      noTone(C);
    }
    Serial.print("C:");
    Serial.println(distanceC);
 

    distanceA= (echoTimeA*0.0343)/2;  //time x speed of sound in cm/micros
    if (distanceG > 3 && distanceG < 90) { 
      switch(distanceA){
        case 2:
        case 3 :
          analogWrite(A, 100);    //A note
          break;
        case 5:
        case 6 :
          analogWrite(A, 150); //B note
          break;
        case 8:
        case 9:
          analogWrite(A, 175); //C5 note
          break;
        case 11:
        case 12:
          analogWrite(A, 200); //D5 note
          break;
        default:
          break;
      }
    }
    else{
      noTone(A);
    }
    Serial.print("A: ");
    Serial.println(distanceA);

    distanceE= (echoTimeE*0.0343)/2;  //time x speed of sound in cm/micros
    if (distanceE > 3 && distanceE < 70) {
      switch(distanceE){
        case 4:
        case 5 :
          analogWrite(E, 100);    //E note
          break;
        case 7:
        case 8 :
          analogWrite(E, 150); //F note
          break;
        case 10:
        case 11:
          analogWrite(E, 175); //G note
          break;
        case 13:
        case 14:
          analogWrite(E, 200);    //A note
          break;
        default:
          break;
      }
    }
    else{
      noTone(E);
    }
    Serial.print("E: ");
    Serial.println(distanceE);
    endMusic();
    delay(5000);
}
void endMusic(){
  if(digitalRead(endSense)==HIGH){
    analogWrite(E, 0);
    analogWrite(C, 0);
    analogWrite(G, 0);
    analogWrite(A, 0);
    delay(500);
  }
}



