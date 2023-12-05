#!/usr/bin/python3
"""Defines an object attribute look up Function """
def lookup(obj):
    """Return the list of an object's available attribute"""
    return (dir(obj))
