#!/bin/bash

# ============================================================
# Mini-Moulinette caseira da libft
# Para cada ft_*.c, usa um teste testscripts/ft_*.txt
# Compila o teste junto com todos os ft_*.c por dependencias
# Compara todas as linhas FT vs ORIG
# ============================================================

LOG_DIR="logs"
TEST_DIR="tests/testscripts"
TMP_MAIN="main_test.c"
TMP_BIN="test_bin"

GNL_TMP_DIR=".tmp_gnl_tests"
GNL_MAIN="$GNL_TMP_DIR/main_gnl_test.c"
GNL_BIN="$GNL_TMP_DIR/gnl_test_bin"
GNL_TEST_SCRIPT="$TEST_DIR/get_next_line.txt"

SRCS=$(find src -name "*.c" ! -path "src/extra/ft_printf/auxiliar_functions/*")

SEM_TESTE_LIST=""
FALHAS_LIST=""
PASSOU=0
FALHOU=0
SEM_TESTE=0

cleanup_gnl_tmp()
{
	rm -rf "$GNL_TMP_DIR"
}

trap cleanup_gnl_tmp EXIT INT TERM

create_gnl_test_files()
{
	rm -rf "$GNL_TMP_DIR"
	mkdir -p "$GNL_TMP_DIR"

	: > "$GNL_TMP_DIR/empty.txt"
	printf "A" > "$GNL_TMP_DIR/single_char.txt"
	printf "A\n" > "$GNL_TMP_DIR/single_char_newline.txt"
	printf "\n" > "$GNL_TMP_DIR/only_newline.txt"
	printf "Hello\nWorld\n42" > "$GNL_TMP_DIR/multiple_lines.txt"
	printf "Hello" > "$GNL_TMP_DIR/no_final_newline.txt"
	printf "\n\nabc\n\n" > "$GNL_TMP_DIR/consecutive_newlines.txt"
	printf "A1\nA2\n" > "$GNL_TMP_DIR/interleaved_1.txt"
	printf "B1\nB2\n" > "$GNL_TMP_DIR/interleaved_2.txt"
	printf "closed fd test\n" > "$GNL_TMP_DIR/closed_fd.txt"

	i=0
	while [ "$i" -lt 5000 ]; do
		printf "A" >> "$GNL_TMP_DIR/long_line.txt"
		i=$((i + 1))
	done
	printf "\n" >> "$GNL_TMP_DIR/long_line.txt"

	i=0
	while [ "$i" -lt 3000 ]; do
		printf "B" >> "$GNL_TMP_DIR/long_line.txt"
		i=$((i + 1))
	done
}

run_gnl_tests()
{
	log="$LOG_DIR/get_next_line.log"

	if ! find src -name "get_next_line*.c" -print -quit | grep -q .; then
		return
	fi

	if [ ! -f "$GNL_TEST_SCRIPT" ]; then
		SEM_TESTE_LIST="$SEM_TESTE_LIST\n⚪ get_next_line"
		SEM_TESTE=$((SEM_TESTE + 1))
		return
	fi

	create_gnl_test_files

	cp "$GNL_TEST_SCRIPT" "$GNL_MAIN"

	cc -Wall -Wextra -Werror "$GNL_MAIN" libft.a -I include \
		-D"GNL_TEST_DIR=\"$GNL_TMP_DIR\"" \
		-o "$GNL_BIN" > "$log" 2>&1

	if [ $? -ne 0 ]; then
		FALHAS_LIST="$FALHAS_LIST\n❌ COMPILA : get_next_line"
		tmp_log=$(cat "$log")
		echo "=== ERRO DE COMPILACAO GNL ===" > "$log"
		echo "$tmp_log" >> "$log"
		FALHOU=$((FALHOU + 1))
		cleanup_gnl_tmp
		return
	fi

	"$GNL_BIN" > "$log" 2>&1
	status_exec=$?

	if [ "$status_exec" -ne 0 ]; then
		FALHAS_LIST="$FALHAS_LIST\n❌ FALHOU  : get_next_line"
		echo "" >> "$log"
		echo "=== RESULTADO: GNL FALHOU ===" >> "$log"
		echo "Exit status: $status_exec" >> "$log"
		FALHOU=$((FALHOU + 1))
		cleanup_gnl_tmp
		return
	fi

	echo "✅ PASSOU    : get_next_line"
	echo "" >> "$log"
	echo "=== RESULTADO: PASSOU ===" >> "$log"
	PASSOU=$((PASSOU + 1))

	cleanup_gnl_tmp
}

mkdir -p "$LOG_DIR"
rm -f "$LOG_DIR"/*.log
rm -f "$TMP_MAIN" "$TMP_BIN"
rm -f *.o

echo "🧪 Rodando testes da libft..."
echo "----------------------------------------"

for src in $SRCS; do
	if [ ! -f "$src" ]; then
		continue
	fi

	nome=$(basename "$src" .c)

	case "$nome" in
		get_next_line|get_next_line_bonus|get_next_line_utils|get_next_line_utils_bonus)
			continue
			;;
	esac

	txt="$TEST_DIR/$nome.txt"
	log="$LOG_DIR/$nome.log"

	if [ ! -f "$txt" ]; then
		SEM_TESTE_LIST="$SEM_TESTE_LIST\n⚪ $nome"
		SEM_TESTE=$((SEM_TESTE + 1))
		continue

	fi

	cp "$txt" "$TMP_MAIN"

	cc -Wall -Wextra -Werror "$TMP_MAIN" libft.a -I include -o "$TMP_BIN" \
		> "$log" 2>&1

	if [ $? -ne 0 ]; then
		FALHAS_LIST="$FALHAS_LIST\n❌ COMPILA : $nome"
		tmp_log=$(cat "$log")
		echo "=== ERRO DE COMPILACAO ===" > "$log"
		echo "$tmp_log" >> "$log"
		FALHOU=$((FALHOU + 1))
		rm -f "$TMP_MAIN" "$TMP_BIN"
		continue
	fi

	./"$TMP_BIN" > "$log" 2>&1
	status_exec=$?

	if [ "$status_exec" -ne 0 ]; then
		FALHAS_LIST="$FALHAS_LIST\n💥 CRASH   : $nome"
		echo "" >> "$log"
		echo "=== RESULTADO: CRASH / ERRO DE EXECUCAO ===" >> "$log"
		echo "Exit status: $status_exec" >> "$log"
		FALHOU=$((FALHOU + 1))
		rm -f "$TMP_MAIN" "$TMP_BIN"
		continue
	fi

	raw_ft=$(grep -a "^FT  :" "$log")
	raw_orig=$(grep -a "^ORIG:" "$log")

	if [ -z "$raw_ft" ] || [ -z "$raw_orig" ]; then
		FALHAS_LIST="$FALHAS_LIST\n⚠️ FORMATO : $nome"
		echo "" >> "$log"
		echo "=== RESULTADO: FORMATO INVALIDO ===" >> "$log"
		FALHOU=$((FALHOU + 1))
		rm -f "$TMP_MAIN" "$TMP_BIN"
		continue
	fi

	count_ft=$(echo "$raw_ft" | wc -l)
	count_orig=$(echo "$raw_orig" | wc -l)

	if [ "$count_ft" -ne "$count_orig" ]; then
		echo "⚠️  FORMATO  : $nome (quantidade FT/ORIG diferente)"
		echo "" >> "$log"
		echo "=== RESULTADO: QUANTIDADE DIFERENTE ===" >> "$log"
		echo "FT   linhas: $count_ft" >> "$log"
		echo "ORIG linhas: $count_orig" >> "$log"
		FALHOU=$((FALHOU + 1))
		rm -f "$TMP_MAIN" "$TMP_BIN"
		continue
	fi

	linha_ft=$(echo "$raw_ft" | sed 's/^FT  ://')
	linha_orig=$(echo "$raw_orig" | sed 's/^ORIG://')

	if [ "$linha_ft" = "$linha_orig" ]; then
		echo "✅ PASSOU    : $nome"
		echo "" >> "$log"
		echo "=== RESULTADO: PASSOU ===" >> "$log"
		PASSOU=$((PASSOU + 1))
	else
		FALHAS_LIST="$FALHAS_LIST\n❌ FALHOU  : $nome"
		echo "" >> "$log"
		echo "=== RESULTADO: FALHOU ===" >> "$log"
		echo "$raw_ft" >> "$log"
		echo "$raw_orig" >> "$log"
		FALHOU=$((FALHOU + 1))
	fi

	rm -f "$TMP_MAIN" "$TMP_BIN"
done

run_gnl_tests

rm -f "$TMP_MAIN" "$TMP_BIN"
rm -f *.o
cleanup_gnl_tmp

echo "----------------------------------------"

if [ "$FALHOU" -gt 0 ]; then
	echo "❌ Arquivos com problemas:"
	echo -e "$FALHAS_LIST"
	echo ""
fi

if [ "$SEM_TESTE" -gt 0 ]; then
	echo "⚪ Arquivos sem teste:"
	echo -e "$SEM_TESTE_LIST"
	echo ""
fi

echo "🏁 Testes concluídos!"
echo "   ✅ Passou     : $PASSOU"
echo "   ❌ Falhou     : $FALHOU"
echo "   ⚪ Sem teste  : $SEM_TESTE"