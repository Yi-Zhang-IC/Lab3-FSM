// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlfsr.h for the primary calling header

#include "Vlfsr.h"
#include "Vlfsr__Syms.h"

//==========

void Vlfsr::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlfsr::eval\n"); );
    Vlfsr__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("lfsr.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vlfsr::_eval_initial_loop(Vlfsr__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("lfsr.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vlfsr::_sequent__TOP__1(Vlfsr__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr::_sequent__TOP__1\n"); );
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__lfsr__DOT__sreg;
    // Body
    __Vdly__lfsr__DOT__sreg = vlTOPp->lfsr__DOT__sreg;
    if (vlTOPp->rst) {
        __Vdly__lfsr__DOT__sreg = 1U;
    } else {
        if (vlTOPp->en) {
            __Vdly__lfsr__DOT__sreg = ((7U & (IData)(__Vdly__lfsr__DOT__sreg)) 
                                       | (8U & ((IData)(vlTOPp->lfsr__DOT__sreg) 
                                                << 1U)));
            __Vdly__lfsr__DOT__sreg = ((0xbU & (IData)(__Vdly__lfsr__DOT__sreg)) 
                                       | (4U & ((IData)(vlTOPp->lfsr__DOT__sreg) 
                                                << 1U)));
            __Vdly__lfsr__DOT__sreg = ((0xdU & (IData)(__Vdly__lfsr__DOT__sreg)) 
                                       | (2U & ((IData)(vlTOPp->lfsr__DOT__sreg) 
                                                << 1U)));
            __Vdly__lfsr__DOT__sreg = ((0xeU & (IData)(__Vdly__lfsr__DOT__sreg)) 
                                       | (1U & (((IData)(vlTOPp->lfsr__DOT__sreg) 
                                                 >> 3U) 
                                                ^ ((IData)(vlTOPp->lfsr__DOT__sreg) 
                                                   >> 2U))));
        }
    }
    vlTOPp->lfsr__DOT__sreg = __Vdly__lfsr__DOT__sreg;
    vlTOPp->data_out = vlTOPp->lfsr__DOT__sreg;
}

void Vlfsr::_eval(Vlfsr__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr::_eval\n"); );
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vlfsr::_change_request(Vlfsr__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr::_change_request\n"); );
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vlfsr::_change_request_1(Vlfsr__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr::_change_request_1\n"); );
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vlfsr::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
