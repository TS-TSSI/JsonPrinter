Conda C++ package test:

Builds a test Json printer both as an executable utility and as a shared library, exercising
Conda's per-environment binaries in both executable and library forms.
It uses JsonCpp, linked statically for the Json parsing functionality.

After installing the package, the executable utility can be tested using: 'jsonprinter'
from the command line of a Conda environment where the package is installed.
Usage of the library can be tested with the test app testapp.py, or by manually loading
'libjsonprinter.so' using dynamic load mechanisms.