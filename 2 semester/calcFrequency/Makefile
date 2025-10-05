compiler = gcc 
include  = -Ilibs
sources  = src/*.c
flags    = -std=c11 -Wall -Wextra -Werror -O2
output   = calcFrequency

build:
	$(compiler) $(include) $(flags) $(sources) -o $(output)

clean:
	rm -f $(output)
