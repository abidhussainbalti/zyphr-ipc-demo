# Project Stucture
'''
zyphr-ipc-demo/
├── src/
│   └── main.c
├── .gitignore
├── README.md
├── CMakeLists.txt
└── prj.conf

'''


# Zephyr IPC Demo Project

This is a **Zephyr RTOS IPC demo** running on **QEMU RISC-V 64-bit**. The demo shows producer-consumer communication using message queues.

## Features
- Producer sends 15 integer messages
- Consumer receives messages
- Uses Zephyr threads and IPC API (`k_msgq`, `k_thread`, `printk`)
- Runs on QEMU RISC-V (virtual hardware)

## Requirements
- Ubuntu 22.04+
- Zephyr SDK 0.17.4
- Python 3.12+
- Zephyr v4.3.99
- Virtual environment (`.venv`) recommended

## How to run
1. Open terminal and activate venv:
   ```bash
   source ~/zephyrproject/.venv/bin/activate

