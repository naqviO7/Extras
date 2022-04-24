compliment = {'A': 'T', 'T': 'A', 'G': 'C', 'C': 'G'}
count=0

while count < 3:
    str_in=str(input('Enter String: '))
    reverse_str = ''.join(compliment[bp] for bp in reversed(str_in))
    print(f'Oligonucleotide Sequence: {str_in}')
    print(f'Complement Sequence: {reverse_str}\n')
    count = count + 1
    
    if count == 3:
        print('Three Oligonucleotide Sequence have been Generated')
        break
