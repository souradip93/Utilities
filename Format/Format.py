import sys, re

input_file_list = []
output_file_list = []

pattern_list = ['=', ':']

pattern_found = False
update_dict = {}

def update_contents():

	global update_dict
	global input_file_list
	global output_file_list
	global pattern_list
	
	pattern = '|'.join(pattern_list)
	my_regex = r'(.*?)([' + re.escape(pattern) + r'])(.*)'
	
	max_number_of_characters = max(update_dict.values())
	for each in update_dict.keys():
		line = input_file_list[each]
		number_of_spaces_to_be_added = max_number_of_characters - update_dict[each]
		search_obj = re.search(my_regex, line)
		left_part = search_obj.group(1)
		sign = search_obj.group(2)
		right_part = search_obj.group(3)
		updated_line = left_part+" "*number_of_spaces_to_be_added+sign+right_part
		output_file_list[each] = updated_line


def do_magic():

	global update_dict
	global pattern_found
	global output_file_list
	global input_file_list
	global pattern_list
	
	pattern = '|'.join(pattern_list)
	my_regex = r'(.*?)[' + re.escape(pattern) + r']'
	
	for each_line in input_file.readlines():
		input_file_list.append(each_line.strip('\n'))
		output_file_list.append(each_line.strip('\n'))
		
	for line_number, each_line in enumerate(input_file_list):
		search_obj = re.search(my_regex, each_line)
		if search_obj != None:
			pattern_found = True
			left_part = search_obj.group(1)
			number_of_letters = len(left_part)
			update_dict[line_number] = number_of_letters
		else:
			if pattern_found:
				update_contents()
				update_dict = {}
			pattern_found = False
	else:
		if pattern_found:
			update_contents()
		pattern_found = False
		
	output_file = open(output_file_name , 'w')
	for each in output_file_list:
		output_file.write(each+"\n")
		

arguments = sys.argv
assert(len(arguments) > 2)

input_file_name = arguments[1]
output_file_name = arguments[2]

input_file = open(input_file_name, "r")

do_magic()
		
