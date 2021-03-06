//
// TM & (c) 2017 Lucasfilm Entertainment Company Ltd. and Lucasfilm Ltd.
// All rights reserved.  See LICENSE.txt for license.
//

#include <PyMaterialX/PyMaterialX.h>

#include <MaterialXFormat/XmlIo.h>
#include <MaterialXCore/Document.h>

#include <PyBind11/operators.h>

namespace py = pybind11;
namespace mx = MaterialX;

void bindPyXmlIo(py::module& mod)
{
    mod.def("readFromXmlFileBase", &mx::readFromXmlFile,
        py::arg("doc"), py::arg("filename"), py::arg("searchPath") = mx::EMPTY_STRING, py::arg("readXIncludes") = true);
    mod.def("readFromXmlString", &mx::readFromXmlString);
    mod.def("writeToXmlFile", mx::writeToXmlFile,
        py::arg("doc"), py::arg("filename"), py::arg("writeXIncludes") = true, py::arg("predicate") = mx::ElementPredicate());
    mod.def("writeToXmlString", mx::writeToXmlString,
        py::arg("doc"), py::arg("writeXIncludes") = true, py::arg("predicate") = mx::ElementPredicate());
    mod.def("prependXInclude", mx::prependXInclude);

    py::register_exception<mx::ExceptionParseError>(mod, "ExceptionParseError");
    py::register_exception<mx::ExceptionFileMissing>(mod, "ExceptionFileMissing");
}
