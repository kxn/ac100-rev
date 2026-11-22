; func cw_priv_ch_state_free @ 0x005ad244 size=0x3c
  5ad244:	27bdffe0 	addiu	sp,sp,-32
  5ad248:	afb00018 	sw	s0,24(sp)
  5ad24c:	00808021 	move	s0,a0
  5ad250:	afbf001c 	sw	ra,28(sp)
  5ad254:	8c840010 	lw	a0,16(a0)
  5ad258:	10800005 	beqz	a0,0x5ad270
  5ad25c:	8fbf001c 	lw	ra,28(sp)
  5ad260:	0c101f7c 	jal	0x407df0
  5ad264:	00000000 	nop
  5ad268:	ae000010 	sw	zero,16(s0)
  5ad26c:	8fbf001c 	lw	ra,28(sp)
  5ad270:	00001021 	move	v0,zero
  5ad274:	8fb00018 	lw	s0,24(sp)
  5ad278:	03e00008 	jr	ra
  5ad27c:	27bd0020 	addiu	sp,sp,32
