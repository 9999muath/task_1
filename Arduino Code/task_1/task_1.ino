int O_F_MoterA = 6;   //OUTPUT
int O_B_MoterA = 5;
int O_F_MoterB = 4;
int O_B_MoterB = 3;
int LED_1 = 1;       //Eror_Motor_A 
int LED_2 = 0;       //Eror_Motor_B
int EN1 = 10;
int EN2 = 9;
int I_F_MoterA = A0;  //INPUT
int I_B_MoterA = A1;
int I_F_MoterB = A2;
int I_B_MoterB = A3;
int Speed_MotorA = A4;
int Speed_MotorB = A5;
int read_Speed_MotorA;  
int write_Speed_MotorA;
int read_Speed_MotorB;  
int write_Speed_MotorB;

void setup() {
 

pinMode(O_F_MoterA, OUTPUT);
pinMode(O_B_MoterA, OUTPUT);
pinMode(O_F_MoterB, OUTPUT);
pinMode(O_B_MoterB, OUTPUT);
pinMode(LED_1, OUTPUT);
pinMode(LED_2, OUTPUT);

pinMode(I_F_MoterA,  INPUT);
pinMode(I_B_MoterA, INPUT);
pinMode(I_F_MoterB, INPUT);
pinMode(I_B_MoterB, INPUT);
pinMode(Speed_MotorA, INPUT);
pinMode(Speed_MotorB, INPUT);

read_Speed_MotorA = analogRead(Speed_MotorA); 
read_Speed_MotorB = analogRead(Speed_MotorB);
}
 

void loop() {
read_Speed_MotorA = analogRead(Speed_MotorA); 
read_Speed_MotorB = analogRead(Speed_MotorB);
write_Speed_MotorA = map(read_Speed_MotorA,0,1022,0,255);
write_Speed_MotorB = map(read_Speed_MotorB,0,1022,0,255);
analogWrite(EN1, write_Speed_MotorA);
analogWrite(EN2, write_Speed_MotorB);
 
if (digitalRead(I_F_MoterA )== HIGH && digitalRead(I_B_MoterA )== LOW)                // MotorA states //AS0
    {digitalWrite(O_F_MoterA, HIGH);
      digitalWrite(O_B_MoterA, LOW);
      digitalWrite(LED_1 ,LOW );}
      
      else if (digitalRead(I_F_MoterA) == LOW && digitalRead(I_B_MoterA) == HIGH)     // AS1 
    {digitalWrite(O_F_MoterA, LOW);
      digitalWrite(O_B_MoterA, HIGH);
      digitalWrite(LED_1 ,LOW );}
      
      else if (digitalRead(I_F_MoterA) == HIGH && digitalRead(I_B_MoterA) == HIGH)     //AS2
    {digitalWrite(O_F_MoterA, LOW);
      digitalWrite(O_B_MoterA, LOW);
      digitalWrite(LED_1 ,HIGH );}
      
      else if (digitalRead(I_F_MoterA) == LOW && digitalRead(I_B_MoterA) == LOW)      //AS3
    {digitalWrite(O_F_MoterA, LOW);
      digitalWrite(O_B_MoterA, LOW);
      digitalWrite(LED_1 ,LOW );}
        


 if (digitalRead(I_F_MoterB) == HIGH && digitalRead(I_B_MoterB) == LOW)                  //MotorB States //AS0
    {digitalWrite(O_F_MoterB, HIGH);
      digitalWrite(O_B_MoterB, LOW);
      digitalWrite(LED_2 ,LOW );}
      
      else if (digitalRead(I_F_MoterB) == LOW && digitalRead(I_B_MoterB) == HIGH)        //BS1
    {digitalWrite(O_F_MoterB, LOW);
      digitalWrite(O_B_MoterB, HIGH);
      digitalWrite(LED_2 ,LOW );}
      
      else if (digitalRead(I_F_MoterB) == HIGH && digitalRead(I_B_MoterB) == HIGH)        //BS2
    {digitalWrite(O_F_MoterB, LOW);
      digitalWrite(O_B_MoterB, LOW);
      digitalWrite(LED_2 ,HIGH );}
      
      else if (digitalRead(I_F_MoterB) == LOW && digitalRead(I_B_MoterB) == LOW)        //BS3
    {digitalWrite(O_F_MoterB, LOW);
      digitalWrite(O_B_MoterB, LOW);
      digitalWrite(LED_2 , LOW );}
      
      
}
