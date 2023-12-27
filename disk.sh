#!/bin/bash

threshold=90
recipient="your_email@test.com"
subject="Disk Space Alert"
body="Your disk space is running low. Please take action."

# Get the current disk usage
disk_usage=$(df -H /dev/sda1 | awk 'NR==2 { print $5}' | sed 's/%//')

echo "Disk usage retrieved: $disk_usage"  
if [ -z "$disk_usage" ]; then
    echo "Error: Disk usage value not found or empty."
    exit 1
fi

# Check if disk usage exceeds the threshold
if [ "$disk_usage" -ge "$threshold" ]; then
    echo "Disk space is running low. Current usage: $disk_usage%"
    # Send an email alert
    echo "$body" | mail -s "$subject" "$recipient"
else
    echo "Disk space is within acceptable limits. Current usage: $disk_usage%"
fi
