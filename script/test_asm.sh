#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

#Path Champion
DIR="../champions/champs"

# Check if asm is in current dir and put it where it belong
if [ -f ../asm ]
then cp ../asm ./resources/bin/
fi

# Create directory
if [ -d log ]
then rm -rf log
fi
mkdir log

#delete .cor
rm -f $DIR/*.cor

# Assemble Champions
for champion in $DIR/*.s
do
	name=$(basename "$champion" .s)
	./resources/bin/asm_zaz $champion &> ./log/${name}.zaz.log
	mv $DIR/${name}.cor $DIR/${name}.zaz.cor
	./resources/bin/asm $champion &> ./log/${name}.log
done

# Compare asm output
for champion in ./log/*.zaz.log
do
	clear
	name=$(basename "$champion" .zaz.log)
	DIFF=$(diff  ./log/${name}.log ./log/${name}.zaz.log)
	printf "${name}\n"
	if [ "$DIFF" == "" ]
	then
		echo "${GREEN}No difference${NC}"
	else
		echo "${RED}$DIFF${NC}"
	fi
	read -n 1 -s -p "Press any key to continue"
	printf "\n"
done

# Compare champion binary files
for champion in $DIR/*.zaz.cor
do
	rm -f champion chapion_zaz
	name=$(basename "$champion" .zaz.cor)
	hexdump -C $DIR/${name}.cor > champion
	hexdump -C $DIR/${name}.zaz.cor > champion_zaz
	if [ ! -f $DIR/${name}.cor ]
		then echo "NULL" > champion
	fi
	if [ ! -f $DIR/${name}.zaz.cor ]
		then echo "NULL" > champion_zaz
	fi
	cols=80
	lines=0
	clear
	while read -r a && read -r b <&3;
	do
		if [[ "$a" == "$b" ]]
			then printf "${GREEN}"
			tput cup $lines 0
			printf "%s" "$a"
			tput cup $lines $cols
			printf "%s" "$b"
			printf "${NC}\n";
		else
			printf "${RED}"
			tput cup $lines 0
			printf "%s" "$a"
			tput cup $lines $cols
			printf "%s" "$b"
			printf "${NC}\n";
		fi
		lines=$(($lines+1))
 	done < champion 3<champion_zaz
 	echo $name
	read -n 1 -s -p "Press any key to continue"
	printf "\n"
done
