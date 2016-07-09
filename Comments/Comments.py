'''
MIT License

Copyright (c) 2016 Souradip Guha

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
'''

#!/usr/bin/python

import sys
arguments = sys.argv
if(len(arguments)==1):
  print("No arguments found.")
  print("You can execute with '-help' to get more information.")
  sys.exit(0)
if('-help' in arguments):
  print("You need to pass the path of config file while executing.")
  print("Following options are available in config file.")
  print('''	1) File name - Specifies the path to your input file.
				Ex - File name : config.txt''')
  print('''	2) Index - Specifies the line number where you want to add comment.
				Ex - Index : 15''')
  print('''	3) Comment - Specifies the comment you want to add.
				Ex - Comment : Test''')
  print('''	4) Comment Length - Specifies the total length of your comment including '#' symbols. Default value is 45.
				Ex - Comment length : 60''')
  print('''	5) Start Comment symbol - Specifies the starting symbol of comment. Default value is '/*'.
				Ex - Start  comment symbol : /*''')
  print('''	6) End Comment symbol - Specifies the ending symbol of comment. Default value is '*/'.
				Ex - End comment symbol : /*''')
  sys.exit(0)
file_name = arguments[1]
my_file = open(file_name, 'r')
my_file_dict = {};
for line in my_file.readlines():
  line = line.strip('\n')
  if(":" not in line):
    continue
  [key, value] = line.split(":");
  [key, value] = [key.strip().lower(), value.strip()]
  if key=="comment" and len(value)%2==0:
    value = value + ' '
  if key=="comment length" and int(value)%2==0:
    value = int(value)-1
  if key in my_file_dict.keys():
    my_file_dict[key].append(value)
  else:
    my_file_dict[key] = [value]
my_file.close()
if "comment length" not in my_file_dict.keys():
  COMMENT_LENGTH = 45
else:
  COMMENT_LENGTH = int(my_file_dict["comment length"][0])
if "start comment symbol" not in my_file_dict.keys():
  start_comment_sign = '/*'
else:
  start_comment_sign = my_file_dict["start comment symbol"][0]
if "end comment symbol" not in my_file_dict.keys():
  end_comment_sign = '*/'
else:
  end_comment_sign = my_file_dict["end comment symbol"][0]
test_file = open(my_file_dict['file name'][0], 'r')
test_file_list = []
for line in test_file.readlines():
  line = line.strip('\n')
  test_file_list.append(line)
test_file.close()
parts = []
last = 0
for key,each in enumerate(my_file_dict["index"]):
  parts.append(test_file_list[last:int(each)-1])
  last = int(each)-1
parts.append(test_file_list[last:len(test_file_list)])
for key,value in enumerate(parts):
  if key != len(parts)-1:
    value.append(start_comment_sign)
    value.append("#"*COMMENT_LENGTH)
    comment = " "*4+my_file_dict["comment"][key]+" "*4
    len_of_remaining_hash = int((COMMENT_LENGTH - len(comment))/2)
    value.append("#"*len_of_remaining_hash+comment+"#"*len_of_remaining_hash)
    value.append("#"*COMMENT_LENGTH)
    value.append(end_comment_sign)

test_file_list = []
for each in parts:
    test_file_list = test_file_list + each;

output_file = open(my_file_dict['file name'][0]+".commented", 'w')
for line in test_file_list:
  output_file.write(line+'\n');
output_file.close()
