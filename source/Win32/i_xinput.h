// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
// Copyright (C) 2013 James Haley et al.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/
//
// Additional terms and conditions compatible with the GPLv3 apply. See the
// file COPYING-EE for details.
//
//-----------------------------------------------------------------------------
//
// XInput Gamepad Support
//
// By James Haley
//
//-----------------------------------------------------------------------------

#ifndef I_XINPUT_H__
#define I_XINPUT_H__

#ifdef EE_FEATURE_XINPUT

#include "../hal/i_gamepads.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <XInput.h>

//
// XInputGamePadDriver
//
// Implements support for XBox 360 controller and compatible devices through
// their native interface.
//
class XInputGamePadDriver : public HALGamePadDriver
{
public:
   virtual bool initialize();
   virtual void shutdown();
   virtual void enumerateDevices();
   virtual int  getBaseDeviceNum() { return 0; }
};

// motor types
enum motor_e
{
    MOTOR_LEFT,
    MOTOR_RIGHT
};

extern XInputGamePadDriver i_xinputGamePadDriver;
//
// Effect Base Class
//
class XIBaseEffect : public ZoneObject
{
public:
    DLListItem<XIBaseEffect> links;
    XIBaseEffect(DLList<XIBaseEffect, &XIBaseEffect::links>& effects, uint32_t p_startTime, uint32_t p_duration);
    virtual ~XIBaseEffect();



    virtual void evolve(XINPUT_VIBRATION &xvib, uint32_t curTime) = 0;

    static void RunEffectsList(XINPUT_VIBRATION &xvib, uint32_t curTime, DLList<XIBaseEffect, &XIBaseEffect::links>& effects);
    static void ClearEffectsList(DLList<XIBaseEffect, &XIBaseEffect::links>& effects);

protected:
    uint32_t startTime;
    uint32_t duration;
    static void AddClamped(XINPUT_VIBRATION &xvib, motor_e which, WORD addValue);

    bool checkDone(uint32_t curTime) { return (curTime > startTime + duration); }

    DLList<XIBaseEffect, &XIBaseEffect::links>* pEffects;
};
typedef DLList<XIBaseEffect, &XIBaseEffect::links> effectsList_t;

//
// XInputHapticInterface
//
// Exposes support for force feedback effects through XInput gamepads.
//
class XInputHapticInterface : public HALHapticInterface
{
   DECLARE_RTTI_TYPE(XInputHapticInterface, HALHapticInterface)

protected:
   unsigned long dwUserIndex;
   bool pauseState;

   void zeroState();

   effectsList_t effects;

public:
   XInputHapticInterface(unsigned long userIdx = 0);
   virtual void startEffect(effect_e effect, int data1, int data2);
   virtual void pauseEffects(bool effectsPaused);
   virtual void updateEffects();
   virtual void clearEffects();
};

//
// XInputGamePad
//
// Represents an actual XInput device.
//
class XInputGamePad : public HALGamePad
{
   DECLARE_RTTI_TYPE(XInputGamePad, HALGamePad)

protected:
   unsigned long dwUserIndex;
   XInputHapticInterface haptics;

   float normAxis(int value, int threshold, int maxvalue);
   void  normAxisPair(float &axisx, float &axisy, int threshold, int min, int max);

public:
   XInputGamePad(unsigned long userIdx = 0);

   virtual bool select();
   virtual void deselect();
   virtual void poll();
   
   virtual HALHapticInterface *getHapticInterface() { return &haptics; }
};

#endif

#endif

// EOF

