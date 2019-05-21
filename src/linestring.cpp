#include "common.hpp"


template <typename PointT>
boost::geometry::model::linestring<PointT> create_from_vector(const std::vector<PointT> &array) {
    return boost::geometry::model::linestring<PointT>(array.begin(), array.end());
}


template <typename PointT>
void make_linestring(pybind11::handle scope, const std::string &suffix) {
    pybind11::class_<boost::geometry::model::linestring<PointT>>(scope, ("linestring" + suffix).c_str())
        .def(pybind11::init<>())
        .def(pybind11::init(&create_from_vector<PointT>))
        ;
}

void init_boost_geometry_linestring(pybind11::handle module) {
    make_linestring<point2dc>(module, "2dc");
    make_linestring<point3dc>(module, "3dc");
}
