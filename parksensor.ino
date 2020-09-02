int buzzer = 2;
int trigPin = 11;
int echoPin = 12;

int d1 = 20;
int d2 = 15;
int d3 = 10;
int d4 = 5;

long duration;
long distance;

void distance1 (long d) {
  d = d1;
  for (int i = 3; i <= 10; i++)
    digitalWrite(i, LOW);
      
  digitalWrite(buzzer, LOW);
}

void distance2 () {
  digitalWrite(3, HIGH);
  digitalWrite(10, HIGH);
  
  for (int i = 4; i <= 9; i++)
    digitalWrite(i, LOW);
      
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(600);
}

void distance3 () {
  for (int i = 3; i <= 4; i++)
    digitalWrite(i, HIGH);
  for (int i = 9; i <= 10; i++)
    digitalWrite(i, HIGH);
  for (int i = 5; i <= 8; i++)
    digitalWrite(i, LOW);
      
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(200);
}

void distance4 () {
  for (int i = 3; i <= 5; i++)
    digitalWrite(i, HIGH);
  for (int i = 6; i <= 7; i++)
    digitalWrite(i, LOW);  
  for (int i = 8; i <= 10; i++)
    digitalWrite(i, HIGH);
  
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(70);
}

void distance5 () {
  for (int i = 3; i <= 10; i++)
    digitalWrite(i, HIGH);
      
    digitalWrite(buzzer, HIGH);
}

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
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 29.1 / 2;
  
  if (distance > d1) {
    distance1(distance);
  }

  if (distance < d1 && distance >= d2) {
    distance2();
  }

  else if (distance < d2 && distance >= d3) {
    distance3();
  }

  else if (distance < d3 && distance >= d4) {
    distance4();
  }

  else if (distance < d4) {
    distance5();
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}
