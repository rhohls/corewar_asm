.name "ldi"
.comment "ldi"
start:
live %1
ldi r1,%4,r2        # RDR
ldi r1,r2,r3        # RRR
ldi %70,%30,r4        # DDR
ldi %4,r1,r5        # DRR
ldi 5,%0,r6    # IDR
ldi 10,r6,r7    # IRR

sti r2,%0,%164 # pc + 5
sti r3,%0,%170
sti r4,%0,%176
sti r5,%0,%182
sti r6,%0,%188
sti r7,%0,%194