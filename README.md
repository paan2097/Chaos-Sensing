# Chaos-Sensing
Arduino Uno with Triple Axis Accelerometer

Similar to my previous post, the Chaos Activated Camera, I have created a functional piece that senses chaos. The components include an Arduino Uno along with a triple axis accelerometer. The Arduino serves as a platform to process the triple axis accelerometer data and to relay that data. The triple axis accelerometer feeds in the orientation and more importantly, the amount of g forces in the x,y, and z direction. Based upon the amount of g forces in a given direction, ranging from -3 to +3 g forces, the Arduino will cause an LED light to light up. The LED represents a camera that could be activated. Other uses could be a warning light for planes or cars. The technology could be a tipping warning for semi trucks. Roadblocks I came across included difficulty connecting to a GoPro via wifi, which would have required an Arduino Yun which is much more expensive but has wifi capability. The second roadblock was instead of connecting to a GoPro, we could replace the LED with an Arduino camera would would be a simple replacement but again, very expensive. 

In this project I learned how to use a microcontroller (Arduino Uno) along with a triple axis accelerometer for the first time. I'm glad I did this project because it opens up vast opportunities of using g force sensing technology in any direction in 3 dimensions. 

