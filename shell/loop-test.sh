#!/bin/bash

counter=1

#while [ $counter -le 10 ]
while true
do
    echo $counter
    ((counter++))
    sleep 0.1
done
