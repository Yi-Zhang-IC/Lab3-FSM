// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlfsr__Syms.h"


void Vlfsr::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vlfsr__Syms* __restrict vlSymsp = static_cast<Vlfsr__Syms*>(userp);
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vlfsr::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vlfsr__Syms* __restrict vlSymsp = static_cast<Vlfsr__Syms*>(userp);
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->rst));
        tracep->chgBit(oldp+1,(vlTOPp->en));
        tracep->chgBit(oldp+2,(vlTOPp->clk));
        tracep->chgCData(oldp+3,(vlTOPp->data_out),4);
        tracep->chgCData(oldp+4,(vlTOPp->lfsr__DOT__sreg),4);
    }
}

void Vlfsr::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vlfsr__Syms* __restrict vlSymsp = static_cast<Vlfsr__Syms*>(userp);
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
