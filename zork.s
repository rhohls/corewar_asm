.name "zork"

l2:	#	sti r1, %:live, %2  #I am a comment
		and r1, %0, r1
#I am also a comment
#live:live %1#hy
#		zjmp %:live

live:	live %2
		zjmp %:live