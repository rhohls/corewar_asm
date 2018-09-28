.name	"Booster !"
.comment "Alors la, si ca marche, trop content !  :)"

boost:	ld %12,r2 #7
	ld %3,r3 #7
	ld %4,r4 #7
	ld %5,r7 #7

	sti r1,%:live1,%1 #7he
live1:	live %66 #5
	sti r1,%:fork0,%1 #7
	sti r1,%:fork1,%1 #7
	sti r1,%:fork2,%1 #7 
	sti r1,%:wait,%1 #7
	ldi %:wait,%-2,r6 #7
	sti r1,%:master,%1 #7
	sti r1,%:numero1,%1 #7
	sti r1,%:numero2,%1 #7

	sti r1,%:live,%-4 #7
	ldi %:live,%-2,r6 #7
fork0:	live %66 #5
	fork %:numero1 #3
fork1:	live %66 #5
	fork %:numero2 #3
fork2:	live %66
	fork %:fork0

master:	live %66
	ld %0,r3
	ld %16777216,r6
	ldi %:master,%0,r6
	ld %0,r5
	zjmp %:ready

numero1: live %66
	ld %3,r3
	ld %68436,r2
	ldi %:live,%-2,r6
	ld %0,r5
	zjmp %:ready

numero2: live %66
	ld %6,r3
	ld %1409680135,r6
	ldi %:tampon,%1,r6
	ld %0,r5
	zjmp %:ready

tampon:	sti r6,r3,r5
live:	sti r1,r5,r5

ready:	sti r6,r3,%:ecriture

wait:	live %66
	zjmp %:ecriture

ecriture: zjmp %:wait



