find "$1" -name "*.c" | while read filename
do
tempName=${filename}~temp~.c
mv "$filename" "$tempName"
iconv -c -f euc-kr -t utf-8 "$tempName" > "$filename"
rm "$tempName"
done
