/*********************************************************************
 *
 *                EiBotBoard Firmware
 *
 *********************************************************************
 * FileName:        servo.h
 * Company:         Schmalz Haus LLC
 * Author:          Brian Schmalz
 *
 * Based on original files by Microchip Inc. in MAL USB example.
 *
 * Software License Agreement
 *
 * Copyright (c) 2014, Brian Schmalz of Schmalz Haus LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * 1. Redistributions of source code must retain the above
 * copyright notice, this list of conditions and the following
 * disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials
 * provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of
 * its contributors may be used to endorse or promote products
 * derived from this software without specific prior written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef SERVO_H
#define SERVO_H
#include "GenericTypeDefs.h"
#include "Compiler.h"

typedef enum
{
  PEN_DOWN = 0,
  PEN_UP
} PenStateType;

#define MAX_RC2_SERVOS    24      // This is 24 because there are 24 RPn pins
#define INITAL_RC2_SLOTS  8       // Inital number of RC2 slots (determines repeat rate of pulses)
#define DEFAULT_EBB_SERVO_PORTB_PIN   1 // Note, this indicates a PortB pin number, not RPn number
#define DEFAULT_EBB_SERVO_RPN (DEFAULT_EBB_SERVO_PORTB_PIN + 3) // RPn number for default pen up/down servo
#define RCSERVO_POWEROFF_DEFAULT_MS (60ul*1000ul)  // Number of milliseconds to default the RCServo power autotimeout (5min)

// Set TRUE to enable RC Servo output for pen up/down
extern BOOL gUseRCPenServo;

extern volatile unsigned long int gRCServoPoweroffCounterMS;
extern volatile unsigned long int gRCServoPoweroffCounterReloadMS;

extern UINT8 gRC2msCounter;
extern UINT16 gRC2Value[MAX_RC2_SERVOS];
extern UINT8 gRC2RPn[MAX_RC2_SERVOS];
extern UINT8 gRC2Ptr;
extern UINT16 gRC2Target[MAX_RC2_SERVOS];
extern UINT16 gRC2Rate[MAX_RC2_SERVOS];
extern far ram UINT8 * gRC2RPORPtr;
extern UINT16 g_servo2_max;
extern UINT16 g_servo2_min;
extern UINT8 gRC2Slots;
extern UINT8 gRC2SlotMS;
extern UINT16 g_servo2_rate_up;
extern UINT16 g_servo2_rate_down;
extern UINT8 g_servo2_RPn;

// track the latest state of the pen
extern PenStateType PenState;

void servo_Init(void);
void parse_SP_packet(void);
void servo_S2_command(void);
UINT8 servo_Move(UINT16 Position, UINT8 RPn, UINT16 Rate, UINT16 Delay);
void process_SP(PenStateType NewState, UINT16 CommandDuration);


#endif
