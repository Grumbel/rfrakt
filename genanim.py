#!/usr/bin/env python3

import subprocess
import os


if __name__ == "__main__":
    for i in range(1000, 10000):
        outfile = "/tmp/rfract/%08d.pgm" % i
        with open(outfile, "w") as fout:
            zoom = 0.001 * i
            print(i)
            subprocess.call(["build/rfrakt", str(zoom)], stdout=fout)
            subprocess.call(["convert", outfile, outfile + ".jpg"])
            os.remove(outfile)

# EOF #
