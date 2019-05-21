#pragma once

#include <pybind11/pybind11.h>

#include <pybind11/stl.h>

#include <boost/geometry.hpp>

typedef boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian> point2dc;
typedef boost::geometry::model::point<double, 3, boost::geometry::cs::cartesian> point3dc;
typedef boost::geometry::model::linestring<point2dc> linestring2dc;
typedef boost::geometry::model::linestring<point3dc> linestring3dc;
typedef boost::geometry::model::polygon<point2dc> polygon2dc;
typedef boost::geometry::model::polygon<point3dc> polygon3dc;

typedef boost::geometry::model::multi_point<point2dc> multi_point2dc;
typedef boost::geometry::model::multi_point<point3dc> multi_point3dc;
typedef boost::geometry::model::multi_linestring<linestring2dc> multi_linestring2dc;
typedef boost::geometry::model::multi_linestring<linestring3dc> multi_linestring3dc;
typedef boost::geometry::model::multi_polygon<polygon2dc> multi_polygon2dc;
typedef boost::geometry::model::multi_polygon<polygon3dc> multi_polygon3dc;
typedef boost::geometry::model::box<point2dc> box2dc;
typedef boost::geometry::model::box<point3dc> box3dc;
typedef boost::geometry::model::ring<point2dc> ring2dc;
typedef boost::geometry::model::ring<point3dc> ring3dc;
typedef boost::geometry::model::ring<point2dc, true, true> closed_clockwise_ring2dc;
typedef boost::geometry::model::ring<point2dc, false, true> closed_counterclockwise_ring2dc;
typedef boost::geometry::model::ring<point2dc, true, false> open_clockwise_ring2dc;
typedef boost::geometry::model::ring<point2dc, false, false> open_counterclockwise_ring2dc;
typedef boost::geometry::model::ring<point3dc, true, true> closed_clockwise_ring3dc;
typedef boost::geometry::model::ring<point3dc, false, true> closed_counterclockwise_ring3dc;
typedef boost::geometry::model::ring<point3dc, true, false> open_clockwise_ring3dc;
typedef boost::geometry::model::ring<point3dc, false, false> open_counterclockwise_ring3dc;
typedef boost::geometry::model::segment<point2dc> segment2dc;
typedef boost::geometry::model::segment<point3dc> segment3dc;
