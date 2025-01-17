CFLAGS+=-Wall -g -O2
OBJ=main.o alt.o tree.o script.o
PREFIX?=/usr
BIN=alt

all: ${OBJ}
	${CC} -o ${BIN} ${OBJ}
#	./${BIN} t/ops.alt

loc:
	@cat *.c *.h | wc -l

locdiff:
	@A=`hg diff | grep -v '+++' | grep ^+ |wc -l` ; \
	B=`hg diff | grep -v -- '---' | grep ^- |wc -l` ; \
	echo $$((A-B))

install:
	cp alt ${DESTDIR}${PREFIX}/bin

clean:
	rm -f ${OBJ} ${BIN}
