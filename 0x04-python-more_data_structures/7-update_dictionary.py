#!/usr/bin/python3
def update_dictionary(a_dictionary, key, value):
    if isinstance(key, str):  # Check if key is a string
        a_dictionary[key] = value
        return a_dictionary
    else:
        raise ValueError("Key must be a string")
