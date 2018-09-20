
	fork %:fork1				; 1 -> 2
    fork1:
    		sti r5, %:end, r10			; write 4 bytes
    end:
    		sti r1, %:live0, %1		; initialize live instructions
live0: