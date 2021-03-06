// Apaza Colque Miguel Fernando
#include <Servo.h>
Servo T;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(6, INPUT);
  pinMode(7, OUTPUT);
  T.attach(5);
  Serial.begin(9600);
}

void loop()
{
  avanzar();
  T.write(90);
  delay(100);
  int c=ultrasonido();
  Serial.println(c);
  if (c>=0 && c <=15) {
     verificaPared();  
  }
  delay(100);
}
void izquierda(){
  Serial.println("Giro a la Izquierda");
   digitalWrite(13, LOW);
   digitalWrite(12, HIGH);  
   digitalWrite(11, LOW);
   digitalWrite(10, LOW);
}
void derecha(){
  Serial.println("Giro a la Derecha");
   digitalWrite(13, LOW);
   digitalWrite(12, LOW);  
   digitalWrite(11, LOW);
   digitalWrite(10, HIGH);
}
void avanzar(){
  Serial.println("Avanzado");
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}
void parar(){
  Serial.println("Parando");
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}
void retroceder(){
  Serial.println("Retrocediendo");
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
void verificaPared(){
  T.write(0);
  int c=ultrasonido();
  delay(200);
  T.write(90);
  int c1=ultrasonido();
  delay(200);
  T.write(180);
  int c2=ultrasonido();
  delay(200);
  int r=verificaMayor(c,c1,c2);
  if(r==c){
    retroceder();
    delay(100);
    Serial.println("Muro encontrado en Derecha");
    derecha();
    delay(530);
  }
  if(r==c2){
    retroceder();
    delay(100);
    Serial.println("Muro encontrado en Izquierda");
    izquierda();
    delay(530);
  }
}
int ultrasonido(){
  int dist,dur;
  digitalWrite(7,LOW);
  delayMicroseconds(2);
  digitalWrite(7,HIGH);
  delayMicroseconds(10);
  digitalWrite(7,LOW);
  dur=pulseIn(6, HIGH);
  dist = (dur/2)/29;
  return(dist);
}
int verificaMayor(int a,int b,int c){
  if(a > b ){
    if(a > c){
      return (a);
    }else{
      return (c);
    }
    if(b>c){
      return(b);
    }else{
      return(c);
    }
  }
}
