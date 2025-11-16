Mine Safety Sensor Monitor
----
Overview
---
The Mine Safety Sensor Monitor is a C-based console application that simulates real-time underground safety sensors. It checks temperature, methane gas, and equipment load, then logs alerts when thresholds are exceeded.
This project demonstrates system monitoring, safety-critical logic, and file logging — perfect for your GitHub portfolio and mining/IT internship applications.

Features
---
Continuous monitoring loop

Temperature, methane gas, and equipment load simulation

Threshold-based safety alerts

Timestamped logging to safety_log.txt

Lightweight implementation in pure C

Tech Stack
---
Language: C

Compiler: GCC

Libraries: stdio.h, stdlib.h, time.h

Output: Console + log file

###How to Run
---
1️⃣ Clone the Repository
git clone https://github.com/SidratEvan/mine-safety-sensor.git
cd mine-safety-sensor

2️⃣ Compile the Program
gcc -o sensor_monitor main.c

3️⃣ Run
./sensor_monitor

4️⃣ View Logs

All readings + alerts are stored in:

safety_log.txt

Example Output
---
Cycle 1
Mine Safety Sensor Monitor
Temperature reading: 50 °C
ALERT: Temperature too high!
Methane reading: 2.75 %
ALERT: Methane level unsafe!
Equipment Load: 90 %
ALERT: Equipment overload risk!

File Structure
main.c             → core logic, simulation, alerts, logging
safety_log.txt     → auto-generated runtime log file
README.md          → project documentation

Future Enhancements
---
Add adjustable thresholds via a config file

Generate CSV history for graphing

Add GUI dashboard (JavaFX or simple HTML UI)

Integrate real hardware sensors (Arduino / Raspberry Pi)

Add networking alerts (email, SMS, or server ping)

Author
---
Sidrat Evan
GitHub: https://github.com/SidratEvan
