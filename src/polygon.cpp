#include "common.hpp"


template <typename PointT>
void make_polygon(pybind11::handle scope, const std::string &suffix) {
    typedef boost::geometry::model::polygon<PointT> polygon_t;
    pybind11::class_<polygon_t>(scope, ("polygon" + suffix).c_str())
        .def(pybind11::init<>())
        .def_property("inners",
            pybind11::cpp_function(static_cast<typename polygon_t::inner_container_type &(polygon_t::*)()>(&polygon_t::inners), pybind11::return_value_policy::reference_internal),
            pybind11::cpp_function([](polygon_t &self, const typename polygon_t::inner_container_type &container) { self.inners() = container; })
        )
        .def_property("outer",
            pybind11::cpp_function(static_cast<typename polygon_t::ring_type &(polygon_t::*)()>(&polygon_t::outer), pybind11::return_value_policy::reference_internal),
            pybind11::cpp_function([](polygon_t &self, const typename polygon_t::ring_type &ring) { self.outer() = ring; })
        )
        .def("clear", &polygon_t::clear)
        ;
}

void init_boost_geometry_polygon(pybind11::handle module) {
    make_polygon<point2dc>(module, "2dc");
    make_polygon<point3dc>(module, "3dc");
}
