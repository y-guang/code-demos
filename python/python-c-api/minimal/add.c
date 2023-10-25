#define PY_SSIZE_T_CLEAN
#include <Python.h> // intro before all other lib

static PyObject* add(PyObject* self, PyObject* args)
{
    double a, b, out;

    // parse
    if(!PyArg_ParseTuple(args, "dd", &a, &b)) {
        return NULL;
    }

    out = a + b;

    return Py_BuildValue("d", out);
}

// Method table mapping function names to C functions
static PyMethodDef AddMethods[] = {
    {"add", add, METH_VARARGS, "Add two double."},
    {NULL, NULL, 0, NULL}
};

// Module definition
static struct PyModuleDef addmodule = {
    PyModuleDef_HEAD_INIT,
    "addmodule",  // name of module
    NULL,         // module documentation, may be NULL
    -1,           // size of per-interpreter state of the module
    AddMethods    // the methods of the module
};

// Module initialization
PyMODINIT_FUNC PyInit_addmodule(void) {
    return PyModule_Create(&addmodule);
}