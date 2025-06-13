# Arduino Joystick RGB Indicator

Make sure to place the joystick module on an insulating surface (like wood, plastic, or your table) because, the exposed pins on the underside can pick up stray electrical signals if they touch something conductive. 
This can cause false readings on the X and Y axes, making the LEDs flicker even when you're not moving the joystick.

## 📑 Project Description
This project uses an **Arduino**, a **joystick module**, and **5 individual LEDs** (Red, Green, Blue, Yellow, and White) to visually indicate the direction the joystick is being moved. It also lights up a **white LED** when the joystick's built-in switch is pressed.

---

## 🎮 Functionality
| Joystick Input | LED Color |
|---|---|
| Up | 🔵 Blue |
| Down | 🔴 Red |
| Left | 🟡 Yellow |
| Right | 🟢 Green |
| Switch Pressed | ⚪️ White |

---

## 🧰 Hardware Used
- Arduino (any compatible board like UNO, Nano, etc.)
- Joystick Module (with X, Y, and SW pins)
- 5 individual LEDs (Red, Green, Blue, Yellow, White)
- Current-limiting resistors for LEDs (typically 220Ω)
- Breadboard & jumper wires

---

## ⚡️ Pin Mapping

| Component | Arduino Pin |
|---|---|
| Joystick X-axis (VRx) | A0 |
| Joystick Y-axis (VRy) | A1 |
| Joystick Switch (SW) | 2 |
| Red LED | 11 |
| Yellow LED | 10 |
| Green LED | 6 |
| Blue LED | 9 |
| White LED (Switch) | 3 |

---

## 💻 Code Overview
The code continuously reads the analog values from the joystick’s **X** and **Y axes** and compares them to calibrated neutral positions. Based on the direction, the corresponding LED lights up with brightness proportional to how far the joystick is pushed. The switch is handled as a **digital input** using the Arduino’s internal **pull-up resistor**.

---

## 🧪 Calibration
The joystick’s neutral (centered) position is read once at startup, allowing the code to automatically account for minor hardware variations.

---

## 🌈 Optional Ideas for Future
- Add blended colors for diagonal movements (e.g., cyan for up-right)
- Replace individual LEDs with a **single RGB LED module** for simpler wiring
- Display direction data on an **OLED screen** alongside the LEDs
- Add a **buzzer** for auditory feedback

---
