📡 Arduino Radar System

An Arduino-based radar system that detects objects and displays their distance and angle using an ultrasonic sensor and a servo motor. This project simulates a basic radar by scanning an area and visualizing detected objects in real time.

🚀 Features

📐 180° scanning using a servo motor

📏 Distance measurement with ultrasonic sensor

📊 Real-time radar visualization (via Serial Monitor / Processing / Python GUI / LCD)

⚡ Simple, low-cost components

🧠 Great for learning Arduino, sensors, and data visualization

🛠️ Components Used

Arduino Uno (or compatible board)

Ultrasonic Sensor (HC-SR04)

Servo Motor (SG90 or similar)

LCD

Buzzer

Power Supply (Arduino power isnt enough)

Jumper wires

Breadboard

USB cable




Pin Connections (you can use whatever pin you wnat but remember to adjust the code to match the pins you choosed)

|Component|	    |Arduino Pin|

|HC-SR04 Trig|	  | Digital pin|

|HC-SR04 Echo|	 |Digital pin|

|Servo Signal|	   |Digital pin|

|VCC	       |     |5V|

|GND         | 	   |GND|

|LCD SDA     |     |Analog pin|

|LCD SCL     |     |Analog pin|

|Buzzer      |     |Digital pin|

|Button      |     |Digital pin|

⚙️ How It Works

The servo motor rotates from 0° to 180°

At each angle, the ultrasonic sensor sends a pulse

The echo time is converted into distance

Angle and distance data are sent over serial

Data is visualized on the LCD screen as texts like "target detected"...

When button is pressed the LCD displays "LAUNCHING"


💻 Software Requirements

Arduino IDE


▶️ Installation & Usage

Clone the repository:

git clone https://github.com/mahdidarbaj-cmd/Arduino-fully-fonctional-radar-project

Open the .ino file in Arduino IDE

Connect your Arduino board

Select the correct Board and Port

Upload the code

Open the Serial Monitor (or radar GUI)

📸 Demo

<img width="405" height="435" alt="Screenshot 2026-01-24 130152" src="https://github.com/user-attachments/assets/f7874dc7-b111-496b-8347-8408c863fc37" />


📈 Future Improvements

Object tracking

Multiple sensors

OLED/LCD display

Bluetooth/WiFi support

Higher accuracy filtering

🤝 Contributing

Contributions are welcome!

Feel free to fork the project, open issues, or submit pull requests.

📜 License

This project is open-source and available under the MIT License

👤 Author

Mahdi darbaj

GitHub: @mahdidarbaj-cmd
