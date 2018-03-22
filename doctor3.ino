int ldr1 = A0;
int ldr2 = A1;
int total = 0;
float threshhold1 = 200;
float threshhold2 = 200;
int entering = 0;
int exiting = 0;
int flag = 0;

void setup()
{
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  Serial.begin(9600);
  String data = "PERSON COUNTER\nTotal = ";
  data.concat(total);
  Serial.println(data);
  /*Serial.println("PERSON COUNTER");
  Serial.print("total=");
  Serial.println(total);
  Serial.print("Entered=");
  Serial.println(entering);
  Serial.print("Exitted=");
  Serial.println(exiting);*/

}
void loop()
{
  String data="";
  if (analogRead(ldr1) <= threshhold1 && analogRead(ldr2) >= threshhold2)
  {
    while (flag == 0)
    {
      if (analogRead(ldr1) >= threshhold1 && analogRead(ldr2) <= threshhold2)
      {
        entering++;
        total = total + 1;
        data = "PERSON COUNTER\nTotal = ";
        data.concat(total);
        Serial.println(data);

        flag = 1;
      }
      else if (analogRead(ldr1) <= threshhold1 && analogRead(ldr2) <= threshhold2)
      {
        if (analogRead(ldr1) >= threshhold1 && analogRead(ldr2) <= threshhold2)
        {
          entering++;
          total = total + 1;
          data = "PERSON COUNTER\nTotal = ";
          data.concat(total);
          Serial.println(data);

          flag = 1;
        }
        else
        {
          flag = 1;
        }
      }

    }
    flag = 0;
  }

  if (analogRead(ldr1) >= threshhold1 && analogRead(ldr2) <= threshhold2)
  {
    while (flag == 0)
    {
      if (analogRead(ldr1) <= threshhold1 && analogRead(ldr2) >= threshhold2)
      {
        exiting++;
        total = total - 1;
        data = "PERSON COUNTER\nTotal = ";
        data.concat(total);
        Serial.println(data);

        flag = 1;
      }
      else if (analogRead(ldr1) <= threshhold1 && analogRead(ldr2) <= threshhold2)
      {
        if (analogRead(ldr1) <= threshhold1 && analogRead(ldr2) >= threshhold2)
        {
          exiting++;
          total = total - 1;
          data = "PERSON COUNTER\nTotal = ";
          data.concat(total);
          Serial.println(data);

          flag = 1;
        }
        else
        {
          flag = 1;
        }
      }
    }
    flag = 0;
  }
}

