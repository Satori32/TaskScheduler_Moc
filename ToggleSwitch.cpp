#include "ToggleSwitch.h"

ToggleSwitch ConstructToggleSwitch(bool F) {
	ToggleSwitch T;
	T.F = F;

	return T;
}
bool ToOn(ToggleSwitch& In) {
	In.F = true;
	return true;
}
bool ToOff(ToggleSwitch& In) {
	In.F = false;
	return true;
}
bool ToTurn(ToggleSwitch& In) {
	In.F = !In.F;
	return true;
}
bool Now(ToggleSwitch& In) {
	return In.F;
}
bool NowInvarse(ToggleSwitch& In) {
	return !In.F;
}
bool Set(ToggleSwitch& In, bool B) {
	In.F = B;
	return true;
}
bool Get(ToggleSwitch& In) {
	return In.F;
}
bool IsOff(ToggleSwitch& In) {
	return In.F==false;
}
bool IsOn(ToggleSwitch& In) {
	return In.F==true;
}
