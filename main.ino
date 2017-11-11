#define asen0 A0
#define asen1 A1
#define asen2 A2
#define led0 2
#define led1 3
#define led2 4

long rand_num;
int score;
int anal0 = 0;
int anal1 = 0;
int anal2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  randomSeed(analogRead(4));
  pinMode (led0, OUTPUT);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  score = 0;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  rand_num = random(3);
  Serial.println ("LED: "); Serial.println (rand_num);
  digitalWrite (rand_num + 2, HIGH); 
  /********************************************************************/
  delay (1000); //we wait for the user to see the light and press the Sensor.
  /********************************************************************/  
  anal0 = analogRead(asen0);
  delay (200);
  Serial.println (anal0);
  anal1 = analogRead(asen1);
  delay (200);
  Serial.println (anal1);
  anal2 = analogRead(asen2);
  delay (200);
  Serial.println (anal2);
  /********************************************************************/
  if (rand_num == 0)
  {
    if ((anal0 < 7) && (anal1 > 7) && (anal2 > 7))
    {
      digitalWrite (2, LOW);
      score++;
      }
    else 
    {
      digitalWrite (2, LOW);
      }
  }
    /********************************************************************/
    if (rand_num == 1)
  {
    if ((anal0 > 7) && (anal1 < 7) && (anal2 > 7))
    {
      digitalWrite (3, LOW);
      score++;
      }
     else 
    {
      digitalWrite (3, LOW);
      }
    }
   /********************************************************************/
    if (rand_num == 2)
  {
    if ((anal0 > 7) && (anal1 > 7) && (anal2 < 7))
    {
      digitalWrite (4, LOW);
      score++;
      } else 
    {
      digitalWrite (4, LOW);
      }
    }
     /********************************************************************/
    
      Serial.println ("Current Score is :");
      Serial.println (score);
    delay (2000);
    
}
