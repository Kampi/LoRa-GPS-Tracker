# LoRa-GPS-Tracker

[![License](https://img.shields.io/badge/License-GPL%203.0-blue.svg)](https://opensource.org/license/gpl-3-0/)
[![Build](https://github.com/Kampi/ZSWatch-Dock/actions/workflows/build.yml/badge.svg)](https://github.com/Kampi/ZSWatch-Dock/actions/workflows/build.yml)

## Table of Contents

- [LoRa-GPS-Tracker](#lora-gps-tracker)
  - [Table of Contents](#table-of-contents)
  - [About](#about)
  - [Directory structure](#directory-structure)
  - [Purchasing](#purchasing)
  - [Programming](#programming)
  - [Maintainer](#maintainer)

## About

This is a project for a LoRa based APRS GPS tracker.

![PCB Top side](/docs/images/Image_Complete.jpg)

## Directory structure

- `docs`: All kinds of project documentation
- `firmware`: The firmware project for the tracker
- `project`: KiCad project for the PCB
- `testing`: 

## Purchasing

Please open `LoRa-GPS-Tracker-navigate.html` and use the files listed under `purchasing` for ordering a PCB.

## Programming

1. Download and install [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html)
2. Close the `PROG` jumper on the PCB
3. Connect the board via USB to your PC
4. Open `Memory & File editing` in `STM32CubeProgrammer`
5. Select `UART`, the target COM port and `Read Unprotect (MCU)`
6. Click `Connect` and wait for a connection
7. Open `Erase & Programming` and click `Browse`

## Maintainer

- [Daniel Kampert](mailto:daniel.kameprt@kampis-elektroecke.de)
