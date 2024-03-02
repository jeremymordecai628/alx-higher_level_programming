#!/bin/bash
# Sends a request to a URL and displays the size of the body of the response

URL=$1
SIZE=$(curl -sI $URL | grep -i Content-Length | awk '{print $2}')
echo $SIZE
