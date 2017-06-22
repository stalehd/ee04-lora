#!/bin/bash

# Create a new project
newt new ee04-lora
cd ee04-lora/

#
# Switch to the develop branch
#
cd repos/apache-mynewt-core/
git checkout develop
cd ../..

#
# Create the boot loader
#
newt target create ee04_boot
newt target set ee04_boot app@apache-mynewt-core/apps/boot
newt target set ee04_boot app=@apache-mynewt-core/apps/boot
newt target set ee04_boot bsp=@apache-mynewt-core/hw/bsp/telee02
newt target set ee04_boot build_profile=optimized

#
# Create the lora target
#
newt target create ee04-lora
newt target set ee04-lora app=apps/blinky
newt target set ee04-lora bsp=@apache-mynewt-core/hw/bsp/telee02
newt target set ee04-lora build_profile=debug


#
# Remove the blinky sim (you won't need it)
#
newt target delete my_blinky_sim

#
# ....and build
#
newt build ee04_boot
newt build ee04-lora
newt load ee04_boot
newt create-image ee04-lora 0.0.0.1
newt load ee04-lora
# Do
#
#   newt target show
#
# to see the targets that have been built