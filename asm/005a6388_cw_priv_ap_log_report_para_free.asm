; func cw_priv_ap_log_report_para_free @ 0x005a6388 size=0x2c
  5a6388:	27bdffe0 	addiu	sp,sp,-32
  5a638c:	afbf001c 	sw	ra,28(sp)
  5a6390:	8c840010 	lw	a0,16(a0)
  5a6394:	10800004 	beqz	a0,0x5a63a8
  5a6398:	8fbf001c 	lw	ra,28(sp)
  5a639c:	0c101f7c 	jal	0x407df0
  5a63a0:	00000000 	nop
  5a63a4:	8fbf001c 	lw	ra,28(sp)
  5a63a8:	00001021 	move	v0,zero
  5a63ac:	03e00008 	jr	ra
  5a63b0:	27bd0020 	addiu	sp,sp,32
