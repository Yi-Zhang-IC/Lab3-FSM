#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vlfsr.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 10000000

int main(int argc, char **argv, char **env) {
  int cycle;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vlfsr* top = new Vlfsr;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("lfsr.vcd"); //name the wave file we want to save 
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T1:lfsr");
  
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation input 
  top->clk = 1;
  top->en = 0;
  top->rst = 0 ;


  // run simulation for MAX_SIM_CYC clock cycles
  for (cycle=0; cycle<MAX_SIM_CYC; cycle++) {
    // dump variables into VCD file and toggle clock
    top->rst = (cycle<2); 
    top->en = vbdFlag();

    for (tick=0; tick<2; tick++) {
      tfp->dump (2*cycle+tick);
      top->clk = !top->clk;
      top->eval ();
    }
    
    vbdHex(1, top->data_out & 0xF);
    vbdBar(top->data_out & 0xFF);

  }

  vbdClose();     
  tfp->close(); 
  printf("Exiting\n");
  exit(0);
}
