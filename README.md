# Get Next Line

get_next_line is a function that reads a file line by line

`#include "get_next_line.h"`

`int	get_next_line(int const fd, char **line)`

**Return value:**
* `return 1:  a line is readed and the file is not over`
* `return 0:  the file is over`
* `return -1: an error occurs`
