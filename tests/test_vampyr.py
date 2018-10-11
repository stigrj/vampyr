import os
import sys
sys.path.append(os.getenv('VAMPYR_MODULE_PATH'))

import vampyr as vp

def f(x):
    return x*x

x = 2.0

foo = vp.eval_func(0, f, x)
print("Output eval_func " + str(foo) + "\n")

bar = vp.eval_func(1, f, x)
print("Output eval_func " + str(bar) + "\n")
