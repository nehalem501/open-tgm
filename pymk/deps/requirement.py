#!/usr/bin/env python3

class Requirement:
    def __init__(self, entry, requires):
        self.entry = entry
        self.requires = requires

    def __repr__ (self):
        return "Requirement('" + self.requires + "')"
