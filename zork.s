.name "zork"

.comment "kroz"

l2:	sti r1, %:live, %2  #I am a comment
		and r1, %0, r1

live:	live %2
		zjmp %:live
live0:
live_1: live %:live_2
live_2: