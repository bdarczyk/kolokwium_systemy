#!/bin/bash

if [ -z "$1" ]; then
    echo "Podaj czas trwania symulowanego zadania"
    exit 1
fi

TIME=$1

sleep $TIME &
PID=$!

handler() {
    echo "Wykryto przerwanie (ctrl+c). Konczenie procesu potomnego..."
    kill $PID
    wait $PID
    exit 1
}

trap handler SIGINT

wait $PID
echo "Sukces: Proces zakonczyl sie naturalnie."