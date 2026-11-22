; func cw_dtls_pkt_destroy @ 0x00598244 size=0x40
  598244:	27bdffe0 	addiu	sp,sp,-32
  598248:	afb00018 	sw	s0,24(sp)
  59824c:	00808021 	move	s0,a0
  598250:	10800008 	beqz	a0,0x598274
  598254:	afbf001c 	sw	ra,28(sp)
  598258:	0c165fe4 	jal	0x597f90
  59825c:	00000000 	nop
  598260:	02002021 	move	a0,s0
  598264:	8fbf001c 	lw	ra,28(sp)
  598268:	8fb00018 	lw	s0,24(sp)
  59826c:	08101f7c 	j	0x407df0
  598270:	27bd0020 	addiu	sp,sp,32
  598274:	8fbf001c 	lw	ra,28(sp)
  598278:	8fb00018 	lw	s0,24(sp)
  59827c:	03e00008 	jr	ra
  598280:	27bd0020 	addiu	sp,sp,32
