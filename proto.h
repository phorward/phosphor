/* prog.c */
pvmprog* pvm_prog_create( pvm* vm, char* src );
pvmprog* pvm_prog_free( pvmprog* prog );
pboolean pvm_prog_compile( pvmprog* prog, char* src );
void pvm_prog_dump( pvmprog* prog );

/* run.c */
void pvm_prog_run( pany** ret, pvmprog* prog );

/* vm.c */
pvm* pvm_init( pvm* vm );
pvm* pvm_create( void );
pvm* pvm_reset( pvm* vm );
pvm* pvm_free( pvm* vm );
int pvm_define( pvm* vm, char* mn, pvmop op );

/* main.c */
void dump_mnemonics( pvm* vm );
void help( char** argv );

