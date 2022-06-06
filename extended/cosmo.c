#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "gnuastro/cosmology.h"





#define H0_DEFAULT 67.66
#define OLAMBDA_DEFAULT 0.6889
#define OMATTER_DEFAULT 0.3111
#define ORADIATION_DEFAULT 0.000










static PyObject *cosmology_velocity_from_z(PyObject *self, PyObject *args)
{
  double z, vel;

  if (!PyArg_ParseTuple(args, "d", &z))
    return NULL;

  vel = gal_cosmology_velocity_from_z(z);

  return PyFloat_FromDouble(vel);
}





static PyObject *cosmology_proper_distance(PyObject *self, PyObject *args, PyObject *keywds)
{
  double z, res;
  double H0 = H0_DEFAULT;
  double o_lambda_0 = OLAMBDA_DEFAULT;
  double o_matter_0 = OMATTER_DEFAULT;
  double o_radiation_0 = ORADIATION_DEFAULT;

  static char *kwlist[] = {"z", "H0", "olambda", "omatter", "oradiation", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, keywds, "d|dddd", kwlist,
                                   &z, &H0, &o_lambda_0, &o_matter_0, &o_radiation_0))
    return NULL;

  res = gal_cosmology_proper_distance(z, H0, o_lambda_0, o_matter_0, o_radiation_0);

  return PyFloat_FromDouble(res);
}





static PyObject *cosmology_comoving_volume(PyObject *self, PyObject *args, PyObject *keywds)
{
  double z, res;
  double H0 = H0_DEFAULT;
  double o_lambda_0 = OLAMBDA_DEFAULT;
  double o_matter_0 = OMATTER_DEFAULT;
  double o_radiation_0 = ORADIATION_DEFAULT;

  static char *kwlist[] = {"z", "H0", "olambda", "omatter", "oradiation", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, keywds, "d|dddd", kwlist,
                                   &z, &H0, &o_lambda_0, &o_matter_0, &o_radiation_0))
    return NULL;

  res = gal_cosmology_comoving_volume(z, H0, o_lambda_0, o_matter_0, o_radiation_0);

  return PyFloat_FromDouble(res);
}





static PyObject *cosmology_critical_density(PyObject *self, PyObject *args, PyObject *keywds)
{
  double z, res;
  double H0 = H0_DEFAULT;
  double o_lambda_0 = OLAMBDA_DEFAULT;
  double o_matter_0 = OMATTER_DEFAULT;
  double o_radiation_0 = ORADIATION_DEFAULT;

  static char *kwlist[] = {"z", "H0", "olambda", "omatter", "oradiation", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, keywds, "d|dddd", kwlist,
                                   &z, &H0, &o_lambda_0, &o_matter_0, &o_radiation_0))
    return NULL;

  res = gal_cosmology_critical_density(z, H0, o_lambda_0, o_matter_0, o_radiation_0);

  return PyFloat_FromDouble(res);
}





static PyObject *cosmology_angular_distance(PyObject *self, PyObject *args, PyObject *keywds)
{
  double z, res;
  double H0 = H0_DEFAULT;
  double o_lambda_0 = OLAMBDA_DEFAULT;
  double o_matter_0 = OMATTER_DEFAULT;
  double o_radiation_0 = ORADIATION_DEFAULT;

  static char *kwlist[] = {"z", "H0", "olambda", "omatter", "oradiation", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, keywds, "d|dddd", kwlist,
                                   &z, &H0, &o_lambda_0, &o_matter_0, &o_radiation_0))
    return NULL;

  res = gal_cosmology_angular_distance(z, H0, o_lambda_0, o_matter_0, o_radiation_0);

  return PyFloat_FromDouble(res);
}





static PyObject *cosmology_luminosity_distance(PyObject *self, PyObject *args, PyObject *keywds)
{
  double z, res;
  double H0 = H0_DEFAULT;
  double o_lambda_0 = OLAMBDA_DEFAULT;
  double o_matter_0 = OMATTER_DEFAULT;
  double o_radiation_0 = ORADIATION_DEFAULT;

  static char *kwlist[] = {"z", "H0", "olambda", "omatter", "oradiation", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, keywds, "d|dddd", kwlist,
                                   &z, &H0, &o_lambda_0, &o_matter_0, &o_radiation_0))
    return NULL;

  res = gal_cosmology_luminosity_distance(z, H0, o_lambda_0, o_matter_0, o_radiation_0);

  return PyFloat_FromDouble(res);
}





static PyObject *cosmology_distance_modulus(PyObject *self, PyObject *args, PyObject *keywds)
{
  double z, res;
  double H0 = H0_DEFAULT;
  double o_lambda_0 = OLAMBDA_DEFAULT;
  double o_matter_0 = OMATTER_DEFAULT;
  double o_radiation_0 = ORADIATION_DEFAULT;

  static char *kwlist[] = {"z", "H0", "olambda", "omatter", "oradiation", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, keywds, "d|dddd", kwlist,
                                   &z, &H0, &o_lambda_0, &o_matter_0, &o_radiation_0))
    return NULL;

  res = gal_cosmology_distance_modulus(z, H0, o_lambda_0, o_matter_0, o_radiation_0);

  return PyFloat_FromDouble(res);

}





static PyObject *cosmology_z_from_velocity(PyObject *self, PyObject *args)
{
  double z, vel;

  if (!PyArg_ParseTuple(args, "d", &vel))
    return NULL;

  z = gal_cosmology_z_from_velocity(vel);

  return PyFloat_FromDouble(z);
}





static PyObject *cosmology_to_absolute_mag(PyObject *self, PyObject *args, PyObject *keywds)
{
  double z, res;
  double H0 = H0_DEFAULT;
  double o_lambda_0 = OLAMBDA_DEFAULT;
  double o_matter_0 = OMATTER_DEFAULT;
  double o_radiation_0 = ORADIATION_DEFAULT;

  static char *kwlist[] = {"z", "H0", "olambda", "omatter", "oradiation", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, keywds, "d|dddd", kwlist,
                                   &z, &H0, &o_lambda_0, &o_matter_0, &o_radiation_0))
    return NULL;

  res = gal_cosmology_to_absolute_mag(z, H0, o_lambda_0, o_matter_0, o_radiation_0);

  return PyFloat_FromDouble(res);
}





static PyObject *cosmology_age(PyObject *self, PyObject *args, PyObject *keywds)
{
  double z, res;
  double H0 = H0_DEFAULT;
  double o_lambda_0 = OLAMBDA_DEFAULT;
  double o_matter_0 = OMATTER_DEFAULT;
  double o_radiation_0 = ORADIATION_DEFAULT;

  static char *kwlist[] = {"z", "H0", "olambda", "omatter", "oradiation", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, keywds, "d|dddd", kwlist,
                                   &z, &H0, &o_lambda_0, &o_matter_0, &o_radiation_0))
    return NULL;

  res = gal_cosmology_age(z, H0, o_lambda_0, o_matter_0, o_radiation_0);

  return PyFloat_FromDouble(res);
}





static PyMethodDef CosmologyMethods[] = {
    {"cosmology_age",                 (PyCFunction)(void (*)(void))cosmology_age,                 METH_VARARGS | METH_KEYWORDS, "Returns the age of the universe at redshift z in units of Giga years."},
    {"cosmology_proper_distance",     (PyCFunction)(void (*)(void))cosmology_proper_distance,     METH_VARARGS | METH_KEYWORDS, "Returns the proper distance to an object at redshift z in units of Mega parsecs."},
    {"cosmology_comoving_volume",     (PyCFunction)(void (*)(void))cosmology_comoving_volume,     METH_VARARGS | METH_KEYWORDS, "Returns the comoving volume over 4pi stradian to z in units of Mega parsecs cube."},
    {"cosmology_critical_density",    (PyCFunction)(void (*)(void))cosmology_critical_density,    METH_VARARGS | METH_KEYWORDS, "Returns the critical density at redshift z in units of g/cm3."},
    {"cosmology_angular_distance",    (PyCFunction)(void (*)(void))cosmology_angular_distance,    METH_VARARGS | METH_KEYWORDS, "Return the angular diameter distance to an object at redshift z in units of Mega parsecs."},
    {"cosmology_luminosity_distance", (PyCFunction)(void (*)(void))cosmology_luminosity_distance, METH_VARARGS | METH_KEYWORDS, "Return the luminosity diameter distance to an object at redshift z in units of Mega parsecs."},
    {"cosmology_distance_modulus",    (PyCFunction)(void (*)(void))cosmology_distance_modulus,    METH_VARARGS | METH_KEYWORDS, "Return the distance modulus at redshift z (with no units)."},
    {"cosmology_to_absolute_mag",     (PyCFunction)(void (*)(void))cosmology_to_absolute_mag,     METH_VARARGS | METH_KEYWORDS, "Return the conversion from apparent to absolute magnitude for an object at redshift z. This value has to be added to the apparent magnitude to give the absolute magnitude of an object at redshift z."},
    {"cosmology_velocity_from_z",                                  cosmology_velocity_from_z,     METH_VARARGS,                 "Return the velocity (in km/s) corresponding to the given redshift (z)."},
    {"cosmology_z_from_velocity",                                  cosmology_z_from_velocity,     METH_VARARGS,                 "Return the redshift corresponding to the given velocity (v in km/s)."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};





static struct PyModuleDef cosmology = {
    PyModuleDef_HEAD_INIT,
    "cosmology",
    "This library does the main cosmological calculations that are commonly necessary in extra-galactic astronomical studies. The main variable in this context is the redshift (z). The cosmological input parameters in the functions below are H0, o_lambda_0, o_matter_0, o_radiation_0 which respectively represent the current (at redshift 0) expansion rate (Hubble constant in units of km/sec/Mpc), cosmological constant (Λ), matter and radiation densities.",
    -1,
    CosmologyMethods};

PyMODINIT_FUNC
PyInit_cosmology(void)
{
  return PyModule_Create(&cosmology);
}





















int main(int argc, char *argv[])
{
  wchar_t *program = Py_DecodeLocale(argv[0], NULL);
  if (program == NULL)
  {
    fprintf(stderr, "Fatal error : cannot decode argv[0]\n");
    exit(1);
  }

  /* Add a built-in module before Py_initialize. */
  if (PyImport_AppendInittab("spam", PyInit_cosmology) == -1)
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
  char mod_name[] = "cosmology";
  PyObject *pmodule = PyImport_ImportModule("cosmology");
  if (!pmodule)
  {
    PyErr_Print();
    fprintf(stderr, "Error: could not import module %s\n", mod_name);
  }

  PyMem_RawFree(program);
  return 0;
}
