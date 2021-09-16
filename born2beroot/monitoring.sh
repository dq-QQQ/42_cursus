#!/bin/bash

printf "#Architecture: "
uname -a

printf "#CPU physical : "
grep  "physical id" /proc/cpuinfo | uniq | wc -l

printf "#vCPU : "
grep -c processor /proc/cpuinfo

printf "#Memory Usage: "
free -m |grep Mem |awk '{printf "%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 *100}'

printf "#Disk Usage: "
df -Bm |grep /dev/mapper/ | awk '{usedisk+=$3} END {printf "%d/", usedisk}' | tr -d '\n'

df -Bg |grep /dev/mapper/ | awk '{fulldisk += $2} END {printf "%dGb (", fulldisk}' | tr -d '\n'

df -Bm |grep /dev/mapper/ | awk '{fulldisk += $2} {usedisk += $3} END {printf "%d%%)\n", usedisk/fulldisk * 100}'

printf "#CPU load: "
grep 'cpu ' /proc/stat |awk '{use=($2 + $4)/($2+$4+$5) * 100} END {print use "%"}'

printf "#Last boot: "
uptime -s

printf "#LVM use: "
if [ "$(lsblk | grep lvm |wc -l)" -eq 0]; then printf "no\n"; else printf "yes\n"; fi

printf "#Connections TCP : "
ss | grep -i tcp | wc -l | tr -d '\n'
printf " ESTABLISHED\n"

printf "#User log: "
who |wc -l

printf "#Network: IP "
hostname -I |tr -d '\n'
printf "("
ip link show | grep ether |awk '{print $2}' |sed -n '1p'| tr -d '\n'
printf ")\n"

printf "#Sudo : "
cat /var/log/sudo/sudo.log |grep 'COMMAND=' |wc -l |tr -d '\n'
printf " cmd\n"
