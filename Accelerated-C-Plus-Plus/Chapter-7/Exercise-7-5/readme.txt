Explanation
This program is my version for sampling a category from an entered grammar. Given
the following input

<noun>          cat
<noun>          dog
<noun>          table
<noun-phrase>   <noun>
<noun-phrase>   <adjective> <noun-phrase>
<adjective>     large
<adjective>     brown
<adjective>     absurd
<verb>          jumps
<verb>          sits
<location>      on the stairs
<location>      under the sky
<location>      wherever it wants
<sentence>      the <noun-phrase> <verb> <location> <adverb>
<adverb> quickly
<adverb> slowly

a possible output is as follows:

The sample from the requested category is as follows:
the large cat jumps under the sky slowly


If a category string is not embedded in '<' and '>'

Please enter the grammar line by line. Please quit your input with the '|' 
character.
<noun>          cat
<noun>          dog
<noun>          table
<noun-phrase>   <noun>
<noun-phrase>   <adjective> <noun-phrase>
<adjective>     large
<adjective>     brown
<adjective>     absurd
<verb>          jumps
<verb>          sits
<location>      on the stairs
<location>      under the sky
<location>      wherever it wants
<sentence>      the <noun-phrase> <verb> <location> <adverb>
<adverb> quickly
<adverb> slowly
pronoun

then the following output is created:

There is a problem in the input. The first word of each
of the grammar lines must be a category which is a word embedded
in '<' and '>'. However, the first word of the last line is 'pronoun'.
