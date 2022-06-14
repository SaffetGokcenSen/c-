Explanation
The program takes a description of a sentence structure—a grammar—and generates 
random sentences that meet that description. For example, we might describe an
English sentence as a noun and a verb, or as a noun, a verb, and an object, and 
so on. The sentences that we can construct will be more interesting if we can 
handle complicated rules. For example, rather than saying merely that a sentence 
is a noun followed by a verb, we might allow noun phrases, where a noun phrase 
is either simply a noun or an adjective followed by a noun phrase. As a concrete
example, given the following input

<noun> cat
<noun> dog
<noun> table
<noun-phrase> <noun>
<noun-phrase> <adjective> <noun-phrase>
<adjective> large
<adjective> brown
<adjective> absurd
<verb> jumps
<verb> sits
<location> on the stairs
<location> under the sky
<location> wherever it wants
<sentence> the <noun-phrase> <verb> <location>

the program might generate

the table jumps wherever it wants

This program is presented in the book. I have written the presented code, 
compiled and run it.