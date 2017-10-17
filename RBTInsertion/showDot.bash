#!/bin/bash

###############################################################################
# This file opens up the dot file containing a tree produced by the treeGen.c
# program.
# Usage: cfgllvm file.c
###############################################################################

if [ $# -lt 1 ]
then
    echo Syntax: showDot num_nodes
    exit 1
else
  num_nodes=$1
  dot_type=$2
  dot_name=file.dot
  ./treeGen $num_nodes $dot_type > $dot_name ;
  open $dot_name
fi
