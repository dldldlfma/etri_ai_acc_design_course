#!/bin/csh
echo "probe -create -shm -all -depth all" | cat > wave.tcl
ncverilog +gui +access+rwc  +nctimescale+1ns/1ns -f file_list.f \
          -input wave.tcl          
