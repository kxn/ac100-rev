; func rrm_db_uninit @ 0x004b1b70 size=0x3c
  4b1b70:	27bdffe0 	addiu	sp,sp,-32
  4b1b74:	afb00018 	sw	s0,24(sp)
  4b1b78:	3c100076 	lui	s0,0x76
  4b1b7c:	afbf001c 	sw	ra,28(sp)
  4b1b80:	8e047c34 	lw	a0,31796(s0)
  4b1b84:	10800005 	beqz	a0,0x4b1b9c
  4b1b88:	8fbf001c 	lw	ra,28(sp)
  4b1b8c:	0c1020d8 	jal	0x408360
  4b1b90:	00000000 	nop
  4b1b94:	ae007c34 	sw	zero,31796(s0)
  4b1b98:	8fbf001c 	lw	ra,28(sp)
  4b1b9c:	00001021 	move	v0,zero
  4b1ba0:	8fb00018 	lw	s0,24(sp)
  4b1ba4:	03e00008 	jr	ra
  4b1ba8:	27bd0020 	addiu	sp,sp,32
