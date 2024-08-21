#!/usr/bin/env python

import os, sys, time

# ./i2cget -y 2 0x2d 1

i2c_bus = 2
chip_addr = 0x2d

def set_register(filename):
    for l in file(filename).readlines():
        params = l.strip().split(" ")

        if params[0] == 'sleep':
            sec = int(params[1])
            print "sleep %s" % sec
            time.sleep(sec);
        else:
            # i2cset i2cbus chip-address data-address [value] [mode]
            cmd = "/home/root/tools/i2cset -y %s %s %s %s b" % (i2c_bus, chip_addr, params[0], params[1])
            print cmd
            #os.system(cmd)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print "need reg file"
    else:
        print "reg file:" + sys.argv[1]
        set_register(sys.argv[1])
