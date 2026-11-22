; func cw_frag_timer_arg_free_callback @ 0x005966e0 size=0x4c
  5966e0:	3c02007c 	lui	v0,0x7c
  5966e4:	27bdffe0 	addiu	sp,sp,-32
  5966e8:	8c425988 	lw	v0,22920(v0)
  5966ec:	14400004 	bnez	v0,0x596700
  5966f0:	afbf001c 	sw	ra,28(sp)
  5966f4:	8fbf001c 	lw	ra,28(sp)
  5966f8:	03e00008 	jr	ra
  5966fc:	27bd0020 	addiu	sp,sp,32
  596700:	0c16276a 	jal	0x589da8
  596704:	00000000 	nop
  596708:	1040fffb 	beqz	v0,0x5966f8
  59670c:	8fbf001c 	lw	ra,28(sp)
  596710:	3c04006e 	lui	a0,0x6e
  596714:	3c05006e 	lui	a1,0x6e
  596718:	24842e40 	addiu	a0,a0,11840
  59671c:	24a53300 	addiu	a1,a1,13056
  596720:	240600dd 	li	a2,221
  596724:	08101b74 	j	0x406dd0
  596728:	27bd0020 	addiu	sp,sp,32
