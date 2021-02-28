
int broken1 = 12;
int broken2 = 4;
int broken3 = 8;
int broken4 = 7;

void Allon(int delay_value){
  digitalWrite(broken1, HIGH);
  digitalWrite(broken2, HIGH);
  digitalWrite(broken3, HIGH);
  digitalWrite(broken4, HIGH);
  delay(delay_value);
}
void Firstoff(){
  //First
  digitalWrite(broken1, LOW);
  
  digitalWrite(broken2, HIGH);

  digitalWrite(broken3, HIGH);
 
  digitalWrite(broken4, HIGH);

  delay(3000);

  Allon(1000);
}

void Secondoff(){
  //Second
  digitalWrite(broken1, HIGH);
  
  digitalWrite(broken2, LOW);

  digitalWrite(broken3, HIGH);
 
  digitalWrite(broken4, HIGH);

  delay(3000);

  Allon(1000);
}

void Thirdoff(){
  //Third
  digitalWrite(broken1, HIGH);
  
  digitalWrite(broken2, HIGH);

  digitalWrite(broken3, LOW);
 
  digitalWrite(broken4, HIGH);

  delay(3000);

  Allon(1000);
}

void Fourthoff(){
  //Fourth
  digitalWrite(broken1, HIGH);
  
  digitalWrite(broken2, HIGH);

  digitalWrite(broken3, HIGH);
 
  digitalWrite(broken4, LOW);

  delay(3000);

  Allon(1000);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(broken1, OUTPUT);
  pinMode(broken3, OUTPUT);
  pinMode(broken4, OUTPUT);
  pinMode(broken2, OUTPUT);

}

void loop() {
  Allon(3000);
  Firstoff();
  Secondoff();
  Thirdoff();
  Fourthoff();
} 
