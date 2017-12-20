#!/usr/bin/env python
# coding=utf-8

import sys
from optparse import OptionParser

reload(sys)
sys.setdefaultencoding("utf-8")

#####################################
# Xingwei_He All Rights Reserved.
# Author:Xingwei_He
# Date:2000-01-01
#####################################

def check_build(filename, begin_pos, end_pos):
  fp = open(filename, "r")
  question_dict = dict()
  for line in fp:
    line_sp = line.strip().split("=")
    if line_sp[0].strip() == "name":
      target_name = line_sp[1].strip().strip("\"")
      name_sp = target_name.split("_")
      prefix = name_sp[0]
      question_num = int(name_sp[1])
      question_name = str("_").join(name_sp[2:])
      question_dict[question_num] = question_name
  accepted_list = list()
  todo_list = list()
  begin = begin_pos
  end = end_pos
  while begin <= end:
    if begin in question_dict.keys():
      accepted_list.append(begin)
    else:
      todo_list.append(begin)
    begin += 1
  # information #
  total_counter = len(accepted_list) + len(todo_list)
  accepted_counter = len(accepted_list)
  todo_counter = len(todo_list)
  print "You are checking questions from", begin_pos, " to ", end_pos,"."
  print "Total:", total_counter
  print "Accepted:", accepted_counter, "\trate:", round((float(accepted_counter)/float(total_counter)) * 100, 2), "%"
  print "Todo:", todo_counter, "\trate:", round((float(todo_counter)/float(total_counter)) * 100, 2), "%"

  print "Todo List:"
  i = begin_pos
  while i <= end_pos:
    if i in todo_list:
      print i,"\t",
    if i % 10 == 0:
      print ""
    i += 1
    

  print ""
  fp.close()

def main():
  build_filename = options.build_filename
  begin_index = options.question_number_begin
  end_index = options.question_number_end
  print "Filename:", build_filename
  print "check range:[", begin_index, ", ", end_index, "]" 
  check_build(build_filename, begin_index, end_index)

if __name__ == "__main__":
  parser = OptionParser()
  parser.add_option(
    "--input_build_filename",
    dest = "build_filename",
    type = "str",
    default = "",
    help = "input filename of BUILD.")
  parser.add_option(
    "--question_number_begin",
    dest = "question_number_begin",
    type = "int",
    default = 0,
    help = "the first index of questions' range.")
  parser.add_option(
    "--question_number_end",
    dest = "question_number_end",
    type = "int",
    default = 0,
    help = "the last index of questions' range.")
  (options, args) = parser.parse_args()

  # 主逻辑
  main()
