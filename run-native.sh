#!/bin/bash

jdk="/usr/lib/jvm/java-11-oracle" 
export LD_LIBRARY_PATH="$jdk/lib/server/" 
 
./bin/launch 

