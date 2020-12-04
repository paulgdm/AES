rm result.txt
rm ./../ciphertext.txt

hexdump -e '16/1 "%02x " "\n"' ./$1 >> result.txt

cat result.txt | while  read ligne ; do
	if [ ${#ligne} != 47 ]
		let "a=47-${#ligne}"
		then
			while [ ${#ligne} != 47 ]
			do
				ligne=$ligne" "$a
		done
	else
  		./AES $ligne >> ./$2
  	fi
done

rm result.txt