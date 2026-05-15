<div align="center">

# 🗳️ LPC2148 Electronic Voting Machine  
### ARM7 Embedded Systems Project using LPC2148 Microcontroller

<img src="Images/board_image.png" width="650"/>

![ARM7](https://img.shields.io/badge/ARM7-LPC2148-blue?style=for-the-badge)
![Embedded C](https://img.shields.io/badge/Language-Embedded%20C-green?style=for-the-badge)
![Keil](https://img.shields.io/badge/IDE-Keil%20uVision4-red?style=for-the-badge)
![UART](https://img.shields.io/badge/UART-9600bps-orange?style=for-the-badge)

</div>

---

# 📌 Project Overview

This project implements a **real-time Electronic Voting Machine (EVM)** using the **LPC2148 ARM7 Microcontroller**. The system performs electronic vote recording, LED-based vote confirmation, buzzer indication, GPIO interfacing, and UART-based result transmission.

The project demonstrates practical embedded system concepts including:

- GPIO interfacing
- UART communication
- ARM7 programming
- Embedded C development
- Real-time event handling
- Peripheral interfacing

The complete system was designed and simulated in **Keil uVision4** using Embedded C. :contentReference[oaicite:0]{index=0}

---

# 🚀 Features

✅ Electronic vote counting  
✅ Candidate-wise LED indication  
✅ Buzzer confirmation system  
✅ UART-based result display  
✅ Startup LED animation  
✅ Real-time vote processing  
✅ Active-low LED control  
✅ Keil simulation compatible  
✅ Hardware implementation compatible  

---

# 🧠 Technologies Used

| Technology | Description |
|---|---|
| LPC2148 | ARM7TDMI-S Microcontroller |
| Embedded C | Firmware development |
| Keil uVision4 | Simulation & debugging |
| UART0 | Serial communication |
| GPIO | LED and buzzer control |
| Flash Magic | Hardware flashing utility |

---

# 🛠️ Hardware Components

| Component | Purpose |
|---|---|
| LPC2148 ARM7 Board | Main controller |
| LEDs | Vote indication |
| Buzzer | Audio confirmation |
| UART0 | Result transmission |
| Push Buttons | Candidate selection |

---

# 🔌 GPIO Mapping

| GPIO Pin | Function |
|---|---|
| P0.16 | Candidate_01_PARTY_A |
| P0.17 | Candidate_02_PARTY_B |
| P0.18 | Candidate_03_PARTY_C |
| P0.19 | Candidate_04_INDEPENDENT |
| P0.9 | Buzzer |
| TXD0 | UART Transmission |

:contentReference[oaicite:1]{index=1}

---

# ⚙️ System Workflow

```text
START
   ↓
Initialize GPIO + UART
   ↓
Startup LED Animation
   ↓
Vote Selection
   ↓
Vote Counter Increment
   ↓
LED + Buzzer Confirmation
   ↓
Vote Lock Delay
   ↓
UART Result Transmission
   ↓
END
```

The complete workflow and embedded control sequence are explained in the report. :contentReference[oaicite:2]{index=2}

---

# 🖥️ UART Result Output

```text
------ FINAL RESULT ------

Candidate_01_PARTY_A : 4
Candidate_02_PARTY_B : 3
Candidate_03_PARTY_C : 3
Candidate_04_INDEPENDENT : 2

Total Votes : 12

--------------------------
```

UART communication is configured at:

| Parameter | Value |
|---|---|
| Baud Rate | 9600 bps |
| Data Bits | 8-bit |
| Stop Bit | 1 |
| Parity | None |

:contentReference[oaicite:3]{index=3}

---

# 💡 LED Logic

## Real LPC2148 Hardware (ALS Board)

```c
IO0CLR = LED;   // LED ON
IO0SET = LED;   // LED OFF
```

The ALS LPC2148 board uses **active-low LEDs**.

---

# 📂 Project Structure

```text
LPC2148-Electronic-Voting-Machine/
│
├── Source_Code/
│   ├── main.c
│   └── Startup.s
│
├── Keil_Project/
│   ├── EVM_Project.uvproj
│   ├── EVM_Project.uvopt
│   └── EVM_Project.uvgui
│
├── Build_Output/
│   ├── EVM_Project.hex
│   ├── EVM_Project.axf
│   └── EVM_Project.map
│
├── Report/
│   └── EVM_Project_Report.pdf
│
├── Screenshots/
│   ├── gpio_output.png
│   ├── uart_output.png
│   ├── watch_window.png
│   └── logic_analyzer.png
│
├── README.md
└── .gitignore
```

---

# 📸 Screenshots

## GPIO Activity

<img src="Screenshots/gpio_output.png" width="700"/>

---

## UART Result Window

<img src="Screenshots/uart_output.png" width="500"/>

---

## Watch Window

<img src="Screenshots/watch_window.png" width="500"/>

---

# 📊 Experimental Results

| Operation | Status |
|---|---|
| Vote Counting | ✅ Successful |
| LED Indication | ✅ Successful |
| UART Communication | ✅ Successful |
| Buzzer Operation | ✅ Successful |

The simulation verified accurate GPIO operation and UART communication. :contentReference[oaicite:4]{index=4}

---

# 🎯 Advantages

- Fast vote counting
- Accurate result generation
- Low-cost implementation
- Simple hardware interfacing
- Real-time embedded operation
- Reliable UART communication

:contentReference[oaicite:5]{index=5}

---

# 🔮 Future Enhancements

- Fingerprint authentication
- RFID voting
- EEPROM vote storage
- GSM communication
- Touchscreen interface
- Secure encrypted voting

:contentReference[oaicite:6]{index=6}

---

# 📚 Learning Outcomes

This project demonstrates practical understanding of:

- ARM7 Architecture
- LPC2148 GPIO Programming
- UART Communication
- Embedded C Development
- Real-time Embedded Systems
- Peripheral Interfacing
- Keil Simulation & Debugging

---

# 📖 Report

📄 Detailed Project Report:

`Report/EVM_Project_Report.pdf`

---

# 👨‍💻 Author

### Aditya R Patil

Embedded Systems | ARM7 | LPC2148 | Embedded C

---

# ⭐ If you like this project

Give it a ⭐ on GitHub!

---

# 📜 License

This project is developed for academic and educational purposes.