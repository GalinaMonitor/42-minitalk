#!/bin/bash

rm tests/traces
touch tests/traces
pid=$1
emptyStr=""
if [ "$pid" = "$emptyStr" ]
then
echo 'Please, enter server PID as an argument'
else
echo 'PID = '$pid
fi

echo Sending small string: 12345
time ./client $pid $'\n' > tests/traces

echo Sending 100s
text=`cat ./tests/100s`
time ./client $pid "$text" > tests/traces

echo Sending 1000s
text=`cat ./tests/1000s`
time ./client $pid "$text" > tests/traces

echo Sending 5000s
text=`cat ./tests/5000s`
time ./client $pid "$text" > tests/traces

echo Sending 10000s
text=`cat ./tests/10000s`
time ./client $pid "$text" > tests/traces

echo Sending 30000s
text=`cat ./tests/30000s`
time ./client $pid "$text" > tests/traces
