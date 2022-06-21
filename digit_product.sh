#!/bin/bash

read -p "Enter Number: " num
prod=1
while [ $num -gt 0 ]
do
mod=`expr $num % 10`
prod=`expr $prod \* $mod`
num=`expr $num / 10`
done
echo "Digit Product is: $prod"
