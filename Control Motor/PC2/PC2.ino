int IN4 = 4;
int IN5 = 5;
int ENB= 3;
int mssg = 0;
int velocity;
int giro = 0;
int antiHorarioVelocity = 0;
int stoped = 0;

void setup() {
  pinMode (IN4, OUTPUT); // Input4 conectada al pin 4
  pinMode (IN5, OUTPUT); // Input3 conectada al pin 5
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    mssg = Serial.read();

    //Horario
    if(mssg == 'a') {
      if (antiHorarioVelocity <= 0)  {
        velocity = 50;
        giro = 'h';
        analogWrite (ENB, velocity);
        digitalWrite (IN4, HIGH);
        digitalWrite (IN5, LOW);
      }

      if (antiHorarioVelocity > 0) {
        giro = 'h';
        analogWrite (ENB, antiHorarioVelocity);
        digitalWrite (IN4, HIGH);
        digitalWrite (IN5, LOW);
      }
    }

    //Anti-Horario
    if(mssg == 'c') {
      if (antiHorarioVelocity <= 0) {
        velocity = 50;
        giro = 'ah';
        analogWrite (ENB, velocity);
        digitalWrite (IN4, LOW);
        digitalWrite (IN5, HIGH);
      }

      if (antiHorarioVelocity > 0) {
        giro = 'ah';
        analogWrite (ENB, antiHorarioVelocity);
        digitalWrite (IN4, LOW);
        digitalWrite (IN5, HIGH);
      }
    }

    //Parar
    if(mssg == 'b') {
      velocity = 0;
      antiHorarioVelocity = 0;
      digitalWrite (IN4, LOW);
      digitalWrite (IN5, LOW);
    }

    //Mas
    if(mssg == 'd') {
      velocity = velocity + 50;
      antiHorarioVelocity = velocity;

      if(velocity >= 250) {
        velocity = 250;
        antiHorarioVelocity = 250;
      }

      if (giro == 'h') {
        analogWrite (ENB, velocity);
        digitalWrite (IN4, HIGH);
        digitalWrite (IN5, LOW);

        if (velocity >= 250) {
          analogWrite (ENB, 250);
          digitalWrite (IN4, HIGH);
          digitalWrite (IN5, LOW);
        }
      }
      
      if (giro == 'ah') {
        analogWrite (ENB, velocity);
        digitalWrite (IN4, LOW);
        digitalWrite (IN5, HIGH);

        if (velocity >= 250) {
          analogWrite (ENB, 250);
          digitalWrite (IN4, LOW);
          digitalWrite (IN5, HIGH);
        }
      }
    }

    //Menos
    if(mssg == 'e') {
      velocity = velocity - 50;
      antiHorarioVelocity = velocity;

      if (velocity <= 0) {
        velocity = 0;
        antiHorarioVelocity = 0;
        digitalWrite (IN4, LOW);
        digitalWrite (IN5, LOW);
      }

      if (giro == 'h') {
        // velocity = velocity - 50;
        analogWrite (ENB, velocity);
        digitalWrite (IN4, HIGH);
        digitalWrite (IN5, LOW);

        if (velocity <= 0) {
          velocity = 0;
          antiHorarioVelocity = 0;
          digitalWrite (IN4, LOW);
          digitalWrite (IN5, LOW);
        }
      }
      
      if (giro == 'ah') {
        // velocity = velocity - 50;
        analogWrite (ENB, velocity);
        digitalWrite (IN4, LOW);
        digitalWrite (IN5, HIGH);

        if (velocity <= 0) {
          velocity = 0;
          antiHorarioVelocity = 0;
          digitalWrite (IN4, LOW);
          digitalWrite (IN5, LOW);
        }
      }
    } 
  }
}
