#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - Prints information about Python bytes objects.
 * @p: Pointer to a Python object (assumed to be a bytes object).
 */
void print_python_bytes(PyObject *p)
{
    PyBytesObject *bytes = (PyBytesObject *)p;

    printf("[.] bytes object info\n");
    printf("  size: %ld\n", Py_SIZE(bytes));
    printf("  trying string: %s\n", PyBytes_AS_STRING(bytes));

    printf("  first 10 bytes:");
    for (Py_ssize_t i = 0; i < Py_SIZE(bytes) && i < 10; i++)
        printf(" %02x", (unsigned char)PyBytes_AS_STRING(bytes)[i]);
    printf("\n");
}

/**
 * print_python_list - Prints information about Python lists.
 * @p: Pointer to a Python object (assumed to be a list).
 */
void print_python_list(PyObject *p)
{
    PyListObject *list = (PyListObject *)p;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", Py_SIZE(list));
    printf("[*] Allocated = %ld\n", list->allocated);

    for (Py_ssize_t i = 0; i < Py_SIZE(list); i++)
    {
        printf("Element %ld: ", i);

        PyObject *element = PyList_GET_ITEM(list, i);

        if (PyBytes_Check(element))
        {
            printf("bytes\n");
            print_python_bytes(element);
        }
        else if (PyLong_Check(element))
        {
            printf("int\n");
        }
        else if (PyFloat_Check(element))
        {
            printf("float\n");
        }
        else if (PyTuple_Check(element))
        {
            printf("tuple\n");
        }
        else if (PyList_Check(element))
        {
            printf("list\n");
        }
        else if (PyUnicode_Check(element))
        {
            printf("str\n");
        }
        else
        {
            printf("[ERROR] Invalid Bytes Object\n");
        }
    }
}


