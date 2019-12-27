#!/bin/bash

if [ "$1" = "reset" ]; then
    sed -i 's/used/*/g' parts/weapon.txt
    sed -i 's/used/*/g' parts/helmet.txt
    sed -i 's/used/*/g' parts/armor.txt
    sed -i 's/used/*/g' parts/necklace.txt
    sed -i 's/used/*/g' parts/ring.txt
    sed -i 's/used/*/g' parts/boots.txt
    exit 0
fi

[ -z "$1" ] && echo "\$1 Empty" && exit 1 || sed -i $(($1+1))'s/*/used/g' parts/weapon.txt
[ -z "$2" ] && echo "\$2 Empty" && exit 1 || sed -i $(($2+1))'s/*/used/g' parts/helmet.txt
[ -z "$3" ] && echo "\$3 Empty" && exit 1 || sed -i $(($3+1))'s/*/used/g' parts/armor.txt
[ -z "$4" ] && echo "\$4 Empty" && exit 1 || sed -i $(($4+1))'s/*/used/g' parts/necklace.txt
[ -z "$5" ] && echo "\$5 Empty" && exit 1 || sed -i $(($5+1))'s/*/used/g' parts/ring.txt
[ -z "$6" ] && echo "\$6 Empty" && exit 1 || sed -i $(($6+1))'s/*/used/g' parts/boots.txt

echo "done"