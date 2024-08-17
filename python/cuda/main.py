import pycuda.autoinit
import pycuda.driver as cuda
import numpy as np
from pycuda.compiler import SourceModule

# Read the CUDA kernel code from file
with open("cuda_add.cu", "r") as f:
    cuda_code = f.read()

# Compile the CUDA kernel
mod = SourceModule(cuda_code)
add_func = mod.get_function("add")

# Initialize arrays
n = 1000000
a = np.random.randn(n).astype(np.float32)
b = np.random.randn(n).astype(np.float32)
c = np.empty_like(a)

# Allocate GPU memory and transfer data
a_gpu = cuda.mem_alloc(a.nbytes)
b_gpu = cuda.mem_alloc(b.nbytes)
c_gpu = cuda.mem_alloc(c.nbytes)
cuda.memcpy_htod(a_gpu, a)
cuda.memcpy_htod(b_gpu, b)

# Launch the kernel
block_size = 256
grid_size = (n + block_size - 1) // block_size
add_func(a_gpu, b_gpu, c_gpu, np.int32(n), block=(block_size, 1, 1), grid=(grid_size, 1))

# Transfer the result back to CPU
cuda.memcpy_dtoh(c, c_gpu)

# Verify the result
np.testing.assert_array_almost_equal(c, a + b)
print("Success! The result is correct.")
