/*
 * Copyright 2009 Paul J. Davis <paul.joseph.davis@gmail.com>
 *
 * This file is part of the python-spidermonkey package released
 * under the MIT license.
 *
 */

#ifndef PYSM_CONTEXT_H
#define PYSM_CONTEXT_H

#include <Python.h>
#include "structmember.h"

#include "spidermonkey.h"

typedef struct {
    PyObject_HEAD
    Runtime* rt;
    JSContext* cx;
    JSObject* root;
    PyDictObject* classes;
    PySetObject* objects;
} Context;

PyObject* Context_get_class(Context* cx, const char* key);
int Context_add_class(Context* cx, const char* key, PyObject* val);

int Context_has_object(Context* cx, PyObject* val);
int Context_add_object(Context* cx, PyObject* val);
int Context_rem_object(Context* cx, PyObject* val);

extern PyTypeObject _ContextType;

#endif
