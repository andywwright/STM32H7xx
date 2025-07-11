/*
  btt_octopus_max_map.h - Board map for BIGTREETECH Octopus MAX EZ

  Part of grblHAL

  Copyright (c) 2024 Joe Corelli
  Copyright (c) 2024 Jon Escombe

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 3
#error "Octopus MAX board map is only configured for 6 motors max."
#endif

#if !(defined(STM32H723xx)) || HSE_VALUE != 25000000
#error "This board has a STM32H723 processor with 25MHz crystal, select a corresponding build!"
#endif

#define BOARD_NAME "BTT Octopus MAX"
#define BOARD_URL "https://github.com/bigtreetech/Octopus-Max-EZ"

#define SERIAL_PORT                 32      // GPIOD: TX = 8, RX = 9
#define I2C_PORT                    2       // GPIOB: SCL = 10, SDA = 11
#define SPI_PORT                    4       // GPIOE: SCK = 12, MISO = 13, MOSI = 14

// Motor Reference:
// Motor-1: X-axis
// Motor-2: Y-axis
// Motor-3: Z-axis
// Motor-4: M3-axis
// Motor-5: M4-axis
// Motor-6: M5-axis

// Define step pulse output pins.
#define X_STEP_PORT                 GPIOC
#define X_STEP_PIN                  13
#define Y_STEP_PORT                 GPIOE
#define Y_STEP_PIN                  4
#define Z_STEP_PORT                 GPIOE
#define Z_STEP_PIN                  1
#define STEP_OUTMODE                GPIO_SINGLE

// Define step direction output pins.
#define X_DIRECTION_PORT            GPIOC
#define X_DIRECTION_PIN             14
#define Y_DIRECTION_PORT            GPIOE
#define Y_DIRECTION_PIN             5
#define Z_DIRECTION_PORT            GPIOE
#define Z_DIRECTION_PIN             0
#define DIRECTION_OUTMODE           GPIO_SINGLE

// Define stepper driver enable/disable output pin.
#define X_ENABLE_PORT               GPIOE
#define X_ENABLE_PIN                6
#define Y_ENABLE_PORT               GPIOE
#define Y_ENABLE_PIN                3
#define Z_ENABLE_PORT               GPIOE
#define Z_ENABLE_PIN                2

// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT                GPIOF
#define X_LIMIT_PIN                 0       // MIN1
#define Y_LIMIT_PORT                GPIOF
#define Y_LIMIT_PIN                 2       // MIN2
#define Z_LIMIT_PORT                GPIOF
#define Z_LIMIT_PIN                 4       // MIN3
#define LIMIT_INMODE                GPIO_SINGLE

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE                        // Motor-4
#define M3_STEP_PORT                GPIOB
#define M3_STEP_PIN                 8
#define M3_DIRECTION_PORT           GPIOB
#define M3_DIRECTION_PIN            9
#define M3_LIMIT_PORT               GPIOF
#define M3_LIMIT_PIN                3       // MIN4
#define M3_ENABLE_PORT              GPIOB
#define M3_ENABLE_PIN               7       // EN for M3 motor
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 1
#define M4_AVAILABLE                        // Motor-5
#define M4_STEP_PORT                GPIOB
#define M4_STEP_PIN                 5
#define M4_DIRECTION_PORT           GPIOB
#define M4_DIRECTION_PIN            4
#define M4_LIMIT_PORT               GPIOF
#define M4_LIMIT_PIN                1       // MIN5
#define M4_ENABLE_PORT              GPIOB
#define M4_ENABLE_PIN               6       // EN for M4
#endif

// Define ganged axis or C axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 2
#define M5_AVAILABLE                        // Motor-6
#define M5_STEP_PORT                GPIOG
#define M5_STEP_PIN                 15
#define M5_DIRECTION_PORT           GPIOB
#define M5_DIRECTION_PIN            3
#define M5_LIMIT_PORT               GPIOC
#define M5_LIMIT_PIN                15      // MIN6
#define M5_ENABLE_PORT              GPIOD
#define M5_ENABLE_PIN               5       // EN for M5 motor
#endif

#define AUXOUTPUT0_PORT             GPIOA   // Spindle PWM - FAN4
#define AUXOUTPUT0_PIN              1
#define AUXOUTPUT1_PORT             GPIOA   // Spindle direction - FAN1
#define AUXOUTPUT1_PIN              5
#define AUXOUTPUT2_PORT             GPIOA   // Spindle enable - FAN0
#define AUXOUTPUT2_PIN              6
#define AUXOUTPUT3_PORT             GPIOF   // Coolant flood - HE0
#define AUXOUTPUT3_PIN              6
#define AUXOUTPUT4_PORT             GPIOA   // Coolant mist - HE1
#define AUXOUTPUT4_PIN              0

// Define driver spindle pins.
#if DRIVER_SPINDLE_ENABLE & SPINDLE_ENA
#define SPINDLE_ENABLE_PORT         AUXOUTPUT2_PORT
#define SPINDLE_ENABLE_PIN          AUXOUTPUT2_PIN
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_PWM
#define SPINDLE_PWM_PORT            AUXOUTPUT0_PORT
#define SPINDLE_PWM_PIN             AUXOUTPUT0_PIN
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_DIR
#define SPINDLE_DIRECTION_PORT      AUXOUTPUT1_PORT
#define SPINDLE_DIRECTION_PIN       AUXOUTPUT1_PIN
#endif

// Define flood and mist coolant enable output pins.
#if COOLANT_ENABLE & COOLANT_FLOOD
#define COOLANT_FLOOD_PORT          AUXOUTPUT3_PORT
#define COOLANT_FLOOD_PIN           AUXOUTPUT3_PIN
#endif
#if COOLANT_ENABLE & COOLANT_MIST
#define COOLANT_MIST_PORT           AUXOUTPUT4_PORT
#define COOLANT_MIST_PIN            AUXOUTPUT4_PIN
#endif

#define AUXINPUT0_PORT              GPIOF   // Safety door - PWR-DET
#define AUXINPUT0_PIN               12
#define AUXINPUT1_PORT              GPIOB   // Probe - Z probe
#define AUXINPUT1_PIN               15
#define AUXINPUT2_PORT              GPIOF   // Reset - PS-ON
#define AUXINPUT2_PIN               13
#define AUXINPUT3_PORT              GPIOF   // Feed hold - IND-PROBE
#define AUXINPUT3_PIN               11
#define AUXINPUT4_PORT              GPIOF   // Cycle start - FWS
#define AUXINPUT4_PIN               10

// Define user-control controls (cycle start, reset, feed hold) input pins.
#if CONTROL_ENABLE & CONTROL_HALT
#define RESET_PORT                  AUXINPUT2_PORT
#define RESET_PIN                   AUXINPUT2_PIN
#endif
#if CONTROL_ENABLE & CONTROL_FEED_HOLD
#define FEED_HOLD_PORT              AUXINPUT3_PORT
#define FEED_HOLD_PIN               AUXINPUT3_PIN
#endif
#if CONTROL_ENABLE & CONTROL_CYCLE_START
#define CYCLE_START_PORT            AUXINPUT4_PORT
#define CYCLE_START_PIN             AUXINPUT4_PIN
#endif

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PORT            AUXINPUT0_PORT
#define SAFETY_DOOR_PIN             AUXINPUT0_PIN
#endif

#if PROBE_ENABLE
#define PROBE_PORT                  AUXINPUT1_PORT
#define PROBE_PIN                   AUXINPUT1_PIN
#endif

#if TRINAMIC_UART_ENABLE

#define MOTOR_UARTX_PORT            GPIOG
#define MOTOR_UARTX_PIN             14
#define MOTOR_UARTY_PORT            GPIOG
#define MOTOR_UARTY_PIN             13
#define MOTOR_UARTZ_PORT            GPIOG
#define MOTOR_UARTZ_PIN             12

#ifdef  M3_AVAILABLE
#define MOTOR_UARTM3_PORT           GPIOG
#define MOTOR_UARTM3_PIN            11
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_UARTM4_PORT           GPIOG
#define MOTOR_UARTM4_PIN            10
#endif

#ifdef  M5_AVAILABLE
#define MOTOR_UARTM5_PORT           GPIOG
#define MOTOR_UARTM5_PIN            9
#endif

#elif TRINAMIC_SPI_ENABLE

// The BTT Octopus MAX uses hardware SPI4 for Trinamic drivers
#define TRINAMIC_MOSI_PORT          GPIOE
#define TRINAMIC_MOSI_PIN           14
#define TRINAMIC_SCK_PORT           GPIOE
#define TRINAMIC_SCK_PIN            12
#define TRINAMIC_MISO_PORT          GPIOE
#define TRINAMIC_MISO_PIN           13

#define MOTOR_CSX_PORT              GPIOG
#define MOTOR_CSX_PIN               14
#define MOTOR_CSY_PORT              GPIOG
#define MOTOR_CSY_PIN               13
#define MOTOR_CSZ_PORT              GPIOG
#define MOTOR_CSZ_PIN               12

#ifdef  M3_AVAILABLE
#define MOTOR_CSM3_PORT             GPIOG
#define MOTOR_CSM3_PIN              11
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_CSM4_PORT             GPIOG
#define MOTOR_CSM4_PIN              10
#endif

#ifdef  M5_AVAILABLE
#define MOTOR_CSM5_PORT             GPIOG
#define MOTOR_CSM5_PIN              9
#endif

#endif

// EOF
