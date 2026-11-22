; func cw_priv_ap_checksum_result_free @ 0x005a43a4 size=0x3c
  5a43a4:	27bdffe0 	addiu	sp,sp,-32
  5a43a8:	afb00018 	sw	s0,24(sp)
  5a43ac:	00808021 	move	s0,a0
  5a43b0:	afbf001c 	sw	ra,28(sp)
  5a43b4:	8c840010 	lw	a0,16(a0)
  5a43b8:	10800005 	beqz	a0,0x5a43d0
  5a43bc:	8fbf001c 	lw	ra,28(sp)
  5a43c0:	0c101f7c 	jal	0x407df0
  5a43c4:	00000000 	nop
  5a43c8:	ae000010 	sw	zero,16(s0)
  5a43cc:	8fbf001c 	lw	ra,28(sp)
  5a43d0:	00001021 	move	v0,zero
  5a43d4:	8fb00018 	lw	s0,24(sp)
  5a43d8:	03e00008 	jr	ra
  5a43dc:	27bd0020 	addiu	sp,sp,32
