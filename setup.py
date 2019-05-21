import os, sys

from distutils.core import setup
from distutils.command import build_ext

from distutils.core import Extension

import pybind11

ext_name = "boost_geometry"

py_ver = sys.version_info[:2]

include_dirs = [
    "./include",
    pybind11.get_include(),
]
libraries = []

library_dirs = []

sources = []

source_path = "./src/"
for dirname, dirs, filenames in os.walk(source_path):
    for filename in sorted(filenames):
        if not filename.lower().endswith(".cpp"):
            continue
        sources.append(os.path.join(dirname, filename))
    break

extras = [
    "-std=c++14",
]

ext = Extension(name="{0}.__{0}".format(ext_name),
                include_dirs=include_dirs,
                libraries=libraries,
                library_dirs=library_dirs,
                sources=sources,
                extra_compile_args=extras)


setup(
    name=ext_name,
    packages=[ext_name],
    license="BSL-1.0",
    classifies=[
        "Development Status :: 4 - Beta",
        "Intended Audience :: Developers",
        "License :: OSI Approved :: Boost Software License 1.0 (BSL-1.0)",
        "Programming Language :: Python :: 3.6",
    ],
    ext_modules=[ext],
)
