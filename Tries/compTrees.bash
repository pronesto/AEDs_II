#!/bin/bash

###############################################################################
# This file compares the runtime of different trees: simple binary search
# tree, Trie, Red-Black tree.
# Usage: ./compTrees
###############################################################################

if [ $# -lt 3 ]
then
  echo "Syntax: timeTree min_nodes max_nodes stp_nodes"
  echo "Default values: min_nodes = 100, max_nodes = 110101, stp_nodes = 10000"
  min_nodes=10000
  max_nodes=100001
  stp_nodes=10000
else
  min_nodes=$1
  max_nodes=$2
  stp_nodes=$3
  echo "min_nodes = $min_nodes, max_nodes = $max_nodes, stp_nodes = $stp_nodes"
fi

echo "BinT, Height, Num-Nodes, Time (s)"
for ((num_nodes = $min_nodes; num_nodes < $max_nodes; num_nodes += $stp_nodes))
do
  ./BinTComp $num_nodes ;
done

echo "Trie, Height, Num-Nodes, Time (s)"
for ((num_nodes = $min_nodes; num_nodes < $max_nodes; num_nodes += $stp_nodes))
do
  ./TrieComp $num_nodes ;
done

echo "RBT, Height, Num-Nodes, Time (s)"
for ((num_nodes = $min_nodes; num_nodes < $max_nodes; num_nodes += $stp_nodes))
do
  ./RBTComp $num_nodes ;
done
