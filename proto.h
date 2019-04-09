/* any/any.c */
pboolean pany_init( pany* val );
pany* pany_create( char* str );
pboolean pany_reset( pany* val );
pany* pany_free( pany* val );
pboolean pany_parse( pany* val, char* str, panytype enforce );
pboolean pany_copy( pany* dest, pany* src );
pany* pany_dup( pany* src );

/* any/any.conv.c */
pboolean pany_to_bool( pany* val );
char pany_to_char( pany* val );
int pany_to_int( pany* val );
long pany_to_long( pany* val );
unsigned long pany_to_ulong( pany* val );
float pany_to_float( pany* val );
double pany_to_double( pany* val );
char* pany_to_str( pany* val );
wchar_t* pany_to_wcs( pany* val );
void* pany_to_ptr( pany* val );
pboolean pany_convert( pany* val, panytype type );

/* any/any.get.c */
pboolean pany_get_bool( pany* val );
char pany_get_char( pany* val );
int pany_get_int( pany* val );
long pany_get_long( pany* val );
unsigned long pany_get_ulong( pany* val );
float pany_get_float( pany* val );
double pany_get_double( pany* val );
char* pany_get_cstr( pany* val );
char* pany_get_str( pany* val );
wchar_t* pany_get_cwcs( pany* val );
wchar_t* pany_get_wcs( pany* val );
void* pany_get_ptr( pany* val );

/* any/any.print.c */
void _dbg_any_dump( char* file, int line, char* function, char* name, pany* val );
void pany_fprint( FILE* stream, pany* val );

/* any/any.set.c */
pboolean pany_set_bool( pany* val, pboolean b );
char pany_set_char( pany* val, char c );
int pany_set_int( pany* val, int i );
long pany_set_long( pany* val, long l );
unsigned long pany_set_ulong( pany* val, unsigned long ul );
float pany_set_float( pany* val, float f );
double pany_set_double( pany* val, double d );
char* pany_set_cstr( pany* val, char* s );
char* pany_set_str( pany* val, char* s );
wchar_t* pany_set_cwcs( pany* val, wchar_t* ws );
wchar_t* pany_set_wcs( pany* val, wchar_t* ws );
void* pany_set_ptr( pany* val, void* ptr );

/* vm/prog.c */
pvmprog* pvm_prog_create( pvm* vm, char* src );
pvmprog* pvm_prog_free( pvmprog* prog );
pboolean pvm_prog_compile( pvmprog* prog, char* src );
void pvm_prog_dump( pvmprog* prog );

/* vm/run.c */
void pvm_prog_run( pany** ret, pvmprog* prog );

/* vm/vm.c */
pvm* pvm_init( pvm* vm );
pvm* pvm_create( void );
pvm* pvm_reset( pvm* vm );
pvm* pvm_free( pvm* vm );
int pvm_define( pvm* vm, char* mn, pvmop op );

/* main.c */
void dump_mnemonics( pvm* vm );
void help( char** argv );

