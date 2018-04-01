/* The IR sensor array is to be in the following order:
       L2    L1    M    R1    R2
       
  L1, M and R1 determine the track. L2 and R2 is used for extra precision in very sharp turns.
  
  I have assumed that the IR sensor shows low when detetcting a black surface.
  
  The bot should be placed such that M comes over the black line.
*/        

int L2=8;
int L1=7;
int M=5;
int R1=4;
int R2=3;

int lMotFwd=11;
int rMotFwd=10;
int lMotRev=9;
int rMotRev=6;


void setup()
{
 pinMode(L2,INPUT);
 pinMode(L1,INPUT);
 pinMode(M,INPUT);
 pinMode(R2,INPUT);
 pinMode(R1,INPUT);
 pinMode(lMotFwd,OUTPUT);
 pinMode(rMotFwd,OUTPUT);
 pinMode(lMotRev,OUTPUT);
 pinMode(rMotRev,OUTPUT);

 digitalWrite(lMotFwd,LOW);
 digitalWrite(rMotFwd,LOW);
 digitalWrite(lMotRev,LOW);
 digitalWrite(rMotRev,LOW);
}

void loop()
{

 //Move forward
if((digitalRead(L1)==HIGH)&&(digitalRead(L2)==HIGH)
   &&(digitalRead(R1)==HIGH)&&(digitalRead(R2)==HIGH))
 {
   digitalWrite(lMotFwd,HIGH);
   digitalWrite(rMotFwd,HIGH);
   digitalWrite(lMotRev,LOW);
   digitalWrite(rMotRev,LOW);
 }

 //Less sharp left turn
else if(digitalRead(L1)==LOW && digitalRead(L2)==HIGH)
 {
   analogWrite(lMotFwd,LOW);
   digitalWrite(rMotFwd,160);
   digitalWrite(lMotRev,LOW);
   digitalWrite(rMotRev,LOW);
 }

 //Very sharp left turn to be taken slowly
 else if(digitalRead(L1)==LOW && digitalRead(L2)==LOW)
 {
   analogWrite(lMotFwd,LOW);
   digitalWrite(rMotFwd,80);
   digitalWrite(lMotRev,LOW);
   digitalWrite(rMotRev,LOW);
 }

 //Less sharp right turn
 else if(digitalRead(R1)==LOW && digitalRead(L2)==HIGH)
 {
   analogWrite(lMotFwd,160);
   digitalWrite(rMotFwd,LOW);
   digitalWrite(lMotRev,LOW);
   digitalWrite(rMotRev,LOW);
 }

 //Very sharp right turn to be taken slowly
 else if(digitalRead(R1)==LOW && digitalRead(R2)==LOW)
 {
   analogWrite(lMotFwd,80);
   digitalWrite(rMotFwd,LOW);
   digitalWrite(lMotRev,LOW);
   digitalWrite(rMotRev,LOW);
 }
 
 delay(5);
}
