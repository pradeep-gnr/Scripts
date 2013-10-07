#!/usr/bin/env python
# A Script to parse the output produced by Stanford NER and combine all the BIO annotations !!
#Usage -- python stanford_ner_parse.py <ner_produced_op>
import sys
import os
import ipdb

i_file = open(sys.argv[1],"rb")

tokens_mapping = []

for each_line in i_file:
    tokens_mapping = []
    tokens = each_line.split()
    final_word=""
    is_prev_entity=False    
    prev_entity = None
    prev_word = ""

    for each in tokens:
        word,entity = each.split('/')
        
        if entity=='O' and prev_entity in ['O',None]:            
            prev_entity=entity
            continue

        if entity=='O' and prev_entity not in ['O',None]:            
            tokens_mapping.append(current_tag_mapping)
            prev_entity=entity
            current_tag_mapping=()        
        
        elif entity!='O':
            
            if prev_entity == entity:                               
                try:
                    prev_word = "%s %s" %(current_tag_mapping[0], word)
                    current_tag_mapping=(prev_word,entity)
                except:
                    ipdb.set_trace()

            elif prev_entity!=entity and prev_entity in ['O',None]:
                #tokens_mapping.append(current_tag_mapping)                                
                current_tag_mapping=(word,entity)

            elif prev_entity!=entity and prev_entity not in ['O',None]:                
                tokens_mapping.append(current_tag_mapping)                                
                current_tag_mapping = (word,entity)

            prev_entity = entity

    tokens_mapping = [each for each in tokens_mapping if each]
    prev_entity=None
    prev_tag=''
    current_tag_mapping=()
    print tokens_mapping

    
                

            

            
            

            
            
    
