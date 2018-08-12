############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project gato
set_top gframe
add_files design.cpp
add_files -tb tb.cpp
open_solution "solution1"
set_part {xc7z010clg400-1} -tool vivado
create_clock -period 10 -name default
#source "./gato/solution1/directives.tcl"
csim_design -clean -compiler gcc
csynth_design
cosim_design
export_design -format ip_catalog
