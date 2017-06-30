# ee04-lora

This is a test project with Apache Mynewt that uses the EE-04 development board.


There are some key changes to the Apache Mynewt LoRa libraries:

* Enable AES encryption for messages (it was missing). The regular AES and CMAC
  libraries from the LoRaMac reference implementation is included but there's
  AES encryption libraries in Mynewt that should be used.
* Add the public network method (and corresponding SetPublicNetwork calls) to the
  radio driver.
* Bump the syncword timeout to 10x the regular. The time on air calculations and
  offset calculations in either the LoRaMac or Mynewt implementation is off by
  about 50 ms or more so the response from the gateway goes unnoticed. This
  will increase the power used by the receiver marginally but not by much (11mA
  for about 25-50ms). The same effect can be achieved by putting the receiver in
  continuous listen mode but then you'd have to upgrade the LoRaMac library to 
  a later version.

Pull the latest version of the Mynewt repo and place the changes from this repo
on top to patch the repo:

    rm project.state
    rm -fR repos
    newt upgrade
    git checkout repos/apache-mynewt-core/hw/drivers/lora/sx1276/src/sx1276-board.c \
        repos/apache-mynewt-core/hw/drivers/lora/sx1276/src/sx1276.c \
        repos/apache-mynewt-core/hw/drivers/lora/sx1276/src/sx1276.h \
        repos/apache-mynewt-core/net/lora/node/src/mac/LoRaMac.c

### Shell scripts

There's a few helper scripts included:
* `b.sh` builds the project
* `bd.sh` builds and deploys the project
* `jl.sh` launches the `JLinkExe` process to monitor the debug output

