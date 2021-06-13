
double duration, distance;
int trigPin = 2;
int echoPin = A0;
int tiltSensor = 4;
int getLight = A1;


void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(tiltSensor, INPUT);
}

void loop()
{
  char query;
  if (Serial.available()){
    query = Serial.read();

    if (query == '1'){
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
  
      duration = pulseIn(echoPin, HIGH);
      distance = double(duration / 58.8);  
      Serial.write((int)distance / 256);
      Serial.write((int)distance % 256);
    }
    else if (query == '2') {
      Serial.write((analogRead(getLight) / 256));
      Serial.write((analogRead(getLight) % 256));
    }
    else if (query == '3') {
      Serial.write((digitalRead(tiltSensor) /  256));
      Serial.write((digitalRead(tiltSensor) %  256));
    }
  }
}
