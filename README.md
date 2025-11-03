# 🏎️ Arduino 4WD Robo Race Rover with Crawl Mode

An **Arduino-powered 4WD Robo Race Rover** designed for high-speed performance and precision control.  
This rover features **dual driving modes** — **Race Mode** for maximum speed and **Crawl Mode** for smooth, controlled navigation on technical sections or obstacles.  

Perfect for robotics competitions, college Robo Race events, and DIY RC conversions.

---

## ⚡ Key Features

- 🏁 **Race Mode** – Full-speed driving for racing tracks  
- 🐢 **Crawl Mode** – Reduced-speed control for sharp turns and tight maneuvers  
- ⚙️ **4-Wheel Drive** – Independent control of all 4 DC motors  
- 🔄 **Differential steering** for smooth turns  
- 🎮 **Manual / Bluetooth / Autonomous control** compatible  
- 💡 **Modular design** – easily upgradeable with sensors, camera, or AI  

---

## 🧠 How It Works

The rover runs using four DC motors connected through a motor driver (like L298N or Adafruit Motor Shield).  
The **mode switch** toggles between two speed profiles:
- **Race Mode**: Full PWM power for speed and torque.  
- **Crawl Mode**: Reduces PWM to 30–40% for slow, precise movement.

The driver can switch between these modes using a button, remote input, or software command.

---

## ⚙️ Hardware Requirements

| Component | Description |
|------------|-------------|
| **Microcontroller** | Arduino Uno / Nano / Mega |
| **Motor Driver** | L298N / Adafruit Motor Shield |
| **Motors** | 4 × DC gear motors (same RPM) |
| **Battery** | 7.4V – 12V Li-ion/LiPo |
| **Mode Switch** | Push button / Bluetooth trigger |
| **Optional Add-ons** | Ultrasonic sensor, Bluetooth module (HC-05), camera module |

---

## 🔌 Wiring Overview

| Motor | Driver Port | Function |
|--------|--------------|----------|
| Front Left | M1 | Forward/Reverse |
| Front Right | M2 | Forward/Reverse |
| Rear Left | M3 | Forward/Reverse |
| Rear Right | M4 | Forward/Reverse |

**Power:**  
- Connect motor driver `VCC` to 12V battery supply  
- Connect logic `5V` to Arduino’s 5V pin  
- Common ground for all connections  

---

## 🔧 Mode Control Example

```cpp
int baseSpeed = 255;   // Max PWM
bool crawlMode = false;

if (crawlMode) {
  motorSpeed = baseSpeed * 0.4;  // 40% speed for crawl mode
} else {
  motorSpeed = baseSpeed;        // Full speed for race mode
}
