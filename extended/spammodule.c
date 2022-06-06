/* 
* Since Python may define some pre-processor definitions which affect the standard
* headers on some systems, you must include Python.h before any standard
* headers are included
* It is recommended to always define PY_SSIZE_T_CLEAN before including Python.h. 
*/
# define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <string.h>

/* Declaring a new expception that is unique to this module. it is initialized 
   in the init function of the module. */
static PyObject *SpamError;


/*
The C function always has two arguments, conventionally named self and args.
The self argument points to the module object for module-level functions;
for a method it would point to the object instance.
The args argument will be a pointer to a Python tuple object containing the
arguments.
*/
static
PyObject* spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    /* The function PyArg_ParseTuple() in the Python API checks the argument types and
    converts them to C values. It uses a template string to determine the required
    types of the arguments as well as the types of the C variables into which to
    store the converted values.
    It returns NULL (the error indicator for functions returning object pointers)
    if an error is detected in the argument list, relying on the exception set by
    PyArg_ParseTuple(). */
    if(!PyArg_ParseTuple(args,"s", &command))
        return NULL;

    /* Call to the Unix function system(), passing it the string we just got from PyArg_ParseTuple() */
    sts = system(command);

    if (sts < 0)
    {
        /* The first argument specifies the exception type
         The second argument is an error message*/
        PyErr_SetString(SpamError, "Ssytem Command Failed");
        return NULL;
    }

    /* Our spam.system() function must return the value of sts as a Python object.
    This is done using the function PyLong_FromLong(). */
    return PyLong_FromLong(sts);

    /* If you have a C function that returns no useful argument (a function returning void),
    the corresponding Python function must return None. This can eb doen using:
    Py_INCREF(Py_None);
    return Py_None; */
}

static PyMethodDef SpamMethods[] = {

    /* When using only METH_VARARGS, the function should expect the
    Python-level parameters to be passed in as a tuple acceptable for parsing via PyArg_ParseTuple() */
    {"system", spam_system,METH_VARARGS,"Execute a Shell command."},
    {NULL,NULL,0,NULL} /* Sentinel */
};
    
static 
struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam", /* name of module */
    "Detect spam.", /* module documnetation, maybe NULL */
    -1, /* size of per-interpreter state of the module,
            or -1 if the module keeps state in global variables. */
    SpamMethods
};

/*
The initialization function must be named PyInit_name(), where name is the name of the module, and should be the
only non-static item defined in the module file.
PyMODINIT_FUNC declares the function as PyObject * return type, 
declares any special linkage declarations required by the platform.
*/
PyMODINIT_FUNC
PyInit_spam(void)
{
    PyObject *m;

    m = PyModule_Create(&spammodule);
    if (m == NULL)
        return NULL;

    /* creates and returns a new exception class.
       The name argument must be the name of the new exception, a C string of the form module.classname.
       The base and dict arguments are normally NULL.
       This creates a class object derived from "Exception" */
    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_XINCREF(SpamError);
    if (PyModule_AddObject(m, "error", SpamError) < 0) {
        Py_XDECREF(SpamError);
        Py_CLEAR(SpamError);
        Py_DECREF(m);
        return NULL;
    }
    /* PyModule_Create(), which returns a module object, and inserts built-in function objects into the newly created
    module based upon the table (an array of PyMethodDef structures) found in the module definition. */
    return m;
}





int
main(int argc, char *argv[])
{
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL)
    {
        fprintf(stderr,"Fatal error : cannot decode argv[0]\n");
        exit(1);
    }

    /* Add a built-in module before Py_initialize. */
    if(PyImport_AppendInittab("spam", PyInit_spam) == -1)
    {
        fprintf(stderr,"Error: could not extend in-built modules table\n");
        exit(1);
    }

    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(program);

    /* Initialize the Python interpreter.  Required.
       If this step fails, it will be a fatal error. */
    Py_Initialize();

    /* Optionally import the module; alternatively,
       import can be deferred until the embedded script
       imports it. */
    PyObject *pmodule = PyImport_ImportModule("spam");
    if (!pmodule) {
        PyErr_Print();
        fprintf(stderr, "Error: could not import module 'spam'\n");
    }

    PyMem_RawFree(program);
    return 0;
}