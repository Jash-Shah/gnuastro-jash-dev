#define PY_SSIZE_T_CLEAN
#include <Python.h>

/* This is what a Custom object will contain */
typedef struct {

    /* PyObject_HEAD is mandatory
    at the start of each object struct and defines a field called ob_base
    of type PyObject, containing a pointer to a type object and a
    reference count  */
    PyObject_HEAD

    /* We can define our structure here. */
    
} CustomObject;


/* Definition of the type object. */
static PyTypeObject CustomType = 
{
    /* Mandatory boilerplate to initialize the ob_base */
    PyVarObject_HEAD_INIT(NULL,0)

    /* The name is a dotted name that includes both the module name
    and the name of the type within the module. */
    .tp_name = "custom.Custom",

    /* Doc String. */
    .tp_doc = "Custom Objects",

    /* This is so that Python knows how much memory to allocate when creating new Custom instances. */
    .tp_basicsize = sizeof(CustomObject),
    .tp_itemsize = 0,

    /* All types should include this constant in their flags. */
    .tp_flags = Py_TPFLAGS_DEFAULT,

    /* To enable object creation. */
    .tp_new = PyType_GenericNew,
};

/* Defining the custom module. */
static PyModuleDef custommodule = 
{
    PyModuleDef_HEAD_INIT,
    .m_name = "custom",
    .m_doc = "Example module that creates an extension type.",
    .m_size = -1,
};

PyMODINIT_FUNC
PyInit_custom(void)
{
    PyObject *m;
    if (PyType_Ready(&CustomType) < 0)
        return NULL;
    
    m = PyModule_Create(&custommodule);
    if (m == NULL)
        return NULL;

    Py_INCREF(&CustomType);

    if (PyModule_AddObject(m,"Custom", (PyObject *) &CustomType) < 0)
        {
            Py_DECREF(&CustomType);
            Py_DECREF(m);
            return NULL;
        }

    return m;
}