#!/bin/bash
# connect-wifi.sh - Bring up wlp58s0, associate, and get an IP.

IFACE="wlp58s0" # change this to how its recognized . run ( ip addr show )
WPA_CONF="/etc/wpa_supplicant.conf"
UDHCPC_SCRIPT="/usr/share/udhcpc/default.script"
GATEWAY="192.X.X.X"   # change if your router's IP differs

echo "== Step 1: loading driver =="
modprobe iwlwifi

echo "== Step 2: interface list =="
ip a

echo "== Step 3: bringing $IFACE up =="
ip link set "$IFACE" up

echo "== Step 4: starting wpa_supplicant =="
# kill any old instance first so we don't get a "already running" error
pkill wpa_supplicant 2>/dev/null
sleep 1
wpa_supplicant -B -i "$IFACE" -c "$WPA_CONF"
sleep 2

echo "== Step 5: requesting DHCP lease =="
busybox udhcpc -i "$IFACE" -s "$UDHCPC_SCRIPT"

echo "== Step 6: checking if IP was applied =="
ip a show "$IFACE"

echo
CURRENT_IP=$(ip -4 addr show "$IFACE" | grep -oP '(?<=inet\s)\d+(\.\d+){3}')

if [ -z "$CURRENT_IP" ]; then
    echo "!! No IP was applied automatically."
    echo "   Look at the 'lease of X.X.X.X obtained' line above."
    read -p "Enter the leased IP address (e.g. 192.X.X.X): " MANUAL_IP
    if [ -n "$MANUAL_IP" ]; then
        ip addr add "${MANUAL_IP}/24" dev "$IFACE"
        ip route add default via "$GATEWAY" dev "$IFACE"
        echo "Applied $MANUAL_IP manually with gateway $GATEWAY"
    else
        echo "No IP entered, skipping manual assignment."
    fi
else
    echo "IP already applied: $CURRENT_IP"
fi

echo
echo "== Testing connectivity =="
ping -c 3 8.8.8.8
