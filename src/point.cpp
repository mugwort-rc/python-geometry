#include "common.hpp"


template <typename PointT, typename T>
void make_point2d(pybind11::handle scope, const std::string &suffix) {
    typedef PointT point_t;
    pybind11::class_<point_t>(scope, ("point2" + suffix).c_str())
        .def(pybind11::init<>())
        .def(pybind11::init<const T &>())
        .def(pybind11::init<const T &, const T &>())
        .def_property("x", &point_t::template get<0>, &point_t::template set<0>)
        .def_property("y", &point_t::template get<1>, &point_t::template set<1>)
        ;
}

template <typename PointT, typename T>
void make_point3d(pybind11::handle scope, const std::string &suffix) {
    typedef PointT point_t;
    pybind11::class_<point_t>(scope, ("point3" + suffix).c_str())
        .def(pybind11::init<>())
        .def(pybind11::init<const T &>())
        .def(pybind11::init<const T &, const T &>())
        .def(pybind11::init<const T &, const T &, const T &>())
        .def_property("x", &point_t::template get<0>, &point_t::template set<0>)
        .def_property("y", &point_t::template get<1>, &point_t::template set<1>)
        .def_property("z", &point_t::template get<2>, &point_t::template set<2>)
        ;
}

void init_boost_geometry_point(pybind11::handle module) {
    make_point2d<point2dc, double>(module, "dc");
    make_point3d<point3dc, double>(module, "dc");
}
