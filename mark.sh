#!/bin/bash

[ -z "$1" ] && echo "\$1 Empty" && exit 1 || sed -i $1's/*/@/g' parts/weapon.txt
[ -z "$2" ] && echo "\$2 Empty" && exit 1 || sed -i $2's/*/@/g' parts/helmet.txt
[ -z "$3" ] && echo "\$3 Empty" && exit 1 || sed -i $3's/*/@/g' parts/armor.txt
[ -z "$4" ] && echo "\$4 Empty" && exit 1 || sed -i $4's/*/@/g' parts/necklace.txt
[ -z "$5" ] && echo "\$5 Empty" && exit 1 || sed -i $5's/*/@/g' parts/ring.txt
[ -z "$6" ] && echo "\$6 Empty" && exit 1 || sed -i $6's/*/@/g' parts/boots.txt
echo "done"