#!/bin/sh
PATH_BIN=`dirname $0`
ROOT=`dirname $PATH_BIN`
PATH_LIB="$PATH_BIN"
export LD_LIBRARY_PATH="$PATH_LIB:$LD_LIBRARY_PATH"
ulimit -c 999999999999
cd "$(dirname "$0")"
#exec "$PATH_BIN/tstconsole" 
exec "./tstconsole" 

