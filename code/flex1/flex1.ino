int pin1=8;
int pin2=9;
int pin3=10;
int pin4=11;
int pin5=12;
void setup()
{
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);  
  pinMode(pin2, OUTPUT); 
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);   
  digitalWrite(pin1, HIGH);       
  digitalWrite(pin2, HIGH);   
  digitalWrite(pin3, HIGH);       
  digitalWrite(pin4, HIGH);        
  digitalWrite(pin5, HIGH);
  pinMode(A1, INPUT);  
  pinMode(A2, INPUT); 
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);        
}
void loop()
{
  int A= analogRead(A1);
  int V1 = ((A * (5.0 / 1023.0)) < 4.0) ? 1 : 0;
  
  int B= analogRead(A2);
  int V2 = ((B * (5.0 / 1023.0)) < 4.0) ? 1 : 0;
  
  int C= analogRead(A3);
  int V3 = ((C * (5.0 / 1023.0)) < 4.0) ? 1 : 0;
  
  int D= analogRead(A4);
  int V4 = ((D * (5.0 / 1023.0)) < 4.0) ? 1 : 0;
  
  int E= analogRead(A5);
  int V5 = ((E * (5.0 / 1023.0)) < 4.0) ? 1 : 0;

  if((V1==0)&&(V2==1)&&(V3==0)&&(V4==0)&&(V5==0))
    Serial.println("One Enemy Ahead");
  else if((V1==0)&&(V2==1)&&(V3==1)&&(V4==0)&&(V5==0))
    Serial.println("Alert !!! Two Enemies Ahead");
  else if((V1==1)&&(V2==1)&&(V3==1)&&(V4==0)&&(V5==0))
    Serial.println("3 enemies ahead !!!! ");
  else if((V1==0)&&(V2==1)&&(V3==1)&&(V4==1)&&(V5==1))
    Serial.println("Alert !!! 4 Enemies Ahead");
 else if((V1==1)&&(V2==1)&&(V3==1)&&(V4==1)&&(V5==1))
    Serial.println("Beware 5 Enemies Ahead");
 else if((V1==0)&&(V2==1)&&(V3==1)&&(V4==1)&&(V5==0))
    Serial.println("6 Enemies Ahead");
 else if((V1==0)&&(V2==1)&&(V3==1)&&(V4==0)&&(V5==1))
    Serial.println("7 Enemies Ahead");
 else if((V1==0)&&(V2==1)&&(V3==0)&&(V4==1)&&(V5==1))
    Serial.println("8 Enemies Ahead");
 else if((V1==0)&&(V2==0)&&(V3==1)&&(V4==1)&&(V5==1))
    Serial.println("9 Enemies Ahead");
 else if((V1==0)&&(V2==0)&&(V3==0)&&(V4==0)&&(V5==0))
    Serial.println("DANGER 10 Enemies Ahead");
  else
    Serial.println("Chill Out!");

    delay(500);
  
  Serial.println(A);
  Serial.print(V1);
  Serial.print(" B ");
 Serial.print(V2);
  Serial.print(" C");
 Serial.print(V3);
  Serial.print(" D");
 Serial.print(V4);
  Serial.print(" E");
 Serial.println(V5);
}
