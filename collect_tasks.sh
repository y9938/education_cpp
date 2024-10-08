#!/bin/bash

# Файл для сохранения всех задач
output_file="all_tasks.md"

# Очистим файл перед началом
> $output_file

# Найдём все .cpp файлы и обработаем их
find . -name "*.cpp" -print | while read -r file; do
    # Проверим, начинается ли файл с многострочного комментария
    if head -n 1 "$file" | grep -q "^/\*"; then
        # Извлечём первый многострочный комментарий с задачей, удалим символы /**/ и пустые строки
        description=$(awk '/\/\*/,/\*\// {gsub(/\/\*|\*\//, ""); if (NF) print; if (/.*\*\//) exit}' "$file")
        
        # Если описание найдено, добавим его в файл
        if [ -n "$description" ]; then
            echo "### Processing $file" >> $output_file
            echo "$description" >> $output_file
            echo "" >> $output_file
        fi
    fi
done

echo "All tasks have been collected in $output_file"
