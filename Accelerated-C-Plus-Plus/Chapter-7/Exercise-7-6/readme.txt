Explanation
This program prompts the user to enter a grammar. Then, it asks the user to 
enter a category to sample from. The program generates samples not recursively. 
It uses a dynamic list whose elements may be deleted or into which new elements 
may be inserted. The category to be sampled must be entered as embedded in '<' 
and '>'.
Given the grammar

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

a sample for the sentence category is generated as follows:

the large cat jumps under the sky slowly