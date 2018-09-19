
// t_op    op_tab[17] =
// {
// 	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
// 	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
// 	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
// 	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
// 	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
// 	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
// 		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
// 	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
// 		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
// 	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
// 		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
// 	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
// 	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
// 		"load index", 1, 1},
// 	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
// 		"store index", 1, 1},
// 	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
// 	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
// 	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
// 		"long load index", 1, 1},
// 	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
// 	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
// 	{0, 0, {0}, 0, 0, 0, 0, 0}
// };

// cw_null:
// 		Nothing	1
		
// cw_live:N
// 		D		5
		
// cw_ld:Y
// 		DR		7
// 		IR		5
		
// cw_st:Y
// 		RI		5
// 		RR		4
		
// cw_add:Y
// 		RRR		5
		
// cw_sub:Y
// 		RRR		5
		
// cw_and:Y
// 		RRR		5
// 		IRR		6
// 		RIR		6
// 		IIR		7
// 		DRR		8
// 		RDR		8
// 		DDR		11
// 		DIR		9
// 		IDR		9
		
// cw_or:Y
// 		RRR		5
// 		IRR		6
// 		RIR		6
// 		IIR		7
// 		DRR		8
// 		RDR		8
// 		DDR		11
// 		DIR		9
// 		IDR		9
				
// cw_xor:Y
// 		RRR		5
// 		IRR		6
// 		RIR		6
// 		IIR		7
// 		DRR		8
// 		RDR		8
// 		DDR		11
// 		DIR		9
// 		IDR		9
				
// cw_zjmp:N
// 		D		3
			
// cw_ldi:Y	***ld D=2 (not 4)
// 		RRR		5
// 		IRR		6
// 		DRR		6
// 		RDR		6
// 		DDR		7
// 		IDR		7
		
// cw_sti:Y ***sti D=2 (not 4)
// 		RRR		5
// 		RIR		6
// 		RDR		6
// 		RRD		6
// 		RID		7
// 		RDD		7
			
// cw_fork:N ***sti D=2 (not 4)
// 		D		3
		
// cw_lld:Y
// 		DR		7
// 		IR		5 
		
// cw_lldi:Y	***ld D=2 (not 4)
// 		RRR		5
// 		IRR		6
// 		DRR		6
// 		RDR		6
// 		DDR		7
// 		IDR		7

// cw_lfork:N ***sti D=2 (not 4)
// 		D		3

// cw_aff:N
// 		R		3
