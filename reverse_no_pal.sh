#!/bin/bash

read -p "Enter Number: " n
x=$n
sd=0
rev=0
while [ $n -gt 0 ]
do
sd=$(( $n % 10 ))
rev=$(( $rev * 10 + $sd ))
n=$(( $n / 10 ))
done

if [ $x -eq $rev ]
then
echo "Palindrome"
else
echo "Not Palindrome"
fi
