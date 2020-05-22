int buzzer = 2;
int trigPin = 11;
int echoPin = 12;

long sure;
long uzaklik;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  for(int i = 3; i <= 10; i++)
    pinMode(i, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  uzaklik = sure / 29.1 / 2;
  
  if (uzaklik > 20) {
    uzaklik = 20;
    digitalWrite(3, LOW);
    digitalWrite(10, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(buzzer, LOW);
  }
    
  
  if (uzaklik < 20 && uzaklik >= 15) {
    digitalWrite(3, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(600);
  }

  else if (uzaklik < 15 && uzaklik >= 10) {
    digitalWrite(3, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(200);
  }

  else if (uzaklik < 10 && uzaklik >= 5) {
    digitalWrite(3, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(70);
  }

  else if (uzaklik < 5) {
    digitalWrite(3, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  
  Serial.print("Uzaklik ");
  Serial.print(uzaklik);
  Serial.println(" cm");
  delay(100);
}
