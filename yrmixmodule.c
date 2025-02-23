#include <Python.h>

#include "yrmix.h"

static PyObject *yrmix_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    yrmix_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    yrmix_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef YrmixMethods[] = {
    { "getPoWHash", yrmix_getpowhash, METH_VARARGS, "Returns the proof of work hash using yrmix hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef YrmixModule = {
    PyModuleDef_HEAD_INIT,
    "yrmix_hash",
    "...",
    -1,
    YrmixMethods
};

PyMODINIT_FUNC PyInit_yrmix_hash(void) {
    return PyModule_Create(&YrmixModule);
}

#else

PyMODINIT_FUNC inityrmix_hash(void) {
    (void) Py_InitModule("yrmix_hash", YrmixMethods);
}
#endif
