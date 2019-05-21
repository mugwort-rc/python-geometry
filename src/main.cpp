#include <pybind11/pybind11.h>

extern void init_boost_geometry_point(pybind11::handle);
extern void init_boost_geometry_linestring(pybind11::handle module);
extern void init_boost_geometry_polygon(pybind11::handle module);
extern void init_boost_geometry_algorithms(pybind11::module module);

PYBIND11_MODULE(__boost_geometry, module) {
    init_boost_geometry_point(module);
    init_boost_geometry_linestring(module);
    init_boost_geometry_polygon(module);
    init_boost_geometry_algorithms(module);
}
