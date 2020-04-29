# -*- coding: utf-8 -*-
# @Author: Baptiste Bertrand-Rapello
# @Date:   2020-04-29 14:26:06
# @Last Modified by:   Baptiste Bertrand-Rapello
# @Last Modified time: 2020-04-29 14:52:22

import sys
from datetime import date
from datetime import datetime

def main():
	print("Begining of the output's save ", end='')
	
	curDate = str(datetime.now()).replace(' ', '=')
	filename = "output-CoinCoin-" + curDate + ".txt"
	print("inside the file : ", filename)
	file = open (filename, 'w')
	for line in sys.stdin:
		file.write(line)
		print("$>out>" + line, end='')
	file.close()

if __name__=="__main__":
	main() 