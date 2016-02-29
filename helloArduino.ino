int scale = 3; 
boolean micro_is_5V = true;
void setup()
{
  // Initialize serial communication at 115200 baud
  Serial.begin(115200);

  pinMode(13, OUTPUT);
}

// Read, scale, and print accelerometer data
void loop()
{
  // Get raw accelerometer data for each axis
  int rawX = analogRead(A0);
  int rawY = analogRead(A1);
  int rawZ = analogRead(A2);
  
  float scaledX, scaledY, scaledZ; // Scaled values for each axis
  if (micro_is_5V) // Microcontroller runs off 5V
  {
    scaledX = mapf(rawX, 0, 675, -scale, scale); // 3.3/5 * 1023 =~ 675
    scaledY = mapf(rawY, 0, 675, -scale, scale);
    scaledZ = mapf(rawZ, 0, 675, -scale, scale);
  }
  else // Microcontroller runs off 3.3V
  {
    scaledX = mapf(rawX, 0, 1023, -scale, scale);
    scaledY = mapf(rawY, 0, 1023, -scale, scale);
    scaledZ = mapf(rawZ, 0, 1023, -scale, scale);
  }

  if (scaledX > 1)
  {
    digitalWrite(13, HIGH); 
  }
  else
  {
    digitalWrite(13, LOW);
  }
  if (scaledY > 1)
  {
    digitalWrite(13, HIGH); 
  }
  else
  {
    digitalWrite(13, LOW);
  }
  if (scaledZ > 1)
  {
    digitalWrite(13, HIGH); 
  }
  else
  {
    digitalWrite(13, LOW);
  }
  // Print out raw X,Y,Z accelerometer readings
  Serial.print("X: "); Serial.println(rawX);
  Serial.print("Y: "); Serial.println(rawY);
  Serial.print("Z: "); Serial.println(rawZ);
  Serial.println();
  
  // Print out scaled X,Y,Z accelerometer readings
  Serial.print("X: "); Serial.print(scaledX); Serial.println(" g");
  Serial.print("Y: "); Serial.print(scaledY); Serial.println(" g");
  Serial.print("Z: "); Serial.print(scaledZ); Serial.println(" g");
  Serial.println();
  
  delay(2000); // Minimum delay of 2 milliseconds between sensor reads (500 Hz)
}


float mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

