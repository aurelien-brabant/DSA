#! /bin/sh

# Generate a BSQ map given its x and y dimensions.
# Each cell has either the value 0 or 1.

if [ $# -ne 2 ]; then
	printf "USAGE: ./genmap <x> <y>\n";
	exit 1
fi

x=$1; y=$2

printf "${x}x${y}\n"

for i in $(seq 1 $y);
do
	for i in $(seq 1 $x);
	do
		r=$((RANDOM % 2))
		[ $r -eq 0 ] && printf '0' || printf '1'
	done
	printf '\n';
done
