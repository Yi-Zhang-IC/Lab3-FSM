// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlfsr.h for the primary calling header

#include "Vlfsr.h"
#include "Vlfsr__Syms.h"

//==========

VL_CTOR_IMP(Vlfsr) {
    Vlfsr__Syms* __restrict vlSymsp = __VlSymsp = new Vlfsr__Syms(this, name());
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vlfsr::__Vconfigure(Vlfsr__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vlfsr::~Vlfsr() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vlfsr::_settle__TOP__2(Vlfsr__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr::_settle__TOP__2\n"); );
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->data_out = vlTOPp->lfsr__DOT__sreg;
}

void Vlfsr::_eval_initial(Vlfsr__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr::_eval_initial\n"); );
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vlfsr::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr::final\n"); );
    // Variables
    Vlfsr__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vlfsr::_eval_settle(Vlfsr__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr::_eval_settle\n"); );
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vlfsr::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr::_ctor_var_reset\n"); );
    // Body
    rst = VL_RAND_RESET_I(1);
    en = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    data_out = VL_RAND_RESET_I(7);
    lfsr__DOT__sreg = VL_RAND_RESET_I(7);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
