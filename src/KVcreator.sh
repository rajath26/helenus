#!/bin/bash


exec 5< $1

COUNTER=0

while read -u5 line
do

        COUNTER=`expr $COUNTER + 1`
	KEY=`echo ${line} | tr -s ' ' | cut -d, -f1`
        VALUE=`echo ${line} | tr -s ' ' | cut -d, -f2`

        LENGTH=`echo ${VALUE} | wc -c`

        if [ ${LENGTH} -lt 200 ]
        then 
            ./KVclient 4001 130.126.112.107 3492 "INSERT:::${KEY}:::${VALUE}" 1
        else
            echo "NOT CALLING COMMAND"
        fi

        if [ ${COUNTER} -eq 200 ]
        then
            sleep 1
            COUNTER=0
        fi

done
