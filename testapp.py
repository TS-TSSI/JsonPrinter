import ctypes
import os

if __name__ == "__main__":
    # Using absolute library path in order to avoid discouraged modification of LD_LIBRARY_PATH
    # based on https://github.com/conda/conda/issues/12800
    libPath = os.environ["CONDA_PREFIX"] + "/lib/libjsonprinter.so"
    LibJsonPrinter = ctypes.CDLL(libPath) # Load it
    LibJsonPrinter.TestJsonPrinter() # Call it!