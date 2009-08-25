#define PRINTLEVEL { int i;for(i=0;i<st->level;i++) printf("  "); }

#define ALT_MAX_LEVEL 128
typedef enum {
	MODE_PARSE,
	MODE_COMMENT,
	MODE_STRING,
} AltMode;

typedef struct AltState {
	AltMode mode;
	int word;
	int line;
	int level;
	int levels[ALT_MAX_LEVEL];
	int lastchar;
	int skipuntil;
	char str[128];
	int stridx;
	void (*cb_word)(struct AltState *st);
	void (*cb_level)(struct AltState *st, int delta, char ch);
	int (*cb_error)(struct AltState *st, const char *fmt, ...);
	void *user;
} AltState;


int parse_char(AltState *st, char ch);
int parse_str(AltState *st, char *str);
int parse_fd(AltState *st, int fd);
int parse_file(AltState *st, const char *file);

void alt_tree(AltState *st);
