echo "Enter Numbers: "
read -a int
big=${int[0]}
sma=${int[0]}

for i in ${int[@]}
do
if [[ $i -gt $big ]]
then
big=$i
fi

if [[ $i -lt $sma ]]
then
sma=$i
fi
done

echo "Biggest : $big"
echo "Smallest: $sma"
