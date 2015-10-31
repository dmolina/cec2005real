import pytest
from cec2005real.cec2005 import Function
import numpy as np

@pytest.fixture
def sol_zeros():
    return np.zeros(10)

## for f in range(1, 26):
##     b = Function(f, 10)
##     print(b.info())
##     f = b.get_eval_function()
##     x = np.zeros(10)
##     fitness = f(x)
##     print("fitness: {}".format(fitness))

def test_all_nozeros(sol_zeros):
    for fid in range(1,26):
        fn = Function(fid, 10).get_eval_function()
        assert fn(sol_zeros)  != 0

def testF4(sol_zeros):
    b = Function(4, 10)
    f = b.get_eval_function()
    result1 = f(sol_zeros)
    result2 = f(sol_zeros)
    assert result1 != result2
