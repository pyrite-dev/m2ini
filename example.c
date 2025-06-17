#define M2INI_IMPLEMENTATION
#include "m2ini.h"

int main() {
	mi_ini_t* ini = mi_parse_file("example.ini");
	if(ini != NULL) {
		printf("%s\n", mi_string(ini));

		mi_free(ini);
		return 0;
	}
	return 1;
}
