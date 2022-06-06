static PyMethodDef AstroMethods[] = {

    /* When using only METH_VARARGS, the function should expect the
    Python-level parameters to be passed in as a tuple acceptable for parsing via PyArg_ParseTuple() */
    {"function_name", function_name, METH_VARARGS, "Perform a function."},
    .
        .
        .
        .{NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef astromodule = {
    PyModuleDef_HEAD_INIT,
    "astro",                      /* name of module */
    "Astronomical calculations.", /* module documnetation, maybe NULL */
    -1,                           /* size of per-interpreter state of the module,
                                      or -1 if the module keeps state in global variables. */
    AstroMethods};

/*
The initialization function must be named PyInit_name(), where name is the name of the module, and should be the
only non-static item defined in the module file.
PyMODINIT_FUNC declares the function as PyObject * return type,
declares any special linkage declarations required by the platform.
*/
PyMODINIT_FUNC
PyInit_spam(void)
{
    /* PyModule_Create(), which returns a module object, and inserts built-in function objects into the newly created
    module based upon the table (an array of PyMethodDef structures) found in the module definition. */
    return PyModule_Create(&astromodule);
}