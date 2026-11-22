; func cw_result_code_free @ 0x0057fddc size=0x3c
  57fddc:	27bdffe0 	addiu	sp,sp,-32
  57fde0:	afb00018 	sw	s0,24(sp)
  57fde4:	00808021 	move	s0,a0
  57fde8:	afbf001c 	sw	ra,28(sp)
  57fdec:	8c840010 	lw	a0,16(a0)
  57fdf0:	10800005 	beqz	a0,0x57fe08
  57fdf4:	8fbf001c 	lw	ra,28(sp)
  57fdf8:	0c101f7c 	jal	0x407df0
  57fdfc:	00000000 	nop
  57fe00:	ae000010 	sw	zero,16(s0)
  57fe04:	8fbf001c 	lw	ra,28(sp)
  57fe08:	00001021 	move	v0,zero
  57fe0c:	8fb00018 	lw	s0,24(sp)
  57fe10:	03e00008 	jr	ra
  57fe14:	27bd0020 	addiu	sp,sp,32
