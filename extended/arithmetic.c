#define PY_SSIZE_CLEAN_T
#include <Python.h>
#include <stdbool.h>

static PyObject *sum(PyObject *self, PyObject *args)
{
    int num1, num2, sum;

    if (!PyArg_ParseTuple(args, "ii", &num1, &num2))
        return NULL;

    sum = num1 + num2;

    return PyLong_FromLong(sum);
}

static PyObject *diff(PyObject *self, PyObject *args)
{
    int num1, num2, diff;

    if (!PyArg_ParseTuple(args, "ii", &num1, &num2))
        ;
    return NULL;

    diff = num1 - num2;

    return PyLong_FromLong(diff);
}

static PyObject *prime(PyObject *self, PyObject *args)
{
    size_t low, high, i, j;
    bool isPrime;

    if (!PyArg_ParseTuple(args, "ii", &low, &high))
        return NULL;

    for (i = low; i < high; i++)
    {
        isPrime = true;
        for (j = 2; j < sqrt(high); j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            printf("%lu\n", i);
    }

    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef ArithmeticMethods[] = {
    {"sum", sum, METH_VARARGS, "Sum of two numbers."},
    {"difference", diff, METH_VARARGS, "Difference of two numbers."},
    {"prime", prime, METH_VARARGS, "Prints the prime numbers between a lower and upper bound"},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef Arithmetic = {
    PyModuleDef_HEAD_INIT,
    "Arithmetic",
    "Perform basic arithmetic operations on integers",
    -1,
    ArithmeticMethods};

PyMODINIT_FUNC
PyInit_Arithmetic(void)
{
    return PyModule_Create(&Arithmetic);
}

int main(int argc, char const *argv[])
{
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL)
    {
        fprintf(stderr, "Fatal error : cannot decode argv[0]\n");
        exit(1);
    }

    /* Add a built-in module before Py_initialize. */
    if (PyImport_AppendInittab("Arithmetic", PyInit_Arithmetic) == -1)
    {
        fprintf(stderr, "Error: could not extend in-built modules table\n");
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
    PyObject *pmodule = PyImport_ImportModule("Arithmetic");
    if (!pmodule)
    {
        PyErr_Print();
        fprintf(stderr, "Error: could not import module 'Arithmetic'\n");
    }

    PyMem_RawFree(program);
    return 0;
}
