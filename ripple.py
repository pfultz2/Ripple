#!/usr/bin/python


import re
import string
import sys, os

class Lexer:
    lexer_regex = "\\w+|\\s+|\\W"
    def __init__(self, s, index=-1, tokens=""):
        self.s = s
        self.index = index
        if (tokens == ""): self.tokens = re.findall(Lexer.lexer_regex, s)
        else: self.tokens = tokens
        
    def Next(self):
        self.index = self.index + 1
        return self.tokens[self.index]
        
    def HasNext(self):
        return self.index < (len(self.tokens) - 1)
        
    def Copy(self):
        return Lexer(self.s, self.index, self.tokens)