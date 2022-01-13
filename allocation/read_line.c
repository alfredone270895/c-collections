char *read_line( void ) { 
	char *p, c;
	int n = 0, size = 2;
	p = my_malloc( size );
	while ( ( c = getchar() ) != EOF ) {
		if ( n >= size ) { 
			// spazio terminato, lo raddoppio 
			size *=2;
			p = my_realloc( p, size );
		}
		if ( c == '\n' ) { 
			// fine stringa, interrompo 
			p[n] = '\0';
		break;
		}
	p[n++] = c; 
	}
	return p; 
}