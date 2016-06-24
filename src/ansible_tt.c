#include "print_funcs.h"

#include "monome.h"

#include "main.h"
#include "ansible_tt.h"


void set_mode_tt(void) {
	print_dbg("\r\n> mode tt");
	app_event_handlers[kEventKey] = &handler_TTKey;
	app_event_handlers[kEventTr] = &handler_TTTr;
	app_event_handlers[kEventTrNormal] = &handler_TTTrNormal;
	clock = &clock_tt;
	clock_set(50);
	update_leds(0);
}

void clock_tt(uint8_t phase) {
	static uint16_t d[4];
	static uint16_t cv;
	cv += 0xff;
	cv &= 4095;

	d[0] = cv;
	d[1] = 4095 - cv;

	update_dacs(d);
}

void ii_tt(uint8_t i, int d) {
	;;
}


void handler_TTKey(s32 data) { 
	print_dbg("\r\n> TT key");
	print_dbg_ulong(data);
}

void handler_TTTr(s32 data) { 
	print_dbg("\r\n> TT tr");
	print_dbg_ulong(data);
}

void handler_TTTrNormal(s32 data) { 
	print_dbg("\r\n> TT tr normal ");
	print_dbg_ulong(data);
}