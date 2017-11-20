#!/bin/bash

###############################################################################
# This file compares the runtime of different implementations of set:
# unsorted array, sorted array (quicksort and insertion sort) and Red-Black set.
#
# Usage: ./timeTree
###############################################################################

if [ $# -lt 3 ]
then
  echo "Syntax: timeTree min_nodes max_nodes stp_nodes"
  echo "Default values: min_nodes = 100, max_nodes = 110101, stp_nodes = 10000"
  min_nodes=1000
  max_nodes=110100
  stp_nodes=10000
else
  min_nodes=$1
  max_nodes=$2
  stp_nodes=$3
  echo "min_nodes = $min_nodes, max_nodes = $max_nodes, stp_nodes = $stp_nodes"
fi

echo "int_sort, Time (s)"
for ((num_nodes = $min_nodes; num_nodes < $max_nodes; num_nodes += $stp_nodes))
do
  ./IntArraySet $num_nodes $num_nodes ;
done

echo "bit_sort, Time (s)"
for ((num_nodes = $min_nodes; num_nodes < $max_nodes; num_nodes += $stp_nodes))
do
  ./BitArraySet $num_nodes $num_nodes ;
done

echo "rbt_sort, Time (s)"
for ((num_nodes = $min_nodes; num_nodes < $max_nodes; num_nodes += $stp_nodes))
do
  ./RBTSet $num_nodes $num_nodes ;
done

echo "hst_sort, Time (s)"
for ((num_nodes = $min_nodes; num_nodes < $max_nodes; num_nodes += $stp_nodes))
do
  ./HashSet $num_nodes $num_nodes ;
done

echo "neq_sort, Time (s)"
for ((num_nodes = $min_nodes; num_nodes < $max_nodes; num_nodes += $stp_nodes))
do
  ./NoEqualHashSet $num_nodes $num_nodes ;
done
