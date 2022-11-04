#!/bin/sh

rm -rf obj_dir
rm -f *.vcd

verilator -Wall --cc --trace lfsr.sv --exe lfsr_tb.cpp

make -j -C obj_dir/ -f Vlfsr.mk Vlfsr

ls /dev/ttyUSB* > vbuddy.cfg

./obj_dir/Vlfsr
