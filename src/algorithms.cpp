#include <pybind11/pybind11.h>

#include "common.hpp"


template <typename GeometryT>
void init_common2d_algorithms(pybind11::module scope) {
    scope
        .def("area", &boost::geometry::area<GeometryT>)
        // disjoint
        .def("disjoint", &boost::geometry::disjoint<GeometryT, point2dc>)
        .def("disjoint", &boost::geometry::disjoint<GeometryT, segment2dc>)
        .def("disjoint", &boost::geometry::disjoint<GeometryT, box2dc>)
        .def("disjoint", &boost::geometry::disjoint<GeometryT, linestring2dc>)
        // NG: MultiPoint .def("disjoint", &boost::geometry::disjoint<GeometryT, ring2dc>)
        // NG: MultiPoint .def("disjoint", &boost::geometry::disjoint<GeometryT, polygon2dc>)
        // NG: Ring, Polygon, MultiPolygon, Variant .def("disjoint", &boost::geometry::disjoint<GeometryT, multi_point2dc>)
        .def("disjoint", &boost::geometry::disjoint<GeometryT, multi_linestring2dc>)
        // NG: MultiPoint .def("disjoint", &boost::geometry::disjoint<GeometryT, multi_polygon2dc>)
        // intersects
        .def("intersects", &boost::geometry::intersects<GeometryT, point2dc>)
        .def("intersects", &boost::geometry::intersects<GeometryT, segment2dc>)
        .def("intersects", &boost::geometry::intersects<GeometryT, box2dc>)
        .def("intersects", &boost::geometry::intersects<GeometryT, linestring2dc>)
        .def("intersects", &boost::geometry::intersects<GeometryT, ring2dc>)
        .def("intersects", &boost::geometry::intersects<GeometryT, polygon2dc>)
        .def("intersects", &boost::geometry::intersects<GeometryT, multi_point2dc>)
        .def("intersects", &boost::geometry::intersects<GeometryT, multi_linestring2dc>)
        .def("intersects", &boost::geometry::intersects<GeometryT, multi_polygon2dc>)
        ;
}

template <typename GeometryT>
void init_2axis_algorithms(pybind11::module scope) {
    scope
        .def("intersects", &boost::geometry::intersects<GeometryT>)
        ;
}


void init_point_algorithms(pybind11::module scope) {
    init_common2d_algorithms<point2dc>(scope);

    scope
        .def("disjoint", &boost::geometry::disjoint<point2dc, ring2dc>)
        .def("disjoint", &boost::geometry::disjoint<point2dc, polygon2dc>)
        .def("disjoint", &boost::geometry::disjoint<point2dc, multi_point2dc>)
        .def("disjoint", &boost::geometry::disjoint<point2dc, multi_linestring2dc>)
        .def("disjoint", &boost::geometry::disjoint<point2dc, multi_polygon2dc>)
        .def("within", &boost::geometry::within<point2dc, point2dc>)
        .def("within", &boost::geometry::within<point2dc, segment2dc>)
        .def("within", &boost::geometry::within<point2dc, box2dc>)
        .def("within", &boost::geometry::within<point2dc, linestring2dc>)
        .def("within", &boost::geometry::within<point2dc, ring2dc>)
        .def("within", &boost::geometry::within<point2dc, polygon2dc>)
        .def("within", &boost::geometry::within<point2dc, multi_point2dc>)
        .def("within", &boost::geometry::within<point2dc, multi_linestring2dc>)
        .def("within", &boost::geometry::within<point2dc, multi_polygon2dc>)
        ;
}

void init_linestring_algorithms(pybind11::module scope) {
    init_common2d_algorithms<linestring2dc>(scope);
    init_2axis_algorithms<linestring2dc>(scope);

    scope
        .def("disjoint", &boost::geometry::disjoint<linestring2dc, ring2dc>)
        .def("disjoint", &boost::geometry::disjoint<linestring2dc, polygon2dc>)
        .def("disjoint", &boost::geometry::disjoint<linestring2dc, multi_point2dc>)
        .def("disjoint", &boost::geometry::disjoint<linestring2dc, multi_linestring2dc>)
        .def("disjoint", &boost::geometry::disjoint<linestring2dc, multi_polygon2dc>)
        .def("within", &boost::geometry::within<linestring2dc, linestring2dc>)
        .def("within", &boost::geometry::within<linestring2dc, ring2dc>)
        .def("within", &boost::geometry::within<linestring2dc, polygon2dc>)
        .def("within", &boost::geometry::within<linestring2dc, multi_linestring2dc>)
        .def("within", &boost::geometry::within<linestring2dc, multi_polygon2dc>)
        ;
}

void init_polygon_algorithms(pybind11::module scope) {
    init_common2d_algorithms<polygon2dc>(scope);
    init_2axis_algorithms<polygon2dc>(scope);

    scope
        .def("disjoint", &boost::geometry::disjoint<polygon2dc, ring2dc>)
        .def("disjoint", &boost::geometry::disjoint<polygon2dc, polygon2dc>)
        // NG: .def("disjoint", &boost::geometry::disjoint<polygon2dc, multi_point2dc>)
        .def("disjoint", &boost::geometry::disjoint<polygon2dc, multi_linestring2dc>)
        .def("disjoint", &boost::geometry::disjoint<polygon2dc, multi_polygon2dc>)
        .def("within", &boost::geometry::within<polygon2dc, ring2dc>)
        .def("within", &boost::geometry::within<polygon2dc, polygon2dc>)
        .def("within", &boost::geometry::within<polygon2dc, multi_polygon2dc>)
        ;
}


void init_boost_geometry_algorithms(pybind11::module scope) {
    init_point_algorithms(scope);
    init_linestring_algorithms(scope);
    init_polygon_algorithms(scope);
}
