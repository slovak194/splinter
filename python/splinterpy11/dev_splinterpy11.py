import os, sys

sys.path.extend([os.getcwd()+"python/splinterpy11"])
from splinterpy import splinterpy11

import tempfile
import splinterpy
import numpy as np
from itertools import product
np.set_printoptions(suppress=True)


def some_fun(lx):
    return np.array((
        np.sin(lx[0] + lx[1]),
        np.cos(lx[0] - lx[1]),
        np.tan(lx[0]/lx[1])
    )).tolist()


domain = [
    np.linspace(-1, 1, 10),
    np.linspace(-1, 1, 10)
]

x = [list(xx) for xx in product(*domain)]
y = [some_fun(xx) for xx in x]

bspline = splinterpy.bspline_interpolator(x, y, degree=3)

p = np.array((0.7, -0.1))

print("\nbspline.eval:\n", bspline.eval(p))
print("\nbspline.eval_jacobian:\n", bspline.eval_jacobian(p))

with tempfile.NamedTemporaryFile() as temp:
    bspline.to_json(temp.name)

    bspline11 = splinterpy11.BSpline(temp.name)
    print("\nbspline11.eval:\n", bspline11.eval(p))
    print("\nbspline11.eval_jacobian:\n", bspline11.eval_jacobian(p))
