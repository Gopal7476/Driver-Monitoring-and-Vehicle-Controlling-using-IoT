# Driver-Monitoring-and-Vehicle-Controlling-using-IoT

Abstract
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------The growth of automotive vehicles has been increasing gradually day to day, which in turn lead to the increased growth of road accidents. The numbers of these totalities that take place in India are ranked to be in the top most position in the world.  Previously, there were no technologies to lock the engine of the vehicle after sensing the alcohol intake by the driver or Drowsiness which is considered to be the main cause of accidents. There was manual checking after certain distance on the roads or the highways but still these checks were not sufficient to stop the happening of the mishaps. So, to avoid these problems, this project of alcohol detection with vehicle controlling system by locking engine is developed. The main objective of this project is to reduce road accidents, to provide automatic safety to the vehicle, driver and passengers. In India, drowsy driving is a major problem. The risk and often ruinous results of drowsy driving are alerting. Recent statistics estimate that annually 1,200 deaths and 76,000 injuries are a case of fatigue related crashes all over the world. Therefore, a technology to prevent and detect driver drowsiness is a major challenge in the field of accident-avoidance systems. Since the drowsiness presents a hazard on the road, therefore counteractive methods need to be developed to deal with its effects.
So here we develop an innovative system to avoid such cases. Our system would be constantly monitoring the driving force breath by placing it on the steering wheel or at place where the driver’s breath is often constantly being monitored by it. So, if a driver is drunk and tries to drive the system detects alcohol presence in his/her breathe and locks the engine in order that the vehicle fails to start out. In another case if the driving force isn't drunk while he starts the vehicle and engine is started but he/she drinks while driving the sensor still detects alcohol in his breath and stops the engine in order that the car wouldn't accelerate any longer and driver can steer it to roadside. At the same time if driver is in Drowsiness condition, it is sensed by Arduino Controller and slowly stops the Vehicle and update in Blynk Server with Buzzer and Indicator alert.

Existing System
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------Many existing systems require a spectacle with eye blink sensor, camera which is installed in front of driver. If we take the spectacles, it is problem for the sight of the driver. If we take camera, it points straight towards the face of the driver and monitors the driver’s eyes in order to identify the drowsiness. For large vehicle such as heavy trucks and buses this arrangement is not pertinent. In order to conquer the problem of existing system, new detection system is developed in this project work.

Project Working
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
In this proposed system we have designed a Drowsiness Detection and Alcohol detection for Driver using IoT based Technology. Arduino, Alcohol sensor, Ultrasonic Sensor, Accelerometer and WIFI module is used as major components of the project. User is provided with a cap, in that Accelerometer is attached to it. This accelerometer signal is sent to Arduino for further processing. When user tilts his Head for more than 5-10 second, than a Buzzer alert sound will be generated and An Indicator LED will also glow if user gets sleep. Alcohol sensor is used to monitor if driver is consuming any alcohol while vehicle driving condition. If it detected by Arduino than it generates Buzzer Alert with LED Indication. DC Geared motor is used to simulate the vehicle engine status. If alcohol and Drowsiness is detected then will stop gradually with the help of L293D Motor driver. Ultrasonic Sensor is used to detect the any obstacle in front of vehicle that leads to collision. If any obstacle detected, DC Motor will stop immediately. This project is also interfaced with IOT based Monitoring System. Accelerometer, Ultrasonic sensor and Alcohol sensor data are update in Blynk Server in every 4-5 Second and User can monitor it using Android Blynk Application. LCD Module is interfaced with this system to display important notification / Message to the user. Node MCU is used to Internet connectivity and Update data on Blynk Server.The power supply consists of a step-down transformer 230/12V, which steps down the voltage to 12V AC. This is converted to DC using a rectifier. The ripples are removed using a capacitive filter and it is then regulated to +5V using a voltage regulator 7805 which is required for the operation of the microcontroller and other components.

Hardware Requirements
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
- Ultrasonic Sensor.
- Alcohol Sensor.
- Accelerometer Sensor.
- Arduino UNO.
- Node MCU.
- LCD 2x16.
- Buzzer.
- DC Geared Motor.
- Motor Driver.
- 12V Transformer.
- Voltage Regulators and Filters.

Software Requirements
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
- Arduino IDE.
- Embedded C Programming Language.
- Blynk Application.
