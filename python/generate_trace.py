#!/usr/bin/env python
__author__="Pradeep Prabakar - ppravind@cs.cmu.edu"

"""
Code still Incomplete -- Does not work properly ! 
Initial Version
"""

import sys
import re
import os
import glob

if __name__=="__main__":
    """
    Script to append a System.out.println() to each method in a Java CodeBase ! 
    Useful for tracing through large java codebases
    """
    
    # regex pattern for java methods signatures
    m_pattern = re.compile("(public|protected|private|static|\s) +[\w\<\>\[\]]+\s+(\w+) *\([^\)]*\) *(\{?|[^;])")
    
    ## Input -- Requires a Directory containing only java Files
    ## Read All files from a given directory !
    
    input_files =  glob.glob("%s%s*.java" %(sys.argv[1],os.sep))
    os.mkdir(sys.argv[2])
    os.mkdir(sys.argv[2]+os.sep+sys.argv[1].rsplit(os.sep)[0])

    for each_file in input_files:        

        op_file = open(sys.argv[2]+os.sep+each_file,"wb")
        opened_file = open(each_file,"rb")
        for each_line in opened_file:
            match = m_pattern.findall(each_line)
            if not match:
                op_file.write(each_line)
                op_file.write("\n")

            else:
                if match[0][2]=='{':
                    op_file.write(each_line)
                    op_file.write("\n")
                    op_file.write('System.out.println("In Method : %s in File : %s");' %(match[0][1],each_file))

        
                
        



    

    
