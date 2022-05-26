#include <Servo.h>

Servo myservo[4];

float DesireLen[3];
float ServoHornLen = 14.57; //servonun kulaklarının uzunlugu
float ConnectingRodLen = 55;
float HornConnectRodDistance =  3.85;
int ServoPos[3] = {0, 0, 0};
float RaduisBottomPlate = 51; // tabanın yaricapi
float BottomRodAngleDeg[3] = {120, 120, 120}; // kolların derece cinsinden acisi
float RadiusTopPlate = 51; // ust plakanin yaricapi
float TopRodAngleDeg[3] = {84, 84, 84};
float flatLength;
float  BottomRodAngleRad[3];
float TopRodAngleRad[3];
int DegY = 1;
int DegZ = 1;


float BottomPx[3] = {0, 0, 0}; // alt P degerleri
float BottomPy[3] = {0, 0, 0};
float BottomPz[3] = {0, 0, 0};
float TopPx[3];
float TopPy[3];
float TopPz[3];
int moveX = 1;
int moveZ = 1;
float Z_Offset = 0; // platform baslangic degeri
float pi = 3.14159265;

//change
float X_translation = 0; // istenilen dönüşüm
float Y_translation = 0;
float Z_translation = 0;
//change
float X_rotationDeg = 95; // istenilen acısal degisim
float Y_rotationDeg = 0;
float Z_rotationDeg = 0;


float X_rotationRad = X_rotationDeg / 57.2958; //radyana cevirme
float Y_rotationRad = Y_rotationDeg / 57.2958;
float Z_rotationRad = Z_rotationDeg / 57.2958;

void calculate()// hesaplama fonksiyonu
{
  for (int x = 0; x < 3; x++)
  {
    BottomRodAngleRad[x] = BottomRodAngleDeg[x] / 57.2958;
    TopRodAngleRad[x] = TopRodAngleDeg[x] / 57.2958;
    BottomPx[x] = RaduisBottomPlate * cos(BottomRodAngleRad[x]);
    BottomPy[x] = RaduisBottomPlate * sin(BottomRodAngleRad[x]);
    TopPx[x] = (RadiusTopPlate * cos(TopRodAngleRad[x]) * cos(X_rotationRad) * cos(Z_rotationRad)) + RadiusTopPlate * sin(TopRodAngleRad[x]) * (sin(X_rotationRad) * sin(Y_rotationRad) * cos(Z_rotationRad) - cos(X_rotationRad) * sin(Z_rotationRad)) + X_translation;
    TopPy[x] = (RadiusTopPlate * cos(TopRodAngleRad[x]) * cos(Y_rotationRad) * sin(Z_rotationRad)) + RadiusTopPlate * sin(TopRodAngleRad[x]) * (sin(X_rotationRad) * sin(Y_rotationRad) * sin(Z_rotationRad) + cos(X_rotationRad) * cos(Z_rotationRad)) + Y_translation;
    TopPz[x] = -RadiusTopPlate * cos(TopRodAngleRad[x]) * sin(Y_rotationRad) + (RadiusTopPlate * sin(TopRodAngleRad[x]) * sin(X_rotationRad) * cos(Z_rotationRad)) + Z_Offset + Z_translation;
    DesireLen[x] = sqrt((TopPx[x] - BottomPx[x]) * (TopPx[x] - BottomPx[x])  + (TopPy[x] - BottomPy[x]) * (TopPy[x] - BottomPy[x]) + (TopPz[x] - BottomPz[x]) * (TopPz[x] - BottomPz[x]));
    flatLength = sqrt((ConnectingRodLen * ConnectingRodLen) - (HornConnectRodDistance * HornConnectRodDistance));
    ServoPos[x] = (acos(((ServoHornLen * ServoHornLen) - (DesireLen[x] * DesireLen[x]) + (flatLength * flatLength)) / (DesireLen[x] * ServoHornLen * 2))) * (95 / pi);
    //    Serial.print(DesireLen[x]);
    //    Serial.print("  ");
    //    Serial.print(ServoPos[x]);
    //    Serial.println("  ");
    delay(4);
  }
  myservo[1].write(ServoPos[0] - 2);
  myservo[3].write(ServoPos[2] + 4);
  myservo[2].write(ServoPos[1]);
}

void setup()
{
  for (int x = 1; x <= 3; x++) //servo kurulumları
  {
    myservo[x].attach(x + 8);
    myservo[x].write(0);
  }
  delay(1300);
  Serial.begin(9600);
}

void loop()
{
  //hareket dongusu
  for ( int w = 0; w < 3; w++)
  {
    for (int x = 0; x < 28; x++)
    {
      Z_translation = Z_translation + moveZ;
      calculate();
      if (Z_translation == 7)
      {
        moveZ = -1;
      }
      if (Z_translation == -7)
      {
        moveZ = 1;
      }
    }
  }
  for ( int w = 0; w < 3; w++)
  {
    for (int x = 0; x < 24; x++)
    {
      X_translation = X_translation + moveX;
      calculate();
      if (X_translation == 3)
      {
        moveX = -1;
      }
      if (X_translation == -3)
      {
        moveX = 1;
      }
    }
  }
  for (int w = 0; w < 3; w++)
  {
    for (int x = 0; x < 40; x++)
    {
      Y_rotationDeg = Y_rotationDeg + DegY;
      Y_rotationRad = Y_rotationDeg / 57.2958;
      calculate();
      if (Y_rotationDeg == 10)
      {
        DegY = -1;
      }
      if (Y_rotationDeg == -10)
      {
        DegY = 1;
      }
    }
  }
  for (int w = 0; w < 3; w++)
  {
    for (int x = 0; x < 40; x++)
    {
      Z_rotationDeg = Z_rotationDeg + DegZ;
      Z_rotationRad = Z_rotationDeg / 57.2958;
      calculate();
      if (Z_rotationDeg == 10)
      {
        DegZ = -1;
      }
      if (Z_rotationDeg == -10)
      {
        DegZ = 1;
      }
    }
  }




}
