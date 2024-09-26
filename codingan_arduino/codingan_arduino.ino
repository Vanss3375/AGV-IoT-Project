int a =0;
void setup() {

#define m1 3
#define m2 5
#define m3 9
#define m4 10

#define enA 6
#define enB 11

pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);

pinMode(12,INPUT);
pinMode(13,INPUT);

}

void loop() {

int lsen=digitalRead(12);
int rsen=digitalRead(13);


if((lsen==HIGH) && (rsen==HIGH))
{
analogWrite(enA, 120);
analogWrite(enB, 120);

digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
digitalWrite(m3,LOW);
digitalWrite(m4,HIGH);
}

else if(lsen == LOW && rsen == HIGH)
{
//kiri
analogWrite(enA, 60);
analogWrite(enB, 200);

digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
digitalWrite(m3,LOW);
digitalWrite(m4,HIGH);
a = 1;
}

else if(lsen == HIGH && rsen == LOW)
{
//kanan
analogWrite(enA, 200);
analogWrite(enB, 60);

digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
digitalWrite(m3,HIGH);
digitalWrite(m4,LOW);
a = 2;
}

if(lsen == LOW && rsen == LOW)
{
  if (a == 1){
analogWrite(enA, 60);
analogWrite(enB, 200);

digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
digitalWrite(m3,LOW);
digitalWrite(m4,HIGH);
  a=0;
  }
 if (a == 2){
analogWrite(enA, 200);
analogWrite(enB, 60);

digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
digitalWrite(m3,HIGH);
digitalWrite(m4,LOW);
  a=0;
  }  
}

}