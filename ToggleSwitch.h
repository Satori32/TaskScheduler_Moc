#pragma once
#include <stdio.h>

struct ToggleSwitch {
	bool F = false;
};
ToggleSwitch ConstructToggleSwitch(bool F);
bool ToOn(ToggleSwitch& In);
bool ToOff(ToggleSwitch& In);
bool ToTurn(ToggleSwitch& In);
bool Now(ToggleSwitch& In);
bool NowInvarse(ToggleSwitch& In);