# Compilar todos os arquivos .c
echo "Compilando o projeto..."

gcc -I./src/utils -I./src/Mochila_Dinamica src/teste.c src/Mochila_Dinamica/dinamica.c src/Mochila_recursiva/recursiva.c src/utils/utils.c -o mochila

# Verifica se a compilação foi bem-sucedida
if [ $? -eq 0 ]; then
    echo "Compilação concluída com sucesso!"
    echo "Executando o programa:"
    echo "-----------------------------------------------"
    ./mochila
else
    echo "Falha na compilação."
fi