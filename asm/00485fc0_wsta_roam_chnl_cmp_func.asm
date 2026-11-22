; func wsta_roam_chnl_cmp_func @ 0x00485fc0 size=0x30
  485fc0:	27bdffe0 	addiu	sp,sp,-32
  485fc4:	00001021 	move	v0,zero
  485fc8:	10800006 	beqz	a0,0x485fe4
  485fcc:	afbf001c 	sw	ra,28(sp)
  485fd0:	10a00005 	beqz	a1,0x485fe8
  485fd4:	8fbf001c 	lw	ra,28(sp)
  485fd8:	0c101f44 	jal	0x407d10
  485fdc:	00000000 	nop
  485fe0:	2c420001 	sltiu	v0,v0,1
  485fe4:	8fbf001c 	lw	ra,28(sp)
  485fe8:	03e00008 	jr	ra
  485fec:	27bd0020 	addiu	sp,sp,32
