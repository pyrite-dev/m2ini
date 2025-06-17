#define M2INI_IMPLEMENTATION
#include "m2ini.h"

int main() {
	mi_ini_t* ini = mi_parse_file("example.ini");
	if(ini != NULL) {
		mi_ini_t* r = mi_get_kv(ini, "abc");
		printf("%s\n", r->value);

		mi_free(ini);
		return 0;
	}
	return 1;
}
