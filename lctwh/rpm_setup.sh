#!/bin/sh
echo "System set-up for RPM based system"
su -c "yum groupinstall development-tools"
