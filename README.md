# malibu

Custom control suite to replace the BCM in a 2019 Chevy Malibu using a PC.

This project integrates a React-based Tesla-style center display, a digital gauge cluster, and a unified backend system to manage relays, sensors, CAN bus data, and vehicle functions. It enables full replacement of the vehicle's BCM with a custom PC and software suite.

## Features

- Tesla-style center screen UI built with React
- Digital gauge cluster with real-time data
- Python backend for vehicle control and CAN bus communication
- Custom relay control logic
- Modular architecture for future upgrades
- GPIO and sensor input support (e.g., Arduino, Raspberry Pi)
- Designed for use in custom automotive PC builds

## File Structure

```
malibu/
├── backend/
│   ├── canbus/
│   ├── gpio/
│   ├── sensors/
│   └── main.py
├── frontend/
│   ├── public/
│   └── src/
│       ├── components/
│       ├── screens/
│       └── App.jsx
├── docs/
│   └── schematics.md
├── hardware/
│   ├── relay_control/
│   └── microcontroller/
├── config/
│   └── settings.json
└── README.md
```

## Requirements

- Node.js (Frontend)
- Python 3.9+ (Backend)
- SocketCAN or compatible CAN interface
- Optional: Arduino/RPi for GPIO inputs

