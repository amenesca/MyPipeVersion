# MyPipeVersion

It's a programm that simulates the pipes of bash, made in C<br><br>

Usage:<br>
Compile using make, them<br><br>
$&gt;./pipex file1 cmd1 cmd2 file2<br>
It should behave like:<br><br>
$&gt; &lt; file1 cmd1 | cmd2 &gt; file2<br><br>

$&gt; ./pipex infile "ls -l" "wc -l" outfile<br>
Should behave like:<br><br>
&lt; infile ls -l | wc -l &gt; outfile<br><br>

$&gt; ./pipex infile "grep a1" "wc -w" outfile<br>
Should behave like:<br><br>
&lt; infile grep a1 | wc -w &gt; outfile
