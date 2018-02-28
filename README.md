# 2048 for Nintendo 64

Port of [2048](https://gabrielecirulli.github.io/2048/) game created
by [Gabriele Cirulli](https://gabrielecirulli.com/) for N64.

Support for Rumble Pak :D

![game](./misc/screenshot.png?raw=true)


## Installation

[Download](./Memory64.z64?raw=true) or compile the ROM file and load it as
you would any other N64 ROM.

This ROM file has been tested to work on real Nintendo 64 hardware using the
[EverDrive-64 by krikzz](http://krikzz.com/). It should also work with
[64drive by retroactive](http://64drive.retroactive.be/).

This ROM file is only known to work on low-level, high-accuracy Nintendo 64
emulators such as [CEN64](https://cen64.com/) or [MAME](http://mamedev.org/)
due to the use of [libdragon](https://dragonminded.com/n64dev/libdragon/)
instead of the proprietary SDK used by official licensed Nintendo software.


## Building

In order to build you will need the following open-source software installed:

 * [conker64's fork of libdragon development toolchain](https://github.com/conker64/libdragon)

Run `make` to produce the `2048-64.z64` ROM file from this source tree.

You can run `make docker` to use [Docker](https://docker.com).

## Thanks

Thanks to [Shaun Taylor](https://github.com/DragonMinded) for libdragon.
Thanks to [conker64](https://github.com/conker64) and the [#n64dev](irc://irc.efnet.org/#n64dev) IRC community for their help.
Thanks to [Christopher Bonhage](https://github.com/meeq) for his work on [FlappyBird-N64](https://github.com/meeq/FlappyBird-N64).