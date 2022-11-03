// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlfsr__Syms.h"


//======================

void Vlfsr::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vlfsr::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vlfsr__Syms* __restrict vlSymsp = static_cast<Vlfsr__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vlfsr::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vlfsr::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vlfsr__Syms* __restrict vlSymsp = static_cast<Vlfsr__Syms*>(userp);
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vlfsr::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vlfsr__Syms* __restrict vlSymsp = static_cast<Vlfsr__Syms*>(userp);
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"rst", false,-1);
        tracep->declBit(c+2,"en", false,-1);
        tracep->declBit(c+3,"clk", false,-1);
        tracep->declBus(c+4,"data_out", false,-1, 3,0);
        tracep->declBit(c+1,"lfsr rst", false,-1);
        tracep->declBit(c+2,"lfsr en", false,-1);
        tracep->declBit(c+3,"lfsr clk", false,-1);
        tracep->declBus(c+4,"lfsr data_out", false,-1, 3,0);
        tracep->declBus(c+5,"lfsr sreg", false,-1, 3,0);
    }
}

void Vlfsr::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vlfsr::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vlfsr__Syms* __restrict vlSymsp = static_cast<Vlfsr__Syms*>(userp);
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vlfsr::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vlfsr__Syms* __restrict vlSymsp = static_cast<Vlfsr__Syms*>(userp);
    Vlfsr* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->rst));
        tracep->fullBit(oldp+2,(vlTOPp->en));
        tracep->fullBit(oldp+3,(vlTOPp->clk));
        tracep->fullCData(oldp+4,(vlTOPp->data_out),4);
        tracep->fullCData(oldp+5,(vlTOPp->lfsr__DOT__sreg),4);
    }
}
